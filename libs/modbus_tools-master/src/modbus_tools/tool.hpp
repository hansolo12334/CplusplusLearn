#include <string>
#include <sstream>
std::string processHexStr(std::string hexStr) noexcept
{
    // 去除0x
    if (hexStr.find("0x") != -1)
    {
        hexStr = hexStr.substr(2);
    }
    while (hexStr.size() < 4)
    {
        hexStr = "0" + hexStr;
    }
    // 补0x
    hexStr = "0x" + hexStr;
    return hexStr;
}

template <typename T>
std::string decToHex(T dec)
{
    std::stringstream ss;
    ss << std::hex << std::uppercase << dec;
    return ss.str();
}