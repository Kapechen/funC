#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
using namespace std;
//������ļ�ʵ��
template <typename Object>
class matrix
{
public:
	//���캯����array����ɾ���rows��Ԫ�أ�ÿ��Ԫ�ض���vector<Object>���Ͷ��󣬶���Щ�����������������캯��������õ�����
	matrix(int rows, int cols) :array(rows)
	{
		//ÿ�еĴ�С������Ϊ��cols����λ��
		for (auto& thisRow : array)
			thisRow.resize(cols);
	}
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
private:
	vector<vector<Object>> array;//����ͨ��array�����ݳ�Ա����ʾ�������ݳ�Ա������Ϊvector<Object>��һ��vector��Ķ���
};
#endif // !MATRIX_H
