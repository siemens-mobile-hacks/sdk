#pragma once

/**
 * @addtogroup Java
 * @brief Functions for the JVM.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/java.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#include "csm.h"
#include "wstring.h"
#endif

__swilib_begin

/**
 * Get the name of the running Java application.
 *
 * @return Pointer to the current Java application name, or NULL if no application is available.
 * */
__swi_begin(0x1E7)
char *GetLastJavaApplication(void)
__swi_end(0x1E7, GetLastJavaApplication, ());

/**
 * Check if Java is NOT running.
 * @return 1 or 0
 * */
__swi_begin(0x1E8)
int IsNoJava()
__swi_end(0x1E8, IsNoJava, ());

/**
 * Check if Java IS running.
 * On EL71/E71 sw45 this is the midlet manager's count of open Java screens (an int,
 * "decremented gui count to %d" in native/midmgr/midlet_manager.c): 0 = no Java app on screen.
 * @return 2 - is no java running
 * */
__swi_begin(0x8281)
int8_t *RamIsRunJava()
__swi_end(0x8281, RamIsRunJava, ());

/**
 * Open file with java midlet.
 * Launches a java midlet passing it a file name.
 * @param midlet	path to the .jar
 * @param filename	path to the any file
 * */
__swi_begin(0x283)
int runMidletLinkablely(const char *midlet, WSHDR *filename)
__swi_end(0x283, runMidletLinkablely, (midlet, filename));

/**
 * Start java midlet.
 * @param midlet	path to the .jar
 * */
__swi_begin(0x04B)
void StartMidlet(char *midlet)
__swi_end(0x04B, StartMidlet, (midlet));

/**
 * Java heap slots: the VM takes its heap from one of two slots, malloc'ed at the VM start.
 * The firmware does not free them when the VM ends; see #RamJavaHeapSlots.
 * */
typedef struct JAVA_HEAP_SLOTS {
	void *heap[2];	/**< aligned heap start, NULL = slot free */
	void *raw[2];	/**< block from malloc, to be freed with mfree */
	int size[2];	/**< heap size */
} JAVA_HEAP_SLOTS;

/**
 * "VM started" flag: 1 while the Java VM exists, cleared when the VM ends.
 * In the VM state of the JVM message handler (native/jenv/java_jvm_port.c, JVM_*_MSG 0x6200-0x6203).
 * @return pointer to the flag
 * */
__swi_begin(0x8454)
int *RamJavaVMStarted(void)
__swi_end(0x8454, RamJavaVMStarted, ());

/**
 * Java exit popup flag: 1 while the "exit Java" popup is shown. Then JVM_STOP_MSG / JVM_END_MSG
 * show the popup again instead of ending the VM.
 * @return pointer to the flag
 * */
__swi_begin(0x8455)
int *RamJavaExitPopup(void)
__swi_end(0x8455, RamJavaExitPopup, ());

/**
 * Java heap slots (see #JAVA_HEAP_SLOTS). After the VM has ended (#RamJavaVMStarted is 0) the
 * blocks can be freed: mfree(raw[i]), then zero heap[i], raw[i], size[i] and the matching
 * #RamJavaVMHeaps entry. Without this the Java heap (MBs) stays allocated until a reboot.
 * @return pointer to the slot table
 * */
__swi_begin(0x8456)
JAVA_HEAP_SLOTS *RamJavaHeapSlots(void)
__swi_end(0x8456, RamJavaHeapSlots, ());

/**
 * VM heap globals (set up by the VM start, "HeapCapacity (%d bytes) too low to start VM").
 * Entry [1] belongs to heap slot 0, entry [0] to heap slot 1: zero them with the slots.
 * @return pointer to the globals
 * */
__swi_begin(0x8457)
void **RamJavaVMHeaps(void)
__swi_end(0x8457, RamJavaVMHeaps, ());

/**
 * Start a Java application by class name, as the firmware's FlexMenu_start does at boot for
 * L"com.siemens.mp.app.flexmenu.MenuContainer" ("JAM_StartApplicationClass(%Pw)",
 * csrc/core/jam_start_handler.c). Starts the VM first when it is not running.
 * @param class_name	full class name
 * @param unk1, unk2, unk3, unk4	0
 * @return nonzero if started
 * */
__swi_begin(0x458)
int JAM_StartApplicationClass(WSHDR *class_name, int unk1, int unk2, int unk3, int unk4)
__swi_end(0x458, JAM_StartApplicationClass, (class_name, unk1, unk2, unk3, unk4));

__swilib_end

/** @} */
