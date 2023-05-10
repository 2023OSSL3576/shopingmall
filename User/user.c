#include "user.h"
#include "stdio.h"
#define max_size = 20;

void saveUser(User *u[], int count){
    FILE *data;
    data = fopen("user.txt", "w");
    for(int i=0; i<count; i++){
        if(u[i]->id!=0){
            fprintf(data,"%s %s %s %s\n", u[i]->id, u[i]->password, u[i]->phoneNumber, u[i]->userName);
        }
    }
    printf("=> 저장되었습니다!\n");
    fclose(data);
}