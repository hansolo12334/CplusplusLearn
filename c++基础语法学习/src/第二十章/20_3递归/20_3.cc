#include<iostream>




void countDown(int cnt)
{
    std::cout << "push "<<cnt<<'\n';
    if(cnt>1){
        countDown(cnt - 1);
    }
    std::cout << "pop "<<cnt<<'\n';
}


int main()
{
    countDown(5);
    return 0;
}
