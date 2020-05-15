#include "queue.h"
#include <cstdlib>
Queue::Queue(int qs) :qsize(qs),front(0),rear(0),items(0)
{
	//对于const类成员和被声明为引用的成员，必须使用成员初始化列表初始化，因为他们只能在被创建时进行初始化
	//只有构造函数可以使用初始化列表方法
}
Queue::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;//先保存
		front = front->next;//再移动
		delete temp;//再删除
	}
}

bool Queue::isempty()const
{
	return items == 0;
}
bool Queue::isfull()const
{
	return items == qsize;
}
int Queue::queuecount()const
{
	return items;
}
//将item加入到队列中
bool Queue::enqueue(const Item& item)
{
	if (isfull())
		return false;
	Node* add = new Node;
	if (add == nullptr)
		return false;
	add->item = item;
	add->next = nullptr;
	items++;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

bool Queue::dequeue(Item& item)
{
	if (front == nullptr)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = nullptr;
	return true;
}

/**顾客类方法**/
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}