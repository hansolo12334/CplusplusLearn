#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <set>
#include <string>
#include<numeric>

#include<random>

using namespace std;



class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {


        string tilurl{};

        while(true){
            for (int i = 0; i < 6; i++)
            {
                std::random_device rd{};
                std::mt19937 mt{rd()};

                std::uniform_int_distribution die6{0, 61};
                int rand = die6(mt);
                tilurl += index[rand];
            }
            string shorturl = prefix + tilurl;
            if(map.count(shorturl)==0){
                map[shorturl] = longUrl;
                return shorturl;
            }
        }


        return tilurl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }

private:
    string index = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string prefix = "http://tinyurl.com/";
    unordered_map<string, string> map;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main()
{
    string url = "https://leetcode.com/problems/design-tinyurl";

    Solution s;
    auto tiny=s.encode(url);
    auto ans = s.decode(tiny);
    cout << tiny << '\n';
    cout << ans << '\n';
    return 0;
}
