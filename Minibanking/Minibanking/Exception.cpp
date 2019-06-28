#include "Exception.h"

void D_Exception::ShowExceptionReason()
{
	cout << "┌───────────────────────┐" << endl;
	cout << "│\t\t   ※ 경 고 ※     \t\t│" << endl;
	cout << "│\t   " << depositMoney << "원은 입금이 불가합니다.\t\t│" << endl;
	cout << "└───────────────────────┘" << endl;
	getchar();
	getchar();
}

void W_Exception::ShowExceptionReason()
{
	cout << "┌───────────────────────┐" << endl;
	cout << "│\t\t   ※ 경 고 ※     \t\t│" << endl;
	cout << "│ 잔액이 부족하여 " << balance << "원을 출금할 수 없습니다. │" << endl;
	cout << "└───────────────────────┘" << endl;
	getchar();
	getchar();
}

void FULL_ACCOUNT::ShowAccFull()
{
	cout << "┌───────────────────────┐" << endl;
	cout << "│\t\t   ※ 경 고 ※     \t\t│" << endl;
	cout << "│\t개설 가능한 계좌수를 초과하였습니다.   \t│" << endl;
	cout << "└───────────────────────┘" << endl;
	
	getchar();
	getchar();
}

void AlreadyRegiAcc::ShowAlreadyRegi()
{
	cout << "┌───────────────────────┐" << endl;
	cout << "│\t\t   ※ 경 고 ※     \t\t│" << endl;
	cout << "│\t   이미 등록된 계좌 번호입니다.     \t│" << endl;
	cout << "└───────────────────────┘" << endl;
	getchar();
	getchar();
}

void IntoMoney::ShowIntoMoney() 
{
	cout << "┌───────────────────────┐" << endl;
	cout << "│\t\t   ※ 경 고 ※     \t\t│" << endl;
	cout << "│    계좌 개설 금액은 0원 이상이어야합니다.\t│" << endl;
	cout << "└───────────────────────┘" << endl;
	getchar();
	getchar();
}

void GradeErr::ShowGradeErr()
{
	cout << "┌───────────────────────┐" << endl;
	cout << "│\t\t   ※ 경 고 ※     \t\t│" << endl;
	cout << "│\t  신용 등급을 다시 입력해주세요.      \t│" << endl;
	cout << "└───────────────────────┘" << endl;
	getchar();
	getchar();
}

void NoMinusMoney::ShowNoMinusMoney()
{
	cout << "┌───────────────────────┐" << endl;
	cout << "│\t\t   ※ 경 고 ※     \t\t│" << endl;
	cout << "│\t  " << money << "원은 출금 불가 금액입니다. \t│" << endl;
	cout << "└───────────────────────┘" << endl;
	getchar();
	getchar();
}