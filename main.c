#include <stdio.h>
#include <stdlib.h>
#include "User/user.h"
#include "Product/product.h"
#define max 50

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
        }
        else if(Umenu==2) count = signUp(u, count);
        else if(Umenu==3) withdrawal(u, count);
    }
    free(*u);
    if(checkSignIn==0){
        printf("\n����Ǿ����ϴ�.\n");
        return 0;
    }

    Product *p[30];
    int Pmenu;
    count = 0;
    

    while(1){
        Pmenu = productMenu();
        if(Pmenu == 0) break;
        if(Pmenu == 1){
            p[count] = (Product*)malloc(sizeof(Product));
            count += addProduct(p[count]);
        }
        if(Pmenu == 2){
            count -= deleteProduct(p, count);
        }
        if(Pmenu == 3){
            updateProduct(p, count);
        }
        if(Pmenu == 4){
            readProduct(p, count);
        }
        if(Pmenu == 5){
            payProduct(p, count);
            break;
        }
        if(Pmenu == 6){
            showCoupon();
        }
    }
}
