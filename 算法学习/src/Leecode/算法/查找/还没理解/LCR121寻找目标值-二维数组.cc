#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

#include <deque>
#include <queue>


using namespace std;


class Solution {
public:


bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
    if(plants.size()==0)
    {
        return 0;
    }
    if(plants[0].size()==0)
    {
        return 0;
    }
    int height = plants.size();
    int weight = plants[0].size() - 1;
    for (int i = 0; i < height; i++)
    {
        if( plants[i][0]==target || plants[i][weight]==target )
        {
            return true;
        }
        if( plants[i][0]<target && plants[i][weight]>target)
        {
            if(findInRow(plants[i],target))
            {
                return true;
            }
        }
        if(plants[i][weight]<target)
        {
            continue;
        }
    }
    return false;
}
  bool findInRow(vector<int> row,int target)
  {
      int left = 0;
      int right = row.size() - 1;
      while(left<=right)
      {
          int mid = (left + right) / 2;
          if(row[mid]<target)
          {
              left = mid + 1;
          }
          else if(row[mid]>target)
          {
              right = mid - 1;
          }
          else
          {
              return true;
          }
      }
      return false;
  }

  //方法二 将矩阵旋转45度 类似一个二叉搜索树
  bool findTargetIn2DPlants1(vector<vector<int>>& plants, int target) {
      int i = plants.size() - 1;
      int j = 0;
      while(i>=0 && plants[0].size())
      {
        if(plants[i][j]>target)
        {
            i--;
        }
        else if (plants[i][j]<target)
        {
            j++;
        }
        else{
            return true;
        }
      }
      return false;
  }
};


int main()
{
    //vector<vector<int>> plants{{1,4},{2,5}};
    vector<vector<int>> plants{{2, 3, 6, 8}, {4, 5, 8, 9}, {5, 9, 10, 12}};
    int target{8};
    Solution ss;
    cout << ss.findTargetIn2DPlants(plants, target) << '\n';
    return 0;
}
