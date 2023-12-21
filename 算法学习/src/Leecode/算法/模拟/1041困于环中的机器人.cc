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

        int x{0}, y{0};
        int heading{90};

        int j{};
        for (int t = 0; t <4;t++)
        {
            for (int i = 0; i < instructions.size(); i++)
            {
                char ins = instructions[i];

                if (ins == 'G')
                {
                    if(heading==0){
                        x += 1;
                    }
                    if(heading==90){
                        y += 1;
                    }
                    if(heading==180){
                        x -= 1;
                    }
                    if(heading==270){
                        y -= 1;
                    }
                    if(heading==360){
                        x += 1;
                    }

                    // x += cos(heading* M_PI / 180);
                    // y += sin(heading* M_PI / 180);
                }
                j++;

                if (ins == 'L')
                {
                    heading += 90;
                }
                if (ins == 'R')
                {
                    heading -= 90;
                }

                while(heading>=360){
                    heading -= 360;
                }
                while(heading<0){
                    heading += 360;
                }

                char derect{};
                if (heading == 0 || heading == 360)
                {
                    derect = 'E';
                }
                if(heading==90){
                    derect = 'N';
                }
                if(heading==180){
                    derect = 'W';
                }
                if(heading==270){
                   derect = 'S';
                }
                cout << x << ' ' << y << ' ' <<derect<<' '<<ins<<'\n';

            }
            cout << "--------------" << '\n';
        }
        return (x == 0 && y == 0);
        // return false;
    }
};



int main()
{
    string instructions{"GLRLGLLGLGRGLGL"};
    Solution ss;
    cout << ss.isRobotBounded(instructions) << '\n';
    return 0;
}
