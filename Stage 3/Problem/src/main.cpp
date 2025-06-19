#include "multi_music_player.hpp"
#include <iostream>
#include <string>

int main()
{
    MultiMusicPlayer multi_music_player(MultiMusicPlayer::Source::spotify);

    std::string track_name_to_search = "I bet you look good on the dancefloor - arctic monkeys";
    std::cout << "Searching for track: " << track_name_to_search << std::endl; 
    multi_music_player.search_track(track_name_to_search);
    
    std::cout << "Caling play_music()!" << std::endl;
    multi_music_player.play_music();
}