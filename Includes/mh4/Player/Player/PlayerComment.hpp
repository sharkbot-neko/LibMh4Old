#include <CTRPluginFramework.hpp>

class PlayerComment
{
public:
    u32 getPlayerCommentStruct() {
        return 0x00f39dec;
    }

    u32 getPlayerCommentContentStruct() {
        return 0x0F39DF0;
    }

    void setPlayerCommentContent(std::string string) {
        CTRPluginFramework::Process::WriteString(0x0F39DF0, string, CTRPluginFramework::StringFormat::Utf16);
    }

    std::string getPlayerCommentContent() {
        std::string string;
        CTRPluginFramework::Process::ReadString(0x0F39DF0, string, 15, CTRPluginFramework::StringFormat::Utf16);
        return string;
    }
};