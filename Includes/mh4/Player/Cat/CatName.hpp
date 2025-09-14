#include "Player.hpp"
#include <CTRPluginFramework.hpp>

class CatName
{
public:

    std::string getCatName() {
        std::string string;
        CTRPluginFramework::Process::ReadString(0x00ED69A8, string, 15, CTRPluginFramework::StringFormat::Utf16);
        return string;
    }

    void setCatName(std::string catname) {
        CTRPluginFramework::Process::WriteString(0x00ED69A8, catname, CTRPluginFramework::StringFormat::Utf16);
    }

    u32 getCatNameStruct() {
        return 0x00ED69A8;
    }

};