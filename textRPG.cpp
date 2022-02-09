#include <iostream>
#include <time.h>

using namespace std;

enum MAIN_MENU
{
    MM_NONE,
    MM_MAP,
    MM_STORE,
    MM_INVENTORY,
    MM_EXIT
};


enum MAP_TYPE
{
    MT_NONE,
    MT_EASY,
    MT_NORMAL,
    MT_HARD,
    MT_BACK
};


enum JOB
{
    JOB_NONE,
    JOB_KNIGHT,
    JOB_ARCHER,
    JOB_WIZARD,
    JOB_END
};

enum BATTLE
{
    BATTLE_NONE,
    BATTLE_ATTACK,
    BATTLE_BACK
};



struct _tagInventory
{
    int iGold;
};


#define NAME_SIZE 32

struct _tagPlayer
{
    char strName[NAME_SIZE];
    char strJobName[NAME_SIZE];
    JOB eJob;
    int iAttackMin;
    int iAttackMax;
    int iArmorMin;
    int iArmorMax;
    int iHP;
    int iHPMax;
    int iMP;
    int iMPMax;
    int iExp;
    int iLevel;
    _tagInventory tInventory;
};

struct _tagMonster
{
    char strName[NAME_SIZE];
    int iAttackMin;
    int iAttackMax;
    int iArmorMin;
    int iArmorMax;
    int iHP;
    int iHPMax;
    int iMP;
    int iMPMax;
    int iLevel;
    int iExp;
    int iGoldMin;
    int iGoldMax;

};




int main() {

    srand((unsigned int)time(0));

    // 게임을 시작할때 플레이어 정보를 설정하게 한다.
    _tagPlayer tPlayer = {};

    // 플레이어 이름을 입력 받는다.
    cout << "이름 : ";
    cin.getline(tPlayer.strName, NAME_SIZE - 1);

    int iJob = JOB_NONE;
    while (iJob == JOB_NONE)
    {
        system("cls");
        cout << "1. 기사" << endl;
        cout << "2. 궁수" << endl;
        cout << "3. 마법사" << endl;
        cout << "직업을 선택하세요 : ";
        cin >> iJob;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if (iJob <= JOB_NONE || iJob >= JOB_END)
            iJob = JOB_NONE;

    }


    tPlayer.iLevel = 1;
    tPlayer.iExp = 0;
    tPlayer.eJob = (JOB)iJob;
    tPlayer.tInventory.iGold = 10000;


    switch (tPlayer.eJob)
    {
    case JOB_KNIGHT:
        strcpy_s(tPlayer.strJobName, "기사");
        tPlayer.iAttackMin = 5;
        tPlayer.iAttackMax = 10;
        tPlayer.iArmorMin = 15;
        tPlayer.iArmorMax = 20;
        tPlayer.iHPMax = 500;
        tPlayer.iHP = 500;
        tPlayer.iMP = 100;
        tPlayer.iMPMax = 100;
        break;
    case JOB_ARCHER:
        strcpy_s(tPlayer.strJobName, "궁수");
        tPlayer.iAttackMin = 10;
        tPlayer.iAttackMax = 15;
        tPlayer.iArmorMin = 10;
        tPlayer.iArmorMax = 15;
        tPlayer.iHPMax = 400;
        tPlayer.iHP = 400;
        tPlayer.iMP = 200;
        tPlayer.iMPMax = 200;
        break;
    case JOB_WIZARD:
        strcpy_s(tPlayer.strJobName, "마법사");
        tPlayer.iAttackMin = 15;
        tPlayer.iAttackMax = 20;
        tPlayer.iArmorMin = 5;
        tPlayer.iArmorMax = 10;
        tPlayer.iHPMax = 300;
        tPlayer.iHP = 300;
        tPlayer.iMP = 300;
        tPlayer.iMPMax = 300;
        break;
    }


    // 몬스터를 생성한다
    _tagMonster tMonsterArr[MT_BACK - 1] = {};

    // 고블린 생성
    strcpy_s(tMonsterArr[0].strName, "고블린");
    tMonsterArr[0].iAttackMin = 20;
    tMonsterArr[0].iAttackMax = 30;
    tMonsterArr[0].iArmorMin = 2;
    tMonsterArr[0].iArmorMax = 5;
    tMonsterArr[0].iHP = 100;
    tMonsterArr[0].iHPMax = 100;
    tMonsterArr[0].iMP = 10;
    tMonsterArr[0].iMPMax = 10;
    tMonsterArr[0].iLevel = 1;
    tMonsterArr[0].iExp = 1000;
    tMonsterArr[0].iGoldMin = 500;
    tMonsterArr[0].iGoldMax = 1500;

    // 트롤 생성
    strcpy_s(tMonsterArr[1].strName, "트롤");
    tMonsterArr[1].iAttackMin = 80;
    tMonsterArr[1].iAttackMax = 130;
    tMonsterArr[1].iArmorMin = 60;
    tMonsterArr[1].iArmorMax = 90;
    tMonsterArr[1].iHP = 2000;
    tMonsterArr[1].iHPMax = 2000;
    tMonsterArr[1].iMP = 100;
    tMonsterArr[1].iMPMax = 100;
    tMonsterArr[1].iLevel = 5;
    tMonsterArr[1].iExp = 7000;
    tMonsterArr[1].iGoldMin = 6000;
    tMonsterArr[1].iGoldMax = 8000;

    // 드래곤 생성
    strcpy_s(tMonsterArr[2].strName, "드래곤");
    tMonsterArr[2].iAttackMin = 250;
    tMonsterArr[2].iAttackMax = 500;
    tMonsterArr[2].iArmorMin = 200;
    tMonsterArr[2].iArmorMax = 400;
    tMonsterArr[2].iHP = 30000;
    tMonsterArr[2].iHPMax = 30000;
    tMonsterArr[2].iMP = 20000;
    tMonsterArr[2].iMPMax = 20000;
    tMonsterArr[2].iLevel = 10;
    tMonsterArr[2].iExp = 30000;
    tMonsterArr[2].iGoldMin = 20000;
    tMonsterArr[2].iGoldMax = 50000;


    while (true) {
        system("cls");
        cout << "************************** 로비 **************************" << endl;
        cout << "1. 맵" << endl;
        cout << "2. 상점" << endl;
        cout << "3. 가방" << endl;
        cout << "4. 종료" << endl;
        cout << "메뉴를 선택하세요 : ";
        int iMenu;
        cin >> iMenu;

        if (cin.fail()) {

            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        if (iMenu == MM_EXIT)
            break;


        switch (iMenu) {

        case MM_MAP:
            while (true) {
                system("cls");
                cout << "************************** 맵 **************************" << endl;
                cout << "1. 쉬움" << endl;
                cout << "2. 보통" << endl;
                cout << "3. 어려움 " << endl;
                cout << "4. 뒤로가기" << endl;
                cout << "맵을 선택하세요: ";
                cin >> iMenu;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }

                // 이 if문에 속한 break는 맵 메뉴를 돌려주기 위한 while에 속해 있으므로
                // 이 while문을 빠져나간다.
                if (iMenu == MT_BACK)
                    break;

                // 선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스가 된다.
                // 그렇게 해서 해당 맵의 몬스터를 생성해준다.
                _tagMonster tMonster = tMonsterArr[iMenu - 1];

                while (true) {

                    system("cls");

                    switch (iMenu)
                    {
                    case MT_EASY:
                        cout << "************************** 쉬움 **************************" << endl;
                        break;
                    case MT_NORMAL:
                        cout << "************************** 보통 **************************" << endl;
                        break;
                    case MT_HARD:
                        cout << "************************** 어려움 **************************" << endl;
                        break;
                    }

                    // 플레이어 정보를 출력한다.
                    cout << "************************** Player **************************" << endl;
                    cout << "이름 : " << tPlayer.strName << "\t직업 : " << tPlayer.strJobName << endl;
                    cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << endl;
                    cout << "공격력 : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax << "\t방어력 : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
                    cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
                    cout << "보유골드 : " << tPlayer.tInventory.iGold << " Gold" << endl;


                    // 몬스터 정보 출력
                    cout << "************************** Monster **************************" << endl;
                    cout << "이름 : " << tMonster.strName << "\t레벨 : " << tMonster.iLevel << endl;
                    cout << "공격력 : " << tMonster.iAttackMin << " - " << tMonster.iAttackMax << "\t방어력 : " << tMonster.iArmorMin << " - " << tMonster.iArmorMax << endl;
                    cout << "체력 : " << tMonster.iHP << " / " << tMonster.iHPMax << "\t마나 : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
                    cout << "획득 경험치 : " << tMonster.iExp << "\t획득골드 : " << tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl;


                    cout << "1. 공격" << endl;
                    cout << "2. 도망가기" << endl;
                    cout << "메뉴를 선택하세요 : ";
                    cin >> iMenu;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1024, '\n');
                        continue;
                    }
                    else if (iMenu == BATTLE_BACK)
                        break;

                    switch (iMenu) {

                    case BATTLE_ATTACK:
                    {
                        int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) + tPlayer.iAttackMin;
                        int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) + tMonster.iArmorMin;

                        int iDamage = iAttack - iArmor;

                        
                        iDamage = iDamage < 1 ? 1 : iDamage;


                        // 몬스터 HP를 감소시킨다.
                        tMonster.iHP -= iDamage;

                        cout << tPlayer.strName << "가 " << tMonster.strName << "에게  " << iDamage << " 피해를 입혔습니다." << endl;

                        // 몬스터가 죽었을 경우를 처리한다.
                        if (tMonster.iHP <= 0) {

                            cout << tMonster.strName << " 몬스터가 사망하였습니다." << endl;

                            tPlayer.iExp += tMonster.iExp;
                            int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin);
                            tPlayer.tInventory.iGold += iGold;

                            cout << tMonster.iExp << " 경험치를 획득하였습니다." << endl;
                            cout << iGold << " Gold를 획득하였습니다." << endl;

                            tMonster.iHP = tMonster.iHPMax;
                            tMonster.iMP = tMonster.iMPMax;

                            system("pause");
                            break;

                        }

                        // 몬스터가 살아있다면 플레이어를 공격한다.
                        iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin;
                        iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) + tPlayer.iArmorMin;

                        iDamage = iAttack - iArmor;

                        iDamage = iDamage < 1 ? 1 : iDamage;


                        // 플레이어의 HP를 감소시킨다.
                        tPlayer.iHP -= iDamage;

                        cout << tMonster.strName << "가 " << tPlayer.strName << "에게  " << iDamage << " 피해를 입혔습니다." << endl;

                        // 플레이어가 죽었을 경우를 처리한다.
                        if (tPlayer.iHP <= 0) {

                            cout << tPlayer.strName << " 플레이어가 사망하였습니다." << endl;

                            int iExp = tPlayer.iExp * 0.1f;
                            int iGold = tPlayer.tInventory.iGold * 0.1f;

                            tPlayer.iExp -= iExp;
                            tPlayer.tInventory.iGold -= iGold;
                            

                            cout << iExp << " 경험치를 잃었습니다." << endl;
                            cout << iGold << " Gold를 잃었습니다." << endl;


                            // 플레이어의 HP와 MP를 회복한다.
                            tPlayer.iHP = tPlayer.iHPMax;
                            tPlayer.iMP = tPlayer.iMPMax;

                        }
                        system("pause");
                    }
                    break;
                    }

                }


            }
            break;
        case MM_STORE:
            break;
        case MM_INVENTORY:
            break;
        default:
            cout << "잘못 선택하였습니다." << endl;
            break;
        }

    }

    return 0;
}
