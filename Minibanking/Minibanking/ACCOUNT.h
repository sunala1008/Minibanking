#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "Exception.h"
#include "String.h"

enum {NOR = 1, CRE = 2};

class ACCOUNT
{
private:
	int accID;		// 계좌번호
	int balance;	// 잔액
	String cusName; // 고객 이름

	int indx;		// 일반-신용 구분

public:
	ACCOUNT(const int indx, const int ID, const int money, const String myname) // 생성자
		: accID(ID), balance(money), cusName(myname)
	{
		this->indx = indx;
	}

	ACCOUNT(const ACCOUNT &copy); // default 복사 생성자
	
	int getindx();
	virtual int getaccID();
	virtual int getbalance();
	virtual char* getcusName() const;
	virtual int getroi() = 0;
	virtual char gettrust() = 0;
	virtual void setplusbalance(int money);
	void setminusbalance(int money);

	//~ACCOUNT();
};

#endif // !_ACCOUNT_H_
