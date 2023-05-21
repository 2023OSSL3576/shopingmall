#include "stdio.h"
#include "stdlib.h"
#include "User/user.h"
//#include "Product/product.h"
#define max 50

int main(void){
    /////////////////////////////////////////////////////////////////////////////////////////////
    //로그인 시스템
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
        }
        else if(Umenu==2) count = signUp(u, count);
        else if(Umenu==3) withdrawal(u, count);
    }
    free(*u);
    if(checkSignIn==0){
        printf("\n종료되었습니다.\n");
        return 0;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////
}