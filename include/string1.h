#include <iostream>
using std::ostream;
using std::istream;

#ifndef  STRING1_H_
#define STRING1_H_
class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;//cin input limit
public:
	//constructors and other methods
	String(const char* s);
	String();
	String(const String&);//¿½±´¹¹Ôìº¯Êý
	~String();
	int length()const { return len; }
	//overloaded operator methods
	String& operator=(const String&);
	String& operator=(const char*);
	char& operator[](int i);
	const char& operator[](int i) const;
	//overloaded operator friends
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st)
	{
		os << st.str;
		return os;
	}
	friend istream& operator>>(istream& is, String& st)
	{
		char temp[String::CINLIM];
		is.get(temp, String::CINLIM);
		if (is)
			st = temp;
		while (is && is.get() != '\n')
			continue;
		return is;
	}
	//static function
	static int HowMany();
};
#endif // ! STRING1_H_
