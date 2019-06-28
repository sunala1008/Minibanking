#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "MiniBankingCommonDecl.h"

class String //♠
{
private:
	int strLen;
	char * str;

public:
	String() // 기본 생성자
	{
		strLen = 0;
		str = NULL;
	}

	String(const char * str, int len) // 매개변수가 있는 생성자
	{
		strLen = strlen(str) + 1;
		this->str = new char[strLen]; // new 로 char 배열 생성
		strcpy(this->str, str);

		strLen = len;
	}

	// 복사 생성자
	String(const String &copy) : str(copy.str)
	{}

	// 소멸자
	~String()
	{
		delete[]str;
	}
};

class ACCOUNT
{
private:
	int accID;		// 계좌번호
	int balance;	// 잔액
	char * cusName; // 고객 이름
	//myString * cusName;

public:
	ACCOUNT(const int ID, const int money, const char * myname) // 생성자
		: accID(ID), balance(money)
	{
		int len = strlen(myname) + 1;
		cusName = new char[len];
		strcpy(cusName, myname);
	}
	
	int getaccID();
	int getbalance();
	virtual void setplusbalance(int money);
	void setminusbalance(int money);
	char * getcusName();
	~ACCOUNT();
};




#endif // !_ACCOUNT_H_
