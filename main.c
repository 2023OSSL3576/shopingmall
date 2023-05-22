#include <stdio.h>
#include <stdlib.h>
#include "User/user.h"
#include "Product/product.h"
#define max 30

int main(void){
    User *u[max];
    int Umenu;
    int count = 0;
    int checkSignIn = 0;

    for(int i=0; i<max; i++){
        u[i] = (User*)malloc(sizeof(User));
    }

    count = loadUser(u);

    while(1){
        Umenu = userMenu();
        if(Umenu==0) break;
        if(Umenu==1) {
            checkSignIn = signIn(u, count);
            if(checkSignIn==1) break;
        }
        else if(Umenu==2) count = signUp(u, count);
        else if(Umenu==3) updateUser(u, count);
        else if(Umenu==4) withdrawal(u, count);
    }
    free(*u);
    if(checkSignIn==0){
        printf("종료되었습니다.\n");
        return 0;
    }
}