#ifndef _STRING_H_
#define _STRING_H_

#include "MiniBankingCommonDecl.h"
#include <cstring>

#define LEN 1000

class String	// ��
{
private:
	int strLen; // ���ڿ� ���� ��� ����
	char * str; // ���ڿ� �迭 �ּ�

public:
	String(); // �⺻ ������

	String(const char * stri); // �Ű������� �ִ� ������

	String(const String &copy); // ���� ������

	//String(String &copy);

	int getLen() const;

	char * getcusNamestr() const;

	~String();	// �Ҹ���

	void operator=(const String &aa);

	char& operator[](int index);

	friend ostream& operator<<(ostream &out, const String &obj);

	friend istream& operator>>(istream &in, String &obj);
};

#endif // !_STRING_H_
