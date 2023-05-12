typedef struct{
    char id[10]; //아이디
    char password[12]; //비밀번호
    char phoneNumber[11]; //휴대전화 번호
    char userName[30]; //이름
}User;

void signUp(User *u[]); //회원가입하는 함수
void signIn(User *u[]); //로그인하는 함수
int loadUser(User *u[]); //유저 정보 파일을 읽어오는 함수
void saveUser(User *u[], int count); //유저 정보 파일을 저장함수 함수
void withdrawal(User *u[]); //회원 탈퇴하는 함수(유저 정보 삭제하는 함수)
