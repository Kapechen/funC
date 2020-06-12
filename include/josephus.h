#ifndef __JOSEPHUS_H
#define __JOSEPHUS_H
#include <iostream>
#include <list>
#include <ctime>
/*
Josephus问题是下面的游戏:N个人编号1~N，围坐在一个圆圈。从1号人开始传递一个热土豆。经过M次传递后拿着热土豆的人被
清除离座，由坐在被清除人后面的人拿起热土豆继续进行游戏。最后剩下的人获胜。
1.编写一个程序解决在M和N为一般的值下的Josephus问题，应使所编程序尽可能地高效率，要确保各个单元都能被清楚。
2.该程序的运行时间是多少？
3.如果M=1，这个程序的运行时间又是多少？对于N的一些大值，delete例程如何影响该程序的速度？
*/
static int M;  // 传递次数
static int N; // 实时的人数
static int totalround;
extern clock_t start, finish;
extern std::list<int> Circle;
void inputData();  //用于获得玩家输入的N和M值并做检测

void initCircle(); //用于初始化围坐在一起的圆圈

void ComputeResult(); //计算结果并清除
void playGame(); //游戏启动窗口
#endif // !__JOSEPHUS_H
