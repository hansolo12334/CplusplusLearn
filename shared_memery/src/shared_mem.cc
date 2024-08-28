#include "shared_mem.hpp"

int shared_mem::m_count = 0;

shared_mem::shared_mem()
{
}

shared_mem::~shared_mem()
{
  shmdt(m_shm_addr);

  // int sh = shmctl(m_shmId, IPC_RMID, NULL);
  // if (sh == -1)
  // {
  //   perror("shmctl error");
  // }
}

bool shared_mem::init()
{
  m_key = ftok("/home", 0x666);
  if (m_key == -1)
  {
    perror("ftok error");
    return false;
  }
  std::cout << "ftok: " << m_key << '\n';

  m_shmId = shmget(m_key, 4096, IPC_CREAT | 0600);
  if (m_shmId == -1)
  {
    perror("shmget error");
    return false;
  }

  std::cout << "shmget : " << m_shmId << '\n';

  m_semId = semget(m_key, 1, IPC_CREAT | 0600);
  if (m_semId == -1)
  {
    perror("semget error");
    return false;
  }

  m_shm_addr = shmat(m_shmId, NULL, 0);

  union semun sem_union;
  sem_union.val = 1;
  if (semctl(m_semId, 0, SETVAL, sem_union))
  {
    perror("semctl error");
    return false;
  }

  return true;
}

bool shared_mem::lock()
{

  sem_b.sem_num = 0;
  sem_b.sem_flg = SEM_UNDO;

  sem_b.sem_op = -1;
  if (semop(m_semId, &sem_b, 1))
  {
    return false;
  }

  return true;
}

bool shared_mem::unlock()
{
  sem_b.sem_op = 1;
  if (semop(m_semId, &sem_b, 1))
  {
    return false;
  }
  return true;
}

void *shared_mem::get_shm_addr()
{
  return m_shm_addr;
}

void shared_mem::write_data(std::string &serilized_data)
{
  const char *c_str = serilized_data.c_str();
  int str_length = serilized_data.length();
  memcpy(m_shm_addr, &str_length, sizeof(str_length));
  memcpy((char *)m_shm_addr + sizeof(str_length), c_str, str_length);
}

void shared_mem::read_data(std::string &serilized_data)
{
  int c_str_length;
  memcpy(&c_str_length, m_shm_addr, sizeof(c_str_length));

  char *data = new char[c_str_length + 1];
  memcpy(data, (char *)m_shm_addr+ sizeof(c_str_length), c_str_length);
  data[c_str_length] = '\0'; // Add null terminator

  serilized_data = std::string(data);
}