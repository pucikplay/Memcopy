#ifndef MEMCOPY_H
#define MEMCOPY_H

#include <stddef.h>

void* memcopy_uint8(void* restrict dst, const void* restrict src, size_t size);
void* memcopy_uint64(void* restrict dst, const void* restrict src, size_t size);

#endif //MEMCOPY_H