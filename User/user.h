typedef struct{
    char id[30]; //���̵�
    char password[30]; //��й�ȣ
    char phoneNumber[30]; //�޴���ȭ ��ȣ
    char userName[50]; //�̸�
}User;

int signUp(User *u[], int count); //ȸ�������ϴ� �Լ�
int signIn(User *u[], int count); //�α����ϴ� �Լ�
int loadUser(User *u[]); //���� ���� ������ �о���� �Լ�
void saveUser(User *u[], int count); //���� ���� ������ �����Լ� �Լ�
void withdrawal(User *u[], int count); //ȸ�� Ż���ϴ� �Լ�(���� ���� �����ϴ� �Լ�)
void updateUser(User *u[], int count); //ȸ�� ������ �����ϴ� �Լ�
int userMenu(); //�޴���