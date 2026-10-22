#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

/**
 * @addtogroup Bluetooth
 * @brief Bluetooth functions.
 *
 * Usage: `#include <swilib.h>` or `#include <swilib/bluetooth.h>`
 * @platforms ELKA
 * @{
 */
#ifdef ELKA

typedef struct SDEV SDEV;
typedef struct SDEV_APP SDEV_APP;

/**
 * SDev endpoint.
 * */
struct SDEV {
	void *fn[15];	/**< Callback table */
	uint8_t type;	/**< Device type */
	int inst;		/**< Device callback instance */
	uint8_t app;	/**< Application ID */
	int index;		/**< Endpoint callback instance */
};

/**
 * SDev application callbacks.
 * */
struct SDEV_APP {
	int (*open)(SDEV **ep, int dev_type, const uint8_t *info);
	void (*reg)(SDEV *dev, const void *info);
	void *unk;
	void (*close)(int index);
	int (*get_dev)(int index, int *inst);
};

/**
 * Create a Bluetooth accessor. Events are sent to the supplied CEPID.
 * @param cepid		destination process for accessor events
 * @param msg		GBS message number for events
 * @param no_servers	use 0 when creating data servers
 * @param zero		reserved; pass 0
 * @return accessor handle; handles in the 0xFFxx range indicate failure
 * */
__swi_begin(0x420)
int BtAccessor_New(int cepid, int msg, int no_servers, int zero)
__swi_end(0x420, BtAccessor_New, (cepid, msg, no_servers, zero));

/**
 * Delete a Bluetooth accessor after closing its connections and servers.
 * @param oh		accessor handle
 * */
__swi_begin(0x421)
void BtAccessor_Delete(int oh)
__swi_end(0x421, BtAccessor_Delete, (oh));

/**
 * Read the Bluetooth event identifier from an accessor event object.
 * @param ev		event object from the accessor message
 * @return event identifier; its low byte selects the event
 * */
__swi_begin(0x422)
uint32_t BTA_ObjMsg(void *ev)
__swi_end(0x422, BTA_ObjMsg, (ev));

/**
 * Create an RFCOMM or L2CAP server under an accessor.
 * @param oh		accessor handle
 * @param proto		1 for RFCOMM, 2 for L2CAP
 * @param master		master-role option
 * @param encrypt		encryption option
 * @param authenticate	authentication option
 * @param authorize	authorization option
 * @param rx_mtu		receive MTU
 * @param tx_mtu		transmit MTU
 * @param tid		transaction identifier returned in the completion event
 * @return server handle. Creation completes asynchronously
 * */
__swi_begin(0x424)
int BTA_Server_New(int oh, int proto, int master, int encrypt, int authenticate, int authorize, int rx_mtu, int tx_mtu, int tid)
__swi_end(0x424, BTA_Server_New, (oh, proto, master, encrypt, authenticate, authorize, rx_mtu, tx_mtu, tid));

/**
 * Start a Bluetooth server and publish its SDP record.
 * @param oh		accessor handle
 * @param server		server handle
 * @param sdp_record	SDP record handle
 * @param unk		set to 0
 * @param tid		transaction identifier
 * */
__swi_begin(0x425)
void BTA_Server_StartReq(int oh, int server, int sdp_record, int unk, int tid)
__swi_end(0x425, BTA_Server_StartReq, (oh, server, sdp_record, unk, tid));

/**
 * Enable or disable incoming connections on a Bluetooth server.
 * @param oh		accessor handle
 * @param server		server handle
 * @param enable		1 to accept incoming connections, 0 to stop accepting
 * @param tid		transaction identifier
 * */
__swi_begin(0x426)
void BTA_Server_AcceptReq(int oh, int server, int enable, int tid)
__swi_end(0x426, BTA_Server_AcceptReq, (oh, server, enable, tid));

/**
 * Request asynchronous stop of a Bluetooth server.
 * @param oh		accessor handle
 * @param server		server handle
 * @param tid		transaction identifier
 * */
__swi_begin(0x427)
void BTA_Server_StopReq(int oh, int server, int tid)
__swi_end(0x427, BTA_Server_StopReq, (oh, server, tid));

/**
 * Delete a stopped Bluetooth server.
 * @param oh		accessor handle
 * @param server		server handle
 * */
__swi_begin(0x428)
void BTA_Server_Delete(int oh, int server)
__swi_end(0x428, BTA_Server_Delete, (oh, server));

/**
 * Set allocator callbacks for accessor SDP records.
 * @param oh		accessor handle
 * @param alloc		allocator used for SDP data
 * @param free		matching deallocator
 * */
__swi_begin(0x429)
void BTA_Sdp_Converter_New(int oh, void *(*alloc)(unsigned int), void (*free)(void *))
__swi_end(0x429, BTA_Sdp_Converter_New, (oh, alloc, free));

/**
 * Create a Bluetooth SDP service record.
 * @param oh		accessor handle
 * @param uuid		16-byte service UUID, most significant byte first
 * @param proto		1 for RFCOMM, 0 for L2CAP
 * @param channel		RFCOMM channel or L2CAP PSM
 * @return SDP record handle
 * */
__swi_begin(0x42A)
int BTA_SdpRec_New(int oh, const uint8_t uuid[16], int proto, int channel)
__swi_end(0x42A, BTA_SdpRec_New, (oh, uuid, proto, channel));

/**
 * Delete an accessor SDP record.
 * @param oh		accessor handle
 * @param record		SDP record handle
 * */
__swi_begin(0x42B)
void BTA_SdpRec_Delete(int oh, int record)
__swi_end(0x42B, BTA_SdpRec_Delete, (oh, record));

/**
 * Request asynchronous closure of a Bluetooth connection.
 * @param oh		accessor handle
 * @param conn		connection handle
 * @param tid		transaction identifier
 * */
__swi_begin(0x42C)
void BTA_Conn_CloseReq(int oh, int conn, int tid)
__swi_end(0x42C, BTA_Conn_CloseReq, (oh, conn, tid));

/**
 * Get the local Bluetooth address.
 * @return pointer to six bytes, least significant byte first, or NULL if unavailable
 * */
__swi_begin(0x42D)
const uint8_t *BT_GetLocAddr(void)
__swi_end(0x42D, BT_GetLocAddr, ());

/**
 * Initialize an SDev endpoint with the firmware default callbacks.
 * @param ep		endpoint storage owned by the caller
 * */
__swi_begin(0x42E)
void SDev_InitEndpoint(SDEV *ep)
__swi_end(0x42E, SDev_InitEndpoint, (ep));

/**
 * Get the native local Bluetooth device object.
 * @return firmware-owned device object. Its layout is firmware-specific
 * */
__swi_begin(0x42F)
uint8_t *BT_GetLocalDevice(void)
__swi_end(0x42F, BT_GetLocalDevice, ());

/**
 * Set the local Bluetooth connection security level.
 * @param lo		0 selects high security; nonzero selects low security
 * @param unk1		reserved; pass 0
 * @param unk2		reserved; pass 0
 * @param unk3		reserved; pass 0
 * */
__swi_begin(0x430)
void BT_SetSecurityCheck(int lo, int unk1, int unk2, int unk3)
__swi_end(0x430, BT_SetSecurityCheck, (lo, unk1, unk2, unk3));

/**
 * Get the SDev application callback table.
 * @return firmware-owned table of 32 application pointers
 * */
__swi_begin(0x8431)
void **RamSDevApps(void)
__swi_end(0x8431, RamSDevApps, ());

/**
 * Get the native Bluetooth buffer-pool status.
 * @return status words; words 0 and 1 count free receive and transmit buffers
 * */
__swi_begin(0x8432)
uint16_t *RamBtBufferPool(void)
__swi_end(0x8432, RamBtBufferPool, ());

/**
 * Open an outgoing L2CAP connection. Completion arrives as an accessor event.
 * @param oh		accessor handle
 * @param addr		six-byte peer address, least significant byte first
 * @param sapi_type	0x17 selects the Java-compatible L2CAP SDev binding
 * @param psm		remote L2CAP PSM
 * @param master		master-role option
 * @param encrypt		encryption option
 * @param authenticate	authentication option
 * @param rx_mtu		receive MTU
 * @param tx_mtu		transmit MTU
 * @param tid		transaction identifier
 * @return connection handle; handles in the 0xFFxx range indicate failure
 * */
__swi_begin(0x433)
int BTA_Conn_New_L2CAP(int oh, const uint8_t addr[6], int sapi_type, int psm, int master, int encrypt, int authenticate, int rx_mtu, int tx_mtu, int tid)
__swi_end(0x433, BTA_Conn_New_L2CAP, (oh, addr, sapi_type, psm, master, encrypt, authenticate, rx_mtu, tx_mtu, tid));

/**
 * Open an outgoing RFCOMM (SPP) connection to a remote device, client role.
 * @param oh		accessor handle
 * @param addr		eight-byte remote address buffer, least significant byte first
 * @param sapi_type		SAPI application type (0x16 for btspp)
 * @param channel		RFCOMM server channel (1..30)
 * @param master		request the master role
 * @param encrypt		require encryption
 * @param authenticate		require authentication
 * @param tid		transaction id (see NextTid)
 * @return connection handle, or an invalid handle on failure
 * @platforms ELKA
 * */
__swi_begin(0x450)
int BTA_Conn_New_RFCOMM(int oh, const uint8_t addr[8], int sapi_type, int channel, int master, int encrypt, int authenticate, int tid)
__swi_end(0x450, BTA_Conn_New_RFCOMM, (oh, addr, sapi_type, channel, master, encrypt, authenticate, tid));

/**
 * Search the SDP records of a remote device (what JSR-82 searchServices uses).
 * The accessor then gets message 0x0F per matching record (+18 u16 exception, +20 record)
 * and 0x10 when the search is over.
 * @param oh		accessor handle
 * @param addr		remote address, same layout as for BTA_Conn_New_RFCOMM
 * @param uuids		UUID list: { u8 count; u8 allocated; u32 element size = 20; void *elements },
 *			element { u8 type (2 = 128-bit); u8 pad[3]; u8 uuid[16] big endian }; copied
 * @param attrs		attribute ids to fetch (copied)
 * @param nattrs	number of attribute ids
 * @param tid		transaction id
 * @return remote device handle, or an invalid handle on failure
 * @platforms ELKA
 * */
__swi_begin(0x451)
int BTA_ServiceSearch_StartReq(int oh, const uint8_t addr[8], const void *uuids, const uint16_t *attrs, int nattrs, int tid)
__swi_end(0x451, BTA_ServiceSearch_StartReq, (oh, addr, uuids, attrs, nattrs, tid));

/**
 * Cancel a running service search.
 * @param oh		accessor handle
 * @param remdev	remote device handle from BTA_ServiceSearch_StartReq
 * @param tid		transaction id
 * @platforms ELKA
 * */
__swi_begin(0x452)
void BTA_ServiceSearch_StopReq(int oh, int remdev, int tid)
__swi_end(0x452, BTA_ServiceSearch_StopReq, (oh, remdev, tid));

/**
 * Server channel from an SDP record's ProtocolDescriptorList.
 * @param record	record from message 0x0F (+20)
 * @param rfcomm	1: RFCOMM channel, 0: L2CAP PSM
 * @return channel / PSM, 0 if the record has none
 * @platforms ELKA
 * */
__swi_begin(0x453)
unsigned BTA_SdpRec_GetChannel(const void *record, int rfcomm)
__swi_end(0x453, BTA_SdpRec_GetChannel, (record, rfcomm));

/**
 * Open a view of the stored Bluetooth device list.
 * @param oh		accessor handle
 * @param type		list type, 0: stored devices
 * @return device-list handle
 * */
__swi_begin(0x447)
int BTA_DeviceListView_GetList(int oh, int type)
__swi_end(0x447, BTA_DeviceListView_GetList, (oh, type));

/**
 * Count entries in a Bluetooth device-list view.
 * @param oh		accessor handle
 * @param list		device-list handle
 * @return number of entries
 * */
__swi_begin(0x448)
int BTA_DeviceListView_GetNumberOfEntries(int oh, int list)
__swi_end(0x448, BTA_DeviceListView_GetNumberOfEntries, (oh, list));

/**
 * Request a stored Bluetooth device entry asynchronously.
 * @param oh		accessor handle
 * @param list		device-list handle
 * @param index		zero-based entry index
 * @param tid		transaction identifier returned with the entry
 * */
__swi_begin(0x449)
void BTA_DeviceListView_GetEntryReq(int oh, int list, int index, int tid)
__swi_end(0x449, BTA_DeviceListView_GetEntryReq, (oh, list, index, tid));

/**
 * Close a Bluetooth device-list view.
 * @param oh		accessor handle
 * @param list		device-list handle
 * */
__swi_begin(0x44A)
void BTA_DeviceListView_StopList(int oh, int list)
__swi_end(0x44A, BTA_DeviceListView_StopList, (oh, list));

/**
 * Read the Bluetooth address from a returned remote-device object.
 * @param oh		accessor handle
 * @param device		remote-device object from the list-entry event
 * @return six-byte address, least significant byte first. Copy before consuming the event
 * */
__swi_begin(0x44B)
const uint8_t *BTA_RemBtDeviceInfo_GetAddress(int oh, const void *device)
__swi_end(0x44B, BTA_RemBtDeviceInfo_GetAddress, (oh, device));

/**
 * Read the name from a returned remote-device object.
 * @param oh		accessor handle
 * @param device		remote-device object from the list-entry event
 * @return UTF-8 device name. Copy before consuming the event
 * */
__swi_begin(0x44C)
const char *BTA_RemBtDeviceInfo_GetName(int oh, const void *device)
__swi_end(0x44C, BTA_RemBtDeviceInfo_GetName, (oh, device));

/**
 * Request the L2CAP parameters of an open connection.
 * Answered with the accessor event BT_EVENT_CONNECTION_L2CAP_PARAMETERS_CFM (13).
 * @param oh		accessor handle
 * @param conn		connection handle
 * @param tid		transaction ID
 * */
__swi_begin(0x45F)
void BTA_Conn_GetL2CAPParamReq(int oh, int conn, int tid)
__swi_end(0x45F, BTA_Conn_GetL2CAPParamReq, (oh, conn, tid));

/**
 * Get the remote-device object of an open connection.
 * @param oh		accessor handle
 * @param conn		connection handle
 * @return remote-device object, for BTA_RemBtDeviceInfo_* calls
 * */
__swi_begin(0x460)
void *BTA_Conn_GetRemDevInfo(int oh, int conn)
__swi_end(0x460, BTA_Conn_GetRemDevInfo, (oh, conn));

/**
 * Read the link status of a remote device.
 * @param oh		accessor handle
 * @param device	remote-device object
 * @param what		0: ACL status
 * @return status, 2: ACL connected
 * */
__swi_begin(0x461)
uint32_t BTA_RemBtDeviceInfo_GetStatus(int oh, const void *device, int what)
__swi_end(0x461, BTA_RemBtDeviceInfo_GetStatus, (oh, device, what));

/**
 * Drop the ACL link to a remote device (asynchronous). Affects every profile on that link.
 * @param tid		transaction ID
 * @param addr		six-byte Bluetooth address, least significant byte first
 * */
__swi_begin(0x462)
void BTA_AclDisconnectReq(int tid, const uint8_t addr[6])
__swi_end(0x462, BTA_AclDisconnectReq, (tid, addr));

/**
 * Start a Bluetooth device search (asynchronous).
 * @param oh		accessor handle
 * @param service	SAPI service to search for
 * @param tid		transaction ID
 * */
__swi_begin(0x4AE)
void BTA_DeviceDiscovery_StartSearchReq(int oh, uint32_t service, int tid)
__swi_end(0x4AE, BTA_DeviceDiscovery_StartSearchReq, (oh, service, tid));

/**
 * Start a Bluetooth device search filtered by device class (asynchronous). Only partly reversed.
 * @param oh		accessor handle
 * @param cod_class	class byte, matched at bits 16..23 of the class of device; 0: no filter
 * @param param3	transaction ID or IAC, meaning not known
 * @param param4	transaction ID or IAC, meaning not known
 * */
__swi_begin(0x4AF)
void BTA_DeviceDiscovery_StartSearchCodReq(int oh, uint32_t cod_class, uint32_t param3, int param4)
__swi_end(0x4AF, BTA_DeviceDiscovery_StartSearchCodReq, (oh, cod_class, param3, param4));

/**
 * Stop a running Bluetooth device search (asynchronous).
 * @param oh		accessor handle
 * @param tid		transaction ID
 * */
__swi_begin(0x4B0)
void BTA_DeviceDiscovery_StopSearchReq(int oh, int tid)
__swi_end(0x4B0, BTA_DeviceDiscovery_StopSearchReq, (oh, tid));

/**
 * Set the name stored in a remote-device object.
 * @param oh		accessor handle
 * @param device	remote-device object
 * @param name		UTF-8 name
 * @return result of the store, 0 on failure
 * */
__swi_begin(0x4B1)
int BTA_RemBtDeviceInfo_SetName(int oh, void *device, const char *name)
__swi_end(0x4B1, BTA_RemBtDeviceInfo_SetName, (oh, device, name));

/**
 * Get the class-of-device record of a remote-device object.
 * @param oh		accessor handle
 * @param device	remote-device object
 * @return class record (byte +2 is the major class), NULL when unknown
 * */
__swi_begin(0x4B2)
void *BTA_RemBtDeviceInfo_GetDeviceClass(int oh, void *device)
__swi_end(0x4B2, BTA_RemBtDeviceInfo_GetDeviceClass, (oh, device));

/**
 * Set the visibility of the phone's Bluetooth (asynchronous).
 * @param oh		accessor handle
 * @param visibility	visibility mode
 * @param tid		transaction ID
 * */
__swi_begin(0x4B3)
void BTA_LocBtDevice_SetVisibilityReq(int oh, uint32_t visibility, int tid)
__swi_end(0x4B3, BTA_LocBtDevice_SetVisibilityReq, (oh, visibility, tid));

/**
 * Set the inquiry access code (DIAC) the phone answers to (asynchronous).
 * @param oh		accessor handle
 * @param diac		inquiry access code
 * @param tid		transaction ID
 * */
__swi_begin(0x4B4)
void BTA_LocBtDevice_SetDIACReq(int oh, uint32_t diac, int tid)
__swi_end(0x4B4, BTA_LocBtDevice_SetDIACReq, (oh, diac, tid));

/**
 * Set the phone's Bluetooth name (asynchronous).
 * @param oh		accessor handle
 * @param name		UTF-8 name
 * @param tid		transaction ID
 * */
__swi_begin(0x4B5)
void BTA_LocBtDevice_SetNameReq(int oh, const char *name, int tid)
__swi_end(0x4B5, BTA_LocBtDevice_SetNameReq, (oh, name, tid));

/**
 * Get the SAPI application of an open connection.
 * @param oh		accessor handle
 * @param conn		connection handle
 * @return SAPI application, 0xFF when the connection is not found
 * */
__swi_begin(0x4B6)
uint32_t BTA_Conn_GetSapiApp(int oh, int conn)
__swi_end(0x4B6, BTA_Conn_GetSapiApp, (oh, conn));

/**
 * Request an SDP service record of a remote device (asynchronous). Only partly reversed.
 * @param oh		accessor handle
 * @param device	remote device
 * @param record	service record handle
 * @param param4	meaning not known
 * @param param5	meaning not known
 * @param tid		transaction ID
 * @return meaning not known
 * */
__swi_begin(0x4B7)
int BTA_ServiceSearch_RetrieveServiceReq(int oh, uint32_t device, uint32_t record, void *param4, int param5, int tid)
__swi_end(0x4B7, BTA_ServiceSearch_RetrieveServiceReq, (oh, device, record, param4, param5, tid));

/**
 * Find the JSApi (Java Bluetooth) slot of a connection handle.
 * @param conn		connection handle
 * @return slot 0..4, 5 when not registered
 * ARM code.
 * */
__swi_begin(0x4B8)
uint32_t JSApi_CurrentHandleID(int conn)
__swi_end(0x4B8, JSApi_CurrentHandleID, (conn));

/**
 * Initialise the JSApi slots once and register JSApi as SDev application 0x0F.
 * ARM code.
 * */
__swi_begin(0x4B9)
void JSApi_InitHandles(void)
__swi_end(0x4B9, JSApi_InitHandles, ());

/**
 * Register a connection handle in a free JSApi slot.
 * @param conn		connection handle
 * @param packet	0: RFCOMM stream, 1: L2CAP packets
 * @param param3	stored in the slot; meaning not known, 0 works
 * @return 1 OK, 0 when the slots are full or the handle is invalid
 * ARM code.
 * */
__swi_begin(0x4BA)
int JSApi_RegisterConHandle(int conn, uint32_t packet, uint32_t param3)
__swi_end(0x4BA, JSApi_RegisterConHandle, (conn, packet, param3));

/**
 * Get the state of a JSApi connection.
 * @param conn		connection handle
 * @return state, 0: not registered (0 and 2: no connection)
 * ARM code.
 * */
__swi_begin(0x4BB)
uint8_t JSApi_GetConnectionState(int conn)
__swi_end(0x4BB, JSApi_GetConnectionState, (conn));

/**
 * Read received data of a JSApi connection. In packet mode reads one L2CAP packet.
 * @param conn		connection handle
 * @param buffer	output buffer
 * @param size		buffer size; the rest of a longer packet is dropped
 * @return bytes read
 * ARM code.
 * */
__swi_begin(0x4BC)
int JSApi_ReadBytes(int conn, void *buffer, uint32_t size)
__swi_end(0x4BC, JSApi_ReadBytes, (conn, buffer, size));

/**
 * Get the number of received bytes waiting in a JSApi connection.
 * @param conn		connection handle
 * @return bytes available
 * ARM code.
 * */
__swi_begin(0x4BD)
int JSApi_BytesAvailable(int conn)
__swi_end(0x4BD, JSApi_BytesAvailable, (conn));

/**
 * Send data over a JSApi connection.
 * @param conn		connection handle
 * @param data		data
 * @param size		size in bytes
 * @return bytes written, less than size when the stack is busy
 * ARM code.
 * */
__swi_begin(0x4BE)
int JSApi_WriteBytes(int conn, const void *data, uint32_t size)
__swi_end(0x4BE, JSApi_WriteBytes, (conn, data, size));

/**
 * Free the JSApi slot of a connection handle and its receive buffer.
 * @param conn		connection handle
 * @return meaning not known
 * ARM code.
 * */
__swi_begin(0x4BF)
int JSApi_ClearConnectionHandle(int conn)
__swi_end(0x4BF, JSApi_ClearConnectionHandle, (conn));

/**
 * Initialise the 9 L2CAP port devices (SAPI 0x0D..0x15).
 * */
__swi_begin(0x4C0)
void BTLP_InitL2CAP_IO(void)
__swi_end(0x4C0, BTLP_InitL2CAP_IO, ());

/**
 * Send data over an L2CAP port: one buffer per packet from the shared stack pool.
 * @param data		data
 * @param size		size in bytes; more than the channel maximum is a fatal error
 * @param sapi		L2CAP port SAPI (0x0D..0x15)
 * @return bytes queued, less than size when the pool is empty
 * */
__swi_begin(0x4C1)
int BTLP_uiSendDataOverBT(const void *data, uint32_t size, int sapi)
__swi_end(0x4C1, BTLP_uiSendDataOverBT, (data, size, sapi));

/**
 * Deliver received packets queued on an L2CAP port to its application until it stops taking them.
 * @param sapi		L2CAP port SAPI (0x0D..0x15)
 * */
__swi_begin(0x4C2)
void BTLP_vDataToAppCallback(int sapi)
__swi_end(0x4C2, BTLP_vDataToAppCallback, (sapi));

/**
 * Drop the received packets queued on an L2CAP port.
 * @param mode		1 or 3 flushes, other values do nothing
 * @param sapi		L2CAP port SAPI (0x0D..0x15)
 * */
__swi_begin(0x4C3)
void BTLP_vFlushBuffer(int mode, int sapi)
__swi_end(0x4C3, BTLP_vFlushBuffer, (mode, sapi));

/**
 * L2CAP handler of the L2CA_ReadDataReq signal. Not reversed.
 * @param message	signal, meaning not known
 * */
__swi_begin(0x4C4)
void L2CA_ReadDataReq(const void *message)
__swi_end(0x4C4, L2CA_ReadDataReq, (message));

/**
 * Register an SDev application (serial data endpoint) in the application table.
 * @param handler_id	application number (0..31)
 * @param methods	method table of the application
 * ARM code.
 * */
__swi_begin(0x4C5)
void SApp_Register(int handler_id, void *methods)
__swi_end(0x4C5, SApp_Register, (handler_id, methods));

/**
 * Connect a serial device to an SDev application.
 * @param sdevice	device type (0..18)
 * @param handler_id	application number (0..31)
 * @param connection_info	connection information passed to both sides
 * @return 1 OK, 0 when either side refuses
 * ARM code.
 * */
__swi_begin(0x4C6)
int ConnSDevSApp(uint32_t sdevice, uint32_t handler_id, void *connection_info)
__swi_end(0x4C6, ConnSDevSApp, (sdevice, handler_id, connection_info));

/**
 * Move an open device connection from one SDev application to another.
 * @param handler_id	current application number (0..31)
 * @param instance	connection instance of the current application
 * @param new_handler_id	new application number (0..31), not the current one
 * @param connection_info	connection information for the new application
 * @return 1 OK, 0 error
 * ARM code.
 * */
__swi_begin(0x4C7)
int CHConnSApp(uint32_t handler_id, uint32_t instance, uint32_t new_handler_id, void *connection_info)
__swi_end(0x4C7, CHConnSApp, (handler_id, instance, new_handler_id, connection_info));

/**
 * Check whether an SDev application would accept a connection (opens and closes it again).
 * @param handler_id	application number (0..31)
 * @param instance	passed to the application's open method
 * @return 1 yes, 0 no
 * ARM code.
 * */
__swi_begin(0x4C8)
int Serial_CanOpenSApp(uint32_t handler_id, uint32_t instance)
__swi_end(0x4C8, Serial_CanOpenSApp, (handler_id, instance));

/**
 * Initialise the SIM Access Profile server and register it as SDev application 0x13.
 * */
__swi_begin(0x4C9)
void Ca_SasSApp_Init(void)
__swi_end(0x4C9, Ca_SasSApp_Init, ());

/**
 * Get the JSApi (Java Bluetooth) connection list.
 * @return list head of the JSApi connection handles
 * */
__swi_begin(0x84CA)
void *RamJSApiConnections(void)
__swi_end(0x84CA, RamJSApiConnections, ());

/**
 * Get the BTLP (Bluetooth L2CAP port) connection table.
 * @return connection table
 * */
__swi_begin(0x84CB)
void *RamBtlpConnections(void)
__swi_end(0x84CB, RamBtlpConnections, ());

/**
 * Get the L2CAP channel state table.
 * @return channel state table
 * */
__swi_begin(0x84CC)
void *RamL2capChannelState(void)
__swi_end(0x84CC, RamL2capChannelState, ());

#endif

__swilib_end

/** @} */
