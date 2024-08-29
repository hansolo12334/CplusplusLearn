#ifndef SHARED_MEM_H
#define SHARED_MEM_H
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#include<signal.h>

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>

#include <chrono>
#include <thread>
#include<algorithm>




class shared_mem
{
private:
  union semun
  {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
  };
  key_t m_key;

  int m_shmId; // 共享内存区域的ID
  int m_semId; // 信号量
  void *m_shm_addr = nullptr;

  struct sembuf sem_b;

  static int m_count;


  //计数值的偏移量
  int counter_size = sizeof(int);

public:
  shared_mem();
  ~shared_mem();

  bool init();
  // bool destory();
  bool lock();
  bool unlock();

  void *get_shm_addr();

  template <typename T>
  void write_data(T &data)
  {
    int data_size = sizeof(data);
    memcpy(m_shm_addr, &data_size, sizeof(data_size));
    memcpy((char *)m_shm_addr + sizeof(data_size), &data, data_size);
  }
  void write_data(std::string &serilized_data);

  template <typename T>
  void read_data(T &data)
  {
    int data_size;

    memcpy(&data_size, m_shm_addr, sizeof(data_size));
    data_size = data_size > static_cast<int>(sizeof(T)) ? static_cast<int>(sizeof(T)) : data_size;
    memcpy(&data, (char *)m_shm_addr + sizeof(data_size), data_size);
  }
  void read_data(std::string &serilized_data);

  
  shared_mem &operator=(const shared_mem &) = delete;
};


#endif