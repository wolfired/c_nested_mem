#include <assert.h>

#include "son.h"

void son_init(Son* ptr) {
    assert(NULL != ptr);

    ptr->cap = 0;
    ptr->dat = NULL;
}

int8_t son_ctor(Son* ptr, size_t cap) {
    assert(NULL != ptr);

    if(NULL != ptr->dat) { return -1; }

    ptr->cap = cap;

    ptr->dat = (void*)malloc(ptr->cap);
    if(NULL == ptr->dat) { return -1; }

    return 0;
}

void son_dtor(Son* ptr) {
    if(NULL == ptr) { return; }

    ptr->cap = 0;

    if(NULL != ptr->dat) {
        free(ptr->dat);
        ptr->dat = NULL;
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

void son_free(Son* ptr) {
    if(NULL == ptr) { return; }

    son_dtor(ptr);
    free(ptr);
}

void son_create(Son** pptr, size_t cap) {
    if(NULL == pptr || NULL != *pptr) { return; }

    *pptr = son_new(cap);
}

void son_delete(Son** pptr) {
    if(NULL == pptr || NULL == *pptr) { return; }

    son_free(*pptr);
    *pptr = NULL;
}
