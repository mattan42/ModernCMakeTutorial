#ifndef MULTI_MUSIC_PLAYER
#define MULTI_MUSIC_PLAYER

#include <string>
#include "spotify_player/spotify_player.hpp"
#include "music_player/music_player.hpp"

/**
 * @brief This class can play music from several different music sources.
 * 
 * @note Currently only supporting spotify.
 */
class MultiMusicPlayer : music_player::MusicPlayer
{
public:
    enum class Source
    {
        spotify,
    };

    MultiMusicPlayer(Source source);

    /**
     * @brief Tries searching for track of name.
     * 
     * @return true on success, false otherwise.
     */
    bool search_track(const std::string &track_name);

    /**
     * @brief Tries enabling bluetooth for the current source.
     * 
     * @return true on sucess, false if the current source doesn't support bluetooth.
     */
    bool enable_bluetooth();

    /**
     * @return True if the current source supports bluetooth.
     */
    bool source_supports_bluetooth();
        
    virtual bool play_music() override;

private:
    spotify_player::SpotifyPlayer spotify_player;
    Source current_source;
};

#endif