#include <CTRPluginFramework.hpp>
#include "mh4/Player/Player/PlayerName.hpp"
#include "mh4/Player/Player/PlayerComment.hpp"

class Player
{
public:
    static u32 getPlayerStruct() {
        u32 value;
        CTRPluginFramework::Process::Read32(0x00106A3C, value);
        return value;
    }

    u32 getMoneyStruct() {
        return 0x0ECD5B4;
    }

    u32 getNameStruct() {
        return 0xECD580;
    }

    PlayerComment getPlayerCommentClass() {
        PlayerComment comment;
        return comment;
    }

    PlayerName getPlayerNameClass() {
        PlayerName playername;
        return playername;
    }
};