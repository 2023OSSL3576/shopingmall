#include "stdio.h"
#include "stdlib.h"
#include "User/user.h"
//#include "product.h"

int main(void){
    User *u[50]; //수정
    int Umenu;

    int count = loadUserNumber();
    printf("%d", count);
    for(int i=0; i<count; i++){
        u[i] = (User*)malloc(sizeof(User));
    }

    loadUser(u);
}