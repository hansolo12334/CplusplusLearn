#include <iostream>
#include <vector>

using namespace std;


int findMid(vector<int> &vec, int l, int r)
{
    int pviot = vec[l];

    while (l < r)
    {
        while (l < r && vec[r] >= pviot)
        {
            r--;
        }
        vec[l] = vec[r];
        while (l < r && vec[l] <= pviot)
        {
            l++;
        }
        vec[r] = vec[l];
    }


    vec[l] = pviot;
    return l;
}

void fast_sort(vector<int> &vec, int l, int r)
{
    if (l < r)
    {
        int mid = findMid(vec, l, r);
        fast_sort(vec, l, mid - 1);
        fast_sort(vec, mid + 1, r);
    }

}

int main()
{
    vector<int> vec{1,-2,3,2,5,4};
    fast_sort(vec, 0, vec.size() - 1);
    for (auto v : vec)
    {
        cout << v << ' ';
    }
    cout << '\n';
    return 0;
}
