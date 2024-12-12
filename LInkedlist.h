#pragma once
#include<iostream>
#include<Exception>
using namespace std;
template<typename T>
class Linkedlist;

template<typename T>
class Node
{
public:
	friend class Linkedlist<T>;
	T value;
	Node* next;
	Node* prev;
public:
	Node(T val, Node* next = nullptr, Node* prev = nullptr);

};

template<typename T>
Node<T>::Node(T val, Node* next, Node* prev) :value(val), next(next), prev(prev) {};

template<typename T>
class Linkedlist
{
public:

	bool empty() const;
	const T& front() const;
	const T& back() const;
	void push_front(const T& e);
	void push_back(const T& e);
	void pop_front();
	void pop_back();
	int size();
	void erase(int ind);
	T& operator[](int ind);
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int Size = 0;

};

template<typename T>
bool Linkedlist<T>::empty() const
{
	if (head == nullptr)return true;
	return false;
}
template<typename T>
inline const T& Linkedlist<T>::front() const
{
	if (this->empty()) throw(_exception());
	return head->value;
}

template<typename T>
const T& Linkedlist<T>::back() const
{
	if (this->empty()) throw(_exception());
	return tail->value;
}

template<typename T>
void Linkedlist<T>::push_front(const T& e)
{
	Size++;
	if (empty())
	{
		Node<T>* temp = new Node<T>(e);
		temp->next = temp;
		temp->prev = temp;
		head = temp;
		tail = temp;
		return;
	}
	Node<T>* temp = new Node<T>(e, head, tail);
	head->prev = temp;
	if (head->next == head) head->next = temp;
	head = temp;
}

template<typename T>
void Linkedlist<T>::push_back(const T& e)
{
	Size++;
	if (empty())
	{
		Node<T>* temp = new Node<T>(e);
		temp->next = temp;
		temp->prev = temp;
		head = temp;
		tail = temp;
		return;
	}
	Node<T>* temp = new Node<T>(e, head, tail);
	tail->next = temp;
	if (tail->prev == tail) tail->prev = temp;
	tail = temp;


}

template<typename T>
void Linkedlist<T>::pop_front()
{
	Size--;
	if (empty())throw  _exception();
	Node<T>* temp = head;
	head = head->next;
	delete temp;

}

template<typename T>
void Linkedlist<T>::pop_back()
{
	Size--;
	if (empty())throw  _exception();
	Node<T>* temp = tail;
	tail = tail->prev;
	delete temp;


}

template<typename T>
inline int Linkedlist<T>::size()
{
	return Size;
}

template<typename T>
void Linkedlist<T>::erase(int ind)
{
	if (ind == 0)
	{
		pop_front();
		return;
	}
	else if(ind = size()-1)
	{
		pop_back();
		return;
	}
	Size--;
	Node<T> *temp = head;
	for (size_t i = 0; i < ind; i++)
	{
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	delete temp;
}

	template<typename T>
	T& Linkedlist<T>::operator[](int ind)
	{
		if (ind >= this->size()) throw out_of_range("Id Don't Exist!!");
		Node<T>* temp = head;
		for (size_t i = 0; i < ind; i++)
		{
			temp = temp->next;
		}
		return temp->value;

	}



