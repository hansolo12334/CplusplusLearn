#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include<chrono>
#include<thread>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};


int main()
{
  /**********实现步骤中的第1步**********/
  // ftok的第一个参数必须保证和写入程序中一致，最好别写相对路径
  key_t key = ftok("/home", 0x666);
  if (key == -1)
  {
    perror("ftok error");
    return -1;
  }
  printf("ftok : %d\n", key);

  int shmId = shmget(key, 4096, IPC_CREAT | 0600);
  if (shmId == -1)
  {
    perror("shmget error");
    return -1;
  }
  printf("shmget : %d\n", shmId);

  /**********实现步骤中的第2步**********/
  void *shm_addr = shmat(shmId, NULL, 0);


  // 获取信号量
  int semId = semget(key, 1, 0600);
  if (semId == -1) {
      perror("semget error");
      return -1;
  }
  // 创建一个sembuf结构体，用于改变信号量的值
  struct sembuf sem_b;
  sem_b.sem_num = 0;
  sem_b.sem_flg = SEM_UNDO;

  

  // while(true)
  // {
  //   // 等待信号量变为0
  //   sem_b.sem_op = -1; //尝试将信号量的值减1。
  //   //如果信号量的值已经是0（表示共享内存正在被使用），这个操作会阻塞，直到信号量的值不为0（表示共享内存可用）
  //   semop(semId, &sem_b, 1);

  //   int c_str_length;
  //   memcpy(&c_str_length, shm_addr, sizeof(c_str_length));

  //   char* data = new char[c_str_length + 1];
  //   memcpy(data, (char*)shm_addr + sizeof(c_str_length), c_str_length);
  //   data[c_str_length] = '\0';  // Add null terminator

  //   std::cout << "get data  "<<data << '\n';


  //   // 将信号量的值增加1
  //   sem_b.sem_op = 1;
  //   semop(semId, &sem_b, 1);
    
    

  //   std::this_thread::sleep_for(std::chrono::seconds(1));

  // }
  // // 取出数据
  // char data[30] = {0};
  // memcpy(&data, shm_addr, sizeof(data));
  // std::cout << "the data : " << data << std::endl;

  // /**********实现步骤中的第3步**********/
  // // 断开
  shmdt(shm_addr);

  // /**********实现步骤中的第4步**********/
  // // 将共享内存释放
  int sh = shmctl(shmId, IPC_RMID, NULL);
  if (sh == -1)
  {
    perror("shmctl error");
    return -1;
  }
  printf("shmctl is worked.\n");

  return 0;
}
