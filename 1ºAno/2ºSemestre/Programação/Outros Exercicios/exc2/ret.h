//
// Created by ASUS on 25/04/2023.
//

#ifndef EXC2_RET_H
#define EXC2_RET_H
typedef struct retangulo ret;
struct retangulo{
    int x,y,altura,largura;
};

print_ret(ret a);
init_ret(ret *a);
area_ret(ret *a);
desl_ret(ret *a, int deslx,int desly);

#endif //EXC2_RET_H
