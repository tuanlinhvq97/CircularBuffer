#pragma once

#include <iostream>
using namespace std;

template<class T>
class CircularBuffer
{
private:
	unsigned int size;
	int head;
	int tail;
	bool full;
	T* buffer;

public:
	CircularBuffer(unsigned int sz);
	unsigned int Count();
	bool IsFull();
	bool IsEmpty();
	T Pop();
	void Push(T data);
};

template<class T>
CircularBuffer<T>::CircularBuffer(unsigned int sz)
{
	size = sz;
	buffer = new T[sz];
	head = 0;
	tail = 0;
	full = false;
}

template<class T>
unsigned int CircularBuffer<T>::Count()
{
	return size;
}

template<class T>
bool CircularBuffer<T>::IsFull()
{
	return full;
}

template<class T>
bool CircularBuffer<T>::IsEmpty()
{
	return (!full && (head == tail));
}

template<class T>
T CircularBuffer<T>::Pop()
{
	if (IsEmpty()) return T();
	T data = buffer[tail++];
	full = false;
	tail %= size;
	return data;
}

template<class T>
void CircularBuffer<T>::Push(T data)
{
	buffer[head++] = data;
	if (IsFull()) tail = (tail++) % size;
	head %= size;
	full = (head == tail);
}
