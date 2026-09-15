
/**
    * 2011
    * (c) Z.Vova
*/


#include <unistd.h>
#include <swilib.h>
#include <errno.h>


int setenv(const char *name, const char *value, int replace)
{
    return __swi_invoke(0x2F2, setenv, name, value, replace);
}


int unsetenv(const char *name)
{
    return __swi_invoke(0x2F3, unsetenv, name);
}


char * getenv(const char *var)
{
    return __swi_invoke(0x2F4, getenv, var);
}


int clearenv(void)
{
    return __swi_invoke(0x2F5, clearenv);
}

