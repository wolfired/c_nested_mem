#include <assert.h>

#include "sun.h"

void sun_init(Sun* inst) {
    assert(NULL != inst);

    inst->cap = 0;
    inst->dat = NULL;
    inst->raw = NULL;
    son_init(&inst->son);
    inst->son_ptr = NULL;
}

int8_t sun_ctor(Sun* inst, size_t cap) {
    assert(NULL != inst);

    if(NULL != inst->dat) { return -1; }
    if(NULL != inst->raw) { return -1; }
    if(NULL != inst->son_ptr) { return -1; }

    inst->cap = cap;

    inst->dat = (void*)malloc(inst->cap);
    if(NULL == inst->dat) { return -1; }

    inst->raw = (void*)malloc(inst->cap);
    if(NULL == inst->raw) { return -1; }

    if(0 != son_ctor(&inst->son, inst->cap)) { return -1; }

    son_create(&inst->son_ptr, inst->cap);
    if(NULL == inst->son_ptr) { return -1; }

    return 0;
}

void sun_dtor(Sun* inst) {
    if(NULL == inst) { return; }

    inst->cap = 0;

    if(NULL != inst->dat) {
        free(inst->dat);
        inst->dat = NULL;
    }

    if(NULL != inst->raw) {
        free(inst->raw);
        inst->raw = NULL;
    }

    son_dtor(&inst->son);

    son_delete(&inst->son_ptr);
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

void sun_free(Sun* inst) {
    if(NULL == inst) { return; }

    sun_dtor(inst);
    free(inst);
}

void sun_create(Sun** pinst, size_t cap) {
    if(NULL == pinst || NULL != *pinst) { return; }

    *pinst = sun_new(cap);
}

void sun_freeete(Sun** pinst) {
    if(NULL == pinst || NULL == *pinst) { return; }

    sun_free(*pinst);
    *pinst = NULL;
}
