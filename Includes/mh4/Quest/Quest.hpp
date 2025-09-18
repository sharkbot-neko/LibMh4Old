#ifndef QUEST_HPP
#define QUEST_HPP

#include <CTRPluginFramework.hpp>
#include "mh4/Quest/Quest/QuestAction.hpp"

class Quest
{
public:
    static u32 getQuestOffset() {
        u32 value;
        CTRPluginFramework::Process::Read32(0x00E1CFE4, value);
        return value;
    }

    u32 getQuestStruct() {
        return 0x00E1CFE4;
    }

    static bool isTheQuest() {
        u32 OffCheck = getQuestOffset();
        if (OffCheck != 0x00000000) {
            return true;
        } else {
            return false;
        }
    }

    static QuestAction getQuestActionClass() {
        QuestAction q_a;
        return q_a;
    }

};

#endif