#pragma once


template<typename T>class Circular_Queue
{
public:
	Circular_Queue(int capacity)
		:capacity(capacity)
	{
		datas = new T[capacity + 1];
	}

	~Circular_Queue()
	{
		delete[] datas;
		datas = nullptr;
	}

	int Capacity() { return capacity; }
	int Front() { return front; }
	int Rear() { return rear; }

	T Datas() { return datas; }

	void Enqueue(T data)//�����͸� �Է��ϴ� �Լ�	
	{
		int position = 0;
		if (rear == capacity)//�� ã����� ������
		{
			position = rear;
			rear = 0;
		}
		else
			position = rear++;
		if (rear == front)
			front++;
		datas[position] = data;
	}

	T Dequeue()//�����͸� ����ϴ� �Լ�
	{
		int position = front;
		if (front == capacity)
		{
			front = 0;
		}
		else
			front++;

		return datas[position];
	}

	bool isEmpty()
	{
		return front == rear;
	}

	int Size()
	{
		if(front<=rear)
			return rear - front;
		else
			return (capacity - front) + rear + 1;
	}

	bool IsFull()
	{
		if (front < rear)
			return rear - front == capacity;
		return rear + 1 == front;
	}
private:
	T* datas;

	int capacity = 5;
	int front = 0;
	int rear = 0;
};