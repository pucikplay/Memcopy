#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "memcopy.h"

int main(void)
{
    printf("This is a driver program for memcopy\n");

    char* s1 = "Some string";
    char* s2 = malloc(strlen(s1) + 1);

    memcopy_uint64(s2, s1, strlen(s1) + 1);

    printf("s1: %s, s2: %s\n", s1, s2);

    free(s2);
}