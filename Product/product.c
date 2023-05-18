#include <stdio.h>
#include "product.h"

int addProduct(Product *p){
    printf("상품명: ");
    scanf("%s", p->name);
    printf("가격: ");
    scanf("%d", &p->price);
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
    printf("번호 상품명      가격      상품 타입\n");   
    for(int i=0; i<count; i++){
        printf("%-2d  %s %d %c\n", i+1, p[i]->name, p[i]->price, p[i]->type);
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
    printf("가격: ");
    scanf("%d", &p[num-1]->price);
    printf("상품 타입(1:식품, 2:의류, 3:가전제품): ");
    scanf("%c", &p[num-1]->type);
}
