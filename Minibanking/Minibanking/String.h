#ifndef _STRING_H_
#define _STRING_H_

#include "MiniBankingCommonDecl.h"
#include <cstring>

#define LEN 1000

class String	// ☆
{
private:
	int strLen; // 문자열 길이 멤버 변수
	char * str; // 문자열 배열 주소

public:
	String(); // 기본 생성자

	String(const char * stri); // 매개변수가 있는 생성자

	String(const String &copy); // 복사 생성자

	//String(String &copy);

	int getLen() const;

	char * getcusNamestr() const;

	~String();	// 소멸자

	void operator=(const String &aa);

	char& operator[](int index);

	friend ostream& operator<<(ostream &out, const String &obj);

	friend istream& operator>>(istream &in, String &obj);
};

#endif // !_STRING_H_
