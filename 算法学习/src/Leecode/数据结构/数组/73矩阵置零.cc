#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>
#include<set>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        for (int i = 0; i < matrix.size(); i++)
        {
            if(rowSets.find(i)!=rowSets.end()) continue;
            for (int j = 0; j < matrix[0].size();j++)
            {
                if(columSets.find(j)!=columSets.end()&& sets.find({i,j})!=sets.end()) continue;
                if(matrix[i][j]==0 && sets.find({i,j})==sets.end())
                {
                    sets.insert({i, j});

                    fillColum(matrix, j);
                    if(rowSets.find(i)==rowSets.end()){
                        fillRow(matrix, i);
                        rowSets.insert(i);
                    }
                    columSets.insert(j);
                }
            }
        }
    }



    //填充行
    void fillRow(vector<vector<int>>& matrix, int row){
        for (int i = 0; i < matrix[0].size();i++)
        {
            if(matrix[row][i]!=0 && sets.find({row,i})==sets.end())
            {
                matrix[row][i] = 0;
                sets.insert({row, i});
            }
        }
    }

    //填充列
    void fillColum(vector<vector<int>>& matrix, int colum){
        for (int i = 0; i < matrix.size();i++)
        {
            if(matrix[i][colum]!=0 && sets.find({i,colum})==sets.end())
            {
                matrix[i][colum] = 0;
                sets.insert({i, colum});
            }
        }
    }
private:
     set<vector<int>> sets;
     set<int> rowSets;
     set<int> columSets;



public:
//方法二
void setZeroes1(vector<vector<int>>& matrix) {
    bool firstRowZero{false}, firstColumZero{false};
    int m = matrix.size();
    int n = matrix[0].size();

    //记录第一行第一列是否需要 全零
    for (int i = 0; i < m;i++){
        if(matrix[i][0]==0){
            firstColumZero = true;
            break;
        }
    }
    for (int i = 0; i < n;i++){
        if(matrix[0][i]==0){
            firstRowZero = true;
            break;
        }
    }

    // 利用第一行 第一列 作为数组标记 其他位置的含零情况
    for (int i = 1; i < m;i++)
    {
        for (int j = 1; j < n;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    //根据数组的标记情况 置零
    for (int i = 1; i < m;i++)
    {
        for (int j = 1; j < n;j++)
        {
            if(matrix[i][0]==0|| matrix[0][j]==0)
            {
                matrix[i][j] = 0;
            }
        }
    }

//最后看看 第一行第一列是否需要全置零
    if(firstColumZero){
        for (int i = 0; i < m;i++){
            matrix[i][0] = 0;
        }
    }
    if(firstRowZero){
        for (int i = 0; i < n;i++){
            matrix[0][i] = 0;
        }
    }

    }
};


int main()
{
    vector<vector<int>> matrix{{0,0,0,5}, {4,3,1,4}, {0,1,1,4},{1,2,1,3},{0,0,1,1}};
    Solution ss;
    for(auto mat:matrix)
    {
        for(int mm:mat)
        {
            cout << mm << ' ';
        }
        cout << '\n';
    }
    ss.setZeroes1(matrix);
    for(auto mat:matrix)
    {
        for(int mm:mat)
        {
            cout << mm << ' ';
        }
        cout << '\n';
    }
    return 0;
}
