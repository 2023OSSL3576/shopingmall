typedef struct{
    char id[30]; //아이디
    char password[30]; //비밀번호
    char phoneNumber[30]; //휴대전화 번호
    char userName[50]; //이름
}User;

int signUp(User *u[], int count); //회원가입하는 함수
int signIn(User *u[], int count); //로그인하는 함수
int loadUser(User *u[]); //유저 정보 파일을 읽어오는 함수
void saveUser(User *u[], int count); //유저 정보 파일을 저장함수 함수
void withdrawal(User *u[], int count); //회원 탈퇴하는 함수(유저 정보 삭제하는 함수)
void updateUser(User *u[], int count); //회원 정보를 수정하는 함수
int userMenu(); //메뉴판