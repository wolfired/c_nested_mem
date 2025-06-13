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
void   son_init(Son* thiz);
int8_t son_ctor(Son* thiz, size_t cap);
void   son_dtor(Son* thiz);
Son*   son_new(size_t cap);
void   son_del(Son* thiz);
void   son_make(Son** inst, size_t cap);
void   son_free(Son** inst);

#endif
