

#include <swilib.h>
#include <vector>

extern void fte_cleanMap();


extern "C" void __attribute__((constructor)) __init_env__()
{
    //ShowMSG(1, (int)"oO");
    const char *env = getenv("FONTS");
    if(!env)
    {
        if(isdir("0:\\ZBin\\fonts\\", 0))
            setenv("FONTS", "0:\\ZBin\\fonts\\", 1);
        else if(isdir("4:\\ZBin\\fonts\\", 0))
            setenv("FONTS", "4:\\ZBin\\fonts\\", 1);
        else
            ShowMSG(1, (int)"Attention! Fonts dir not found");
    }
}


extern "C" void __attribute__((destructor)) __destroy_so__()
{
    //ShowMSG(1, (int)"Oo");
    fte_cleanMap();
}
