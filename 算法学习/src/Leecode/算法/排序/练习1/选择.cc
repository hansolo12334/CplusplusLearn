#include<iostream>
#include<vector>

using namespace std;


void choice_sort(vector<int> &vec)
{
    int n = vec.size();
    if(n<=1){
        return ;

    }
    for (int i = 0; i < n-1;i++){
        int minIdx = i;
        for (int j = i + 1; j < n;j++){
            if(vec[minIdx]>vec[j]){
                minIdx = j;
            }
        }
        swap(vec[minIdx], vec[i]);
    }
}

int main()
{
    vector<int> vec{2, 1, 4, 5, 3, 9, 6,-1};

    choice_sort(vec);

    for(auto v:vec){
        cout<<v<<' ';
    }
    cout<<'\n';
    return 0;
}
