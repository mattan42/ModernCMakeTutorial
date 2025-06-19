#include "spotify_player/spotify_player.hpp"
#include <iostream>

int main()
{
    spotify_player::SpotifyPlayer spotify_player;
    int spotify_track_id = 8;

    std::cout << "Setting spotify track id: " << spotify_track_id << " to the music player" << std::endl; 
    spotify_player.set_track_id(spotify_track_id);
    
    std::cout << "Caling play_music()!" << std::endl;
    spotify_player.play_music();
}