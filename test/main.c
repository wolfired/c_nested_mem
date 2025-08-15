#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sun.h"

void test_stack_obj() {
    Sun s0;
    sun_init(&s0);

    assert(NULL == s0.dat);
    assert(NULL == s0.raw);
    assert(NULL == s0.son.dat);
    assert(NULL == s0.son_ptr);

    sun_ctor(&s0, 8);

    assert(NULL != s0.dat);
    assert(NULL != s0.raw);
    assert(NULL != s0.son.dat);
    assert(NULL != s0.son_ptr);

    sun_dtor(&s0);

    assert(NULL == s0.dat);
    assert(NULL == s0.raw);
    assert(NULL == s0.son.dat);
    assert(NULL == s0.son_ptr);
}

void test_heap_obj() {
    {
        Sun* s1 = sun_new_ptr(8);

        assert(NULL != s1->dat);
        assert(NULL != s1->raw);
        assert(NULL != s1->son.dat);
        assert(NULL != s1->son_ptr);

        sun_free_pptr(&s1);

        assert(NULL == s1);
    }

    {
        Sun* s2 = NULL;
        sun_new_pptr(&s2, 8);

        assert(NULL != s2->dat);
        assert(NULL != s2->raw);
        assert(NULL != s2->son.dat);
        assert(NULL != s2->son_ptr);

        sun_free_pptr(&s2);

        assert(NULL == s2);
    }
}

int main(int argc, char const* argv[]) {
    test_stack_obj();
    test_heap_obj();
    
    return EXIT_SUCCESS;
}
