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


// 리스트 노드를 만든다.
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
	cout << "1: 학생추가" << endl;
	cout << "2: 학생삭제" << endl;
	cout << "3: 학생탐색" << endl;
	cout << "4: 학생출력" << endl;
	cout << "5: 종료" << endl;
	int iInput = InputInt();
	
	if(iInput <= MM_NONE || iInput > MM_EXIT)
		return MM_NONE;
	
	return iInput;
}


void Insert(PLIST pList)
{
	system("cls");
	cout << "=================== 학생추가 ===================" << endl;
	
	STUDENT tStudent = {};
	
	cout << "이름: ";
	InputString(tStudent.strName, NAME_SIZE);
	
	cout << "학번: ";
	tStudent.iNumber = InputInt();
	
	
	cout << "국어: ";
	tStudent.iKor = InputInt();
	
	cout << "영어: ";
	tStudent.iEng = InputInt();
	
	cout << "수학: ";
	tStudent.iMath = InputInt();
	
	
}


int main()
{
	// LIST 구조체 타입 변수를 생성한다. 
	LIST	tList;
	
	// InitList는 인자로 PLIST(_tagList*) 타입을 받으므로 주소를 넘겨준다. 
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
