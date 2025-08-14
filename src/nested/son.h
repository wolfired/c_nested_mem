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
void   son_init(Son* inst);
int8_t son_ctor(Son* inst, size_t cap);
void   son_dtor(Son* inst);
Son*   son_new(size_t cap);
void   son_free(Son* inst);
void   son_create(Son** pinst, size_t cap);
void   son_delete(Son** pinst);

#endif
