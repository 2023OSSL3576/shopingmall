typedef struct{
    char id[11]; //���̵�
    char password[13]; //��й�ȣ
    char phoneNumber[12]; //�޴���ȭ ��ȣ
    char userName[30]; //�̸�
}User;

int signUp(User *u[], int count); //ȸ�������ϴ� �Լ�
char signIn(User *u[], int count); //�α����ϴ� �Լ�
int loadUser(User *u[]); //���� ���� ������ �о���� �Լ�
//int loadUserNumber(); //ȸ�����Ե� ���� ���� �ҷ����� �Լ�
void saveUser(User *u[], int count); //���� ���� ������ �����Լ� �Լ�
void withdrawal(User *u[], int count); //ȸ�� Ż���ϴ� �Լ�(���� ���� �����ϴ� �Լ�)
int userMenu();