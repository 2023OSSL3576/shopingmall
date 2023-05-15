#include "user.h"
#include "stdio.h"
#include "string.h"

void saveUser(User *u[], int count){
    FILE *data;
    data = fopen("user.txt", "w");
    for(int i=0; i<count; i++){
        if(u[i]->id!=0){
            fprintf(data,"%s %s %s %s\n", u[i]->id, u[i]->password, u[i]->phoneNumber, u[i]->userName);
        }
    }
    printf("=>저장되었습니다.\n");
    fclose(data);
}

int loadUser(User *u[]){
    FILE *data;
    int i = 0;
    data = fopen("user.txt", "r");
    while(!eof(data)){
        if(fscanf(data, "%s %s %s %s",u[i]->id, u[i]->password, u[i]->phoneNumber, u[i]->userName)!=4) break;
        i++;
    }
    return i;
}

void withdrawal(User *u[], int count){
    char id[10];

    printf("삭제하려는 아이디: ");
    scanf("%[^\n]s", id);
    if(strlen(id)>10){
        printf("아이디는 10글자 이하입니다.\n");
        return;
    }
    for(int i=0; i<count; i++){
        if(strcmp(u[i]->id, id)==0){
            u[i]->id[0] = NULL;
            printf("=>삭제되었습니다.\n");
            return;
        }
    }
    printf("=>찾으시는 아이디가 없습니다.\n");
}