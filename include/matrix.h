#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
using namespace std;
//���;�����ļ�ʵ��
template <typename Object>
class matrix
{
public:
	//���캯�����Ƚ�array����ɾ���rows��Ԫ�أ�ÿ��Ԫ�ض���vector<Object>���Ͷ��󣬶���Щ�����������������캯��������õ�����
	matrix(int rows, int cols)
	{
		if (rows < 0 || cols < 0) {
			cout << "Parameters passed in are invalid!" << endl;
			return;
		}
		array.resize(rows);
		//ÿ�еĴ�С������Ϊ��cols����λ��
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
	//m[i]���ض�Ӧ�����i�е����� m[i][j]��������m[i]��λ��j�ϵ�Ԫ��-------�����operator[]����һ��vector<Object>���͵�ʵ��
	//Ϊ���������汾��һ�ַ���ֵΪ�������ã�һ��ֻ�ǵ�����������---����copyʱ��ֻ�޸�һ���ֵ
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
	//resize�����������µ���matrix�Ĵ�С
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
	vector<vector<Object>> array;//����ͨ��array�����ݳ�Ա����ʾ�������ݳ�Ա������Ϊvector<Object>��һ��vector��Ķ���
};
//���Դ���
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
