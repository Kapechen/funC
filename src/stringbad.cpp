#include "stringbad.h"
#include <cstring>
using std::cout;


int StringBad::num_strings = 0;

StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char(len + 1);
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ":\"" << str << "\"object created\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ":\"" << str << "\"default object created\n";
}
//��ʾ�Ķ���Ĭ�ϸ��ƹ��캯������������ȸ���
StringBad::StringBad(const StringBad& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	cout << num_strings << ":\"" << str << "\" object created\n";
}
//��ȸ��� 
StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st)
		return *this;
	delete[] str; //�ͷ�strԭ��ָ����ڴ棬�Ա㽫һ�����ַ����ĵ�ַ����str
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
	// TODO: �ڴ˴����� return ���
}

StringBad::~StringBad()
{
	cout << "\"" << str << "\" object deleted,";
	--num_strings;
	cout << num_strings << " left\n";
	delete[] str;
}

