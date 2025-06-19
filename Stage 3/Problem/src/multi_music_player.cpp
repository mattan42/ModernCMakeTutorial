#include "multi_music_player.hpp"

MultiMusicPlayer::MultiMusicPlayer(Source source) :
    spotify_player(),
    current_source(source)
{
    if (source != Source::spotify)
    {
        throw "Currently not supporting sources other than spotify";
    }
}

bool MultiMusicPlayer::search_track(const std::string &track_name)
{
    // Dummy implementaiton
    this->spotify_player.set_track_id(8);
    return true;
}

bool MultiMusicPlayer::enable_bluetooth()
{
#ifdef SPOTIFY_ENABLE_BLUETOOTH
    this->spotify_player.enable_bluetooth();
    return true;
#endif

    return false;
}

bool MultiMusicPlayer::source_supports_bluetooth()
{
#ifdef SPOTIFY_ENABLE_BLUETOOTH
    return true;
#endif

    return false;
}
    
bool MultiMusicPlayer::play_music()
{
    return this->spotify_player.play_music();
}