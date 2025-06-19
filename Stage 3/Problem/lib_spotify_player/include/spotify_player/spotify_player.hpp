#ifndef SPOTIFY_PLAYER_SPOTIFY_PLAYER
#define SPOTIFY_PLAYER_SPOTIFY_PLAYER

#include "music_player/music_player.hpp"

namespace spotify_player
{
    class SpotifyPlayer : public music_player::MusicPlayer
    {
    public:
        SpotifyPlayer();

        /**
         * @brief Sets the Spotify's track ID to play.
         * 
         * @note Caller has to call the `play_music` method to play the track.
         */
        void set_track_id(int track_id);

        /**
         * @brief Plays music from Spotify.
         * 
         * @note Caller has to call `set_track_id` before calling this method.
         */
        virtual bool play_music() override;
    
#ifdef SPOTIFY_ENABLE_BLUETOOTH
        void enable_bluetooth();
#endif

    private:
        int track_id;
    };
        
    /**
     * @brief Verifies that a Spotify track ID is valid
     * @return true if valid, false otherwise.
     */
    bool is_valid_track_id(int track_id);
} // namespace music_player


#endif
