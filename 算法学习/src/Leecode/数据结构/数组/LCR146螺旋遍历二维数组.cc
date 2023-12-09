#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

using namespace std;



class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {

        derection dere{RIGHT};

        int arraysize_ud = array.size();
        if(arraysize_ud==0)
        {
            return {};
        }
        int arraysize_lr = array[0].size();
        if(arraysize_lr==0)
        {
            return {};
        }
        int arraySize{arraysize_lr * arraysize_ud};

        arraysize_ud=arraysize_ud-1;

        int lr{0}, ud{0};

        int sumLr{1}, sumUd{1};
        std::vector<int> re;
        while (true)
        {

            switch (dere)
            {
            case derection::RIGHT:
                re.push_back(array[ud][lr]);


                sumLr++;

                if (sumLr > arraysize_lr)
                {
                    sumLr = 1;
                    arraysize_lr--;
                    if(re.size()==arraySize)
                    {
                        dere = derection::OVER;
                        break;
                    }
                    dere = derection::DOWN;
                    ud++;
                }
                else
                {
                    lr++;
                }
                break;

            case derection::DOWN:
                re.push_back(array[ud][lr]);

                sumUd++;
                if (sumUd > arraysize_ud)
                {
                    sumUd = 1;
                    arraysize_ud--;
                    if(re.size()==arraySize)
                    {
                        dere = derection::OVER;
                        break;
                    }
                    dere = derection::LEFT;
                    lr--;

                }
                else
                {
                    ud++;
                }
                break;

            case derection::LEFT:
                re.push_back(array[ud][lr]);

                sumLr++;
                if (sumLr > arraysize_lr)
                {
                    sumLr = 1;
                    arraysize_lr--;
                    if(re.size()==arraySize)
                    {
                        dere = derection::OVER;
                        break;
                    }
                    dere = derection::UP;
                    ud--;

                }
                else{
                    lr--;
                }
                break;

            case derection::UP:
                re.push_back(array[ud][lr]);

                sumUd++;
                if (sumUd > arraysize_ud)
                {
                    sumUd = 1;
                    arraysize_ud--;
                    if(re.size()==arraySize)
                    {
                        dere = derection::OVER;
                        break;
                    }
                    dere = derection::RIGHT;
                    lr++;
                }
                else{
                    ud--;
                }
                break;

            case derection::OVER:
                return re;
            }
        }
    }




    enum derection
    {
        RIGHT,
        DOWN,
        LEFT,
        UP,
        OVER,
    };
};


int main()
{
    //vector<vector<int>> in{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    //vector<vector<int>> in{{1,2},{3,4}};
    vector<vector<int>> in{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13}, {14, 15, 16}};
    Solution s;
    vector<int> re = s.spiralArray(in);
    for(int r:re)
    {
        std::cout << r << ' ';
    }
    std::cout << '\n';
    return 0;
}
