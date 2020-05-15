#include <iostream>
#ifndef STRINGBAD_H_
#define STRINGBAD_H_
class StringBad
{
private:
	char* str;
	int len;
	static int num_strings;
public:
	StringBad(const char* s);
	StringBad();
	StringBad(const StringBad& st);
	StringBad& operator=(const StringBad& st);
	~StringBad();
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st) {
		os << st.str;
		return os;
	}
};

#endif // !STRINGBAD_H_
