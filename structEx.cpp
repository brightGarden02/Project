#include <iostream>
#include <cstring>

using namespace std;
/*
구조체: 관련있는 변수들을 모아서 하나의 새로운 타입을 만들어주는 기능이다.
사용자 정의 변수 타입이다.
형태: struct 구조체명 {}; 형태로 구성된다. 

배열과 구조체의 공통잠
1. 데이터 집합이다.
2. 연속된 메모리 블럭에 할당된다.
구조체 멤버들은 연속된 메모리 블럭으로 잡히게 된다. 
 
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
	
	
	// 구조체 멤버에 접근할 때는 .을 이용해서 접근하게 된다.
	tStudent.iKor = 100;
	
	// 문자열을 배열에 넣을때는 단순 대입으로는 불가능
	// strcpy_s라는 함수를 이용해서 문자열을 복사해야한다.
	 
	// 이 함수는 오른쪽에 문자열을 왼쪽으로 복사해준다. 
	strcpy(tStudent.strName, "김나정");	
//	tStudent.strName[0] = 'a';
//	tStudent.strName[1] = 'b';
//	tStudent.strName[2] = 0;

	cout << "비교할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	cin >> strName;
	
	if(strcmp(tStudent.strName, strName) == 0)
	{
		cout << "학생을 찾았습니다." << endl;
	}
	else
	{
		cout << "찾는 학생이 없습니다." << endl;
	}

	 

	// strcat_s 함수는 문자열을 붙여주는 기능이다.
	strcat(tStudent.strName, " 문자열 붙이기"); 


	cout << "이름: " << tStudent.strName << endl;
	cout << "학번: " << tStudent.iNumber << endl;
	cout << "국어: " << tStudent.iKor << endl;
	cout << "영어: " << tStudent.iEng << endl;
	cout << "수학: " << tStudent.iMath << endl;
	cout << "총점: " << tStudent.iTotal << endl;
	cout << "평균: " << tStudent.fAvg << endl;
	
	
	return 0;
 } 

