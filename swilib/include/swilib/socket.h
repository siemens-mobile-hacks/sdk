#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

/**
 * @addtogroup Socket
 * @brief Functions for working with BSD-like sockets.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/socket.h>`
 * @{
 */

typedef uint16_t				in_port_t;		/**< Port value */
typedef uint16_t				sa_family_t;	/**< Address family */
typedef uint32_t				in_addr_t;		/**< Internet address */
typedef uint32_t				socklen_t;		/**< Socket address length type definition */
typedef struct sockaddr			SOCK_ADDR;		/**< ELF's backward compatibility */

typedef struct sockaddr_in		SOCKADDR_IN;	/**< Windows-style */
typedef struct sockaddr			SOCKADDR;		/**< Windows-style */
typedef struct hostent			HOSTENT;		/**< Windows-style */

/**
 * Definitions of bits in internet address integers.
 * On subnets, the decomposition of addresses to host and net parts
 * is done according to subnet mask, not the masks here.
 */
#define	INADDR_ANY			(u_int32_t) 0x00000000
#define	INADDR_BROADCAST	(u_int32_t) 0xffffffff

#define INET_ADDRSTRLEN			16	/**< Maximum length of the IPv4 address */
#define MAX_IPv4_STR_LEN		16	/**< Maximum length of the IPv4 address */
#define MAX_IPv6_STR_LEN		64	/**< Maximum length of the IPv6 address */

/**
 * Helper for creating IP address.
 * */
#define IP_ADDR(A, B, C, D) (((unsigned long)A << 24) | ((unsigned long)B << 16) | ((unsigned long) C << 8) | ((unsigned long) D << 0))

/**
 * Internet protocols.
 * */
enum SockProtocolID {
	IPPROTO_IP		= 0,	/**< Dummy for IP */
	IPPROTO_TCP		= 6,	/** TCP **/
	IPPROTO_UDP		= 17,	/** UDP **/
	IPPROTO_MAX		= 18,	/**< Total count */
};

/**
 * Socket types.
 * */
enum SockTypeID {
	SOCK_DGRAM		= 0, 	/**< UDP */
	SOCK_STREAM		= 1, 	/**< TCP */
};

/**
 * Socket family types.
 * */
enum SockFamilyID {
	AF_UNSPEC	= 0,	/**< Unspecified */
	AF_INET		= 1, 	/**< Internet IP Protocol */
	AF_MAX		= 2,	/**< Total count */
};

/**
 * Socket shutdown types.
 * */
enum SockShutdownTypeID {
	SHUT_RD		= 0,	/**< shut down the reading side */
	SHUT_WR		= 1,	/**< shut down the writing side */
	SHUT_RDWR	= 2,	/**< shut down both sides */
};

/**
 * Internet address (a structure for historical reasons)
 */
struct in_addr {
	in_addr_t s_addr;
};

/**
 * Socket address, generic.
 */
#ifdef SWILIB_MODERN
struct sockaddr {
	uint16_t sa_family;		/**< address family */
	char sa_data[14];		/**< address value */
};
#else
struct sockaddr {
	union {
		struct { /**< BSD-socket structure */
			uint16_t sa_family;		/**< address family */
			char sa_data[14];		/**< address value */
		};
		struct { /**< Siemens ELF's legacy structure */
			uint16_t family;			/**< Set to #AF_INET */
			uint16_t port;				/**< Port in the network order, use #htons */
			uint32_t ip;				/**< IPv4 in the network order, use #htonl */
			uint32_t unk1;				/**< Set to 0 */
			uint32_t unk2;				/**< Set to 0 */
		};
	};
};
#endif

/**
 * Socket address, internet style.
 */
struct sockaddr_in {
	sa_family_t sin_family;		/**< #AF_INET (old name: family) */
	in_port_t sin_port;			/**< Port value, use #htons (old name: port) */
	struct in_addr sin_addr;	/**< IP value, use #htonl or #inet_addr (old name: ip) */
	char sin_zero[8];
};

/**
 * DNS response.
 * */
struct hostent {
	char *h_name;			/**< Official name of host */
	char **h_aliases;		/**< Alias list */
	short h_addrtype;		/**< Always AF_INET */
	short h_length;			/**< Always 4 */
	char **h_addr_list;		/**< List of addresses */
};

/**
 * Resolve domain name.
 * @param name				domain name to be resolved
 * @param[out] response		pointer to the pointer of #hostent
 * @param[out] req_id		request ID or NULL
 * @return 0 or error
 * 
 * ```C
 * struct hostent *response;
 * int req_id;
 * int ret = async_gethostbyname("LOCALHOST", &response, &req_id);
 * ```
 * 
 * @note `response` is `void *` for compatibility reasons - some old code still uses `int ****` for this function.
 * */
__swi_begin(0x1B6)
int async_gethostbyname(const char *name, void *response, int *req_id)
__swi_end(0x1B6, async_gethostbyname, (name, response, req_id));

/**
 * Convert the string IP address to the numeric format.
 * @param ip	IP address, example: 127.0.0.1
 * @return IP address, example: 0x1B000001
 * */
__swi_begin(0x1B7)
uint32_t str2ip(const char *ip)
__swi_end(0x1B7, str2ip, (ip));

/**
 * Convert the string IP address to the numeric format.
 * @param ip	IP address, example: 127.0.0.1
 * @return IP address, example: 0x1B000001
 * */
__swi_begin(0x1B7)
in_addr_t inet_addr(const char *ip)
__swi_end(0x1B7, inet_addr, (ip));

/**
 * Convert host to network order (unsigned short).
 * */
__swi_begin(0x17A)
uint16_t htons(uint16_t p)
__swi_end(0x17A, htons, (p));

/**
 * Convert host to network order (unsigned int).
 * */
__swi_begin(0x17B)
uint32_t htonl(uint32_t p)
__swi_end(0x17B, htonl, (p));

/**
 * @param domain	socket domain, set to #AF_INET
 * @param type		socket type, set to #SOCK_STREAM
 * @param protocol	set to 0 (default protocol)
 * @return socket descriptor number or -1 on error
 * */
__swi_begin(0x173)
int socket(int domain, int type, int protocol)
__swi_end(0x173, socket, (domain, type, protocol));

/**
 * Connect socket to the address.
 * @param socket		socket descriptor
 * @param address		socket address, see #sockaddr_in
 * @param address_len	size of the socket address
 * @return 0 or error
 * */
__swi_begin(0x174)
int connect(int socket, const struct sockaddr *address, socklen_t address_len)
__swi_end(0x174, connect, (socket, address, address_len));

/**
 * Bind socket to the address.
 * @param socket		socket descriptor
 * @param address		socket address, see #sockaddr_in
 * @param address_len	size of the socket address
 * @return 0 or error
 * */
__swi_begin(0x175)
int bind(int socket, const struct sockaddr *address, socklen_t address_len)
__swi_end(0x175, bind, (socket, address, address_len));

/**
 * Shutdown
 * @param socket		socket descriptor
 * @param how	specifies the type of shutdown, see #SockShutdownTypeID
 * @return 0 or error
 * */
__swi_begin(0x177)
int shutdown(int socket, int how)
__swi_end(0x177, shutdown, (socket, how));

/**
 * Receive data on a socket.
 * @param socket	socket descriptor
 * @param[out] buf	buffer for received data
 * @param len		maximum size for the receiving
 * @param flags		set to 0
 * @return count of the received bytes or -1 (error)
 * */
__swi_begin(0x178)
int recv(int socket, void *buf, int len, int flags)
__swi_end(0x178, recv, (socket, buf, len, flags));

/**
 * Send a message on a socket.
 * @param socket	socket descriptor
 * @param buf		buffer for sending
 * @param len		size of the data in buffer
 * @param flags		set to 0
 * @return count of the sended bytes or -1 (error)
 * */
__swi_begin(0x179)
int send(int socket, const void *buf, int len, int flags)
__swi_end(0x179, send, (socket, buf, len, flags));

/**
 * Get available bytes for reading in the socket.
 * @param socket	socket descriptor
 * @return bytes count
 * */
__swi_begin(0x18D)
int available0(int socket)
__swi_end(0x18D, available0, (socket));

/**
 * Pointer to the last socket error.
 * @return pointer to the error code
 * 
 * ```C
 * int sock_err = *socklasterr();
 * ```
 * */
__swi_begin(0x817C)
int *socklasterr(void)
__swi_end(0x817C, socklasterr, ());

/**
 * Close socket descriptor.
 * @param socket		socket descriptor
 * @return 0 or error
 * */
__swi_begin(0x176)
int closesocket(int socket)
__swi_end(0x176, closesocket, (socket));

__swilib_end

/** @} */
