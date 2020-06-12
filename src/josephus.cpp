#include "josephus.h"

std::list<int> Circle;
clock_t start, finish;
void inputData()
{
	std::cout << "请输入总人数N:\n";
	std::cin >> N;
	//检测机制待完善，如何判断是否是整数输入？
	while (N <= 0 || sizeof(N) != 4) {
	std::cout << "输入值非法,请重新输入N:\n";
	std::cin >> N;
	}
	
	std::cout << "请输入传递次数M:\n";
	std::cin >> M;
	while (M <= 0 || sizeof(M) != 4) {
		std::cout << "输入值非法,请重新输入N:\n";
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
	// 打印结果
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
	std::cout << "游戏共进行了" << totalround << "轮删除\n";
	std::cout << "最终胜利者为:" << *iter << "\n";
	std::cout << "程序运行时间为: " << total_time << " 毫秒\n";
}

void playGame()
{
	std::cout << "输入y或Y开始游戏,输入q或Q退出游戏!\n";
	char input;
	std::cin >> input;
	while (input != 'q' && input != 'Q' && input != 'y' && input != 'Y') {
		std::cout << "输入有误，请重新输入!\n";
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
		std::cout << "输入y或Y继续游戏，输入q或Q退出游戏!\n";
		std::cin >> input;
		while (input != 'q' && input != 'Q' && input != 'y' && input != 'Y') {
			std::cout << "输入有误，请重新输入!\n";
			std::cin >> input;
		}
		if (input == 'q' || input == 'Q')
		{
			std::cout << "bye!\n";
			break;
		}
	}
}

