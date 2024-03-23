#include<iostream>
#include<vector>

using namespace std;


int getMid(vector<int> &vec,int l,int r)
{
    int poivt = vec[l];
    while (l < r)
    {
        while(l<r && vec[r]>=poivt){
            r--;
        }
        vec[l] = vec[r];
        while (l < r && vec[l] <= poivt)
        {
            l++;
        }
        vec[r] = vec[l];
    }
    vec[l] = poivt;
    return l;
}

void fast_sort(vector<int> &vec,int l,int r)
{
    if(l<r){
        int mid=getMid(vec, l, r);
        fast_sort(vec, l, mid - 1);
        fast_sort(vec, mid + 1, r);
    }
}

int main()
{
    vector<int> vec{2, 1, 4, 5, 3, 9, 6};

    fast_sort(vec, 0, vec.size() - 1);

    for(auto v:vec){
        cout<<v<<' ';
    }
    cout<<'\n';
    return 0;
}
