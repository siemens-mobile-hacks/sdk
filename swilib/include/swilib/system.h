#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

/**
 * @addtogroup System
 * @brief The system functions to control miscellaneous stuff on the phone.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/system.h>`
 * @{
 */

typedef struct MUTEX MUTEX;

/**
 * Mutex object.
 * */
struct MUTEX {
	void *p;
	int i;
};

/**
 * Get the platform type.
 * @return 0 - SGold
 * @return 1 - NewSGold
 * @return 2 - NewSGold E71/EL71
 * */
__swi_begin(0x81B5)
int isnewSGold(void)
__swi_end(0x81B5, isnewSGold, ());

/**
 * Run a callback in the background.
 * You can pass up to two additional (32 bit) parameters that are passed to the callback.
 * Callbacks will be called in the RAP queue instead of the MMI.
 * @param callback		pointer to the callback
 * 
 * ```C
 * void test_func(int p1, int p2) {
 *     // some code
 * }
 * 
 * SUBPROC(test_func, 1, 2);
 * ```
 * */
#ifdef SWILIB_MODE_DIRECT
#define SUBPROC(_callback, ...) \
	__swi_call(0x171, void, (void *callback, ...), (_callback, ## __VA_ARGS__));
#else
__swi_begin(0x171)
void SUBPROC(void *callback, ...)
__swi_end(0x171, SUBPROC, (callback));
#endif

/**
 * Get phone uptime in the ticks (1 tick=4.615 ms).
 * @return ticks
 * */
__swi_begin(0x1F3)
uint32_t GetSessionAge(void)
__swi_end(0x1F3, GetSessionAge, ());

/**
 * @name Locking functions
 * @{
 * */

/**
 * Lock OS scheduler.
 * */
__swi_begin(0x146)
void LockSched(void)
__swi_end(0x146, LockSched, ());

/**
 * Unlock OS scheduler.
 * */
__swi_begin(0x147)
void UnlockSched(void)
__swi_end(0x147, UnlockSched, ());

/**
 * Init mutex object.
 * @param mtx	pointer to the mutex object
 * */
__swi_begin(0x190)
void MutexCreate(MUTEX *mtx)
__swi_end(0x190, MutexCreate, (mtx));

/**
 * Lock mutex.
 * @param mtx	pointer to the mutex object
 * */
__swi_begin(0x192)
void MutexLock(MUTEX *mtx)
__swi_end(0x192, MutexLock, (mtx));

/**
 * Lock mutex.
 * @param mtx	pointer to the mutex object
 * @param flag	unknown
 * */
__swi_begin(0x193)
void MutexLockEx(MUTEX *mtx, int flag)
__swi_end(0x193, MutexLockEx, (mtx, flag));

/**
 * Unlock mutex.
 * @param mtx	pointer to the mutex object
 * */
__swi_begin(0x194)
void MutexUnlock(MUTEX *mtx)
__swi_end(0x194, MutexUnlock, (mtx));

/**
 * Destroy mutex (free resources).
 * @param mtx	pointer to the mutex object
 * */
__swi_begin(0x191)
void MutexDestroy(MUTEX *mtx)
__swi_end(0x191, MutexDestroy, (mtx));

/** @} */

/**
 * @name Elfloader functions
 * @{
 * */

/**
 * Get function library address.
 * @return address in memory
 * */
__swi_begin(0x80FF)
void *AddrLibrary()
__swi_end(0x80FF, AddrLibrary, ());

/**
 * Get a pointer to the loaded blib.
 * @return pointer
 * */
__swi_begin(0x81BA)
void *LIB_TOP(void)
__swi_end(0x81BA, LIB_TOP, ());

/**
 * Get a pointer to the list of loaded shared libs.
 * @return pointer to the first element of the linked-list
 * @note Only for Elfloader 3.0+
 * */
__swi_begin(0x2F9)
void *SHARED_TOP()
__swi_end(0x2F9, SHARED_TOP, ());

/**
 * Get a pointer to a list of environment variables.
 * @return pointer to the C-like array of strings
 * @note Only for Elfloader 3.0+
 * */
__swi_begin(0x2F6)
char **getBaseEnviron()
__swi_end(0x2F6, getBaseEnviron, ());

/**
 * Close ELF.
 * @param ex	pointer to the opened ELF
 * @return 0 or error
 * @note Only for Elfloader 3.0+
 * */
__swi_begin(0x2EE)
int elfclose(void *ex)
__swi_end(0x2EE, elfclose, (ex));

#ifndef __ICCARM__
/**
 * Kill current ELF (in background).
 * @note Only for Elfloader 3.0+
 * */
void kill_elf();

/**
 * Free data without returning to the current function.
 * @note Only for Elfloader 3.0+
 * */
extern void kill_data(void *p, void (*func_p)(void *));
#endif

/**
 * @}
 * */

/**
 * @name Shared libs (internal API)
 * @{
 * */

/**
 * Load the dynamic shared object (.so).
 * @param name	path to the `.so` file or only name (`libNAME.so`)
 * @return 0 or error
 * @note Only for Elfloader 3.0+
 * */
__swi_begin(0x2EF)
int _dlopen(const char *name)
__swi_end(0x2EF, _dlopen, (name));

/**
 * Get a pointer to the symbol from the previously loaded dynamic object.
 * @param handle	descriptor obtained from _dlopen
 * @param name		name of the symbol
 * @return pointer to the symbol
 * @note Only for Elfloader 3.0+
 * */
__swi_begin(0x2F0)
void *_dlsym(int handle, const char *name)
__swi_end(0x2F0, _dlsym, (handle, name));

/**
 * Close previously loaded dynamic object.
 * @param handle	descriptor obtained from _dlopen
 * @return 0 or error
 * @note Only for Elfloader 3.0+
 * */
__swi_begin(0x2F1)
int _dlclose(int handle)
__swi_end(0x2F1, _dlclose, (handle));

/**
 * Get a string representation of the last error in _dlopen.
 * @return C-string
 * @note Only for Elfloader 3.0+
 * */
__swi_begin(0x2F7)
const char *_dlerror()
__swi_end(0x2F7, _dlerror, ());

/**
 * Call the garbage collector for the loaded dynamic objects.
 * @return 0 or error
 * @note Only for Elfloader 3.0+
 * */
__swi_begin(0x2F8)
int dlclean_cache()
__swi_end(0x2F8, dlclean_cache, ());

/** @} */

/**
 * @name CPU functions
 * @{
 * */

/**
 * Enable CPU usage monitor.
 * */
__swi_begin(0x19E)
void StartCpuUsageCount(void)
__swi_end(0x19E, StartCpuUsageCount, ());

/**
 * Get CPU usage (time), if the cpu usage monitor is enabled.
 * @return time in unknown unit
 * */
__swi_begin(0x19D)
unsigned long long getCpuUsedTime_if_ena(void)
__swi_end(0x19D, getCpuUsedTime_if_ena, ());

/**
 * Get CPU freq.
 * @return freq in MHz
 * */
__swi_begin(0x05C)
uint8_t GetCPUClock()
__swi_end(0x05C, GetCPUClock, ());

/**
 * Get CPU load.
 * @return 0-100
 * */
__swi_begin(0x05D)
uint8_t GetCPULoad()
__swi_end(0x05D, GetCPULoad, ());

/**
 * Set the CPU frequency to the minimum value.
 * @param unk	unknown, set to 2
 * */
__swi_begin(0x221)
void SetCpuClockLow(int unk)
__swi_end(0x221, SetCpuClockLow, (unk));

/**
 * Set the CPU frequency to the maximum value.
 * @param flag	unknown, set to 2
 * */
__swi_begin(0x222)
void SetCpuClockHi(int flag)
__swi_end(0x222, SetCpuClockHi, (flag));

/**
 * Set the CPU frequency to the maximum value.
 * @param unk	unknown, set to 2
 * */
__swi_begin(0x222)
void SetCpuClockTempHi(int unk)
__swi_end(0x222, SetCpuClockTempHi, (unk));

/** @} */

/**
 * @name Misc system functions
 * @{
 * */

/**
 * Get PRNG seed value.
 * @return pointer to the seed.
 * */
__swi_begin(0x80DC)
int *RamRandSeed()
__swi_end(0x80DC, RamRandSeed, ());

/**
 * Current pickoff error string.
 * @return C-string
 * */
__swi_begin(0x838B)
const char *RamLastStoreString()
__swi_end(0x838B, RamLastStoreString, ());

/**
 * Disable GSM L1 layer (NetOff).
 * @return C-string
 * */
__swi_begin(0x247)
const char *GSM_L1_Disable()
__swi_end(0x247, GSM_L1_Disable, ());

/** @} */

/**
 * @name Stub functions
 * @{
 * */

/**
 * Syscall, which is used by the phone OS, swi 0.
 * */
__swi_begin(0x000)
void loopback0()
__swi_end(0x000, loopback0, ());

/**
 * Syscall, which is used by the phone OS, swi 1.
 * */
__swi_begin(0x001)
void loopback1()
__swi_end(0x001, loopback1, ());

/**
 * Syscall, which is used by the phone OS, swi 2.
 * */
__swi_begin(0x002)
void loopback2()
__swi_end(0x002, loopback2, ());

/**
 * Syscall, which is used by the phone OS, swi 3.
 * */
__swi_begin(0x003)
void loopback3()
__swi_end(0x003, loopback3, ());

/**
 * Syscall, which is used by the phone OS, swi 4.
 * */
__swi_begin(0x004)
void loopback4()
__swi_end(0x004, loopback4, ());

/**
 * Syscall, which is used by the phone OS, swi 171.
 * */
__swi_begin(0x0AB)
void loopback171()
__swi_end(0x0AB, loopback171, ());

/** @} */

__swilib_end

/** @} */
