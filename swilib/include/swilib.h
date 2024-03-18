#pragma once
/**
 * @mainpage
 * - <a href="topics.html">List API methods (swilib.h)</a>
 * - <a href="https://github.com/siemens-mobile-hacks/sdk">SDK</a>
 * @addtogroup SWILIB
 * Universal SWILIB for GCC & IAR
 * 
 * Optional swilib defines:
 * - `-DSWILIB_LIBC`			enbale builtin libc functions (from firmware)
 * - `-DSWILIB_OPENSSL`			enbale builtin OpenSSL 0.9.5a functions (from firmware)
 * - `-DSWILIB_LIBPNG`			enbale builtin libpng 1.2.5 functions (from firmware)
 * - `-DSWILIB_ZLIB`			enbale builtin zlib 1.2.1 functions (from firmware)
 * - `-DSWILIB_MODERN`			don't include any legacy
 * - `-DSWILIB_LEGACY_COMPAT`	enable classic names of the ambiguous named functions (_open/sys_open vs fopen)
 * 
 * **For IAR:** all of these defines enabled by default.
 * @{
 * */

#define __IN_SWILIB__

/* Swilib modules */
#include "swilib/base.h"
#include "swilib/libc.h"
#include "swilib/wstring.h"
#include "swilib/date.h"
#include "swilib/gbs.h"
#include "swilib/csm.h"
#include "swilib/idle.h"
// #include "swilib/nucleus.h"
#include "swilib/image.h"
#include "swilib/gui.h"
#include "swilib/ui.h"
#include "swilib/i2c.h"
#include "swilib/png.h"
#include "swilib/openssl.h"
#include "swilib/gprs.h"
#include "swilib/socket.h"
#include "swilib/info.h"
#include "swilib/eeprom.h"
#include "swilib/file.h"
#include "swilib/explorer.h"
#include "swilib/sound.h"
#include "swilib/obs.h"
#include "swilib/settings.h"
#include "swilib/system.h"
#include "swilib/telephony.h"
#include "swilib/addressbook.h"
#include "swilib/java.h"
#include "swilib/misc.h"
#include "swilib/utils.h"
#include "swilib/zlib.h"
// #include "swilib/patch.h"

#undef __IN_SWILIB__

/** @} */
