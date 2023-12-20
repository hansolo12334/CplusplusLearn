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

#include<set>

using namespace std;



class Solution {
public:
    bool isRobotBounded(string instructions) {
        // set<pair<int, int>> pos_sets;
        int x{0}, y{0};
        double heading{90*M_PI/180};

        int lengthX{0};
        int lengthY{0};
        int j{};
        for (int t = 0; t < 4;t++)
        {
            for (int i = 0; i < instructions.size(); i++)
            {
                char ins = instructions[i];

                if (ins == 'G')
                {
                    lengthX += cos(heading);
                    lengthY += sin(heading);

                    x += cos(heading);
                    y += sin(heading);
                    j++;
                    cout << x << ' ' << y << '\n';
                }


                if (ins == 'L')
                {
                    heading += (90 * M_PI / 180);
                }
                if (ins == 'R')
                {
                    heading -= (90 * M_PI / 180);
                }


                // if (pos_sets.find(make_pair(x, y)) != pos_sets.end())
                // {
                //     return true;
                // }
                if (j>2 && lengthX==0 && lengthY==0)
                {
                    return true;
                }
                // pos_sets.insert(make_pair(x,y));
            }
        }

        return false;
    }
};



int main()
{
    string instructions{"GLGLGGLGL"};
    Solution ss;
    cout << ss.isRobotBounded(instructions) << '\n';
    return 0;
}
