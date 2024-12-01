#ifdef __linux__
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
#endif // __linux__
