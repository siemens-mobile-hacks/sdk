#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CPU_OSC_FREQ	26000000

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MMIO8(addr)			(*(volatile uint8_t *)(addr))
#define MMIO16(addr)		(*(volatile uint16_t *)(addr))
#define MMIO32(addr)		(*(volatile uint32_t *)(addr))
#define MMIO64(addr)		(*(volatile uint64_t *)(addr))

#define BITS_PER_LONG		32

#define BIT(n)				(1 << (n))

#define __AC(X,Y)			(X##Y)
#define _AC(X,Y)			__AC(X,Y)
#define _AT(T,X)			((T)(X))
#define UL(x)				(_AC(x, UL))
#define ULL(x)				(_AC(x, ULL))

#define GENMASK(h, l) \
	(((~UL(0)) - (UL(1) << (l)) + 1) & \
	 (~UL(0) >> (BITS_PER_LONG - 1 - (h))))

#define GENMASK_ULL(h, l) \
	(((~ULL(0)) - (ULL(1) << (l)) + 1) & \
	 (~ULL(0) >> (BITS_PER_LONG_LONG - 1 - (h))))

#define SET_BIT(value, v, shift, mask)			(value) = (((value) & ~(mask << shift)) | ((v & mask) << shift))
#define GET_BIT(value, shift, mask)				(((value) >> shift) & mask)

#ifdef NEWSGOLD
#include "pmb8876_regs.h"
#else
#include "pmb8875_regs.h"
#endif

#ifdef __cplusplus
}
#endif
