#ifndef SON_H
#define SON_H

#include <stdint.h>
#include <stdlib.h>

typedef struct Son_ {
    size_t cap;
    void*  dat;
} Son;

/**
 * 初始化函数只能调用一次
 */
void   son_init(Son* ptr);
int8_t son_ctor(Son* ptr, size_t cap);
void   son_dtor(Son* ptr);
Son*   son_new_ptr(size_t cap);
void   son_free_ptr(Son* ptr);
void   son_new_pptr(Son** pptr, size_t cap);
void   son_free_pptr(Son** pptr);

#endif
