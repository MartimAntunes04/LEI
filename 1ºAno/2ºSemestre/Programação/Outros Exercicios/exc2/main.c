#include <stdio.h>
#include "ret.h"

int main() {
    ret ret1={1,2,4,4},ret2;

    print_ret(ret1);

    init_ret(&ret2);

    printf("Area: %d", area_ret(&ret2));

    desl_ret(&ret2,1,1);
}
