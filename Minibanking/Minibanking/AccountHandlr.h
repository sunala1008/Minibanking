#ifndef _HANDLR_H_
#define _HANDLR_H_

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "AccArr.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"
#include "ScreenOut.h"
#include "Exception.h"

class AccountHandler
{
private:
	ACCOUNT_PTR accArr[MAXACCOUNT]; // 계좌를 관리할 배열
	int accNum;				 // 개설된 계좌 수

public:
	AccountHandler(); // 생성자
	
	~AccountHandler(); // 소멸자

	void AccMenu(void);								 // 계좌 개설 메뉴
	void NormalMakeAccount(void);					 // 일반 계좌 개설 
	void CreditMakeAccount(void);					 // 신용 계좌 개설
	
	void DepositMoney(void) const;					 // 입금
	void WithdrawMoney(void) const;					 // 출금

	void ShowAccInfo() const;						 // 계좌 정보 출력

	// 파일 입력으로 생성된 보통계좌
	void FMNormalAcc(int indx, int ID, int balance, String Name, int rate, char tru);

	// 파일 입력으로 생성된 신용계좌
	void FMHighCreditAcc(int indx, int ID, int balance, String Name, int rate, char tru);
};

class IO_File				// 파일 입력
{
private:
	int indx;				// 일반-신용 구분
	int id;					// 계좌 번호
	String name;			// 고객 명
	int balance;			// 금액
	int roi;				// 이율
	char trust;				// 신뢰등급

public:
	void input(AccountHandler &hand, ifstream &fin); // 파일 업로드 - 입력
};

#endif // !_HANDLR_H_
