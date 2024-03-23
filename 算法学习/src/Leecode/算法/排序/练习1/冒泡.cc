#include<iostream>
#include<vector>

using namespace std;


void bubol_sort(vector<int> &vec)
{
    int n = vec.size();
    if(n<=1){
        return ;

    }
    for (int i = 0; i < n;i++){
        bool isSwap = false;
        for (int j = 1; j < n-i; j++)
        {
            if(vec[j]<vec[j-1]){
                swap(vec[j], vec[j - 1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            break;
        }
    }
}

int main()
{
    vector<int> vec{2, 1, 4, 5, 3, 9, 6,-1};

    bubol_sort(vec);

    for(auto v:vec){
        cout<<v<<' ';
    }
    cout<<'\n';
    return 0;
}
