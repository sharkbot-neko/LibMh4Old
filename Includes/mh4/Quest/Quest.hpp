#include <CTRPluginFramework.hpp>

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

    bool isTheQuest() {
        u32 OffCheck = getQuestOffset();
        if (OffCheck != 0x00000000) {
            return true;
        } else {
            return false;
        }
    }

};