#pragma once
#include <iostream>
#include <fstream>
#include <string>
using TInfo = int;

struct NODE
{
	TInfo* info; // ��������� ������������ ������.
	NODE* next;
	NODE(TInfo info, NODE* ptr = nullptr) /*:info(info), next(ptr) {}*/
	{
		this->info = new int(info);// �������� ������������ ������������
		next = ptr;
		
	}
	~NODE() // ����������
	{
		next = nullptr;
		delete info;
	}
};
using  ptrNODE = NODE*;
struct LIST
{
private:
	ptrNODE head, tail;
	TInfo size;
	// � ��������� �����
	void add_by_pointer(ptrNODE& ptr, TInfo elem)
	{
		ptrNODE p = new NODE(elem, ptr);
		ptr = p;
	}
	void del_by_pointer(ptrNODE& ptr)
	{
		ptrNODE p = ptr;
		ptr = p->next;
		delete p;
	}
public:
	LIST()
	{
		head = new NODE(0);
		tail = head;
		size = 0;
	}
	~LIST();
	ptrNODE get_head()
	{
		return head;
	}
	TInfo get_first()
	{
		return *(head->next->info);
	}
	TInfo get_size()
	{
		return size;
	}
	bool empty();
	void add_to_head(TInfo elem);
	void add_to_tail(TInfo elem);
	void add_after(ptrNODE ptr, TInfo elem);
	void del_from_head();
	void del_after(ptrNODE ptr);
	void clear();
	void create_by_stack(std::ifstream& file);
	void create_by_queue(std::ifstream& file);
	void create_by_order(std::ifstream& file);
	void print();
	void print(std::ofstream& file1, const std::string& mess);
	void sorting();
};