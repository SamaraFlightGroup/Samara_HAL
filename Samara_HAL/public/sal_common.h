#ifndef SAL_COMMON_H
#define SAL_COMMON_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus

#define EXTERN_C_START \
extern "C" \
{

#define EXTERN_C_END \
}

#else

#define EXTERN_C_START

#define EXTERN_C_END

#endif


#endif