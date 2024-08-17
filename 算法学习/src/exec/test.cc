#include<iostream>

#include<string>

#include<algorithm>
#include<vector>



class Test
{

public:
    const int c_a=1;


public:
    Test()
    : c_a{2}
    {
        std::cout << "c_a " << c_a << '\n';
    }
    int l_a = 1;
    static int st_a;

    static void add()
    {
        int aa = 1;
        aa++;
        std::cout << aa << '\n';
    }
    void dd()
    {
        int aa = 1;
        aa++;
        l_a++;
        std::cout << aa << '\n';
    }

    std::string t_string(std::string &ss) const
    {
        auto sss=l_a;
        ss.append("aa");
        return ss;
    }
};

int Test::st_a = 1;




int main()
{
    Test t1;

    Test t2;
    Test::add();
    t2.dd();
    std::string sssss{"sss"};
    std::cout<<t2.t_string(sssss);


    Test *t3 = static_cast<Test*>(malloc(sizeof(Test)));
    free(t3);

    Test *t4 = new Test();
    delete t4;
    t4->add();

    std::vector<int> vec_{1, 2, 34, 5, 6};
    auto ct = std::count_if(vec_.begin(), vec_.end(), [&](int v){return v > 2 ? 1 : 0;}
    );
    std::cout << ct << '\n';
    return 0;
}
