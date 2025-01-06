#ifdef SWILIB_LINUX_SIMULATOR
#include_next <netinet/in.h>
#else
#ifndef _SYS_SOCKET_H_
#define	_SYS_SOCKET_H_

/*
 * -----------------------------------------------
 * Actually defined in the swilib.h
 * -----------------------------------------------
 * */

#include <swilib.h>

#endif // _SYS_SOCKET_H_
#endif // SWILIB_LINUX_SIMULATOR
