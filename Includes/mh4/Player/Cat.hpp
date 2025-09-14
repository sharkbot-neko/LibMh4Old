#include "Player.hpp"
#include <CTRPluginFramework.hpp>

class Cat
{
public:
    u32 getCatStruct() {
        return 0x00ed69a8;
    }

    u32 getCatColorStruct() {
        return 0x00ed69c8;
    }

    u32 getCatHeadStruct() {
        return 0x00ed69ee;
    }

    u32 getCatBodyStruct() {
        return 0x00ed69e6;
    }

    u32 getCatBukiStruct() {
        return 0x00ed69de;
    }

    std::string getCatName() {
        std::string string;
        CTRPluginFramework::Process::ReadString(0x00ED69A8, string, 15, CTRPluginFramework::StringFormat::Utf16);
        return string;
    }

    u32 getCatNameStruct() {
        return 0x00ED69A8;
    }

};