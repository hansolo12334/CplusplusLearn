#include<iostream>
#include<vector>

using namespace std;


void insert_sort(vector<int> &vec)
{
    int n = vec.size();
    if(n<=1){
        return ;

    }
    for (int i = 0; i < n;i++){
        for (int j = i;j>0;j--){
            if(vec[j]<vec[j-1]){
                swap(vec[j], vec[j - 1]);
            }
        }
    }
}

int main()
{
    vector<int> vec{2, 1, 4, 5, 3, 9, 6,-1};

    insert_sort(vec);

    for(auto v:vec){
        cout<<v<<' ';
    }
    cout<<'\n';
    return 0;
}
