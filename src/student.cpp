#include "student.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;
double Student::Average() const
{
	if (scores.size() > 0)
		return scores.sum() / scores.size();
	else
		return 0;
}

const string& Student::Name() const
{
	return name;
}

double& Student::operator[](int i)
{
	return scores[i];
}
double Student::operator[](int i) const
{
	return scores[i];
}


