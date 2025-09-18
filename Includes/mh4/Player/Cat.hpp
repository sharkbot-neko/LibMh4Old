#ifndef CAT_HPP
#define CAT_HPP

#include "Player.hpp"
#include "mh4/Player/Cat/CatName.hpp"
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

    CatName getCatNameClass() {
        CatName catname;
        return catname;
    }

};

#endif