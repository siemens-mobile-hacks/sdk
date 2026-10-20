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
__swi_begin(0xB00)
int BtAccessor_New(int cepid, int msg, int no_servers, int zero)
__swi_end(0xB00, BtAccessor_New, (cepid, msg, no_servers, zero));

/**
 * Delete a Bluetooth accessor after closing its connections and servers.
 * @param oh		accessor handle
 * */
__swi_begin(0xB01)
void BtAccessor_Delete(int oh)
__swi_end(0xB01, BtAccessor_Delete, (oh));

/**
 * Read the Bluetooth event identifier from an accessor event object.
 * @param ev		event object from the accessor message
 * @return event identifier; its low byte selects the event
 * */
__swi_begin(0xB02)
uint32_t BTA_ObjMsg(void *ev)
__swi_end(0xB02, BTA_ObjMsg, (ev));

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
__swi_begin(0xB04)
int BTA_Server_New(int oh, int proto, int master, int encrypt, int authenticate, int authorize, int rx_mtu, int tx_mtu, int tid)
__swi_end(0xB04, BTA_Server_New, (oh, proto, master, encrypt, authenticate, authorize, rx_mtu, tx_mtu, tid));

/**
 * Start a Bluetooth server and publish its SDP record.
 * @param oh		accessor handle
 * @param server		server handle
 * @param sdp_record	SDP record handle
 * @param unk		set to 0
 * @param tid		transaction identifier
 * */
__swi_begin(0xB05)
void BTA_Server_StartReq(int oh, int server, int sdp_record, int unk, int tid)
__swi_end(0xB05, BTA_Server_StartReq, (oh, server, sdp_record, unk, tid));

/**
 * Enable or disable incoming connections on a Bluetooth server.
 * @param oh		accessor handle
 * @param server		server handle
 * @param enable		1 to accept incoming connections, 0 to stop accepting
 * @param tid		transaction identifier
 * */
__swi_begin(0xB06)
void BTA_Server_AcceptReq(int oh, int server, int enable, int tid)
__swi_end(0xB06, BTA_Server_AcceptReq, (oh, server, enable, tid));

/**
 * Request asynchronous stop of a Bluetooth server.
 * @param oh		accessor handle
 * @param server		server handle
 * @param tid		transaction identifier
 * */
__swi_begin(0xB07)
void BTA_Server_StopReq(int oh, int server, int tid)
__swi_end(0xB07, BTA_Server_StopReq, (oh, server, tid));

/**
 * Delete a stopped Bluetooth server.
 * @param oh		accessor handle
 * @param server		server handle
 * */
__swi_begin(0xB08)
void BTA_Server_Delete(int oh, int server)
__swi_end(0xB08, BTA_Server_Delete, (oh, server));

/**
 * Set allocator callbacks for accessor SDP records.
 * @param oh		accessor handle
 * @param alloc		allocator used for SDP data
 * @param free		matching deallocator
 * */
__swi_begin(0xB09)
void BTA_Sdp_Converter_New(int oh, void *(*alloc)(unsigned int), void (*free)(void *))
__swi_end(0xB09, BTA_Sdp_Converter_New, (oh, alloc, free));

/**
 * Create a Bluetooth SDP service record.
 * @param oh		accessor handle
 * @param uuid		16-byte service UUID, most significant byte first
 * @param proto		1 for RFCOMM, 0 for L2CAP
 * @param channel		RFCOMM channel or L2CAP PSM
 * @return SDP record handle
 * */
__swi_begin(0xB0A)
int BTA_SdpRec_New(int oh, const uint8_t uuid[16], int proto, int channel)
__swi_end(0xB0A, BTA_SdpRec_New, (oh, uuid, proto, channel));

/**
 * Delete an accessor SDP record.
 * @param oh		accessor handle
 * @param record		SDP record handle
 * */
__swi_begin(0xB0B)
void BTA_SdpRec_Delete(int oh, int record)
__swi_end(0xB0B, BTA_SdpRec_Delete, (oh, record));

/**
 * Request asynchronous closure of a Bluetooth connection.
 * @param oh		accessor handle
 * @param conn		connection handle
 * @param tid		transaction identifier
 * */
__swi_begin(0xB0C)
void BTA_Conn_CloseReq(int oh, int conn, int tid)
__swi_end(0xB0C, BTA_Conn_CloseReq, (oh, conn, tid));

/**
 * Get the local Bluetooth address.
 * @return pointer to six bytes, least significant byte first, or NULL if unavailable
 * */
__swi_begin(0xB0D)
const uint8_t *BT_GetLocAddr(void)
__swi_end(0xB0D, BT_GetLocAddr, ());

/**
 * Initialize an SDev endpoint with the firmware default callbacks.
 * @param ep		endpoint storage owned by the caller
 * */
__swi_begin(0xB0E)
void SDev_InitEndpoint(SDEV *ep)
__swi_end(0xB0E, SDev_InitEndpoint, (ep));

/**
 * Get the native local Bluetooth device object.
 * @return firmware-owned device object. Its layout is firmware-specific
 * */
__swi_begin(0xB0F)
uint8_t *BT_GetLocalDevice(void)
__swi_end(0xB0F, BT_GetLocalDevice, ());

/**
 * Set the local Bluetooth connection security level.
 * @param lo		0 selects high security; nonzero selects low security
 * @param unk1		reserved; pass 0
 * @param unk2		reserved; pass 0
 * @param unk3		reserved; pass 0
 * */
__swi_begin(0xB10)
void BT_SetSecurityCheck(int lo, int unk1, int unk2, int unk3)
__swi_end(0xB10, BT_SetSecurityCheck, (lo, unk1, unk2, unk3));

/**
 * Get the SDev application callback table.
 * @return firmware-owned table of 32 application pointers
 * */
__swi_begin(0x8B11)
void **RamSDevApps(void)
__swi_end(0x8B11, RamSDevApps, ());

/**
 * Get the native Bluetooth buffer-pool status.
 * @return status words; words 0 and 1 count free receive and transmit buffers
 * */
__swi_begin(0x8B12)
uint16_t *RamBtBufferPool(void)
__swi_end(0x8B12, RamBtBufferPool, ());

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
__swi_begin(0xB13)
int BTA_Conn_New_L2CAP(int oh, const uint8_t addr[6], int sapi_type, int psm, int master, int encrypt, int authenticate, int rx_mtu, int tx_mtu, int tid)
__swi_end(0xB13, BTA_Conn_New_L2CAP, (oh, addr, sapi_type, psm, master, encrypt, authenticate, rx_mtu, tx_mtu, tid));

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
__swi_begin(0xB31)
int BTA_Conn_New_RFCOMM(int oh, const uint8_t addr[8], int sapi_type, int channel, int master, int encrypt, int authenticate, int tid)
__swi_end(0xB31, BTA_Conn_New_RFCOMM, (oh, addr, sapi_type, channel, master, encrypt, authenticate, tid));

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
__swi_begin(0xB32)
int BTA_ServiceSearch_StartReq(int oh, const uint8_t addr[8], const void *uuids, const uint16_t *attrs, int nattrs, int tid)
__swi_end(0xB32, BTA_ServiceSearch_StartReq, (oh, addr, uuids, attrs, nattrs, tid));

/**
 * Cancel a running service search.
 * @param oh		accessor handle
 * @param remdev	remote device handle from BTA_ServiceSearch_StartReq
 * @param tid		transaction id
 * @platforms ELKA
 * */
__swi_begin(0xB33)
void BTA_ServiceSearch_StopReq(int oh, int remdev, int tid)
__swi_end(0xB33, BTA_ServiceSearch_StopReq, (oh, remdev, tid));

/**
 * Server channel from an SDP record's ProtocolDescriptorList.
 * @param record	record from message 0x0F (+20)
 * @param rfcomm	1: RFCOMM channel, 0: L2CAP PSM
 * @return channel / PSM, 0 if the record has none
 * @platforms ELKA
 * */
__swi_begin(0xB34)
unsigned BTA_SdpRec_GetChannel(const void *record, int rfcomm)
__swi_end(0xB34, BTA_SdpRec_GetChannel, (record, rfcomm));

/**
 * Open a view of the stored Bluetooth device list.
 * @param oh		accessor handle
 * @param type		list type, 0: stored devices
 * @return device-list handle
 * */
__swi_begin(0xB27)
int BTA_DeviceListView_GetList(int oh, int type)
__swi_end(0xB27, BTA_DeviceListView_GetList, (oh, type));

/**
 * Count entries in a Bluetooth device-list view.
 * @param oh		accessor handle
 * @param list		device-list handle
 * @return number of entries
 * */
__swi_begin(0xB28)
int BTA_DeviceListView_GetNumberOfEntries(int oh, int list)
__swi_end(0xB28, BTA_DeviceListView_GetNumberOfEntries, (oh, list));

/**
 * Request a stored Bluetooth device entry asynchronously.
 * @param oh		accessor handle
 * @param list		device-list handle
 * @param index		zero-based entry index
 * @param tid		transaction identifier returned with the entry
 * */
__swi_begin(0xB29)
void BTA_DeviceListView_GetEntryReq(int oh, int list, int index, int tid)
__swi_end(0xB29, BTA_DeviceListView_GetEntryReq, (oh, list, index, tid));

/**
 * Close a Bluetooth device-list view.
 * @param oh		accessor handle
 * @param list		device-list handle
 * */
__swi_begin(0xB2A)
void BTA_DeviceListView_StopList(int oh, int list)
__swi_end(0xB2A, BTA_DeviceListView_StopList, (oh, list));

/**
 * Read the Bluetooth address from a returned remote-device object.
 * @param oh		accessor handle
 * @param device		remote-device object from the list-entry event
 * @return six-byte address, least significant byte first. Copy before consuming the event
 * */
__swi_begin(0xB2B)
const uint8_t *BTA_RemBtDeviceInfo_GetAddress(int oh, const void *device)
__swi_end(0xB2B, BTA_RemBtDeviceInfo_GetAddress, (oh, device));

/**
 * Read the name from a returned remote-device object.
 * @param oh		accessor handle
 * @param device		remote-device object from the list-entry event
 * @return UTF-8 device name. Copy before consuming the event
 * */
__swi_begin(0xB2C)
const char *BTA_RemBtDeviceInfo_GetName(int oh, const void *device)
__swi_end(0xB2C, BTA_RemBtDeviceInfo_GetName, (oh, device));

#endif

__swilib_end

/** @} */
