#ifndef __MDFN_TYPES
#define __MDFN_TYPES

#include <assert.h>
#include <stdint.h>

#ifndef __cplusplus
#if defined(_MSC_VER) && !defined(SN_TARGET_PS3)
/* Hack applied for MSVC when compiling in C89 mode
 * as it isn't C99-compliant. */
#define bool unsigned char
#define true 1
#define false 0
#else
#include <stdbool.h>
#endif
#endif

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32; 
typedef int64_t int64;

typedef uint8_t uint8;  
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

#ifdef __GNUC__
#define MDFN_UNLIKELY(n) __builtin_expect((n) != 0, 0)
#define MDFN_LIKELY(n) __builtin_expect((n) != 0, 1)

  #define inline     inline __attribute__((always_inline))
  #define NO_INLINE  __attribute__((noinline))

  #if defined(__386__) || defined(__i386__) || defined(__i386) || defined(_M_IX86) || defined(_M_I386)
    #define MDFN_FASTCALL __attribute__((fastcall))
  #else
    #define MDFN_FASTCALL
  #endif

  #define MDFN_ALIGN(n)	__attribute__ ((aligned (n)))
  #define MDFN_FORMATSTR(a,b,c) __attribute__ ((format (a, b, c)));
  #define MDFN_WARN_UNUSED_RESULT __attribute__ ((warn_unused_result))
  #define MDFN_NOWARN_UNUSED __attribute__((unused))

#elif defined(_MSC_VER)
#define roundf(in) (in >= 0.0f ? floorf(in + 0.5f) : ceilf(in - 0.5f))
  #define NO_INLINE
#define MDFN_LIKELY(n) ((n) != 0)
#define MDFN_UNLIKELY(n) ((n) != 0)

  #define MDFN_FASTCALL

  #define MDFN_ALIGN(n) __declspec(align(n))

  #define MDFN_FORMATSTR(a,b,c)

  #define MDFN_WARN_UNUSED_RESULT
  #define MDFN_NOWARN_UNUSED

#else
  #error "Not compiling with GCC nor MSVC"
  #define inline inline
  #define NO_INLINE

  #define MDFN_FASTCALL

  #define MDFN_ALIGN(n)	// hence the #error.

  #define MDFN_FORMATSTR(a,b,c)

  #define MDFN_WARN_UNUSED_RESULT

#endif


#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#if !defined(MSB_FIRST) && !defined(LSB_FIRST)
 #error "Define MSB_FIRST or LSB_FIRST!"
#endif

#endif