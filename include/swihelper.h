
#ifndef __SWI_HELPER_H__
#define __SWI_HELPER_H__

#ifdef __cplusplus
extern "C" const int __sys_switab_addres[];
#else
extern const int __sys_switab_addres[];
#endif
#define __inl static inline

#ifndef __USE_SWI

#ifdef __cplusplus

//#define __def(id, ret, ...) { return ((ret (*)(...))((__sys_switab_addres[id])))(__VA_ARGS__); }
#define __def(id, ret, ...) \
  {\
      if(id >= 0x8000)\
        return (ret)(__sys_switab_addres[id-0x8000]); \
      else\
        return ((ret (*)(...))((__sys_switab_addres[id])))(__VA_ARGS__); \
  }\

#define __defn(id, ...) { ((void (*)(...))((__sys_switab_addres[id])))(__VA_ARGS__); }

#define __cdef(id, ret, ...) (ret)((ret (*)(...))((__sys_switab_addres[id])))(__VA_ARGS__)
#define __cdefn(id, ...) ((void (*)(...))((__sys_switab_addres[id])))(__VA_ARGS__)

#define __nul_def(id, ret) { return ((ret (*)())((__sys_switab_addres[id])))(); }
#define __nul_defn(id) { ((void (*)())((__sys_switab_addres[id])))(); }

#define __def_noinline(id, ret, ...) \
      if(id >= 0x8000)\
        return (ret)(__sys_switab_addres[id-0x8000]); \
      else\
        return ((ret (*)(...))((__sys_switab_addres[id])))(__VA_ARGS__); \

//#define __ldr(id, ret) { return (ret)(__sys_switab_addres[id-0x8000]); }

#else

//#define __def(id, ret, ...) { return ((ret (*)())((__sys_switab_addres[id])))(__VA_ARGS__); }
#define __def(id, ret, ...) \
  {\
      if(id >= 0x8000)\
        return (ret)(__sys_switab_addres[id-0x8000]); \
      else\
        return ((ret (*)())((__sys_switab_addres[id])))(__VA_ARGS__); \
  }\

#define __defn(id, ...) { ((void (*)())((__sys_switab_addres[id])))(__VA_ARGS__); }

/* РёСЃРїРѕР»СЊР·РѕРІР°С‚СЊ РґР»СЏ С„СѓРЅРєС†РёР№ С‚РёРїР° sprintf, РЅРѕ РЅРµ СЋР·Р°С‚СЊ РґР»СЏ СЂР°РјРЅС‹С… С„СѓРЅРєС†РёР№! */
#define __cdef(id, ret, ...) (ret)((ret (*)())((__sys_switab_addres[id])))(__VA_ARGS__)
#define __cdefn(id, ...) ((void (*)())((__sys_switab_addres[id])))(__VA_ARGS__)

#define __nul_def(id, ret) { return ((ret (*)())((__sys_switab_addres[id])))(); }

#define __def_noinline(id, ret, ...) \
      if(id >= 0x8000)\
        return (ret)(__sys_switab_addres[id-0x8000]); \
      else\
        return ((ret (*)())((__sys_switab_addres[id])))(__VA_ARGS__); \

#define __nul_defn(id) { ((void (*)())((__sys_switab_addres[id])))(); }

//#define __ldr(id, ret) { return (ret)(__sys_switab_addres[id-0x8000]); }

#endif

#endif



#endif
