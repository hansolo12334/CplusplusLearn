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

  // hansolo_std::std_msg msg;
  // msg.set_datatype("ssssss");
  // msg.set_data(2);

  hansolo_std::std_msg_array msg_array;

  data_example d_e;
  while (times < 100)
  {
    // msg.set_datatype("ssssss");
    // msg.set_data(times);
    std::string str_s;
    // msg.SerializeToString(&str_s);
    msg_array.clear_msg();
    for (int i = 0; i < 5; i++)
    {
      auto add_m = msg_array.add_msg();
      add_m->set_data(i+times);
      add_m->set_datatype("ssss");
    }
    msg_array.SerializeToString(&str_s);

    std::cout << "time : " << times << '\n';
    sh_mem.lock();

    // std::string data="test datas";
    // data = data + std::to_string(times);
    // int c_str_length = data.length();
    // memcpy(sh_mem.get_shm_addr(), &c_str_length, sizeof(c_str_length));
    // memcpy((char*)sh_mem.get_shm_addr()+sizeof(c_str_length), data.c_str(), c_str_length);
    // printf("Writing is finish !   %s\n",data.c_str());

    // data_example d_e;
    // d_e.time = times;
    // sh_mem.write_data(d_e);
    // std::string data = "test datas\n";
    sh_mem.write_data(str_s);
    // sh_mem.write_data(data_cstr);

    sh_mem.unlock();

 

    times++;
    std::this_thread::sleep_for(std::chrono::seconds(1));

  }

  return 0;
}