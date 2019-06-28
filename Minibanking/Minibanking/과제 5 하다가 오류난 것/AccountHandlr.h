#ifndef _HANDLR_H_
#define _HANDLR_H_

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

typedef ACCOUNT * ACCOUNT_PTR; // ♠

class AccountHandler
{
private:
	ACCOUNT * accArr[100];		// 계좌를 관리할 배열
	//ACCOUNT_PTR * accArr;		// 배열 포인터? ♠
	int accNum;						// 개설된 계좌 수 


public:
	AccountHandler() : accNum(0) // 생성자
	{}

	//AccountHandler(int num) : accNum(num) // ♠
	//{
	//	accArr = new ACCOUNT_PTR[num];
	//}

	//~AccountHandler()	// 소멸자 ♠
	//{
	//	delete[]accArr;
	//}

	void NormalMakeAccount(void);			// 일반 계좌 개설 
	void CreditMakeAccount(void);			// 신용 계좌 개설
	void DepositMoney(void) const;			// 입금
	void WithdrawMoney(void) const;			// 출금
	void AccMenu(void);						// 계좌 개설 메뉴
	void ShowAllAccInfo(void) const; 		// 잔액조회
};

#endif // !_HANDLR_H_
