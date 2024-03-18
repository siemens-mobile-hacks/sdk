#pragma once

#if defined(__ICCARM__)
	#include "swilib/compiler/iar.h"
#elif defined(__GNUC__)
	#include "swilib/compiler/gcc.h"
#else
	#error Unknown compiler!
#endif
