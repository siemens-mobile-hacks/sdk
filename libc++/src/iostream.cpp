//===------------------------ iostream.cpp --------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "__std_stream"
#include "string"
#include "new"

_LIBCPP_BEGIN_NAMESPACE_STD

#ifndef _LIBCPP_HAS_NO_STDIN
_ALIGNAS_TYPE (istream) _LIBCPP_FUNC_VIS char cin[sizeof(istream)]
#if defined(_MSC_VER) && defined(__clang__)
__asm__("?cin@__1@std@@3V?$basic_istream@DU?$char_traits@D@__1@std@@@12@A")
#endif
;
_ALIGNAS_TYPE (__stdinbuf<char> ) static char __cin[sizeof(__stdinbuf <char>)];
#ifndef _LIBCPP_HAS_NO_WIDE_CHARACTERS
static mbstate_t mb_cin;
_ALIGNAS_TYPE (wistream) _LIBCPP_FUNC_VIS char wcin[sizeof(wistream)]
#if defined(_MSC_VER) && defined(__clang__)
__asm__("?wcin@__1@std@@3V?$basic_istream@_WU?$char_traits@_W@__1@std@@@12@A")
#endif
;
_ALIGNAS_TYPE (__stdinbuf<wchar_t> ) static char __wcin[sizeof(__stdinbuf <wchar_t>)];
static mbstate_t mb_wcin;
#endif
#endif

#ifndef _LIBCPP_HAS_NO_STDOUT
_ALIGNAS_TYPE (ostream) _LIBCPP_FUNC_VIS char cout[sizeof(ostream)]
#if defined(_MSC_VER) && defined(__clang__)
__asm__("?cout@__1@std@@3V?$basic_ostream@DU?$char_traits@D@__1@std@@@12@A")
#endif
;
_ALIGNAS_TYPE (__stdoutbuf<char>) static char __cout[sizeof(__stdoutbuf<char>)];
#ifndef _LIBCPP_HAS_NO_WIDE_CHARACTERS
static mbstate_t mb_cout;
_ALIGNAS_TYPE (wostream) _LIBCPP_FUNC_VIS char wcout[sizeof(wostream)]
#if defined(_MSC_VER) && defined(__clang__)
__asm__("?wcout@__1@std@@3V?$basic_ostream@_WU?$char_traits@_W@__1@std@@@12@A")
#endif
;
_ALIGNAS_TYPE (__stdoutbuf<wchar_t>) static char __wcout[sizeof(__stdoutbuf<wchar_t>)];
static mbstate_t mb_wcout;
#endif
#endif

_ALIGNAS_TYPE (ostream) _LIBCPP_FUNC_VIS char cerr[sizeof(ostream)]
#if defined(_MSC_VER) && defined(__clang__)
__asm__("?cerr@__1@std@@3V?$basic_ostream@DU?$char_traits@D@__1@std@@@12@A")
#endif
;
_ALIGNAS_TYPE (__stdoutbuf<char>) static char __cerr[sizeof(__stdoutbuf<char>)];
#ifndef _LIBCPP_HAS_NO_WIDE_CHARACTERS
static mbstate_t mb_cerr;
_ALIGNAS_TYPE (wostream) _LIBCPP_FUNC_VIS char wcerr[sizeof(wostream)]
#if defined(_MSC_VER) && defined(__clang__)
__asm__("?wcerr@__1@std@@3V?$basic_ostream@_WU?$char_traits@_W@__1@std@@@12@A")
#endif
;
#endif
_ALIGNAS_TYPE (__stdoutbuf<wchar_t>) static char __wcerr[sizeof(__stdoutbuf<wchar_t>)];
static mbstate_t mb_wcerr;

_ALIGNAS_TYPE (ostream) _LIBCPP_FUNC_VIS char clog[sizeof(ostream)]
#if defined(_MSC_VER) && defined(__clang__)
__asm__("?clog@__1@std@@3V?$basic_ostream@DU?$char_traits@D@__1@std@@@12@A")
#endif
;
#ifndef _LIBCPP_HAS_NO_WIDE_CHARACTERS
_ALIGNAS_TYPE (wostream) _LIBCPP_FUNC_VIS char wclog[sizeof(wostream)]
#if defined(_MSC_VER) && defined(__clang__)
__asm__("?wclog@__1@std@@3V?$basic_ostream@_WU?$char_traits@_W@__1@std@@@12@A")
#endif
;
#endif

ios_base::Init __start_std_streams;

ios_base::Init::Init()
{
#ifndef _LIBCPP_HAS_NO_STDIN
    istream* cin_ptr  = ::new(cin)  istream(::new(__cin)  __stdinbuf <char>(stdin, &mb_cin));
#ifndef _LIBCPP_HAS_NO_WIDE_CHARACTERS
    wistream* wcin_ptr  = ::new(wcin)  wistream(::new(__wcin)  __stdinbuf <wchar_t>(stdin, &mb_wcin));
#endif
#endif
#ifndef _LIBCPP_HAS_NO_STDOUT
    ostream* cout_ptr = ::new(cout) ostream(::new(__cout) __stdoutbuf<char>(stdout, &mb_cout));
#ifndef _LIBCPP_HAS_NO_WIDE_CHARACTERS
    wostream* wcout_ptr = ::new(wcout) wostream(::new(__wcout) __stdoutbuf<wchar_t>(stdout, &mb_wcout));
#endif
#endif
    ostream* cerr_ptr = ::new(cerr) ostream(::new(__cerr) __stdoutbuf<char>(stderr, &mb_cerr));
                        ::new(clog) ostream(cerr_ptr->rdbuf());
#ifndef _LIBCPP_HAS_NO_WIDE_CHARACTERS
    wostream* wcerr_ptr = ::new(wcerr) wostream(::new(__wcerr) __stdoutbuf<wchar_t>(stderr, &mb_wcerr));
                          ::new(wclog) wostream(wcerr_ptr->rdbuf());
#endif
#if !defined(_LIBCPP_HAS_NO_STDIN) && !defined(_LIBCPP_HAS_NO_STDOUT)
    cin_ptr->tie(cout_ptr);
    wcin_ptr->tie(wcout_ptr);
#endif
    _VSTD::unitbuf(*cerr_ptr);
    _VSTD::unitbuf(*wcerr_ptr);
#ifndef _LIBCPP_HAS_NO_STDOUT
    cerr_ptr->tie(cout_ptr);
    wcerr_ptr->tie(wcout_ptr);
#endif
}

ios_base::Init::~Init()
{
#ifndef _LIBCPP_HAS_NO_STDOUT
    ostream* cout_ptr = reinterpret_cast<ostream*>(cout);
    wostream* wcout_ptr = reinterpret_cast<wostream*>(wcout);
    cout_ptr->flush();
    wcout_ptr->flush();
#endif

    ostream* clog_ptr = reinterpret_cast<ostream*>(clog);
    wostream* wclog_ptr = reinterpret_cast<wostream*>(wclog);
    clog_ptr->flush();
    wclog_ptr->flush();
}

_LIBCPP_END_NAMESPACE_STD
