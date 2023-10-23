#include<iostream>

using namespace std;

bool isEven(int x)
{
    return (x % 2 == 0);
}
int main()
{
    int x{};
    cout << "Enter a integer:";
    cin >> x;
    if(not isEven(x))
    {
        cout << x << " is odd\n";
    }
    else{
        cout << x << " is even\n";
    }
}
