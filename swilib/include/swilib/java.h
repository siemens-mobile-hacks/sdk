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
#include "wstring.h"
#endif

__swilib_begin

/**
 * Get the path to the running Java application.
 * @return C-string
 * */
__swi_begin(0x1E7)
char *GetLastJavaApplication()
__swi_end(0x1E7, GetLastJavaApplication, ());

/**
 * Check if Java is NOT running.
 * @return 1 or 0
 * */
__swi_begin(0x1E8)
int IsNoJava()
__swi_end(0x1E8, IsNoJava, ());

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

__swilib_end

/** @} */
