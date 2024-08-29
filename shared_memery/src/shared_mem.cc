#include "shared_mem.hpp"

int shared_mem::m_count = 0;



shared_mem::shared_mem()
{

}

shared_mem::~shared_mem()
{
  
  int *count = (int *)m_shm_addr;
  --(*count);
  int cnt=*count;

  shmdt(m_shm_addr);
  if (cnt == 0)
  {
    std::cout << "clear shm  shared mem seg\n";
    int sh = shmctl(m_shmId, IPC_RMID, NULL);
    if (sh == -1)
    {
      perror("shmctl error");
    }

    std::cout << "clear sem  signal seg\n";

    sh = semctl(m_semId, 0, IPC_RMID);
    if (sh == -1)
    {
      perror("semctl error");
    }

  }
  else{
    std::cout << "instance remain: " << cnt << '\n';
  }
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

  // 计数器
  int *count = (int *)m_shm_addr;
  if (*count == 0)
  {
    *count = 1;
  }
  else
  {
    (*count)++;
  }
  std::cout << "count: " << *count << '\n';
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
  // 设置偏移量 跳过counter
  memcpy((char *)m_shm_addr + counter_size, &str_length, sizeof(str_length));
  memcpy((char *)m_shm_addr + counter_size + sizeof(str_length), c_str, str_length);
}

void shared_mem::read_data(std::string &serilized_data)
{
  int c_str_length;
  memcpy(&c_str_length, (char *)m_shm_addr + counter_size, sizeof(c_str_length));

  char *data = new char[c_str_length + 1];
  memcpy(data, (char *)m_shm_addr + counter_size + sizeof(c_str_length), c_str_length);
  data[c_str_length] = '\0'; // Add null terminator

  serilized_data = std::string(data);
}