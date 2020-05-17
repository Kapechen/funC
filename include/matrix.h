#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
using namespace std;
//泛型矩阵类的简单实现
template <typename Object>
class matrix
{
public:
	//构造函数首先将array构造成具有rows个元素，每个元素都是vector<Object>类型对象，而这些对象均是由零参数构造函数构造而得的向量
	matrix(int rows, int cols)
	{
		if (rows < 0 || cols < 0) {
			cout << "Parameters passed in are invalid!" << endl;
			return;
		}
		array.resize(rows);
		//每行的大小被调整为有cols个列位置
		for (auto& thisRow : array) {
			thisRow.resize(cols);
		}
			
	}
	matrix() :array{ 0 } {
		for (auto& thisRow : array) {
			thisRow.resize(0);
		}
	}
	~matrix(){}
	matrix(vector<vector<Object>> v):array{v}{}
	matrix(vector<vector<Object>> && v):array{std::move(v)}{}
	//m[i]返回对应矩阵第i行的向量 m[i][j]返回向量m[i]中位置j上的元素-------矩阵的operator[]返回一个vector<Object>类型的实体
	//为何有两个版本，一种返回值为常量引用，一种只是单纯返回引用---矩阵copy时，只修改一侧的值
	const vector<Object>& operator[](int row)const {
		return array[row];
	}
	
	vector<Object>& operator[](int row) {
		return array[row];
	}
	int numrows()const
	{
		return array.size();
	}
	int numcols()const
	{
		return numrows() ? array[0].size() : 0;
	}
	void print() {
		int rows = this->numrows();
		int cols = this->numcols();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << array[i][j] << " ";
			}
			cout << "\n";
		}
	}
	//resize函数用于重新调整matrix的大小
	void resize(int rows, int cols) {
		if (rows < 0 || cols < 0) {
			cout << "Parameters passed in are invalid!" << endl;
			return;
		}
		array.resize(rows);
		for (auto& thisRow : array) {
			thisRow.resize(cols);
		}
	}
private:
	vector<vector<Object>> array;//矩阵通过array型数据成员来表示，该数据成员被声明为vector<Object>的一个vector类的对象
};
//测试代码
//matrix<double> m1(-1, 4);
//matrix<double> m1(3,3);
//m1.resize(5, 4);
//m1.print();
//matrix<int> m1(3, 3);
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 3; j++) {
//		m1[i][j] = i;
//	}
//}
//m1.print();
#endif // !MATRIX_H
