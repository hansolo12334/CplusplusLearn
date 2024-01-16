#include <iostream>
#include <string>
#include <string_view>
#include <thread>
#include <vector>


//使用分离线程处理任务
void edit_document(std::string const &filename)
{
    std::cout << "filename : " << filename << '\n';

    std::cout << std::this_thread::get_id() << '\n';
    while (1)
    {
        std::string new_name{};
        getline(std::cin, new_name);
        if (new_name.size() != 0)
        {
            std::thread t(edit_document, new_name);
            t.detach();
        }
        else
        {
            std::cout << "done!\n";
        }
    }

    std::cout << "end\n";
}


int main()
{
    std::string filename{"hansolo.txt"};
    edit_document(filename);

    return 0;
}
