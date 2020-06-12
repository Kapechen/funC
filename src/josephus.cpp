#include "josephus.h"

std::list<int> Circle;
clock_t start, finish;
void inputData()
{
	std::cout << "������������N:\n";
	std::cin >> N;
	//�����ƴ����ƣ�����ж��Ƿ����������룿
	while (N <= 0 || sizeof(N) != 4) {
	std::cout << "����ֵ�Ƿ�,����������N:\n";
	std::cin >> N;
	}
	
	std::cout << "�����봫�ݴ���M:\n";
	std::cin >> M;
	while (M <= 0 || sizeof(M) != 4) {
		std::cout << "����ֵ�Ƿ�,����������N:\n";
		std::cin >> M;
	}
}

void initCircle()
{
	Circle.resize(N);
	std::list<int>::iterator iter;
	int i = 0;
	for (iter = Circle.begin(); iter != Circle.end(); iter++)
	{
		*iter = ++i;
	}
	// ��ӡ���
	//for (iter = Circle.begin(); iter != Circle.end(); iter++)
	//{
	//	if (*iter % 8 == 0) {
	//		std::cout << "\n";
	//	}
	//	std::cout << *iter << "  ";
	//}
	//std::cout << "\n";
}

void ComputeResult()
{
	start = clock();
	std::list<int>::iterator iter;
	//std::list<int>::iterator startiter;
	std::list<int>::iterator to_delete;
	int step;
	totalround = 0;
	while (Circle.size() > 1)
	{
		if (totalround == 0) {
			iter = Circle.begin();
		}
		for (step = 0; step < M; step++)
		{
			iter++;
			if (iter == Circle.end())
			{
				iter = Circle.begin();
			}
		}
		to_delete = iter;
		iter++;
		if (iter == Circle.end())
		{
			iter = Circle.begin();
		}
		Circle.erase(to_delete);
		totalround++;
	}
	finish = clock();
	double total_time = (double)finish - start;
	std::cout << "��Ϸ��������" << totalround << "��ɾ��\n";
	std::cout << "����ʤ����Ϊ:" << *iter << "\n";
	std::cout << "��������ʱ��Ϊ: " << total_time << " ����\n";
}

void playGame()
{
	std::cout << "����y��Y��ʼ��Ϸ,����q��Q�˳���Ϸ!\n";
	char input;
	std::cin >> input;
	while (input != 'q' && input != 'Q' && input != 'y' && input != 'Y') {
		std::cout << "������������������!\n";
		std::cin >> input;
	}
	if (input == 'q' || input == 'Q') {
		std::cout << "bye!\n";
		return; 
	}
	while (input == 'y' || input == 'Y')
	{
		inputData();
		initCircle();
		ComputeResult();
		std::cout << "����y��Y������Ϸ������q��Q�˳���Ϸ!\n";
		std::cin >> input;
		while (input != 'q' && input != 'Q' && input != 'y' && input != 'Y') {
			std::cout << "������������������!\n";
			std::cin >> input;
		}
		if (input == 'q' || input == 'Q')
		{
			std::cout << "bye!\n";
			break;
		}
	}
}

