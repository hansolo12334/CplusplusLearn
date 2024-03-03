#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <set>
#include <string>



using namespace std;


class Solution {
public:
    // vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    //     int m = img.size();
    //     int n = img[0].size();
    //     auto re = img;

    //     if(m==1 && n==1){
    //         return img;
    //     }
    //     if(m==1)
    //     {
    //         double sum;
    //         for (int j = 0; j < n; j++)
    //         {
    //             sum += img[0][j];
    //         }
    //         sum = floor(sum / n);
    //         for (int j = 0; j < n; j++)
    //         {
    //             re[0][j] = sum;
    //         }
    //         return re;
    //     }
    //     if(m!=1&&n==1)
    //      {
    //         double sum;
    //         for (int i = 0; i < m; i++)
    //         {
    //             sum += img[i][0];
    //         }
    //         sum = floor(sum / m);
    //         for (int i = 0; i < m; i++)
    //         {
    //             re[i][0] = sum;
    //         }
    //         return re;
    //     }



    //     for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < n;j++)
    //         {
    //             double sum = 0;
    //             if(i>=1&&i<=(m-2) && j>=1&& j<=(n-2))
    //             {
    //                 sum = img[i][j] + img[i - 1][j] + img[i - 1][j - 1] + img[i][j - 1] + img[i + 1][j] +
    //                       img[i][j + 1] + img[i + 1][j + 1] + img[i - 1][j + 1] + img[i + 1][j - 1];
    //                 sum = floor(sum / 9);
    //             }
    //             else if((i==0&&j==0) ||i==(m-1)&&j==0 ||(i==0&&j==(n-1))||(i==(m-1)&&j==(n-1)) )
    //             {
    //                 if(i==0&&j==0)
    //                 {
    //                     sum = img[i][j] + img[i + 1][j] + img[i + 1][j + 1] + img[i][j + 1];
    //                 }
    //                 else if(i==0&&j==(n-1))
    //                 {
    //                     sum = img[i][j] + img[i][j-1] + img[i+1][j - 1] + img[i + 1][j];
    //                 }
    //                 else if(i==(m-1)&&j==0)
    //                 {
    //                     sum = img[i][j] + img[i - 1][j] + img[i][j + 1] + img[i - 1][j + 1];
    //                 }
    //                 else
    //                 {
    //                     sum = img[i][j] + img[i][j - 1] + img[i - 1][j - 1] + img[i - 1][j];
    //                 }
    //                 sum = floor(sum / 4);
    //             }
    //             else
    //             {
    //                 if(j==0)
    //                 {
    //                     sum = img[i][j] + img[i - 1][j] + img[i - 1][j + 1] + img[i + 1][j] + img[i + 1][j + 1] +
    //                           img[i][j + 1];
    //                 }
    //                 if(i==0)
    //                 {
    //                     sum = img[i][j] + img[i][j - 1] + img[i][j + 1] + img[i + 1][j] + img[i + 1][j - 1] +
    //                           img[i + 1][j + 1];
    //                 }
    //                 if(i==(m-1))
    //                 {
    //                     sum = img[i][j] + img[i][j + 1] + img[i][j - 1] + img[i - 1][j] + img[i - 1][j - 1] +
    //                           img[i - 1][j + 1];
    //                 }
    //                 if(j==(n-1))
    //                 {
    //                     sum = img[i][j] + img[i][j - 1] + img[i - 1][j - 1] + img[i - 1][j] + img[i + 1][j] +
    //                           img[i + 1][j - 1];
    //                 }
    //                 sum = floor(sum / 6);
    //             }


    //             re[i][j] = sum;
    //         }
    //     }
    //     return re;
    // }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        int l = 0;
        auto re = img;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                l = 1;
                double sum = img[i][j];
                if(i-1>=0&& j-1>=0){
                    sum += img[i - 1][j - 1];
                    l++;
                }
                if(i-1>=0&&j+1<=(n-1))
                {
                    sum+=img[i -1][j + 1];
                    l++;
                }
                if(i+1<=(m-1)&& j-1>=0)
                {
                    sum += img[i + 1][j - 1];
                    l++;
                }
                if(i+1<=(m-1)&&j+1<=(n-1))
                {
                    sum += img[i + 1][j + 1];
                    l++;
                }
                if(i-1>=0)
                {
                    sum += img[i - 1][j];
                    l++;
                }
                if(i+1<=(m-1))
                {
                    sum += img[i + 1][j];
                    l++;
                }
                if(j-1>=0)
                {
                    sum += img[i][j - 1];
                    l++;
                }
                if(j+1<=(n-1))
                {
                    sum += img[i][j + 1];
                    l++;
                }
                sum = floor(sum / l);
                re[i][j] = sum;
            }
        }
        return re;
    }
};


int main()
{
    vector<vector<int>> img = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
    // vector<vector<int>> img = {{3}, {2}};
    Solution s;
    auto re = s.imageSmoother(img);
    for(auto rr:re)
    {
        for(auto r:rr)
        {
            cout << r << ' ';
        }
        cout << '\n';
    }
    return 0;
}
