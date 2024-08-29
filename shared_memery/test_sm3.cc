#include<shared_mem.hpp>


#include<test_msg.pb.h>


struct data_example
{
  int time = 0;
  // std::string str = "sss\n";
};


int main()
{
  shared_mem sh_mem;

  if(!sh_mem.init()){
    return -1;
  }

  int times = 0;
  data_example d_e;
  while (times < 500)
  {
    
    std::cout << "time : " << times << '\n';
    sh_mem.lock();

    // int c_str_length;
    // memcpy(&c_str_length, sh_mem.get_shm_addr(), sizeof(c_str_length));

    // char* data = new char[c_str_length + 1];
    // memcpy(data, (char*)sh_mem.get_shm_addr() + sizeof(c_str_length), c_str_length);
    // data[c_str_length] = '\0';  // Add null terminator

    
    // int struc_size;
    std::string re;
    sh_mem.read_data(re);
    // std::string data;
    // sh_mem.read_data(data);

    sh_mem.unlock();
    hansolo_std::std_msg_array msg_array;
    // hansolo_std::std_msg msg;
    msg_array.ParseFromString(re);


    std::cout << "-------------\nget data : " <<'\n';
    for (int i = 0; i < msg_array.msg_size(); i++){
      auto msgg = msg_array.msg(i);
      std::cout << msgg.data() << ' ';
    }
    std::cout << '\n';

    times++;
    std::cout << sh_mem.get_shm_addr() << '\n';
    std::this_thread::sleep_for(std::chrono::microseconds(100000));
 
  }
  return 0;
}