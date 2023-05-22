#include <stdio.h>
#include "product.h"

int productMenu(){
    int menu;
    printf("\n*** 쇼핑 시스템***\n");
    printf("1. 상품 담기\n");
    printf("2. 상품 삭제\n");
    printf("3. 상품 수정\n");
    printf("4. 상품 조회\n");
    printf("5. 결제\n");
    printf("6. 쿠폰 조회\n");
    printf("0. 종료\n\n");
    printf("메뉴 선택: ");
    scanf("%d", &menu);
    return menu;
}

int addProduct(Product *p){
    printf("상품명: ");
    scanf("%s", p->name);
    getchar();
    printf("가격: ");
    scanf("%d", &p->price);
    getchar();
    printf("상품 타입(1:식품, 2:의류, 3:가전제품): ");
    scanf("%c", &p->type);
    
    return 1;
}

int deleteProduct(Product *p[], int count){
    if(count == 0)
        return 0;
    readProduct(p, count);
    int num;
    printf("삭제하고 싶은 상품의 번호: ");
    scanf("%d", &num);
    for(int i=num-1; i<count-1; i++){
        p[i] = p[i+1];
    }
    return 1;
}

void readProduct(Product *p[], int count){
    printf("%d개의 상품이 있습니다!\n", count);
    printf("번호 상품명      가격      상품타입\n");   
    for(int i=0; i<count; i++){
        printf("%-2d   %-14s %-9d %c\n", i+1, p[i]->name, p[i]->price, p[i]->type);
    }
}

void updateProduct(Product *p[], int count){
    if(count == 0)
        return;
    readProduct(p, count);
    int num;
    printf("수정하고 싶은 상품의 번호: ");
    scanf("%d", &num);
    if(num > count-1 || num < 0)
        return;
    printf("상품명: ");
    scanf("%s", p[num-1]->name);
    getchar();
    printf("가격: ");
    scanf("%d", &p[num-1]->price);
    getchar();
    printf("상품 타입(1:식품, 2:의류, 3:가전제품): ");
    scanf("%c", &p[num-1]->type);
}

void payProduct(Product *p[], int count){
    readProduct(p, count);
    int total = 0;
    for(int i=0; i<count; i++)
        total += p[i]->price;

    printf("상품 금액: %d원\n", total);
    int result = applyCoupon(p, count);
    int discount = total - result;
    printf("할인 금액: %d\n", discount);
    printf("합계: %d\n", result);
}

void showCoupon(){
    printf("\n전체 구매금액 30만원 이상 구매 시 8%% 할인\n");
    printf("식품 10만원 이상 구매 시 12%% 할인\n");
    printf("의류 5만원 이상 구매 시 15%% 할인\n");
    printf("가전제품 20만원 이상 구매 시 10%% 할인\n\n");
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
        if(couponType[0] == 1) printf("식품 금액 할인쿠폰 적용됨\n");
        if(couponType[1] == 1) printf("의류 금액 할인쿠폰 적용됨\n");
        if(couponType[2] == 1) printf("가전제품 금액 할인쿠폰 적용됨\n");

        return foods + clothes + applians;
    }

    printf("전체 금액 할인쿠폰 적용됨\n");
    return totalPrice;
}
