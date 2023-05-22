typedef struct{
    char name[30]; //상품명
    int price; //상품 가격
    char type; //상품 타입(카테고리)
}Product;

int addProduct(Product *p); //상품을 추가하는 함수
int deleteProduct(Product *p[], int count); //담은 상품을 삭제하는 함수
void readProduct(Product *p[], int count); //담은 상품을 조회하는 함수
void updateProduct(Product *p[], int count); //담은 상품의 정보를 수정하는 함수
void payProduct(Product *p[], int count); //담은 상품을 결제하는 함수
void showCoupon(); //쿠폰을 보여주는 함수
int applyCoupon(Product *p[], int count); //쿠폰을 자동으로 적용해주는 함수
