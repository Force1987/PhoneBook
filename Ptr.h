#pragma once
#include "Subscriber.h"
#include <string>

/*Этот класс содержит в себе указатель на массив указателей на абонентов.
Это позволяет при добавлении или удалении абонента не пересоздавать всю базу, а совершать манипуляции только с этим массивом*/

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