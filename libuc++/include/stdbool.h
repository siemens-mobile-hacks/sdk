// -*- C++ -*-
//===--------------------------- stdbool.h --------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef _LIBCPP_STDBOOL_H
#define _LIBCPP_STDBOOL_H


/*
    stdbool.h synopsis

Macros:

    __bool_true_false_are_defined

*/

#include_next <stdbool.h>

#ifdef __cplusplus
#undef bool
#undef true
#undef false
#undef __bool_true_false_are_defined
#define __bool_true_false_are_defined 1
#endif

#endif  // _LIBCPP_STDBOOL_H
