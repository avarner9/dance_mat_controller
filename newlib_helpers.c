//#include <stdio.h>
//#include <errno.h>

#include "uart.h"
/*

#define NEWLIB_HEAP_SIZE (50000)
char newlib_heap[NEWLIB_HEAP_SIZE];
char * sbrk_ptr = newlib_heap;


void * _sbrk(intptr_t incr)
{
    sbrk_ptr += incr;
    return sbrk_ptr;
}

ssize_t _write(__attribute__((__unused__)) int fd, const void * buf_, size_t count)
{
    const char * buf = (const char *)buf_;
    for (size_t i = 0; i < count; i++)
    {
        print_char(buf[i]);
    }
    return count;
}

int _close(__attribute__((__unused__)) int fd)
{
    errno = EBADF;
    return -1;
}
int _fstat(__attribute__((__unused__)) int fd, __attribute__((__unused__)) void * statbuf)
{
    errno = EBADF;
    return -1;
}
int _isatty(__attribute__((__unused__)) int fd)
{
    return 1;
}
int _lseek(__attribute__((__unused__)) int fd, __attribute__((__unused__)) off_t offset, __attribute__((__unused__)) int whence)
{
    errno = ESPIPE;
    return -1;
}
int _read(__attribute__((__unused__)) int fd, __attribute__((__unused__)) void * buf, __attribute__((__unused__)) size_t count)
{
    errno = EWOULDBLOCK;
    return -1;
}

*/

