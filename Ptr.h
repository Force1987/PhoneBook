#pragma once
#include "Subscriber.h"
#include <string>

/*���� ����� �������� � ���� ��������� �� ������ ���������� �� ���������.
��� ��������� ��� ���������� ��� �������� �������� �� ������������� ��� ����, � ��������� ����������� ������ � ���� ��������*/

class Ptr
{
private:
	Subscriber** ptr;
	int size;
public:
	Ptr(int size = 0);
	~Ptr();
	int GetSize();
	void Add();
	void Delete(int i);
	inline void Print();
	void Search(char* str);
	void SaveFile();
	void LoadFile();
};