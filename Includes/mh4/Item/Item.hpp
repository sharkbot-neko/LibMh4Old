#include <CTRPluginFramework.hpp>

class Item
{
public:
    u32 addItem(u32 offset, u32 itemid, u32 count) {
        using TargetFunc = u32(*)(int, int, u32);
        TargetFunc func = (TargetFunc)0x009de864;
        return func((int)offset, (int)itemid, count);
    }
};