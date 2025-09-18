#include "Player.hpp"
#include "mh4/Player/Player.hpp"
#include "mh4/Player/Player/PlayerMoney.hpp"
#include "mh4/Player/Player/PlayerName.hpp"
#include "mh4/Player/Player/PlayerComment.hpp"
#include "mh4/Player/Cat/CatName.hpp"
#include "mh4/Player/Cat.hpp"
#include <string>

namespace CTRPluginFramework
{
    void Money(MenuEntry *entry) {
        u32 count;

        u32 player_money;
        PlayerMoney playerMoneyInstance;
        Process::Read32(playerMoneyInstance.getMoneyStruct(), player_money);

        std::string now_money = Utils::Format("金額を入力 (現在: %dz)", player_money);

        Keyboard keyboard(now_money);
        keyboard.IsHexadecimal(false);
    
        if (keyboard.Open(count) == 0) {
            Process::Write32(playerMoneyInstance.getMoneyStruct(), count);
        }
    }

    void MoneyMaxUp(MenuEntry *entry) {
        const std::vector<std::string> enable_or_disable = {
            "有効",
            "無効"
        };

        Keyboard keyboard("財布に最大以上に入れられる", enable_or_disable);

        int index = keyboard.Open();
        if (index < 0)
            return;

        switch (index) {
            default: break;

            case 0: {
                Process::Patch(0x00A87584, 0xE320F000);
                break;
            }

            case 1: {
                Process::Patch(0x00A87584, 0xC1A00003);
                break;
            }
        }
    }

    void MoneyMinusNoReset(MenuEntry *entry) {
        const std::vector<std::string> enable_or_disable = {
            "有効",
            "無効"
        };

        Keyboard keyboard("財布がマイナスでもリセットされない", enable_or_disable);

		int index = keyboard.Open();
		if(index < 0)
			return;

		switch (index) {
			default: break;

            case 0: {
                Process::Patch(0x00A87590, 0xE320F000);
                break;
            }

            case 1: {
                Process::Patch(0x00A87590, 0xD3A00000);
                break;
            }
        };
    }

    void Name(MenuEntry *entry) {
        PlayerName playerNameInstance;

        std::string input;
        std::string now_name = Utils::Format("名前を入力 (現在: %s)", playerNameInstance.getPlayerName().c_str());

        Keyboard keyboard(now_name);

        if (keyboard.Open(input) == 0) {
            playerNameInstance.setPlayerName(input);
        }
    }

    void Comment(MenuEntry *entry) {
        PlayerComment playerComment;

        std::string string;

        Keyboard keyboard("コメントを入力");

        if (keyboard.Open(string) == 0) {
            Process::WriteString(playerComment.getPlayerCommentContentStruct(), string, StringFormat::Utf16);
        }
    }

    void CatColor(MenuEntry *entry) {
        u8 blue;
        u8 green;
        u8 red;

        if (Keyboard("アイルーの色を入力 (red)").Open(red) == 0) {}
        if (Keyboard("アイルーの色を入力 (green)").Open(green) == 0) {}
        if (Keyboard("アイルーの色を入力 (blue)").Open(blue) == 0) {}

        Cat catins;

        u32 address = catins.getCatColorStruct();    
        u32 color_address = address + 0x20;

        Process::Write8(color_address + 0, blue);
        Process::Write8(color_address + 1, green);
        Process::Write8(color_address + 2, red);
    }

    void RaibowCat(MenuEntry *entry) {
        u8 blue = Utils::Random(0x00, 0xFF);
        u8 green = Utils::Random(0x00, 0xFF);
        u8 red = Utils::Random(0x00, 0xFF);

        Cat catins;

        u32 address = catins.getCatColorStruct();    
        u32 color_address = address + 0x20;

        Process::Write8(color_address + 0, blue);
        Process::Write8(color_address + 1, green);
        Process::Write8(color_address + 2, red);
    }

    void CatName_(MenuEntry *entry) {
        CatName catname;

        std::string input;
        std::string now_name = Utils::Format("アイルーの名前を入力 (現在: %s)", catname.getCatName().c_str());

        Keyboard keyboard(now_name);

        if (keyboard.Open(input) == 0) {
            catname.setCatName(input);
        }
    }

    void CatBuki(MenuEntry *entry) {
        u8 head;
        u8 body;
        u8 buki;

        if (Keyboard("アイルーの頭装備idを入力").Open(head) == 0) {}
        if (Keyboard("アイルーの体装備idを入力").Open(body) == 0) {}
        if (Keyboard("アイルーの武器idを入力").Open(buki) == 0) {}

        Cat catins;

        u32 address = catins.getCatColorStruct();
          
        Process::Write8(address + 0x46, head);
        Process::Write8(address + 0x3e, body);
        Process::Write8(address + 0x2c, buki);
    }

    void Speed(MenuEntry *entry) {
        u32 offset;
        u32 cmp32;
        
        if (Process::Read32(0x0E248F8, cmp32) && cmp32 != 0x00000000)
        {
            Process::Read32(0x0E248F8, offset);
            Process::Write32(offset + 0x000111C, 0x40E00000);
        }
    }
}