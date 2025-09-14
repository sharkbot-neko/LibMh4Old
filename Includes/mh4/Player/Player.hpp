#include <CTRPluginFramework.hpp>

class Player
{
public:
    static u32 getPlayerStruct() {
        u32 value;
        CTRPluginFramework::Process::Read32(0x00106A3C, value);
        return value;
    }
};