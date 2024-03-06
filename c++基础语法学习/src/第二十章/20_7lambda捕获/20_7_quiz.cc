#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>
#include <functional>
#include <random>

int main()
{
    int x{0};
    std::cout << "Start where? ";
    std::cin >> x;
    int y{0};
    std::cout << "How many? ";
    std::cin >> y;


    std::random_device rd{};
    std::mt19937 mt{rd()};
    std::uniform_int_distribution die6{2, 4};
    int randInt = die6(mt);

    std::vector<int> vec{};

    for (int i = x; i < (x+y);i++){
        vec.push_back(i * i * randInt);
    }

    auto getNumber = [&](int num) {
        auto found = std::find(vec.begin(), vec.end(),num);
        if(found!=vec.end()){
            vec.erase(found);
            std::cout << "Nice! " << vec.size() << " number(s) left\n";
            return true;
        }
        else{
            auto closestNum = *std::min_element(vec.begin(), vec.end(), [num](int a, int b) {
                int distance1 = std::abs(a - num);
                int distance2 = std::abs(b - num);
                return distance1 < distance2;
            });
            if(std::abs(closestNum-num)<=4){
                std::cout << num<<" is wrong! Try "<<closestNum <<" next time.\n";
                return true;
            }
            else{
                std::cout << num << " is wrong!\n";
                return false;
            }
        }
    };
    std::cout << "I generated " << y << " square numbers. Do you know what each number is after multiplying it by "<< randInt << "?\n";
    while (vec.size())
    {
        int number{};
        std::cin>>number;

        if(getNumber(number)==false){
            break;
        }
    };
    if(vec.size()==0){
        std::cout << "Nice! You found all numbers, good job!\n";
    }


    return 0;
}
