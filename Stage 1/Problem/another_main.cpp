#include <iostream>

int main()
{
#ifdef DONT_PRINT_HELLO_WORLD
    std::cout << "I don't care about the DONT_PRINT_HELLO_WORLD define. I'm still going to print it!!" << std::endl;
#endif

    std::cout << "Hello World!" << std::endl;
}