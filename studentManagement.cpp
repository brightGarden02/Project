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
	
	// 배열에 추가된 개수를 저장할 변수를 만든다.
	int iStudentCount = 0;
	int iStdNumber = 1;
	 
	
	
	while(true){

		system("cls");
		
		// 메뉴를 출력한다.
		cout << "1. 학생등록"  << endl;
		cout << "2. 학생삭제"  << endl;
		cout << "3. 학생탐색"  << endl;
		cout << "4. 학생출력"  << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 선택하세요: ";
		
		int iMenu;
		cin >> iMenu;
		
		if(cin.fail()){
			
			// 에러버퍼를 비워준다.
			cin.clear();
			
			// 입력버퍼에 \n이 남아있으므로 입력버퍼를 검색하여 \n을 지워준다.
			// 첫번째에는 검색하고자 하는 버퍼 크기를 지정한다.
			// 넉넉하게 1024 바이트 정도 지정한다.
			// 두번째는 찾고자 하는 문자를 넣어준다.
			 
			cin.ignore(1024, '\n');
			continue;
		}
		
		
		
		
		if(iMenu == MENU_EXIT)
			break;
			
		switch(iMenu){
			
			case MENU_INSERT:
				system("cls");
				cout << "========== 학생추가 ==========" << endl; 
				
				// 등록된 학생이 등록할 수 있는 최대치일 경우 
				// 더이상 등록이 안되게 막는다. 
				if(iStudentCount == STUDENT_MAX)
					break;
				
				
				// 학생 정보를 추가한다. 학번, 이름, 주소, 전화번호
				// 국어, 영어, 수학 점수는 입력받고 학번, 총점, 평균은
				// 연산을 통해 계산한다.
				// 이름을 입력받는다.
				
				
				cout << "이름: ";
				cin >> tStudentArr[iStudentCount].strName;
				
				cin.ignore(1024, '\n');
				
				cout << "주소: ";
				cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE); 
				
				cout << "전화번호: ";
				cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE); 
				
				cout << "국어: ";
				cin >> tStudentArr[iStudentCount].iKor;
				
				cout << "영어: ";
				cin >> tStudentArr[iStudentCount].iEng;
				
				cout << "수학: ";
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
				
				cout << "학생 추가 완료" << endl;
				
				break;
			case MENU_DELETE:
				system("cls");
				cout << "========== 학생삭제  ==========" << endl; 
				
				cout << "이름: ";
//				cin >> tStudentArr[iStudentCount].strName;
				
				char strName[NAME_SIZE] = {};
				cin >> strName;
				
				if(strcmp(tStudent.strName, strName) == 0){
					
					cout << "학생을 찾았습니다." << endl;
				}
				else{
					
					cout << "찾는 학생이 없습니다." << endl;
				}
				
				
				
				break;
			case MENU_SEARCH:
				system("cls");
				cout << "========== 학생탐색 ==========" << endl; 
				
				char strSearchName[NAME_SIZE] = {};	
			
				cout << "탐색할 이름을 입력하세요: ";
				
				break;
			case MENU_OUTPUT:
				system("cls");
				cout << "========== 학생출력 ==========" << endl; 
				
				// 등록된 학생 수 만큼 반복하며 학생정보를 출력한다.
				for(int i = 0; i < iStudentCount; ++i)
				{
					cout << "이름: " << tStudentArr[i].strName << endl;
					cout << "전화번호: " << tStudentArr[i].strPhoneNumber << endl;
					cout << "주소: " << tStudentArr[i].strAddress << endl;
					
					cout << "학번: " << tStudentArr[i].iNumber << endl;
					cout << "국어: " << tStudentArr[i].iKor << endl;
					cout << "영어: " << tStudentArr[i].iEng << endl;
					cout << "수학: " << tStudentArr[i].iMath << endl;
					cout << "총점: " << tStudentArr[i].iTotal << endl;
					cout << "평균: " << tStudentArr[i].fAvg << endl << endl;
					
				
				} 
				break;
			default:
				cout << "메뉴를 잘못 선택했습니다." << endl;
				break;
			
		}
		system("pause");
		
	}
	
	return 0;
}
