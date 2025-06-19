#include "spotify_player/spotify_player.hpp"
#include <iostream>

namespace spotify_player
{
    SpotifyPlayer::SpotifyPlayer() : track_id(0)
    {}

    void SpotifyPlayer::set_track_id(int track_id)
    {
        this->track_id = track_id;
    }

    bool SpotifyPlayer::play_music()
    {
        if (!is_valid_track_id(this->track_id))
        {
            return false;
        }

        return true;
    }

#ifdef SPOTIFY_ENABLE_BLUETOOTH
    void SpotifyPlayer::enable_bluetooth()
    {
        std::cout << "Enabled bluetooth!" << std::endl;
    }
#endif
        
    bool is_valid_track_id(int track_id)
    {
        return (track_id > 0) && (track_id < 10);
    }
} // namespace spotify_player
