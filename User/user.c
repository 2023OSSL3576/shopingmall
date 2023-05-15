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
    char id[11];

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

void signUp(User *u[]){
    char check_blank = 0;
    char id[11];
    char password[13];
    char phoneNumber[12];
    char userName[30]; 

    while(1){
        printf("아이디(10글자 이내, 띄어쓰기 미포함): ");
        scanf("%[^\n]s", id);
        if(strlen(id)>10){
            printf("=>10글자 초과입니다. 다시 시도해주세요.\n");
            continue;
        }
        for(int i=0; i<10; i++){
            if(strcmp(id[i], " ")==0){
                printf("=>띄어쓰기가 되어 있습니다. 다시 시도해주세요.\n");
                check_blank = 1;
                break;
            }
        }
        if(check_blank==1) continue;
        else break;
    }
    check_blank = 0;

    while(1){
        printf("비밀번호(12글자 이내, 띄어쓰기 미포함): ");
        scanf("%[^\n]s", password);
        if(strlen(password)>!2){
            printf("=>12글자 초과입니다. 다시 시도해주세요.\n");
            continue;
        }
        for(int i=0; i<12; i++){
            if(strcmp(password[i], " "==0)){
                printf("=>띄어쓰기가 되어 있습니다. 다시 시도해주세요.\n");
                check_blank = 1;
                break;
            }
        }
        if(check_blank==1) continue;
        else break;
    }

    while(1){
        printf("전화번호(-없이 숫자만, 띄어쓰기 미포함): ");
        scanf("%[^\n]s", phoneNumber);
        if(strlen(password)>12){
            printf("=>11글자 초과 혹은 '-'이나 띄어쓰기가 포함되어 있습니다. 다시 시도해주세요.\n");
            continue;
        }
        else break;
    }

    printf("이름: ");
    scanf("%[^\n]s", userName);

    printf("=>회원가입이 완료되었습니다.\n");
}

void signIn(User *u[]);