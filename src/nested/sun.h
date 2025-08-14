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
void   sun_init(Sun* inst);
int8_t sun_ctor(Sun* inst, size_t cap);
void   sun_dtor(Sun* inst);
Sun*   sun_new(size_t cap);
void   sun_free(Sun* inst);
void   sun_create(Sun** pinst, size_t cap);
void   sun_delete(Sun** pinst);

#endif

