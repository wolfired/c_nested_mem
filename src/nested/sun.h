#ifndef SUN_H
#define SUN_H

#include <stdint.h>
#include <stdlib.h>

#include "son.h"

typedef struct Sun_ {
    size_t cap;
    void*  dat;
    void*  raw;
    Son    son;
    Son*   son_ptr;
} Sun;

/**
 * 初始化函数只能调用一次
 */
void   sun_init(Sun* ptr);
int8_t sun_ctor(Sun* ptr, size_t cap);
void   sun_dtor(Sun* ptr);
Sun*   sun_new(size_t cap);
void   sun_free(Sun* ptr);
void   sun_create(Sun** pptr, size_t cap);
void   sun_delete(Sun** pptr);

#endif

