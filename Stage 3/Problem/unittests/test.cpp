#include <gtest/gtest.h>
#include "multi_music_player.hpp"

TEST(MultiMusicPlayerSpotifyTests, Sanity)
{
    MultiMusicPlayer multi_music_player(MultiMusicPlayer::Source::spotify);
}

TEST(MultiMusicPlayerSpotifyTests, NormalUsage)
{
    MultiMusicPlayer multi_music_player(MultiMusicPlayer::Source::spotify);

    EXPECT_TRUE(multi_music_player.search_track("I bet that you look good on the dancefloor - arctic monkeys"));
    EXPECT_TRUE(multi_music_player.play_music());
}

#ifdef SPOTIFY_ENABLE_BLUETOOTH
TEST(MultiMusicPlayerSpotifyTests, Bluetooth)
{
    MultiMusicPlayer multi_music_player(MultiMusicPlayer::Source::spotify);

    EXPECT_TRUE(multi_music_player.enable_bluetooth());
}
#else
TEST(MultiMusicPlayerSpotifyTests, NoBluetooth)
{
    MultiMusicPlayer multi_music_player(MultiMusicPlayer::Source::spotify);

    EXPECT_FALSE(multi_music_player.enable_bluetooth());
}
#endif