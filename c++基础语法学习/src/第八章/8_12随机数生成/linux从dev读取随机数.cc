#include<array>
#include<iostream>
#include<cstddef>
#include<fstream>


int main() {
    std::ifstream urandom("/dev/urandom");

    if (urandom.fail()) {
        std::cerr << "Failed to open /dev/urandom\n";
        return 1;
    }

    char ch;
    urandom.read(&ch, sizeof(ch));

    std::cout << "Random value: " << static_cast<int>(ch) << '\n';

    return 0;
}
