#ifndef PLAYERNAME_HPP
#define PLAYERNAME_HPP

#include <CTRPluginFramework.hpp>

class PlayerName
{
public:
    u32 getNameStruct() {
        return 0xECD580;
    }

    void setPlayerName(std::string string) {
        CTRPluginFramework::Process::WriteString(0xECD580, string, CTRPluginFramework::StringFormat::Utf16);
    }

    std::string getPlayerName() {
        std::string string;
        CTRPluginFramework::Process::ReadString(0xECD580, string, 15, CTRPluginFramework::StringFormat::Utf16);
        return string;
    }
};

#endif