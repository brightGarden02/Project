#include <iostream>
#include <cstring>

using namespace std;
/*
����ü: �����ִ� �������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ������ִ� ����̴�.
����� ���� ���� Ÿ���̴�.
����: struct ����ü�� {}; ���·� �����ȴ�. 

�迭�� ����ü�� ������
1. ������ �����̴�.
2. ���ӵ� �޸� ���� �Ҵ�ȴ�.
����ü ������� ���ӵ� �޸� ������ ������ �ȴ�. 
 
*/

#define NAME_SIZE 32


// 56 bytes
struct _tagStudent
{
	char strName[NAME_SIZE]; // 32bytes
	int iNumber; // 4 bytes
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg; // 4 bytes
};

int main()
{
	
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};
	
	
	// ����ü ����� ������ ���� .�� �̿��ؼ� �����ϰ� �ȴ�.
	tStudent.iKor = 100;
	
	// ���ڿ��� �迭�� �������� �ܼ� �������δ� �Ұ���
	// strcpy_s��� �Լ��� �̿��ؼ� ���ڿ��� �����ؾ��Ѵ�.
	 
	// �� �Լ��� �����ʿ� ���ڿ��� �������� �������ش�. 
	strcpy(tStudent.strName, "�質��");	
//	tStudent.strName[0] = 'a';
//	tStudent.strName[1] = 'b';
//	tStudent.strName[2] = 0;

	cout << "���� �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	cin >> strName;
	
	if(strcmp(tStudent.strName, strName) == 0)
	{
		cout << "�л��� ã�ҽ��ϴ�." << endl;
	}
	else
	{
		cout << "ã�� �л��� �����ϴ�." << endl;
	}

	 

	// strcat_s �Լ��� ���ڿ��� �ٿ��ִ� ����̴�.
	strcat(tStudent.strName, " ���ڿ� ���̱�"); 


	cout << "�̸�: " << tStudent.strName << endl;
	cout << "�й�: " << tStudent.iNumber << endl;
	cout << "����: " << tStudent.iKor << endl;
	cout << "����: " << tStudent.iEng << endl;
	cout << "����: " << tStudent.iMath << endl;
	cout << "����: " << tStudent.iTotal << endl;
	cout << "���: " << tStudent.fAvg << endl;
	
	
	return 0;
 } 

