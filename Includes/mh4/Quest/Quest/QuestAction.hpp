#ifndef QUESTACTION_HPP
#define QUESTACTION_HPP

#include <CTRPluginFramework.hpp>

class QuestAction
{
public:
    static void runAction(u32 offset, u32 id_1, u32 id_2) {
        using TargetFunc = u32(*)(int, int, int);
        TargetFunc func = (TargetFunc)0x009a0fb4;
        func((int)offset, (int)id_1, (int)id_2);
        return;
    }

};

#endif