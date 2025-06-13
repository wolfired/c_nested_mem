#include <assert.h>

#include "sun.h"

void sun_init(Sun* thiz) {
    assert(NULL != thiz);

    thiz->cap = 0;
    thiz->dat = NULL;
    thiz->raw = NULL;
    son_init(&thiz->son);
    thiz->son_ptr = NULL;
}

int8_t sun_ctor(Sun* thiz, size_t cap) {
    assert(NULL != thiz);

    if(NULL != thiz->dat) { return -1; }
    if(NULL != thiz->raw) { return -1; }
    if(NULL != thiz->son_ptr) { return -1; }

    thiz->cap = cap;

    thiz->dat = (void*)malloc(thiz->cap);
    if(NULL == thiz->dat) { return -1; }

    thiz->raw = (void*)malloc(thiz->cap);
    if(NULL == thiz->raw) { return -1; }

    if(0 != son_ctor(&thiz->son, thiz->cap)) { return -1; }

    son_make(&thiz->son_ptr, thiz->cap);
    if(NULL == thiz->son_ptr) { return -1; }

    return 0;
}

void sun_dtor(Sun* thiz) {
    if(NULL == thiz) { return; }

    thiz->cap = 0;

    if(NULL != thiz->dat) {
        free(thiz->dat);
        thiz->dat = NULL;
    }

    if(NULL != thiz->raw) {
        free(thiz->raw);
        thiz->raw = NULL;
    }

    son_dtor(&thiz->son);

    son_free(&thiz->son_ptr);
}

Sun* sun_new(size_t cap) {
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

void sun_del(Sun* thiz) {
    if(NULL == thiz) { return; }

    sun_dtor(thiz);
    free(thiz);
}

void sun_make(Sun** inst, size_t cap) {
    if(NULL == inst || NULL != *inst) { return; }

    *inst = sun_new(cap);
}

void sun_free(Sun** inst) {
    if(NULL == inst || NULL == *inst) { return; }

    sun_del(*inst);
    *inst = NULL;
}
