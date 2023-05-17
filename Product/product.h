typedef struct{
    char name[30]; //상품명
    int price; //상품 가격
    char type; //상품 타입(카테고리)
}Product;

void addProduct(Product *p); //상품을 추가하는 함수
int deleteProduct(Product *p[], int count); //담은 상품을 삭제하는 함수
void readProduct(Product *p[], int count); //담은 상품을 조회하는 함수
void updateProduct(Product *p); //담은 상품의 정보를 수정하는 함수
void payProduct(Product *p); //담은 상품을 결제하는 함수
void applyCoupon(Product *p); //쿠폰을 자동으로 적용해주는 함수
