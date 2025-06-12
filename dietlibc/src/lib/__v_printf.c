#include "dietfeatures.h"
#include <stdarg.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "dietstdio.h"
#include "dietwarning.h"
#include "printf/printf.h"

#define MAX_WIDTH 10*1024

static inline void _out_fn(char character, void *data) {
	struct arg_printf *fn = data;
	fn->put(&character, 1, fn->data);
}

int __v_printf(struct arg_printf *fn, const char *format, va_list arg_ptr) {
	return __vsnprintf_impl(_out_fn, fn, format, arg_ptr);
}
