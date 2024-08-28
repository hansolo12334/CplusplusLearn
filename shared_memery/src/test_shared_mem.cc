#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#include <stdio.h>
#include <string.h>

#include<string>

#include<iostream>
#include<chrono>
#include<thread>



union semun
{
  int val;
  struct semid_ds *buf;
  unsigned short *array;
};

int main()
{
  /**********实现步骤中的第1步**********/
  // 利用ftok获得一个IPC键值，
  key_t key = ftok("/home", 0x666);
  if (key == -1)
  {
    perror("ftok error");
    return -1;
  }
  printf("ftok : %d\n", key);

  // 获取共享内存区域的ID
  int shmId = shmget(key, 4096, IPC_CREAT | 0600);
  if (shmId == -1)
  {
    perror("shmget error");
    return -1;
  }
  printf("shmget : %d\n", shmId);

  // 创建一个信号量
  int semId = semget(key, 1, IPC_CREAT | 0600);
  if (semId == -1)
  {
    perror("semget error");
    return -1;
  }

  /**********实现步骤中的第2步**********/
  // 连接共享内存
  void *shm_addr = shmat(shmId, NULL, 0);

  // 初始化信号量的值为1
  union semun sem_union;
  sem_union.val = 1;
  if (semctl(semId, 0, SETVAL, sem_union))
  {
    perror("semctl error");
    return -1;
  }

  // 创建一个sembuf结构体，用于改变信号量的值
  struct sembuf sem_b;
  sem_b.sem_num = 0;
  sem_b.sem_flg = SEM_UNDO;

  int times = 0;
  while (true)
  {
    // 等待信号量变为0
    sem_b.sem_op = -1;
    int bb=semop(semId, &sem_b, 1);
    // std::cout << "bb : " << bb << '\n';
    // 创建需写入内存的数据并将其写入共享内存区
    // char data[30] = "test datas";
    std::string data="test datas";
    data = data + std::to_string(times);

    int c_str_length = data.length();
    memcpy(shm_addr, &c_str_length, sizeof(c_str_length));

    memcpy((char*)shm_addr+sizeof(c_str_length), data.c_str(), c_str_length);
    printf("Writing is finish !   %s\n",data.c_str());

    
    // 将信号量的值增加1
    sem_b.sem_op = 1;
    semop(semId, &sem_b, 1);

    
    times++;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    }

  /**********实现步骤中的第3步**********/
  // 断开
  shmdt(shm_addr);

  // 写入程序中不需要释放共享内存（第4步），否则读取程序无法正确读取数据

  return 0;
}
