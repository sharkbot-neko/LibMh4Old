#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <CTRPluginFramework.hpp>
#include "mh4/Player/Player/PlayerName.hpp"
#include "mh4/Player/Player/PlayerComment.hpp"
#include "mh4/Player/Player/PlayerMoney.hpp"

class Player
{
public:
    static u32 getPlayerStruct() {
        u32 value;
        CTRPluginFramework::Process::Read32(0x00106A3C, value);
        return value;
    }

    PlayerMoney getPlayerMoneyClass() {
        PlayerMoney playermoney;
        return playermoney;
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

#endif