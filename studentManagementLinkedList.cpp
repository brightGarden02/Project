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
	cout << "메뉴를 선택하세요: ";
	int iInput = InputInt();
	
	if(iInput <= MM_NONE || iInput > MM_EXIT)
		return MM_NONE;
	
	return iInput;
}

// const 포인터이기 때문에 가리키는 대상의 값을 변경할 수 없다. 
void OutputStudent(const PSTUDENT pStudent)
{
	cout << "이름: " << pStudent->strName << "\t학번: " << pStudent->iNumber << endl;
	cout << "국어 점수: " << pStudent->iKor << "\t영어 점수: " << pStudent->iEng << endl;
	cout << "수학 점수: " << pStudent->iMath << endl;
	cout << "총점: " << pStudent->iTotal << "\t평균: " << pStudent->fAvg << endl;
	cout << endl;
}


void Output(PLIST pList)
{
	system("cls");
	cout << "=================== 학생출력 ===================" << endl;
	
	PNODE pNode = pList->pBegin;
	
	while(pNode != NULL)
	{
		
		OutputStudent(&pNode->tStudent);
		pNode = pNode->pNext;
			
	}	
	cout << "학생수: " << pList->iSize << endl;
	
	system("pause");
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
	
	tStudent.iTotal = tStudent.iKor +  tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;
		
	// 추가할 리스트 노드를 생성한다.
	PNODE pNode = new NODE; 
	
	// 현재 추가하는 노드는 가장 마지막에 추가될 것이기 떄문에
	// 다음 노드가 존재하지 않는다.
	// 그래서 다음 노드는 NULL로 초기화하고 정보는 위에서 입력받은
	// 학생 정보를 준다. 
	pNode->pNext = NULL;
	pNode->tStudent = tStudent;
	
	if(pList->pBegin == NULL)
		pList->pBegin = pNode;
	else
		pList->pEnd->pNext = pNode;	
	
	pList->pEnd = pNode;
	
	++pList->iSize;	
}

void ClearList(PLIST pList)
{
	
	PNODE pNode = pList->pBegin;
	
	while(pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
		
	}
	
	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;
	
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
				Output(&tList);
				break;	
		}
		
	
	}
	
	ClearList(&tList);
	
	return 0;
}
