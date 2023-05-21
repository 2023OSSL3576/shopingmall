#include "stdio.h"
#include "stdlib.h"
#include "User/user.h"
//#include "Product/product.h"
#define max 50

int main(void){
    User *u[max]; //수정
    int Umenu;
    int count;

    for(int i=0; i<max; i++){
        u[i] = (User*)malloc(sizeof(User));
    }

    count = loadUser(u);
}