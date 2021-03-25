#pragma once


template<typename T>class Circular_Queue
{
public:
	Circular_Queue(int capacity) : capacity(capacity)
	{//���� �迭�� ũ��� capacity + 1
		datas = new T[capacity + 1];
	}

	~Circular_Queue()
	{
		delete[] datas;
		datas = NUll;
	}

	void Enqueue(T data)
	{
		int position = 0;
		if (rear == capacity)
		{
			position = rear;
			rear = 0;
		}
		else
			position = rear++;

		datas[position] = data;
	}

	T Deque()
	{
		int position = front;
		if (front == capacity)
		{
			front = 0;
		}
		else
		{
			front++;
		}
		return datas[position];
	}
private:
	T* datas;

	int capacity;
	int front = 0;//��
	int rear = 0;//��

};