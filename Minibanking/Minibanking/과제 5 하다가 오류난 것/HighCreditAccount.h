#ifndef _CREDIT_H_
#define _CREDIT_H_

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount	// 신용 신뢰 계좌 entity class
{
private:
	int plusroi;		// 추가 이율

public:
	HighCreditAccount(const int ID, const int Money,
		const char * myname, const int rate, const int prate)
		: NormalAccount(ID, Money, myname, rate)
	{
		plusroi = prate;
	}

	//HighCreditAccount(const HighCreditAccount &copy) // default 복사 생성자
	//	: NormalAccount(copy.getaccID, copy.getbalance, copy.getcusName, copy.getroi),
	//		plusroi(copy.plusroi)
	//{	}

	void setplusbalance(int money);
};

enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 }; // 신용 등급

#endif // !_CREDIT_H_
