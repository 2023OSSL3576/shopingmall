#include "stdio.h"
#include "user.h"
#include "product.h"

int main(void){
    int count = loadUserNumber();

    for(int i=0; i<count; i++){
        User *u = (User*)malloc(sizeof(User));
    }
}