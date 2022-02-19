#include <iostream>
#include <cstring>

using namespace std;


enum MENU{
	
	BOOK_NONE, 
	BOOK_REGISTER,
	BOOK_CHECK,
	BOOK_RETURN,
	BOOK_LIST,
	BOOK_END
	
};

#define BOOK_MAX 10
#define BOOK_NAME_SIZE 50


/*
관리프로그램 만들기
도서 대여 프로그램 만들기
1. 책 등록
2. 책 대여
3. 책 반납 
4. 책 목록
5. 종료

책 구조체는 이름, 대여 금액, 책 번호, 대여 여부가 필요하다.
책 목록을 선택하면 책 정보를 출력해준다. 
*/

struct _bookName{
	
	char book_name[BOOK_NAME_SIZE];
	int iPrice;
	int iBookNumber;
	bool bBorrow;
	bool bExist;
	
};



int main(){
	
	// 책(struct) 10개 빈 공간 생성 
	_bookName bookArr[BOOK_MAX] = {};
	_bookName book = {};
//	char checkBookName[BOOK_NAME_SIZE] = {};	
	
	// 책 개수, 책 번호 관리를 위한 변수 
	int iBookCount = 0;
	int bNumber = 1;
	book.bBorrow = false;
	book.bExist = false;
	
	// 책 검색을 위한 변수 
	char searchBookName[BOOK_NAME_SIZE] = {};
	
	while(true){
		system("cls");
		
		cout << "====== 도서 대여 프로그램입니다======" <<  endl;
		cout << "1. 책 등록" << endl;
		cout << "2. 책 대여" << endl;
		cout << "3. 책 반납" << endl;
		cout << "4. 책 목록" << endl;
		cout << "5. 종료" << endl;
		
		cout << "메뉴를 선택하세요: ";
		int iMenu;
		cin >> iMenu;
		
		// 잘못 적을 경우 
		if(cin.fail()){
			
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		} 
		
		
		if(iMenu == BOOK_END)
			break;
		 
		switch (iMenu){
			
			case BOOK_REGISTER:
				system("cls");
				cout << "====== 책 등록 ======" <<  endl;
		
				// 등록된 책이 등록할 수 있는 최대치일 경우 
				// 더이상 등록이 안되게 막는다. 
				if(iBookCount == BOOK_MAX)
					break;
		
		
				cin.ignore(1024, '\n');
				
				cout << "책 이름: ";
				cin.getline(bookArr[iBookCount].book_name, BOOK_NAME_SIZE);
				
				
				cout << "대여 가격: ";
				cin >> bookArr[iBookCount].iPrice;
				
				bookArr[iBookCount].iBookNumber = bNumber;
				bookArr[iBookCount].bBorrow = false;
				
				++iBookCount;
				++bNumber;
				
				cout << "책 등록이 완료되었습니다." << endl;
				
				break;
			case BOOK_CHECK:
				
				system("cls");
				cout << "====== 책 대여 ======" <<  endl;
				
				cin.ignore(1024, '\n');
				
				cout << "대여할 책 이름을 검색하세요: ";
				cin.getline(searchBookName, BOOK_NAME_SIZE);
				
				for(int i = 0; i < iBookCount; ++i){
					
					if(strcmp(bookArr[i].book_name, searchBookName) == 0){
						
						if(bookArr[i].bBorrow == false){
							
							cout << "대여 완료되었습니다." << endl;
							bookArr[i].bBorrow = true;
							book.bBorrow = true;
							break;
						} 
						else{
							cout << "대여가 불가능합니다. 이미 대여된 책입니다." << endl;
							book.bBorrow = true;
							break;
						}
					}	
				}
				if(book.bBorrow == false){
					cout << "없는 책입니다." << endl;
				}
				else{
					book.bBorrow = false;
				}
				
				break;
			case BOOK_RETURN:
				system("cls");
				cout << "====== 책 반납 ======" <<  endl;
				
				cin.ignore(1024, '\n');
				cout << "반납할 책 이름을 입력하세요: ";
				cin.getline(searchBookName, BOOK_NAME_SIZE);
				
				cout << endl;
				
				book.bExist = false;
				for(int i = 0; i < iBookCount; ++i){
					
					if(strcmp(bookArr[i].book_name, searchBookName) == 0){
						
						if(bookArr[i].bBorrow == true){
							
							cout << "반납 완료되었습니다." << endl;
							bookArr[i].bBorrow = false;
							book.bExist = true;
							break;
						} 
						else{
							cout << "반납이 불가능합니다. 이미 대여된 책입니다." << endl;
							book.bExist = true;
							break;
						}
					}	
				}
				if(book.bExist == false){
					cout << "없는 책입니다." << endl;
				}
				
				break;
			case BOOK_LIST:
				system("cls");
				cout << "====== 책 목록 ======" <<  endl;
				
				for(int i = 0; i < iBookCount; ++i){
					
					cout << "책 이름: " << bookArr[i].book_name << endl;
					cout << "대여 가격: " << bookArr[i].iPrice << endl;
					cout << "책 번호: " << bookArr[i].iBookNumber << endl;
					cout << "대여 여부: " << bookArr[i].bBorrow << endl << endl;
							
				}
				
				break;
			default:
				cout << "메뉴를 잘못 선택했습니다." << endl;
				break;
		}
		
		// 입출력이 끝난 뒤 화면이 전환되지 않도록 해줌 
		system("pause");
	}
	
	return 0;
}
