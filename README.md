# shopingmall
<p align="center"><img src="https://cdn.pixabay.com/photo/2013/07/12/17/22/basket-152089_1280.png" width="425" height="410"/></p>

# #basket 주제

- 쇼핑몰 로그인과 장바구니를 관리하는 프로그램

# #basket에 대한 소개

- 구매하고 싶은 물품들을 장바구니에 담고 한번에 결제하게 해주는 프로그램입니다.
- 구매목록의 조건이 만족되면 할인쿠폰을 자동으로 적용시켜줍니다.
- 구매목록의 총 결제금액과 할인된 금액을 보여줍니다.

# #basket의 기능소개

- 장바구니에 품목 추가 기능
- 장바구니의 품목 삭제 기능
- 장바구니 품목 조회 기능
- 품목 수정 기능(가격, 갯수)
- 장바구니 전체 결제 기능
- 할인쿠폰 자동적용 기능

# 코드 및 기능
```c
typedef struct{
    char id[10]; //아이디
    char password[12]; //비밀번호
    char phoneNumber[11]; //휴대전화 번호
    char userName[30]; //이름
}User;

void signUp(User *u[], int count); //회원가입하는 함수
void signIn(User *u[], int count); //로그인하는 함수
int loadUser(User *u[]); //유저 정보 파일을 읽어오는 함수
void saveUser(User *u[], int count); //유저 정보 파일을 저장함수 함수
void withdrawal(User *u[], int count); //회원 탈퇴하는 함수(유저 정보 삭제하는 함수)
void updateUser(User *u[], int count); //회원 정보를 수정하는 함수
int userMenu(); //메뉴판

typedef struct{
    char name[30]; //상품명
    int price; //상품 가격
    char type; //상품 타입(카테고리)
}Product;

int productMenu(); //메뉴 입력 함수
int addProduct(Product *p); //상품을 추가하는 함수
int deleteProduct(Product *p[], int count); //담은 상품을 삭제하는 함수
void readProduct(Product *p[], int count); //담은 상품을 조회하는 함수
void updateProduct(Product *p[], int count); //담은 상품의 정보를 수정하는 함수
void payProduct(Product *p[], int count); //담은 상품을 결제하는 함수
void showCoupon(); //쿠폰을 보여주는 함수
int applyCoupon(Product *p[], int count); //쿠폰을 자동으로 적용해주는 함수
```

# 개발환경 및 언어

- git
- vscode
- c

# 팀원 소개 및 팀원 역할
### 곽동우 [GoldenWo1f GITHUB LINK](https://github.com/GoldenWo1f)
- 장바구니 구현
- 위키관리
- README.md 수정
### 김민서 [csee22-076 GITHUB LINK](https://github.com/csee22-076)
- 로그인 구현
- 코드 오류 수정
