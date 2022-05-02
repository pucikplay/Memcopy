#include "memcopy.h"

#include <stddef.h>
#include <stdint.h>

void* memcopy_uint8(void* restrict dst, const void* restrict src, size_t size)
{
    if (!dst || !src)
        return 0;
    
    if (size == 0)
        return dst;

    uint8_t* restrict _dst = (uint8_t*)dst;
    const uint8_t* restrict _src = (const uint8_t*)src;

    for (size_t i = 0; i < size; i++)
        _dst[i] = _src[i];

    return dst;
}

void* memcopy_uint64(void* restrict dst, const void* restrict src, size_t size)
{
    if (!dst || !src)
        return 0;
    
    if (size == 0)
        return dst;

    uint64_t* restrict _dst = (uint64_t*)dst;
    const uint64_t* restrict _src = (const uint64_t*)src;
    size_t no_of_uint64_parts = size / sizeof(uint64_t);
    size_t size_left = size % sizeof(uint64_t);

    for (size_t i = 0; i < no_of_uint64_parts; i++)
        _dst[i] = _src[i];

    memcopy_uint8(&_dst[no_of_uint64_parts], &_src[no_of_uint64_parts], size_left);

    return dst;
}