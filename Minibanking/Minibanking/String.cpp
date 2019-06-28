#include "String.h"

String::String() // �⺻ ������
{
	strLen = 0;
	str = NULL;
}

String::String(const char * stri) // �Ű������� �ִ� ������
{
	strLen = strlen(stri) + 1;
	str = new char[strLen]; // new �� char �迭 ����
	strcpy(str, stri);
}

String::String(const String &copy)	// ���� ������
{
	this->strLen = strlen(copy.str) + 1;
	this->str = new char[this->strLen];
	strcpy(this->str, copy.str);
}

int String::getLen() const
{
	return strLen;
}

char * String::getcusNamestr() const
{
	return str;
}

String::~String()	// �Ҹ���
{
	delete[] str;
}

void String::operator=(const String &aa)
{
	strLen = strlen(aa.str) + 1;
	this->str = new char[strLen];
	strcpy(this->str, aa.str);
}

char& String::operator[](int index)
{
	return this->str[index];
}

ostream& operator<<(ostream &out, const String &obj)
{
	out << obj.str;
	return out;
}

istream& operator>>(istream &in, String &obj)
{
	char *name = new char[LEN];
	in >> name; // ��
	
	delete[] obj.str;

	obj.strLen = strlen(name) + 1;
	obj.str = new char[obj.strLen];
	strcpy(obj.str, name);
	delete[] name;
	return in;
}