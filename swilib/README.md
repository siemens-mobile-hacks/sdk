# SWILIB - functions from the firmware
Documentation by platforms:
- [SG](https://siemens-mobile-hacks.github.io/swilib/SG/index.html) - SL65, C65, CX70, ...
- [X75](https://siemens-mobile-hacks.github.io/swilib/SG_X75/index.html) - CX75, M75, CF75, ...
- [NSG](https://siemens-mobile-hacks.github.io/swilib/NSG/index.html) - C81, S75, SL75, S68, ...
- [ELKA](https://siemens-mobile-hacks.github.io/swilib/NSG_ELKA/index.html) - E71, EL71, ...

Note: Functions across platforms are mostly the same, but some structures have different memory layout.

# How add new function?
1. Fork this repository.
2. Choose right category in `include/swilib/*.h`
3. Add function definition to this file, commit changes, send PR.

Format of the function definition:
```C
/**
 * Write data to a file.
 * @param fd			file descriptor
 * @param buffer		pointer to a buffer with data to be written
 * @param length		maximum size for write
 * @param[out] err		error code
 * @return count of written bytes or error (< 0)
 * */ // <--- Short documentation in Doxygen format
__swi_begin(0x00C) // <-- swi number for IAR
int sys_write(int fd, const void *buffer, int length, uint32_t *err) // <-- function definition
__swi_end(0x00C, sys_write, (fd, buffer, length, err)); // <-- swi number for GCC and others
```

Format of the variadic function definition:
```C
/**
 * Send message to the GBS event processor.
 * You can pass up to 3 additional parameters (submsg, data0, data1 - see #GBS_MSG).
 * @param cepid		destination CEPID.
 * @param msg		ID of the message
 */ // <--- Short documentation in Doxygen format
#ifdef SWILIB_MODE_DIRECT // <-- for GCC

#define GBS_SendMessage(_cepid, _msg, ...) \
	__swi_call(0x100, void, (int cepid, int msg, ...), (_cepid, _msg, ## __VA_ARGS__)); // <-- function definition

#else // <-- for IAR

__swi_begin(0x100) // <-- swi number for IAR
void GBS_SendMessage(int cepid, int msg, ...) // <-- function definition
__swi_end(0x100, GBS_SendMessage, (cepid, msg)); // <-- swi number for others (actually stub)

#endif

```

Macroses:
- `__swi_begin(swi_num)` - macros for IAR support
  - swi_num - SWI number
- `__swi_end(swi_num, function_name, function_arguments)` - macros for GCC support
  - swi_num - SWI number
  - function_name - name of the function
  - function_arguments - list of the function arguments in braces `()`
- `__swi_call(swi_num, return_type, function_signature, function_arguments)` - variadic support for GCC
  - swi_num - SWI number
  - return_type - return type of the function
  - function_signature - function arguments definition in braces `()`
  - function_arguments - list of the function arguments in braces `()`
  
