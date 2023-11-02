#include<iostream>

struct AdRevenue
{
    int watchTime{};
    double percentageClickedAd{};
    double averageEarningPerClickedAd{};
};


AdRevenue getAd()
{
    AdRevenue ad{};
    std::cout << "How many ads were watched? ";
    std::cin >> ad.watchTime;
    std::cout << "What percentage of users clicked on an ad? ";
    std::cin >> ad.percentageClickedAd;
    std::cout << "The average earnings per clicked ad? ";
    std::cin >> ad.averageEarningPerClickedAd;

    return ad;
}
void printEarnADay(AdRevenue daily)
{
    std::cout <<"一天的收入为: " <<daily.watchTime * daily.percentageClickedAd * daily.averageEarningPerClickedAd << '\n';
}

int main()
{
    printEarnADay(getAd());
    return 0;
}
