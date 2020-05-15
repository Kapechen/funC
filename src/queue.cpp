#include "queue.h"
#include <cstdlib>
Queue::Queue(int qs) :qsize(qs),front(0),rear(0),items(0)
{
	//����const���Ա�ͱ�����Ϊ���õĳ�Ա������ʹ�ó�Ա��ʼ���б��ʼ������Ϊ����ֻ���ڱ�����ʱ���г�ʼ��
	//ֻ�й��캯������ʹ�ó�ʼ���б���
}
Queue::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;//�ȱ���
		front = front->next;//���ƶ�
		delete temp;//��ɾ��
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
//��item���뵽������
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

/**�˿��෽��**/
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}