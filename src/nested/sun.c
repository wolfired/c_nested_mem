#include <assert.h>

#include "sun.h"

void sun_init(Sun* ptr) {
    assert(NULL != ptr);

    ptr->cap = 0;
    ptr->dat = NULL;
    ptr->raw = NULL;
    son_init(&ptr->son);
    ptr->son_ptr = NULL;
}

int8_t sun_ctor(Sun* ptr, size_t cap) {
    assert(NULL != ptr);

    if(NULL != ptr->dat) { return -1; }
    if(NULL != ptr->raw) { return -1; }
    if(NULL != ptr->son_ptr) { return -1; }

    ptr->cap = cap;

    ptr->dat = (void*)malloc(ptr->cap);
    if(NULL == ptr->dat) { return -1; }

    ptr->raw = (void*)malloc(ptr->cap);
    if(NULL == ptr->raw) { return -1; }

    if(0 != son_ctor(&ptr->son, ptr->cap)) { return -1; }

    son_new_pptr(&ptr->son_ptr, ptr->cap);
    if(NULL == ptr->son_ptr) { return -1; }

    return 0;
}

void sun_dtor(Sun* ptr) {
    if(NULL == ptr) { return; }

    ptr->cap = 0;

    if(NULL != ptr->dat) {
        free(ptr->dat);
        ptr->dat = NULL;
    }

    if(NULL != ptr->raw) {
        free(ptr->raw);
        ptr->raw = NULL;
    }

    son_dtor(&ptr->son);

    son_free_pptr(&ptr->son_ptr);
}

Sun* sun_new_ptr(size_t cap) {
    Sun* obj = (Sun*)malloc(sizeof(Sun));
    if(NULL == obj) { return NULL; }

    sun_init(obj);

    if(0 != sun_ctor(obj, cap)) {
        sun_dtor(obj);
        free(obj);
        return NULL;
    }

    return obj;
}

void sun_free_ptr(Sun* ptr) {
    if(NULL == ptr) { return; }

    sun_dtor(ptr);
    free(ptr);
}

void sun_new_pptr(Sun** pptr, size_t cap) {
    if(NULL == pptr || NULL != *pptr) { return; }

    *pptr = sun_new_ptr(cap);
}

void sun_free_pptr(Sun** pptr) {
    if(NULL == pptr || NULL == *pptr) { return; }

    sun_free_ptr(*pptr);
    *pptr = NULL;
}
