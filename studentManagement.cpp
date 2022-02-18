#include <iostream>
#include <cstring>
using namespace std;

#define NAME_SIZE 32
#define ADDRESS_SIZE 128
#define PHONE_SIZE 14
#define STUDENT_MAX 10

struct _tagStudent{

	char strName[NAME_SIZE];
	char strAddress[ADDRESS_SIZE];
	char strPhoneNumber[PHONE_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;	
	
};


enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main(){
	
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	
	// �迭�� �߰��� ������ ������ ������ �����.
	int iStudentCount = 0;
	int iStdNumber = 1;
	 
	
	
	while(true){

		system("cls");
		
		// �޴��� ����Ѵ�.
		cout << "1. �л����"  << endl;
		cout << "2. �л�����"  << endl;
		cout << "3. �л�Ž��"  << endl;
		cout << "4. �л����"  << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ���: ";
		
		int iMenu;
		cin >> iMenu;
		
		if(cin.fail()){
			
			// �������۸� ����ش�.
			cin.clear();
			
			// �Է¹��ۿ� \n�� ���������Ƿ� �Է¹��۸� �˻��Ͽ� \n�� �����ش�.
			// ù��°���� �˻��ϰ��� �ϴ� ���� ũ�⸦ �����Ѵ�.
			// �˳��ϰ� 1024 ����Ʈ ���� �����Ѵ�.
			// �ι�°�� ã���� �ϴ� ���ڸ� �־��ش�.
			 
			cin.ignore(1024, '\n');
			continue;
		}
		
		
		
		
		if(iMenu == MENU_EXIT)
			break;
			
		switch(iMenu){
			
			case MENU_INSERT:
				system("cls");
				cout << "========== �л��߰� ==========" << endl; 
				
				// ��ϵ� �л��� ����� �� �ִ� �ִ�ġ�� ��� 
				// ���̻� ����� �ȵǰ� ���´�. 
				if(iStudentCount == STUDENT_MAX)
					break;
				
				
				// �л� ������ �߰��Ѵ�. �й�, �̸�, �ּ�, ��ȭ��ȣ
				// ����, ����, ���� ������ �Է¹ް� �й�, ����, �����
				// ������ ���� ����Ѵ�.
				// �̸��� �Է¹޴´�.
				
				
				cout << "�̸�: ";
				cin >> tStudentArr[iStudentCount].strName;
				
				cin.ignore(1024, '\n');
				
				cout << "�ּ�: ";
				cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE); 
				
				cout << "��ȭ��ȣ: ";
				cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE); 
				
				cout << "����: ";
				cin >> tStudentArr[iStudentCount].iKor;
				
				cout << "����: ";
				cin >> tStudentArr[iStudentCount].iEng;
				
				cout << "����: ";
				cin >> tStudentArr[iStudentCount].iMath;
				
				tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;
				
				tStudentArr[iStudentCount].fAvg =
				tStudentArr[iStudentCount].iTotal / 3.f;
				
				tStudentArr[iStudentCount].iNumber = iStdNumber;
				
				++iStdNumber;
				++iStudentCount;
				
				cout << "�л� �߰� �Ϸ�" << endl;
				
				break;
			case MENU_DELETE:
				system("cls");
				cout << "========== �л�����  ==========" << endl; 
				
				cout << "�̸�: ";
//				cin >> tStudentArr[iStudentCount].strName;
				
				char strName[NAME_SIZE] = {};
				cin >> strName;
				
				if(strcmp(tStudent.strName, strName) == 0){
					
					cout << "�л��� ã�ҽ��ϴ�." << endl;
				}
				else{
					
					cout << "ã�� �л��� �����ϴ�." << endl;
				}
				
				
				
				break;
			case MENU_SEARCH:
				system("cls");
				cout << "========== �л�Ž�� ==========" << endl; 
				
				char strSearchName[NAME_SIZE] = {};	
			
				cout << "Ž���� �̸��� �Է��ϼ���: ";
				
				break;
			case MENU_OUTPUT:
				system("cls");
				cout << "========== �л���� ==========" << endl; 
				
				// ��ϵ� �л� �� ��ŭ �ݺ��ϸ� �л������� ����Ѵ�.
				for(int i = 0; i < iStudentCount; ++i)
				{
					cout << "�̸�: " << tStudentArr[i].strName << endl;
					cout << "��ȭ��ȣ: " << tStudentArr[i].strPhoneNumber << endl;
					cout << "�ּ�: " << tStudentArr[i].strAddress << endl;
					
					cout << "�й�: " << tStudentArr[i].iNumber << endl;
					cout << "����: " << tStudentArr[i].iKor << endl;
					cout << "����: " << tStudentArr[i].iEng << endl;
					cout << "����: " << tStudentArr[i].iMath << endl;
					cout << "����: " << tStudentArr[i].iTotal << endl;
					cout << "���: " << tStudentArr[i].fAvg << endl << endl;
					
				
				} 
				break;
			default:
				cout << "�޴��� �߸� �����߽��ϴ�." << endl;
				break;
			
		}
		system("pause");
		
	}
	
	return 0;
}
