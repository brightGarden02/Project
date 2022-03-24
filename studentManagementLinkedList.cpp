#include <iostream>

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_EXIT
};



#define NAME_SIZE	32

typedef struct _tagStudent
{
	char	strName[NAME_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
	
}STUDENT, *PSTUDENT;


// ����Ʈ ��带 �����.
typedef struct _tagNode
{
	STUDENT		tStudent;
	_tagNode*	pNext;
	
 }NODE, *PNODE; 


typedef struct _tagList
{
	PNODE 	pBegin;
	PNODE 	pEnd;
	int		iSize;
}LIST, *PLIST;


int InputInt()
{
	int iInput;
	cin >> iInput;
	
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	
	return iInput;
}


void InputString(char* pString, int iSize)
{
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize-1);
	
}


void InitList(PLIST pList)
{
	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;
}


int OutputMenu()
{
	system("cls");
	cout << "1: �л��߰�" << endl;
	cout << "2: �л�����" << endl;
	cout << "3: �л�Ž��" << endl;
	cout << "4: �л����" << endl;
	cout << "5: ����" << endl;
	int iInput = InputInt();
	
	if(iInput <= MM_NONE || iInput > MM_EXIT)
		return MM_NONE;
	
	return iInput;
}


void Insert(PLIST pList)
{
	system("cls");
	cout << "=================== �л��߰� ===================" << endl;
	
	STUDENT tStudent = {};
	
	cout << "�̸�: ";
	InputString(tStudent.strName, NAME_SIZE);
	
	cout << "�й�: ";
	tStudent.iNumber = InputInt();
	
	
	cout << "����: ";
	tStudent.iKor = InputInt();
	
	cout << "����: ";
	tStudent.iEng = InputInt();
	
	cout << "����: ";
	tStudent.iMath = InputInt();
	
	
}


int main()
{
	// LIST ����ü Ÿ�� ������ �����Ѵ�. 
	LIST	tList;
	
	// InitList�� ���ڷ� PLIST(_tagList*) Ÿ���� �����Ƿ� �ּҸ� �Ѱ��ش�. 
	InitList(&tList);
	
	
	while(true)
	{
		int iMenu = OutputMenu();
		
		if(iMenu == MM_EXIT)
			break;
		
		switch(iMenu)
		{
			case MM_INSERT:
				Insert(&tList);
				break;
			case MM_DELETE:
				break;	
			case MM_SEARCH:
				break;
			case MM_OUTPUT:
				break;	
		}
		
	
	}
	
	
	return 0;
}
