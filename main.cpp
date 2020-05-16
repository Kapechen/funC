// learnC++.cpp: 定义应用程序的入口点。
//

#include "main.h"

#include <string>
#include <vector>
#include <iostream>
//#include <cctype>
//#include <string>
//#include "mycollection.h"
#include "matrix.h"
using namespace std;




int main()
{
	matrix<int> m1(3, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m1[i][j] = i;
		}
	}
	m1.print();


return 0;
}
