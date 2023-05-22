#include <stdio.h>
#include "product.h"

int productMenu(){
    int menu;
    printf("\n*** ���� �ý���***\n");
    printf("1. ��ǰ ���\n");
    printf("2. ��ǰ ����\n");
    printf("3. ��ǰ ����\n");
    printf("4. ��ǰ ��ȸ\n");
    printf("5. ����\n");
    printf("6. ���� ��ȸ\n");
    printf("0. ����\n\n");
    printf("�޴� ����: ");
    scanf("%d", &menu);
    return menu;
}

int addProduct(Product *p){
    printf("��ǰ��: ");
    scanf("%s", p->name);
    getchar();
    printf("����: ");
    scanf("%d", &p->price);
    getchar();
    printf("��ǰ Ÿ��(1:��ǰ, 2:�Ƿ�, 3:������ǰ): ");
    scanf("%c", &p->type);
    
    return 1;
}

int deleteProduct(Product *p[], int count){
    if(count == 0)
        return 0;
    readProduct(p, count);
    int num;
    printf("�����ϰ� ���� ��ǰ�� ��ȣ: ");
    scanf("%d", &num);
    for(int i=num-1; i<count-1; i++){
        p[i] = p[i+1];
    }
    return 1;
}

void readProduct(Product *p[], int count){
    printf("%d���� ��ǰ�� �ֽ��ϴ�!\n", count);
    printf("��ȣ ��ǰ��      ����      ��ǰŸ��\n");   
    for(int i=0; i<count; i++){
        printf("%-2d   %-14s %-9d %c\n", i+1, p[i]->name, p[i]->price, p[i]->type);
    }
}

void updateProduct(Product *p[], int count){
    if(count == 0)
        return;
    readProduct(p, count);
    int num;
    printf("�����ϰ� ���� ��ǰ�� ��ȣ: ");
    scanf("%d", &num);
    if(num > count-1 || num < 0)
        return;
    printf("��ǰ��: ");
    scanf("%s", p[num-1]->name);
    getchar();
    printf("����: ");
    scanf("%d", &p[num-1]->price);
    getchar();
    printf("��ǰ Ÿ��(1:��ǰ, 2:�Ƿ�, 3:������ǰ): ");
    scanf("%c", &p[num-1]->type);
}

void payProduct(Product *p[], int count){
    readProduct(p, count);
    int total = 0;
    for(int i=0; i<count; i++)
        total += p[i]->price;

    printf("��ǰ �ݾ�: %d��\n", total);
    int result = applyCoupon(p, count);
    int discount = total - result;
    printf("���� �ݾ�: %d\n", discount);
    printf("�հ�: %d\n", result);
}

void showCoupon(){
    printf("\n��ü ���űݾ� 30���� �̻� ���� �� 8%% ����\n");
    printf("��ǰ 10���� �̻� ���� �� 12%% ����\n");
    printf("�Ƿ� 5���� �̻� ���� �� 15%% ����\n");
    printf("������ǰ 20���� �̻� ���� �� 10%% ����\n\n");
}

int applyCoupon(Product *p[], int count){
    showCoupon();
    int totalPrice = 0;
    int foods = 0;
    int clothes = 0;
    int applians = 0;
    int couponType[3] = {0};
    for(int i=0; i<count; i++){
        totalPrice += p[i]->price;
        if(p[i]->type == '1')
            foods += p[i]->price;
        if(p[i]->type == '2')
            clothes += p[i]->price;
        if(p[i]->type == '3')
            applians += p[i]->price;
    }
    if(totalPrice >= 300000){
        totalPrice = totalPrice * 0.92;
    }
    if(foods >= 100000){
        foods = foods * 0.88;
        couponType[0]++;
    }
    if(clothes >= 50000){
        clothes = clothes * 0.85;
        couponType[1]++;
    }
    if(applians >= 200000){
        applians = applians * 0.90;
        couponType[2]++;
    }

    if(totalPrice > foods + clothes + applians){
        if(couponType[0] == 1) printf("��ǰ �ݾ� �������� �����\n");
        if(couponType[1] == 1) printf("�Ƿ� �ݾ� �������� �����\n");
        if(couponType[2] == 1) printf("������ǰ �ݾ� �������� �����\n");

        return foods + clothes + applians;
    }

    printf("��ü �ݾ� �������� �����\n");
    return totalPrice;
}
