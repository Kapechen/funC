#ifndef QUEUE_H_
#define QUEUE_H_
class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when()const { return arrive; }
	int ptime()const { return processtime; }
};
typedef Customer Item;

class Queue
{
private:
	enum
	{
		Q_SIZE = 10
	};
	struct Node
	{
		Item item;
		struct Node* next;
	};
	Node* front;//指向队列前部的指针
	Node* rear;//指向队列后部的指针
	int items;//当前队列中的items数目
	const int qsize;
	//避免类被复制
	Queue(const Queue &q):qsize(0){}
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty()const;
	bool isfull()const;
	int queuecount()const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};
#endif // !QUEUE_H_
