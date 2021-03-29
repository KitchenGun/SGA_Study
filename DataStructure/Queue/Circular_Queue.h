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
		datas = NULL;
	}

	int Capacity() { return capacity; }
	int Front() { return front; }
	int Rear() { return rear; }

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

	T Dequeue()
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

	bool isEmpty()
	{
		return front == rear;
	}

	bool isFull()
	{
		if (front < rear)
		{
			return (rear - front) == capacity;
		}
		return (rear + 1) == front;
	}

	int Size()
	{
		if (front <= rear)
		{
			return rear - front;
		}
		return rear + (capacity - front)+1;
	}

	
private:
	T* datas;

	int capacity;
	int front = 0;//��
	int rear = 0;//��

};