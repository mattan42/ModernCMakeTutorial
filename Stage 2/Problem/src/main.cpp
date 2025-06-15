#include "music_player.hpp"
#include <iostream>
#include <stdlib.h>

int main()
{
    std::cout << "Trying to play music..." << std::endl;
    MusicPlayer music_player;
    music_player.play_music();

    return EXIT_SUCCESS;
}