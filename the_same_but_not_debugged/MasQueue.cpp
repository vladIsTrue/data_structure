#include "MasQueue.h"
using namespace std;

MasQueue::MasQueue(int n)
{
	size = n;
	que = new int[n]; // datatype
	head = 0;
	tail = -1;
}
MasQueue::~MasQueue()
{
	delete[] que;
}

void MasQueue::clear()
{
	while (!is_empty())
	{
		deque();
	}
}
bool MasQueue::is_empty()
{
	return tail == -1;
}

void MasQueue::enque(int elem) // datatype elem
{
	int count = tail - head + 1 + size * (head > tail && tail != -1); //count++
	if (count < size) {
		tail = (tail + 1) % size;
		que[tail] = elem;
	}
}
void MasQueue::deque()
{
	int count = tail - head + 1 + size * (head > tail && tail != -1); //count--
	if (count > 0)
		head = (head + 1) % size;
}

int MasQueue::peek()
{
	return que[head]; // Опасно, если head == nullptr
}
