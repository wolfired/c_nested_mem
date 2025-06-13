#include <assert.h>

#include "son.h"

void son_init(Son* thiz) {
    assert(NULL != thiz);

    thiz->cap = 0;
    thiz->dat = NULL;
}

int8_t son_ctor(Son* thiz, size_t cap) {
    assert(NULL != thiz);

    if(NULL != thiz->dat) { return -1; }

    thiz->cap = cap;

    thiz->dat = (void*)malloc(thiz->cap);
    if(NULL == thiz->dat) { return -1; }

    return 0;
}

void son_dtor(Son* thiz) {
    if(NULL == thiz) { return; }

    thiz->cap = 0;

    if(NULL != thiz->dat) {
        free(thiz->dat);
        thiz->dat = NULL;
    }
}

Son* son_new(size_t cap) {
    Son* obj = (Son*)malloc(sizeof(Son));
    if(NULL == obj) { return NULL; }

    son_init(obj);

    if(0 != son_ctor(obj, cap)) {
        son_dtor(obj);
        free(obj);
        return NULL;
    }

    return obj;
}

void son_del(Son* thiz) {
    if(NULL == thiz) { return; }

    son_dtor(thiz);
    free(thiz);
}

void son_make(Son** inst, size_t cap) {
    if(NULL == inst || NULL != *inst) { return; }

    *inst = son_new(cap);
}

void son_free(Son** inst) {
    if(NULL == inst || NULL == *inst) { return; }

    son_del(*inst);
    *inst = NULL;
}
