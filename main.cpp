#include <iostream>
#include <string>

int main() {
    std::cout << "Hello, MinGW64!" << std::endl;
    std::cout << "This is a simple C++ program compiled with MinGW64." << std::endl;
    
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    
    if (!name.empty()) {
        std::cout << "Nice to meet you, " << name << "!" << std::endl;
    }
    
    return 0;
}
