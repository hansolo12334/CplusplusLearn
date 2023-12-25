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
    string multiply(string num1, string num2) {
        if((num1.size()==1&&num1[0]=='0')|| (num2.size()==1&&num2[0]=='0')){
            return "0";
        }
        string re;
        re = multiplySingle(num1, num2[num2.size() - 1]);
        cout << re << '\n';
        int pos = 1;
        for (int i = num2.size() - 2; i >= 0; i--)
        {
            string re1 = multiplySingle(num1, num2[i]);
            cout << re1 << '\n';
            resultAdd(re1, re, pos);
            cout << re << '\n';
            cout << "-------" << '\n';
        }
        return re;
    }

    string multiplySingle(string &num1,char num2)
    {
        string re{};
        int jinwei = 0;
        int x = num2 - 48;
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            int y = num1[i] - 48;
            int multi = x * y + jinwei;
            if (multi / 10 != 0)
            {
                jinwei = multi/10;
            }
            else{
                jinwei = 0;
            }
            multi = multi - (multi / 10) * 10;
            re= static_cast<char>(multi+48)+re;
        }
        if(jinwei){
            re= static_cast<char>(jinwei+48)+re;
        }
        return re;
    }
    void resultAdd(string &re1,string &re,int &pos){
        int leftfill = pos + re1.size() - re.size();
        int rightfill = pos;
        //补零
        for (int i = 0; i < leftfill;i++){
            re = '0' + re;
        }
        for (int j = 0; j < rightfill;j++){
            re1 += '0';
        }

        //相加
        int jinwei = 0;
        for (int i = re.size() - 1; i >= 0; i--)
        {
            int x = re[i] - 48;
            int y = re1[i] - 48;
            if(x+y+jinwei>=10){
                re[i] = static_cast<char>(x + y + jinwei - 10 + 48);
                jinwei = 1;
            }
            else{
                re[i] = static_cast<char>(x + y + jinwei + 48);
                jinwei = 0;
            }
        }
        if(jinwei){
            re = '1' + re;
        }
        pos++;
    }
};


int main()
{
    string num1{"123456789"};
    string num2{"987654321"};
    Solution s;
    cout << s.multiply(num1, num2) << '\n';
    return 0;
}
