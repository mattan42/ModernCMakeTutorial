#include <music_player.hpp>
#include <iostream>
#include <stdlib.h>

int main()
{
    std::cout << "Main of the unittests!" << std::endl;
    std::cout << "Testing play_music()..." << std::endl;
    play_music();
    std::cout << "============== end of unitests ==============" << std::endl;

    return EXIT_SUCCESS;
}