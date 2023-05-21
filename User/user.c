#include "user.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void saveUser(User *u[], int count){
    FILE *data;
    data = fopen("user.txt", "w");
    for(int i=0; i<count; i++){
        fprintf(data,"%s %s %s %s\n", u[i]->id, u[i]->password, u[i]->phoneNumber, u[i]->userName);
    }
    printf("����Ǿ����ϴ�.\n");
    fclose(data);
}

int loadUser(User *u[]){
    FILE *data;
    int i = 0;
    data = fopen("user.txt", "r");
    while(!feof(data)){
        if(fscanf(data, "%s %s %s %s",u[i]->id, u[i]->password, u[i]->phoneNumber, u[i]->userName)!=4) break;
        i++;
    }
    fclose(data);
    return i;
}

void withdrawal(User *u[], int count){
    char id[11];
    char password[13];
    bool id_check = false;
    bool password_check = false;
    int id_location;

    printf("------------Withdrawal------------\n");
    printf("�����Ϸ��� ������ ���̵�: ");
    getchar();
    scanf("%[^\n]s", id);
    if(strcmp(id, "-1")==0){
        printf("ã���ô� ���̵� �����ϴ�.\n");
        return;
    }
    for(int i=0; i<count; i++){
        if(strcmp(u[i]->id, id)==0){
            id_check = true;
            id_location = i;
            break;
        }
    }
    if(id_check==false){
        printf("ã���ô� ���̵� �����ϴ�.\n");
        return;
    }
    else{
        printf("�����Ϸ��� ������ ��й�ȣ: ");
        getchar();
        scanf("%[^\n]s", password);
        if(strcmp(u[id_location]->password, password)==0) {
            strcpy(u[id_location]->id, "-1");
            password_check = true;
        }
        if(password_check==false){
            printf("Ʋ�� ��й�ȣ�Դϴ�.\n");
            return;
        }
        else {
            printf("�����Ǿ����ϴ�.\n");
            saveUser(u, count);
        }
    }
}

int signUp(User *u[], int count){
    bool check_blank;
    char id[11];
    char password[13];
    char phoneNumber[12];
    char userName[30]; 

    printf("------------Sign Un------------\n");
    printf("�� �ܰ迡�� ȸ�������� ����Ͻ÷��� -1�� �Է����ּ���.\n");
    while(1){
        check_blank = false;
        printf("1. ���̵�(10���� �̳�, ���� ������): ");
        getchar();
        scanf("%[^\n]s", id);
        if(strcmp(id,"-1")==0) return count;
        if(strlen(id)>10){
            printf("10���� �ʰ��Դϴ�. �ٽ� �õ����ּ���.\n");
            continue;
        }
        for(int i=0; i<strlen(id); i++){
            if(id[i] == ' '){
                printf("���Ⱑ �Ǿ� �ֽ��ϴ�. �ٽ� �õ����ּ���.\n");
                check_blank = true;
                break;
            }
        }
        for(int i=0; i<count; i++){
            if(strcmp(u[i]->id, id)==0){
                printf("�ߺ��� ���̵��Դϴ�. �ٽ� �õ����ּ���.\n");
                check_blank = true;
                break;
            }
        }
        if(check_blank==true) continue;
        else break;
    }

    while(1){
        check_blank = false;
        printf("2. ��й�ȣ(12���� �̳�, ���� ������): ");
        getchar();
        scanf("%[^\n]s", password);
        if(strcmp(password,"-1")==0) return count;
        if(strlen(password)>12){
            printf("12���� �ʰ��Դϴ�. �ٽ� �õ����ּ���.\n");
            continue;
        }
        for(int i=0; i<strlen(password); i++){
            if(password[i] == ' '){
                printf("���Ⱑ �Ǿ� �ֽ��ϴ�. �ٽ� �õ����ּ���.\n");
                check_blank = true;
                break;
            }
        }
        if(check_blank==true) continue;
        else break;
    }

    while(1){
        check_blank = false;
        printf("3. ��ȭ��ȣ(-���� ���ڸ�, ���� ������): ");
        getchar();
        scanf("%[^\n]s", phoneNumber);
        if(strcmp(phoneNumber,"-1")==0) return count;
        /*if(strlen(password)!=11){
            printf("11���� �ʰ�, �̸� Ȥ�� '-'�̳� ���Ⱑ ���ԵǾ� �ֽ��ϴ�. �ٽ� �õ����ּ���.\n");
            continue;
        }
        else break;*/
        for(int i=0; i<strlen(phoneNumber); i++){
            if(phoneNumber[i] == ' '){
                printf("���Ⱑ �Ǿ� �ֽ��ϴ�. �ٽ� �õ����ּ���.\n");
                check_blank = true;
                break;
            }
            if(phoneNumber[i] == '-'){
                printf("-�� ���ԵǾ��ֽ��ϴ�. �ٽ� �õ����ּ���.\n");
                check_blank = true;
                break;
            }
            if(!isdigit(phoneNumber[i])){
                printf("���ڰ� �ƴմϴ�. �ٽ� �õ����ּ���.\n");
                check_blank = true;
                break;
            }
        }
        if(check_blank==true) continue;
        else break;
    }

    printf("�̸�: ");
    getchar();
    scanf("%[^\n]s", userName);
    if(strcmp(userName,"-1")==0) return count;

    strcpy(u[count]->id, id);
    strcpy(u[count]->password, password);
    strcpy(u[count]->phoneNumber, phoneNumber);
    strcpy(u[count]->userName, userName);

    count++;
    printf("\nȸ�������� �Ϸ�Ǿ����ϴ�.\n");
    saveUser(u, count);
    return count;
}

int signIn(User *u[], int count){
    char id[11];
    char password[13];
    bool id_check = false;
    bool password_check = false;

    printf("------------Sign In------------\n");
    printf("���̵�: ");
    scanf("%s", id);
    for(int i=0; i<count; i++){
        if(strcmp(u[i]->id,id)==0){
            id_check = true;
            break;
        }
    }
    if(id_check == false){
        printf("�߸��ǰų� ���� ���̵��Դϴ�.\n");
        return 0;
    }
    else{
        printf("��й�ȣ: ");
        scanf("%s", password);
        for(int i=0; i<count; i++){
            if(strcmp(u[i]->password,password)==0){
            password_check = true;
            break;
            }
        }
    }
    if(password_check==false){
        printf("�߸��� ��й�ȣ�Դϴ�.\n");
        return 0;
    }
    else printf("�α��εǾ����ϴ�.\n");
    return 1;
}

int userMenu(){
    int menu;
    printf("\n*** ���� �ý��� ***\n");
    printf("1. �α���\n");
    printf("2. ȸ�� ����\n");
    printf("3. ȸ�� Ż��\n");
    printf("0. ����\n\n");
    printf("�޴� ����: ");
    scanf("%d", &menu);
    return menu;
}