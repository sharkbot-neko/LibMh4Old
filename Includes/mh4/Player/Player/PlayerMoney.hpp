#include <CTRPluginFramework.hpp>

class PlayerMoney
{
public:
    u32 getMoneyStruct() {
        return 0x0ECD5B4;
    }

    static void addMoney(u32 offset, u32 money) {
        using TargetFunc = u32(*)(int, int);
        TargetFunc func = (TargetFunc)0x00a8756c;
        func((int)offset, (int)money);
        return;
    }

};