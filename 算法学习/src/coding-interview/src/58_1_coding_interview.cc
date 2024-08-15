#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#include<memory>

class Solution
{
public:
    Solution()
    {

    }

    std::string reverseString(std::string &str)
    {
        int head = 0;
        int tail = str.length() - 1;
        std::string out;
        while(tail>=0)
        {
            std::string temp;
            while (tail >= 0 && str[tail] != ' ')
            {
                temp = str[tail] + temp;
                tail--;
            }
            if(tail>=0){
                out = out + temp + ' ';
            }
            else
            {
                out = out + temp;
            }

            tail--;
        }
        return out;
    }

    void reverseStr(int left,int right,std::string &str)
    {
        while(left<right){
            std::swap(str[left], str[right]);
            left++;
            right--;
        }
    }
    std::string reverseString1(std::string &str)
    {
        reverseStr(0, str.length() - 1, str);
        int left = 0;
        for (int i = 0; i < str.length();i++){
            if(str[i]==' ')
            {
                reverseStr(left, i-1, str);
                left = i + 1;
            }
        }
        return str;
    }
};


void test(std::string *str)
{
    str->append("aa");
}

void test1(std::string &str)
{
    str.append("vv");
}


int main()
{
    std::string str{"I am a student."};
    Solution ss;
    std::cout << ss.reverseString1(str) << "0\n";


    std::string sss{"ss"};
    test(&sss);
    std::cout << sss << '\n';
    test1(sss);
    std::cout << sss << '\n';


    std::shared_ptr<std::string> ptr = std::make_shared<std::string>("ssss");
    std::shared_ptr<std::string> ptr1 = ptr;
    auto strs = ptr.use_count();
    std::cout << strs << '\n';
    ptr1.reset();
    strs = ptr.use_count();
    std::cout << strs << '\n';

    std::weak_ptr<std::string> w_ptr;
    w_ptr = ptr;
    strs = ptr.use_count();
    std::cout << strs << '\n';
    return 0;
}
