#include <CTRPluginFramework.hpp>

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

    u32 getPlayerCommentStruct() {
        return 0x00f39dec;
    }

    u32 getPlayerCommentContentStruct() {
        return 0x0F39DF0;
    }
};