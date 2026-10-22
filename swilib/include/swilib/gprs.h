#pragma once

/**
 * @addtogroup GPRS
 * @brief GPRS related functions.
 * 
 * See GprsD.elf sources for more info.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/gprs.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

typedef struct REGSOCKCEPID_DATA REGSOCKCEPID_DATA;
typedef struct CTX_NAPDEF CTX_NAPDEF;
typedef struct NAP_PARAM_CONT NAP_PARAM_CONT;
typedef struct LMAN_DATA LMAN_DATA;

/**
 * LinkManager GBS events.
 * */
enum LmanEventID {
	LMAN_CONNECT_CNF		= 0x80,
	LMAN_CONNECT_REJ_IND	= 0x81,
	LMAN_DISCONNECT_IND		= 0x82,
	LMAN_DISCONNECT_CNF		= 0x84,
	LMAN_LINK_UP_IND		= 0x89,
};

/**
 * ENIP GBS events.
 * */
enum EnipEventID {
	ENIP_BUFFER_FREE		= 0x8A,
	ENIP_BUFFER_FREE1		= 0x8B,
	ENIP_SOCK_DATA_READ		= 0x8C,
	ENIP_SOCK_CONNECTED		= 0x8D,
	ENIP_SOCK_CLOSED		= 0x8E,
	ENIP_SOCK_REMOTE_CLOSED	= 0x8F,
	ENIP_SOCK_ACCEPTED		= 0x90,
	ENIP_SOCK_ICMP_ERROR	= 0x91,
	ENIP_DNR_HOST_BY_NAME	= 0x94,
};

/**
 * CEPID registration data for sockets.
 * @warning Used on NewSGOLD.
 * */
#pragma pack(2)
struct REGSOCKCEPID_DATA {
	uint16_t _0x0080;	/**< Set to 0x0080 */
	uint16_t _0xFFFF;	/**< Set to 0xFFFF */
	uint16_t _0x0000;	/**< Set to 0x0000 */
};
#pragma pack()

/**
 * Network Access Point data.
 * @warning Used on NewSGOLD.
 * */
struct CTX_NAPDEF {
	char body[0x204];	/**< Binary data of the NAP profile */
};

/**
 * Network Access Point data container.
 * @warning Used on NewSGOLD.
 * */
struct NAP_PARAM_CONT {
	uint32_t len;
	CTX_NAPDEF *ctx_napdef;
	uint32_t zero;
	CTX_NAPDEF napdef;
};

/**
 * LinkManager data.
 * @warning Used on NewSGOLD.
 * */
struct LMAN_DATA {
#ifdef NEWSGOLD
	int zero;				/**< Set to 0 */
	void *native_profile;	/**< Set to NULL */
	char _1;				/**< Set to 1 */
	char _4;				/**< Set to 4 */
	uint16_t _0;			/**< Set to 0 */
	NAP_PARAM_CONT *NapParameterContainer;	/**< Pointer to the NAP: #NAP_PARAM_CONT */
#else
	char unk1;
	char *unk;
	char one;
	char isactivated;
#endif
};

/**
 * @name General functions
 * @{
 * */

/**
 * Check if GPRS enabled.
 * @return 1 or 0
 * */
__swi_begin(0x0A7)
char IsGPRSEnabled()
__swi_end(0x0A7, IsGPRSEnabled, ());

/**
 * Check if GPRS available in the current network.
 * @return 1 or 0
 * */
__swi_begin(0x284)
char IsGPRSAvailable()
__swi_end(0x284, IsGPRSAvailable, ());

/**
 * Check if EDGE available in the current network.
 * @return 1 or 0
 * */
__swi_begin(0x285)
char IsEDGEAvailable()
__swi_end(0x285, IsEDGEAvailable, ());

/**
 * Check if the GPRS session is established.
 * @return 1 or 0
 * */
__swi_begin(0x0A8)
char IsGPRSConnected()
__swi_end(0x0A8, IsGPRSConnected, ());

/**
 * Enable or disable GPRS internet.
 * @param enable	1 or 0
 * @param unk		set to 1
 * */
__swi_begin(0x18E)
void GPRS_OnOff(int enable, int unk)
__swi_end(0x18E, GPRS_OnOff, (enable, unk));

/**
 * Get an ID of the active internet profile.
 * @return ID
 * @platforms X75, SG
 * @warning SGOLD only
 * */
__swi_begin(0x1A3)
int GetCurrentGPRSProfile(void)
__swi_end(0x1A3, GetCurrentGPRSProfile, ());

/**
 * Change current internet profile.
 * @param profile_id		ID of the profile
 * @return status
 * @platforms X75, SG
 * @warning SGOLD only
 * */
__swi_begin(0x23C)
int SetCurrentGPRSProfile(int profile_id)
__swi_end(0x23C, SetCurrentGPRSProfile, (profile_id));

/** @} */

/**
 * @name SGOLD-only functions
 * @{
 * */

/**
 * Activate internet profile.
 * @param cepid			current CEPID, use #GBS_GetCurCepid
 * @param profile_id	GPRS profile ID, use #GetCurrentGPRSProfile
 * @return status
 * @platforms X75, SG
 * @warning SGOLD only, call only from SUBPROC.
 * */
__swi_begin(0x1A2)
int ActivateDialUpProfile(uint32_t cepid, int profile_id)
__swi_end(0x1A2, ActivateDialUpProfile, (cepid, profile_id));

/**
 * Register CEPID for internet profile.
 * @param cepid			current CEPID, use #GBS_GetCurCepid
 * @param profile_id	GPRS profile ID, use #GetCurrentGPRSProfile
 * @param is_gprs		connection type, 1: GPRS, 0: CSD
 * @platforms X75, SG
 * @warning SGOLD only, call only from SUBPROC.
 * */
__swi_begin(0x1A5)
void RegisterCepIdForCurProfile(uint32_t cepid, int profile_id, uint32_t is_gprs)
__swi_end(0x1A5, RegisterCepIdForCurProfile, (cepid, profile_id, is_gprs));

/**
 * Get internet connection timeout for disconnect when there is no activity.
 * @return seconds
 * @platforms X75, SG
 * @warning SGOLD only
 * */
__swi_begin(0x1A4)
int GetDisconnectTime(void)
__swi_end(0x1A4, GetDisconnectTime, ());

/** @} */

/**
 * @name NewSGOLD-only functions
 * @{
 * */

/**
 * Register current CEPID for sockets.
 * @param reg	pointer to the #REGSOCKCEPID_DATA
 * @return 1: success, 0: error
 * @warning Call only from SUBPROC, NewSGOLD only.
 * */
__swi_begin(0x186)
int RegisterCepidForSocketWork(REGSOCKCEPID_DATA *reg)
__swi_end(0x186, RegisterCepidForSocketWork, (reg));

/**
 * Connect to the GPRS.
 * @param data	pointer to the #LMAN_DATA
 * @return LMAN connect ID
 * @warning Call only from SUBPROC, NewSGOLD only.
 * */
__swi_begin(0x187)
int RequestLMANConnect(LMAN_DATA *data)
__swi_end(0x187, RequestLMANConnect, (data));

#ifdef ELKA

/**
 * Request disconnection of a native LMAN context.
 * @param req		two request bytes: context ID, then disconnect cause
 * @return 1 if handled, 0 if rejected. Call from a process registered for socket work
 * */
__swi_begin(0x43B)
int RequestLMANDisconnect(const uint8_t *req)
__swi_end(0x43B, RequestLMANDisconnect, (req));

/**
 * Find the socket-registration slot for a CEPID.
 * @param cepid		GBS process identifier
 * @return registration index 0..13, or 0xFFFF if not registered
 * */
__swi_begin(0x43C)
unsigned GetSocketRegIndex(unsigned cepid)
__swi_end(0x43C, GetSocketRegIndex, (cepid));

/**
 * Get the process identifier assigned to a native service.
 * @param service		firmware service index; 3 selects the Java service
 * @return service CEPID, or 0 if unavailable
 * */
__swi_begin(0x43D)
unsigned GetServiceCepid(unsigned service)
__swi_end(0x43D, GetServiceCepid, (service));

/**
 * Allocate a native LMAN context.
 * @param bearer		native bearer kind; 1 selects GPRS
 * @param type		context subtype
 * @return context index 0..7. Check for a free context before calling; a full table asserts
 * */
__swi_begin(0x43E)
unsigned LMAN_AllocContext(unsigned bearer, uint8_t type)
__swi_end(0x43E, LMAN_AllocContext, (bearer, type));

/**
 * Copy a NAP profile into an allocated LMAN context.
 * @param cid		context index 0..7
 * @param profile		profile with a terminated name and native bearer settings
 * */
__swi_begin(0x43F)
void LMAN_SetProfile(unsigned cid, const CTX_NAPDEF *profile)
__swi_end(0x43F, LMAN_SetProfile, (cid, profile));

/**
 * Attach or detach a registered process from an LMAN context.
 * @param reg_index	socket-registration index 0..13
 * @param cid		context index 0..7
 * @param on		1 to attach, 0 to detach
 * */
__swi_begin(0x440)
void LMAN_SetRef(unsigned reg_index, unsigned cid, int on)
__swi_end(0x440, LMAN_SetRef, (reg_index, cid, on));

/**
 * Change a native LMAN context state and notify its registered owners.
 * @param cid		context index 0..7
 * @param state		native state value; 4 means connected
 * */
__swi_begin(0x441)
void LMAN_SetState(unsigned cid, int state)
__swi_end(0x441, LMAN_SetState, (cid, state));

/**
 * Reset and release a native LMAN context without disconnecting a physical bearer.
 * @param cid		context index 0..7
 * */
__swi_begin(0x442)
void LMAN_FreeContext(unsigned cid)
__swi_end(0x442, LMAN_FreeContext, (cid));

/**
 * Get the native LMAN context table.
 * @return pointer to 8 context entries, 0x70 bytes each
 * */
__swi_begin(0x8444)
uint8_t *RamLmanContexts(void)
__swi_end(0x8444, RamLmanContexts, ());

/**
 * Get the LMAN process-to-context reference table.
 * @return 14 rows of 8 reference words, indexed by registration slot and context ID
 * */
__swi_begin(0x8445)
uint32_t *RamLmanRefs(void)
__swi_end(0x8445, RamLmanRefs, ());

/**
 * Get the native socket-registration table.
 * @return pointer to 14 registration entries, 0x14 bytes each
 * */
__swi_begin(0x8446)
void *RamSocketRegs(void)
__swi_end(0x8446, RamSocketRegs, ());

/**
 * Get a WSP object.
 * @param id		object ID, 0x17: preferences, 0x18: network policy
 * @return pointer to the object or NULL
 * */
__swi_begin(0x44D)
void *WSP_GetObject(unsigned id)
__swi_end(0x44D, WSP_GetObject, (id));

/**
 * Read a WSP property.
 * @param key		property name
 * @param value		output buffer
 * @param length	buffer size, receives the value length
 * @return 1: success, 0: error
 * */
__swi_begin(0x44E)
int WSP_ReadProperty(const char *key, void *value, unsigned *length)
__swi_end(0x44E, WSP_ReadProperty, (key, value, length));

/**
 * Get the WSP connection state.
 * @param bearer	bearer ID
 * @param nap		NAP profile ID
 * @return connection state, 2: connected
 * */
__swi_begin(0x44F)
uint8_t WSP_GetConnectionState(int bearer, int nap)
__swi_end(0x44F, WSP_GetConnectionState, (bearer, nap));

/**
 * Initialize an ENIP network module (the driver side of a network interface).
 * @param module	module object, filled by the firmware
 * @param name		module name
 * @param up		called when the module goes up
 * @param down		called when the module goes down
 * @param run		module run callback
 * @param notify	event callback (module, event)
 * @param post_run	called after run
 * @param packet_available	called when a packet is queued on the module port
 * */
__swi_begin(0x464)
void ENIP_ModuleInit(void *module, const char *name, void *up, void *down, void *run, void *notify, void *post_run, void *packet_available)
__swi_end(0x464, ENIP_ModuleInit, (module, name, up, down, run, notify, post_run, packet_available));

/**
 * Run an ENIP network module once. Call from the ENIP process.
 * @param module	module object
 * @param[out] result	run result
 * @return module state
 * */
__swi_begin(0x465)
uint8_t ENIP_ModuleRun(void *module, uint32_t *result)
__swi_end(0x465, ENIP_ModuleRun, (module, result));

/**
 * Bring an ENIP network module up.
 * @param module	module object
 * @return result code
 * */
__swi_begin(0x466)
int ENIP_ModuleUp(void *module)
__swi_end(0x466, ENIP_ModuleUp, (module));

/**
 * Bring an ENIP network module down.
 * @param module	module object
 * @param reason	reason code, 0: normal
 * */
__swi_begin(0x467)
void ENIP_ModuleDown(void *module, uint32_t reason)
__swi_end(0x467, ENIP_ModuleDown, (module, reason));

/**
 * Initialize the packet port of an ENIP network module.
 * @param port		port object inside the module
 * @param module	owning module
 * */
__swi_begin(0x468)
void ENIP_PortInit(void *port, void *module)
__swi_end(0x468, ENIP_PortInit, (port, module));

/**
 * Queue a packet on an ENIP port. The port takes ownership of the packet.
 * @param port		destination port
 * @param packet	packet from ENIP_PacketAlloc
 * */
__swi_begin(0x469)
void ENIP_PortSend(void *port, void *packet)
__swi_end(0x469, ENIP_PortSend, (port, packet));

/**
 * Allocate an ENIP packet.
 * @param module	owning module
 * @param size		buffer size
 * @param pool		buffer pool
 * @param offset	data offset in the buffer
 * @param quota		allocation quota
 * @return packet, or NULL if no memory
 * */
__swi_begin(0x46A)
void *ENIP_PacketAlloc(void *module, int size, uint32_t pool, int offset, int quota)
__swi_end(0x46A, ENIP_PacketAlloc, (module, size, pool, offset, quota));

/**
 * Free an ENIP packet.
 * @param packet	packet from ENIP_PacketAlloc
 * */
__swi_begin(0x46B)
void ENIP_PacketFree(void *packet)
__swi_end(0x46B, ENIP_PacketFree, (packet));

/**
 * Register an IP driver (network interface) in the ENIP IP layer.
 * @param driver	driver object: ports, addresses, DNS, MTU, bearer and interface index
 * @param flags		0
 * @return 1: success
 * */
__swi_begin(0x46C)
int ENIP_RegisterDriver(void *driver, int flags)
__swi_end(0x46C, ENIP_RegisterDriver, (driver, flags));

/**
 * Unregister the IP driver of an ENIP network module.
 * @param module	module of the registered driver
 * */
__swi_begin(0x46D)
void ENIP_UnregisterDriver(void *module)
__swi_end(0x46D, ENIP_UnregisterDriver, (module));

/**
 * Find the IP interface of a bearer.
 * @param bearer	bearer ID
 * @param iface		interface index
 * @return interface object, or NULL
 * */
__swi_begin(0x46E)
void *ENIP_FindInterface(uint32_t bearer, uint16_t iface)
__swi_end(0x46E, ENIP_FindInterface, (bearer, iface));

/**
 * Attach an IP interface to a native LMAN context.
 * @param cid		context ID from LMAN_AllocContext
 * @param iface		interface index
 * @param unk		0xFFFF
 * */
__swi_begin(0x46F)
void LMAN_AttachInterface(unsigned cid, unsigned iface, unsigned unk)
__swi_end(0x46F, LMAN_AttachInterface, (cid, iface, unk));

/**
 * Remove the first item of an ENIP list (packet queue).
 * @param list		list head
 * @return removed item, or NULL if the list is empty
 * */
__swi_begin(0x470)
void *ENIP_ListRemoveHead(void *list)
__swi_end(0x470, ENIP_ListRemoveHead, (list));

/**
 * Get the GPRS PDP driver table (the DNS resolver takes servers for bearer 1 from it).
 * @return 8 entries, 0x2C bytes each: +4 local IP, +8 DNS 1, +C DNS 2
 * */
__swi_begin(0x8471)
void *RamPdpDrivers(void)
__swi_end(0x8471, RamPdpDrivers, ());

/**
 * Schedule a run of an ENIP module: mark it as needing a run and call its post-run procedure
 * if one is set, the module is up and no run is already posted or in progress.
 * @param module	ENIP module
 * */
__swi_begin(0x472)
void enip_module_post_run(void *module)
__swi_end(0x472, enip_module_post_run, (module));

/**
 * Reset the per-context fields of an NSAPI module after enip_nsapi_init_module.
 * @param module	NSAPI module
 * */
__swi_begin(0x473)
void enip_module_nsapi_post_init(void *module)
__swi_end(0x473, enip_module_nsapi_post_init, (module));

/**
 * Append a packet to an ENIP port's queue and schedule the port's module if the queue was empty.
 * @param port	ENIP port
 * @param packet	ENIP packet
 * */
__swi_begin(0x474)
void enip_port_handle_pkt(void *port, void *packet)
__swi_end(0x474, enip_port_handle_pkt, (port, packet));

/**
 * Allocate memory from the ENIP pool, falling back to the second ENIP pool.
 * @param unused	not read by the function
 * @param size	size in bytes
 * @return memory block, NULL when both pools are exhausted
 * */
__swi_begin(0x475)
void *enip_memory_allocate(uint32_t unused, int size)
__swi_end(0x475, enip_memory_allocate, (unused, size));

/**
 * Release a block allocated with enip_memory_allocate. NULL is a fatal error.
 * @param block	memory block
 * */
__swi_begin(0x476)
void enip_memory_release(void *block)
__swi_end(0x476, enip_memory_release, (block));

/**
 * Get the largest ENIP packet size (a firmware constant).
 * @return size in bytes
 * */
__swi_begin(0x477)
int enip_packet_max_size(void)
__swi_end(0x477, enip_packet_max_size, ());

/**
 * Initialise the ENIP IP module, its 8 interface slots and the 2 reassembly slots.
 * @param post_run	stored as the IP module's post-run procedure (not confirmed)
 * @return 1
 * */
__swi_begin(0x478)
int enip_ip_init(void *post_run)
__swi_end(0x478, enip_ip_init, (post_run));

/**
 * Find the IP interface (of 8) whose registered driver belongs to the same module as the given driver.
 * @param driver	ENIP IP driver
 * @return IP interface (its driver part), NULL when not found
 * */
__swi_begin(0x479)
void *enip_find_iface_by_driver(void *driver)
__swi_end(0x479, enip_find_iface_by_driver, (driver));

/**
 * Fill the IPv4 header checksum of a packet, set its size and send it to a port.
 * @param port	pointer to the destination ENIP port pointer
 * @param packet	ENIP packet with an IPv4 header at its data
 * @param size	packet size in bytes
 * */
__swi_begin(0x47A)
void enip_iph_calc_chk_and_port_send(void **port, void *packet, uint32_t size)
__swi_end(0x47A, enip_iph_calc_chk_and_port_send, (port, packet, size));

/**
 * Compute the Internet (one's complement) checksum of a buffer.
 * @param seed	checksum of preceding data, 0 to start
 * @param data	data, summed as big-endian 16-bit words
 * @param size	size in bytes
 * @return checksum, 0 when data already contains a correct checksum
 * */
__swi_begin(0x47B)
uint16_t enip_iph_compute_checksum(uint16_t seed, const void *data, uint16_t size)
__swi_end(0x47B, enip_iph_compute_checksum, (seed, data, size));

/**
 * Find the IP interface whose bearer ID and interface index equal the socket's LMAN destination.
 * @param socket	ENIP socket
 * @return IP interface (its driver part), NULL when not found
 * */
__swi_begin(0x47C)
void *enip_iph_find_IF_for_socket(void *socket)
__swi_end(0x47C, enip_iph_find_IF_for_socket, (socket));

/**
 * Process a received IP packet: check the IPv4 header, find the interface, reassemble fragments
 * and pass the packet to the protocol handler.
 * @param packet	ENIP packet
 * */
__swi_begin(0x47D)
void enip_iph_frame_read(void *packet)
__swi_end(0x47D, enip_iph_frame_read, (packet));

/**
 * Add an IPv4 fragment to its reassembly slot.
 * @param iface	receiving IP interface
 * @param packet	ENIP packet with the fragment
 * @param header	IPv4 header of the fragment
 * @param total_size	IPv4 total length
 * @param header_size	IPv4 header length
 * @param fragment	IPv4 flags and fragment offset field
 * @param source	value matched against the slot owner (probably the source address)
 * @return complete packet, 0 while fragments are missing
 * */
__swi_begin(0x47E)
int enip_iph_manage_reassembly(void *iface, void *packet, uint8_t *header, uint32_t total_size, uint32_t header_size, uint32_t fragment, int source)
__swi_end(0x47E, enip_iph_manage_reassembly, (iface, packet, header, total_size, header_size, fragment, source));

/**
 * Notify the IP layer that a packet buffer is free again.
 * */
__swi_begin(0x47F)
void enip_iph_packet_avail(void)
__swi_end(0x47F, enip_iph_packet_avail, ());

/**
 * Reset an IPv4 reassembly slot and its timer.
 * @param slot	reassembly slot
 * */
__swi_begin(0x480)
void enip_iph_rheader_init(void *slot)
__swi_end(0x480, enip_iph_rheader_init, (slot));

/**
 * Run procedure of the IP module: expire socket timers and handle queued packets.
 * @param module	IP module
 * */
__swi_begin(0x481)
void enip_iph_run(void *module)
__swi_end(0x481, enip_iph_run, (module));

/**
 * Send a packet from the IP layer: fill the header checksum and pass it to the port.
 * @param port	pointer to the destination ENIP port pointer
 * @param packet	ENIP packet, NULL only runs the pending output
 * @param size	packet size in bytes
 * @return 0 when a packet was given
 * */
__swi_begin(0x482)
int enip_iph_write(void *port, void *packet, uint32_t size)
__swi_end(0x482, enip_iph_write, (port, packet, size));

/**
 * Receive handler of the secure IP layer: answers a special 8-byte UDP probe in place.
 * Only partly reversed.
 * @param module	ENIP module
 * @param packet	ENIP packet
 * @return meaning not known
 * */
__swi_begin(0x483)
int enip_siph_crypt_frame_read(void *module, void *packet)
__swi_end(0x483, enip_siph_crypt_frame_read, (module, packet));

/**
 * Find the IP interface with the given local address.
 * @param address	local IPv4 address, network byte order
 * @return IP interface (its driver part), NULL when not found
 * */
__swi_begin(0x484)
void *enip_siph_find_IF(int address)
__swi_end(0x484, enip_siph_find_IF, (address));

/**
 * Process a received ICMP packet (echo request, unreachable, quench, time exceeded, parameter
 * problem) and release it.
 * @param module	ENIP module
 * @param packet	ENIP packet, data at the ICMP header
 * */
__swi_begin(0x485)
void enip_icmp_frame_read(void *module, void *packet)
__swi_end(0x485, enip_icmp_frame_read, (module, packet));

/**
 * Process a received UDP packet: check it and queue it on the matching socket.
 * @param module	ENIP module with the socket list
 * @param packet	ENIP packet, data at the UDP header
 * */
__swi_begin(0x486)
void enip_udph_frame_read(void *module, void *packet)
__swi_end(0x486, enip_udph_frame_read, (module, packet));

/**
 * Fill an IP driver description for the CSD (PPP dial-up) interface.
 * @param module	CSD module
 * @param driver	ENIP IP driver to fill
 * @return 1 when the module is up, otherwise 0
 * */
__swi_begin(0x487)
int enip_init_csd_iface(void *module, void *driver)
__swi_end(0x487, enip_init_csd_iface, (module, driver));

/**
 * Create and register the IP interface of a PDP context (NSAPI module).
 * @param module	NSAPI module
 * @return 0 when the module is not up
 * */
__swi_begin(0x488)
int enip_nsapi_init_iface(void *module)
__swi_end(0x488, enip_nsapi_init_iface, (module));

/**
 * Initialise an NSAPI (PDP context) module named "NSAPI".
 * @param module	NSAPI module
 * @return 1
 * */
__swi_begin(0x489)
int enip_nsapi_init_module(void *module)
__swi_end(0x489, enip_nsapi_init_module, (module));

/**
 * ENIP handler of the PDP NET_UP confirmation.
 * @param context	PDP context index
 * @param result	1: OK
 * */
__swi_begin(0x48A)
void ENIP_PDP_NET_UP_CNF(uint16_t context, int result)
__swi_end(0x48A, ENIP_PDP_NET_UP_CNF, (context, result));

/**
 * ENIP handler of the PDP NET_UP reject indication.
 * @param context	PDP context index
 * @param result	meaning not known; 1 releases the context
 * */
__swi_begin(0x48B)
void ENIP_PDP_NET_UP_REJ_IND(uint16_t context, int result)
__swi_end(0x48B, ENIP_PDP_NET_UP_REJ_IND, (context, result));

/**
 * ENIP handler of the PDP NET_DOWN indication: take the context's interface down.
 * @param context	PDP context index
 * @param mode	meaning not known (0 and 1 handled differently)
 * */
__swi_begin(0x48C)
void ENIP_PDP_NET_DOWN_IND(uint16_t context, int mode)
__swi_end(0x48C, ENIP_PDP_NET_DOWN_IND, (context, mode));

/**
 * ENIP handler of the PDP start request: initialise and bring up the context's NSAPI module.
 * @param context	PDP context index
 * @param mode	meaning not known (0: create the interface)
 * */
__swi_begin(0x48D)
void ENIP_PDP_START_REQ(int context, int mode)
__swi_end(0x48D, ENIP_PDP_START_REQ, (context, mode));

/**
 * ENIP handler of the PDP stop request.
 * @param context	PDP context index
 * @param mode	meaning not known (0 and 1 handled differently)
 * */
__swi_begin(0x48E)
void ENIP_PDP_STOP_REQ(uint16_t context, int mode)
__swi_end(0x48E, ENIP_PDP_STOP_REQ, (context, mode));

/**
 * ENIP handler of the CSD (PPP dial-up) start request: set up the "PPP CSD" module.
 * @param bearer	meaning not known (selects one of two interface types)
 * */
__swi_begin(0x48F)
void ENIP_PDP_START_CSD_INT_REQ(int bearer)
__swi_end(0x48F, ENIP_PDP_START_CSD_INT_REQ, (bearer));

/**
 * Create an ENIP socket.
 * @param family	1: IPv4
 * @param type	0: datagram, 1: stream
 * @param protocol	0, 17 (UDP) or 6 (TCP)
 * @param owner	owner, must not be NULL; meaning not known
 * @param param	passed to enip_sockh_create_internal; meaning not known
 * @param destination	LMAN socket destination (5 halfwords, see lman_get_socket_destination)
 * @return socket ID, negative on error
 * */
__swi_begin(0x490)
int enip_sock_create(int family, int type, int protocol, int *owner, uint32_t param, uint16_t *destination)
__swi_end(0x490, enip_sock_create, (family, type, protocol, owner, param, destination));

/**
 * Connect a socket: set the peer of a datagram socket or start a TCP connection.
 * @param socket	socket ID
 * @param address	peer IPv4 address, network byte order
 * @param unknown	meaning not known
 * @param port	peer port, network byte order
 * @param timeout	TCP connect timeout
 * @return 0 or negative error
 * */
__swi_begin(0x491)
int enip_socket_connect(int socket, int address, int unknown, uint16_t port, uint32_t timeout)
__swi_end(0x491, enip_socket_connect, (socket, address, unknown, port, timeout));

/**
 * Pick a pseudo-random first local port for an interface.
 * @param iface	IP interface
 * */
__swi_begin(0x492)
void enip_sockh_IF_init(void *iface)
__swi_end(0x492, enip_sockh_IF_init, (iface));

/**
 * Allocate and initialise a socket in a free slot of the 12-socket table.
 * @param family	1: IPv4
 * @param type	0: datagram, 1: stream
 * @param protocol	17 (UDP) or 6 (TCP)
 * @param owner	meaning not known
 * @param param1	meaning not known
 * @param param2	meaning not known
 * @return socket, NULL when the table is full
 * */
__swi_begin(0x493)
void *enip_sockh_create_internal(int family, int type, int protocol, int *owner, uint32_t param1, uint32_t param2)
__swi_end(0x493, enip_sockh_create_internal, (family, type, protocol, owner, param1, param2));

/**
 * Bind a socket to an IP interface: the one matching its LMAN destination, or the first usable one.
 * @param socket	ENIP socket
 * @param address	peer IPv4 address, 0 or -1 for none
 * @return 0 or negative error
 * */
__swi_begin(0x494)
int enip_sockh_autobind_IF(void *socket, int address)
__swi_end(0x494, enip_sockh_autobind_IF, (socket, address));

/**
 * Allocate an outgoing packet for a socket with room for the interface headers.
 * @param socket	ENIP socket bound to an interface
 * @param size	payload size in bytes
 * @param flags	meaning not known
 * @param packet	receives the ENIP packet
 * @param timeout	meaning not known
 * @return 0 or negative error
 * */
__swi_begin(0x495)
int enip_sockh_packet_allocate(void *socket, uint32_t size, uint32_t flags, void **packet, int timeout)
__swi_end(0x495, enip_sockh_packet_allocate, (socket, size, flags, packet, timeout));

/**
 * Set the peer of a datagram socket.
 * @param socket	ENIP socket
 * @param address	peer IPv4 address, network byte order
 * @param unused	not read by the function
 * @param port	peer port, network byte order
 * @return 0
 * */
__swi_begin(0x496)
int enip_sockh_dgram_connect(void *socket, int address, uint32_t unused, uint16_t port)
__swi_end(0x496, enip_sockh_dgram_connect, (socket, address, unused, port));

/**
 * Find the socket for a received packet by protocol, ports and address.
 * @param module	ENIP module with the socket list
 * @param header	IPv4 header
 * @return socket, NULL when none matches
 * */
__swi_begin(0x497)
void *enip_sockh_from_ipheader(void *module, const uint8_t *header)
__swi_end(0x497, enip_sockh_from_ipheader, (module, header));

/**
 * Fill the IPv4 header of an outgoing packet from the socket's settings.
 * @param index	index of the outgoing packet in the firmware's table
 * @param socket	ENIP socket
 * @param address	destination IPv4 address, network byte order
 * @return 0 or negative error
 * */
__swi_begin(0x498)
int enip_sockh_prepare_send(int index, void *socket, uint32_t address)
__swi_end(0x498, enip_sockh_prepare_send, (index, socket, address));

/**
 * Allocate an outgoing TCP segment of the socket's maximum size. Only partly reversed.
 * @param socket	ENIP socket
 * @return 0 or negative error
 * */
__swi_begin(0x499)
int enip_sockh_tcp_packet_allocate(void *socket)
__swi_end(0x499, enip_sockh_tcp_packet_allocate, (socket));

/**
 * Initialise the TCP state of a socket: initial sequence number, windows and MSS.
 * @param socket	ENIP socket bound to an interface
 * @return 0 or negative error
 * */
__swi_begin(0x49A)
int enip_tcph_sock_init(void *socket)
__swi_end(0x49A, enip_tcph_sock_init, (socket));

/**
 * Start a TCP connection: send SYN and start the connect timer.
 * @param socket	ENIP socket
 * @param address	peer IPv4 address, network byte order
 * @param unknown	meaning not known
 * @param port	peer port, network byte order
 * @param timeout	connect timeout, 0 for the default
 * @return 0 or negative error
 * */
__swi_begin(0x49B)
int enip_tcph_sock_connect(void *socket, int address, uint32_t unknown, uint16_t port, uint32_t timeout)
__swi_end(0x49B, enip_tcph_sock_connect, (socket, address, unknown, port, timeout));

/**
 * Build and send one TCP segment.
 * @param socket	ENIP socket
 * @param flags	TCP flags (2: SYN)
 * @param data	payload or NULL
 * @param size	payload size in bytes
 * @param packet	preallocated ENIP packet or NULL
 * @param unknown	meaning not known
 * @return 0 or negative error
 * */
__swi_begin(0x49C)
int enip_tcph_send_segment(void *socket, uint32_t flags, const void *data, uint32_t size, void *packet, int unknown)
__swi_end(0x49C, enip_tcph_send_segment, (socket, flags, data, size, packet, unknown));

/**
 * Take a received TCP segment into the socket's receive state (part of TCP input).
 * Only partly reversed.
 * @param socket	ENIP socket
 * @param packet	ENIP packet with the IPv4 and TCP headers
 * @param use_sequence	nonzero: take the sequence number from the segment
 * */
__swi_begin(0x49D)
void enip_tcph_write_segment(void *socket, void *packet, int use_sequence)
__swi_end(0x49D, enip_tcph_write_segment, (socket, packet, use_sequence));

/**
 * Change the TCP state of a socket and notify its owner.
 * @param socket	ENIP socket
 * @param state	new state in firmware numbering (0: closed, 8: SYN sent, 10: established)
 * */
__swi_begin(0x49E)
void enip_tcph_change_sock_state(void *socket, uint32_t state)
__swi_end(0x49E, enip_tcph_change_sock_state, (socket, state));

/**
 * Process a received TCP segment.
 * @param module	ENIP module with the socket list
 * @param packet	ENIP packet
 * */
__swi_begin(0x49F)
void enip_tcph_frame_read(void *module, void *packet)
__swi_end(0x49F, enip_tcph_frame_read, (module, packet));

/**
 * Check the TCP timers of all sockets: retransmit, time out or move on in the close states.
 * */
__swi_begin(0x4A0)
void enip_tcph_run(void)
__swi_end(0x4A0, enip_tcph_run, ());

/**
 * Write a TCP SACK option (NOP, NOP, SACK) from the socket's SACK blocks.
 * @param socket	ENIP socket
 * @param count	maximum number of blocks
 * @param option	output buffer
 * @return option size in bytes, 0 when there are no blocks
 * */
__swi_begin(0x4A1)
uint32_t enip_tcph_get_SACK_option_from_list(void *socket, uint32_t count, uint8_t *option)
__swi_end(0x4A1, enip_tcph_get_SACK_option_from_list, (socket, count, option));

/**
 * Remove the SACK blocks that are already acknowledged.
 * @param socket	ENIP socket
 * */
__swi_begin(0x4A2)
void enip_tcph_update_SACK_block_list(void *socket)
__swi_end(0x4A2, enip_tcph_update_SACK_block_list, (socket));

/**
 * Initialise an ENIP timer.
 * @param timer	timer
 * @param module	ENIP module whose timer list it will use
 * */
__swi_begin(0x4A3)
void enip_timer_init(void *timer, void *module)
__swi_end(0x4A3, enip_timer_init, (timer, module));

/**
 * Stop an ENIP timer if it is running.
 * @param timer	timer
 * */
__swi_begin(0x4A4)
void enip_timer_cancel(void *timer)
__swi_end(0x4A4, enip_timer_cancel, (timer));

/**
 * Start or restart an ENIP timer and schedule its module.
 * @param timer	timer
 * @param timeout	timeout
 * */
__swi_begin(0x4A5)
void enip_timer_start(void *timer, uint32_t timeout)
__swi_end(0x4A5, enip_timer_start, (timer, timeout));

/**
 * LMAN handler of the link-up confirmation: mark the waiting connection as up and notify the owner.
 * */
__swi_begin(0x4A6)
void LMAN_LINK_UP_CNF(void)
__swi_end(0x4A6, LMAN_LINK_UP_CNF, ());

/**
 * Register an application in the LMAN application table. Only partly reversed.
 * @param app	meaning not known
 * @return application slot, error value when the table is full
 * */
__swi_begin(0x4A7)
int16_t lman_app_register(uint16_t app)
__swi_end(0x4A7, lman_app_register, (app));

/**
 * Free an LMAN application slot.
 * @param slot	application slot
 * */
__swi_begin(0x4A8)
void lman_app_free(uint16_t slot)
__swi_end(0x4A8, lman_app_free, (slot));

/**
 * Set the bearer settings of an LMAN application.
 * @param slot	application slot (0..13)
 * @param settings	three halfwords: application flags (below 800), selector, meaning not known
 * @param callback	stored when nonzero; meaning not known
 * @return 1 OK, 0 error
 * */
__swi_begin(0x4A9)
int lman_app_set_bearer(uint16_t slot, const uint16_t *settings, int callback)
__swi_end(0x4A9, lman_app_set_bearer, (slot, settings, callback));

/**
 * Find the LMAN connection with the given bearer ID and key.
 * @param bearer	bearer ID
 * @param key	value at connection +4; meaning not known
 * @return connection ID (0..7), error value when not found
 * */
__swi_begin(0x4AA)
int16_t lman_get_active_connection_id(uint16_t bearer, uint16_t key)
__swi_end(0x4AA, lman_get_active_connection_id, (bearer, key));

/**
 * Get the bearer ID of an LMAN connection.
 * @param connection	connection ID (0..7)
 * @return bearer ID, 0xFF for an invalid connection
 * */
__swi_begin(0x4AB)
uint8_t lman_GetBearerIdForCi(uint16_t connection)
__swi_end(0x4AB, lman_GetBearerIdForCi, (connection));

/**
 * Get where sockets of a process go: application flags, selector, bearer ID and interface index.
 * @param cepid	process ID
 * @param destination	receives the destination (8 bytes: u16 app_flags, u16 selector, u8 bearer_id,
 *	u8 unknown, u16 iface_index; 0xFF when the process has no connection)
 * @return 1 OK, 0 when the process has no LMAN application
 * */
__swi_begin(0x4AC)
int lman_get_socket_destination(uint16_t cepid, void *destination)
__swi_end(0x4AC, lman_get_socket_destination, (cepid, destination));

/**
 * Initialise an empty ENIP double-linked list (two pointers: first, last).
 * @param list	list head
 * */
__swi_begin(0x4AD)
void zDLL_Init(void *list)
__swi_end(0x4AD, zDLL_Init, (list));

#endif

/** @} */

/**
 * @name Profile
 * @{
 * */

/**
 * Get name of the current internet profile.
 * @return C-string
 * */
__swi_begin(0x828E)
const char *RamActiveGPRSProfileName()
__swi_end(0x828E, RamActiveGPRSProfileName, ());

/** @} */

/**
 * @name Statistic
 * @{
 * */

/**
 * Refresh the GPRS traffic counter.
 * */
__swi_begin(0x06F)
void RefreshGPRSTraffic()
__swi_end(0x06F, RefreshGPRSTraffic, ());

/**
 * Reset the GPRS traffic counter.
 * */
__swi_begin(0x0A6)
void ResetGPRSTraffic()
__swi_end(0x0A6, ResetGPRSTraffic, ());

/**
 * Get traffic used by GPRS.
 * @return pointer to the byte count
 * 
 * ```C
 * int bytes = *GetGPRSTrafficPointer();
 * ```
 * */
__swi_begin(0x070)
int *GetGPRSTrafficPointer()
__swi_end(0x070, GetGPRSTrafficPointer, ());

/** @} */

__swilib_end

/** @} */
