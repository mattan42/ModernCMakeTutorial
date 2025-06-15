#include <iostream>

int main()
{
#ifdef DONT_PRINT_HELLO_WORLD
    std::cout << "Not printing Hello World :(" << std::endl;
#else
    std::cout << "Hello World!" << std::endl;
#endif
}