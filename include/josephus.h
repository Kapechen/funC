#ifndef __JOSEPHUS_H
#define __JOSEPHUS_H
#include <iostream>
#include <list>
#include <ctime>
/*
Josephus�������������Ϸ:N���˱��1~N��Χ����һ��ԲȦ����1���˿�ʼ����һ��������������M�δ��ݺ��������������˱�
��������������ڱ�����˺��������������������������Ϸ�����ʣ�µ��˻�ʤ��
1.��дһ����������M��NΪһ���ֵ�µ�Josephus���⣬Ӧʹ������򾡿��ܵظ�Ч�ʣ�Ҫȷ��������Ԫ���ܱ������
2.�ó��������ʱ���Ƕ��٣�
3.���M=1��������������ʱ�����Ƕ��٣�����N��һЩ��ֵ��delete�������Ӱ��ó�����ٶȣ�
*/
static int M;  // ���ݴ���
static int N; // ʵʱ������
static int totalround;
extern clock_t start, finish;
extern std::list<int> Circle;
void inputData();  //���ڻ����������N��Mֵ�������

void initCircle(); //���ڳ�ʼ��Χ����һ���ԲȦ

void ComputeResult(); //�����������
void playGame(); //��Ϸ��������
#endif // !__JOSEPHUS_H
