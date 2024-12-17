#pragma once
#include<exception>
#include<iostream>
using namespace std;
template<typename T>
class Queue
{
public:
	Queue(int capacity);
	void dequeue();
	void inqueue(T val);
	void clear();
	bool IsEmpty();
	T& Front();


private:
	T* queue;
	int capacity=0;
	int size=0;
	int rear = 0;
	int front = 0;

};

template<typename T>
Queue<T>::Queue(int capacity)
{
	if (capacity < 1) throw std::invalid_argument("Invalid input");

	queue = new T[capacity];
	this->capacity = capacity;
	front = rear = 0;
}

template<typename T>
void Queue<T>::dequeue()
{
	if (IsEmpty())throw std::underflow_error("stack is empty");
	front = (front + 1) % capacity;
	queue[front].~T();
}

template<typename T>
void Queue<T>::inqueue(T val)
{
	if(((rear+1)%capacity) ==front)
	{
		T* temp = new T[capacity * 2];
		int j = 0;
		while (front%capacity != rear)
		{
			(front++)%capacity;
			temp[j] = queue[front];
			j++;
		}
		rear = j - 1;
		front = (capacity * 2)-1;
		capacity *= 2;
		delete[] queue;
		queue = temp;
	}
	rear = (rear + 1) % capacity;
	queue[rear] = val;


}

template<typename T>
inline void Queue<T>::clear()
{
	delete[] queue;
	queue = new T[capacity];
}

template<typename T>
inline bool Queue<T>::IsEmpty()
{
	if (front == rear)return true;
	return false;
}

template<typename T>
inline T& Queue<T>::Front()
{
	if (IsEmpty())throw underflow_error("Queue is empty");
	return queue[((front + 1) % capacity)];


}
