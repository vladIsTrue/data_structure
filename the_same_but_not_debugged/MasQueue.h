#pragma once
using namespace std;

class MasQueue {
	int* que; //datatype
	int size;
	int tail, head;
	//int count - ��� ���� ��� �� ������ ��� �� �������������

public:
	MasQueue(int n);
	~MasQueue();
	void clear();
	bool is_empty();
	void enque(const int value); // ����������
	void deque(); // ��������
	int peek();
}