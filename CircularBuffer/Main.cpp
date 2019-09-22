#include "CircularBuffer.h"
#include <thread>
#include <Windows.h>

CircularBuffer<int> cBuf = CircularBuffer<int>(32);
template<typename T> void Push(CircularBuffer<T>* buf);
template<typename T> void Pop(CircularBuffer<T>* buf);

int main()
{
	thread threadPush(&Push<int>, &cBuf);
	thread threadPop(&Pop<int>, &cBuf);

	if (threadPush.joinable()) threadPush.join();
	if (threadPop.joinable()) threadPop.join();

	return 0;
}

template<typename T>
void Push(CircularBuffer<T>* buf)
{
	int count = 0;

	while (true)
	{
		Sleep(250 + rand() % 501);

		T data = rand() % 100;

		buf->Push(data);
		cout << "PUSH\t" << count++ << ":\t\t" << data << endl;
	}
}

template<typename T>
void Pop(CircularBuffer<T>* buf)
{
	int count = 0;

	while (true)
	{
		Sleep(1000 + rand() % 1001);

		T data = buf->Pop();
		cout << ">>POP\t" << count++ << ": \t\t\t\t" << data << endl;
	}
}