#ifndef MUSIC_PLAYER_MUSIC_PLAYER
#define MUSIC_PLAYER_MUSIC_PLAYER

namespace music_player
{
    /**
     * @brief A music player interface that can play music from a source.
     */
    class MusicPlayer
    {
    public:
        /**
         * @brief Plays music from a source.
         */
        virtual bool play_music() = 0;
    };
} // namespace music_player

#endif
