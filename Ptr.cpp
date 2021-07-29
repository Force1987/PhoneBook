#include "Ptr.h"
#include <Windows.h>

Ptr::Ptr(int size)
{
	ptr = new Subscriber * [size];
	for (int i = 0; i < size; i++)
		ptr[i] = new Subscriber();
	Ptr::size = size;
}

Ptr::~Ptr()
{
	for (int i = 0; i < size; i++)
	{
		delete ptr[i];
		ptr[i] = nullptr;
	}
	delete[]ptr;
}

int Ptr::GetSize()
{
	return size;
}

void Ptr::Add()
{
	Subscriber** temp = new Subscriber * [size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = this->ptr[i];
	}
	temp[this->size++] = new Subscriber;
	swap(temp, ptr);
}

void Ptr::Delete(int i)
{
	Subscriber** temp = new Subscriber * [size - 1];
	for (int j = i; j < size; j++)
	{
		swap(this->ptr[j], this->ptr[j - 1]);
	}
	for (int j = 0; j < size - 1; j++)
	{
		temp[j] = this->ptr[j];
	}
	delete ptr[--size];
	swap(temp, ptr);
}

inline void Ptr::Print()
{
	int  init_ctr = 0;
	for (int i = 0, temp_init; i < size; i++)
	{
		temp_init = ptr[i]->Get_init_ctr();
		if (init_ctr < temp_init)init_ctr = temp_init;
	}
	cout << "�  ";
	(init_ctr > 6) ? cout << setw(init_ctr / 2 + 3) << "�.�.�." << setw(init_ctr % 2 == 0 ? init_ctr / 2 - 3 : init_ctr / 2 - 2) << "" << " " : cout << setw(6) << "�.�.�. ";
	cout << "�������� �������  ������� �������  ������� ������� ���. ���������� \n\n";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "  ";
		ptr[i]->Print(init_ctr);
	}
}

void Ptr::Search(char* str)
{
	_strlwr_s(str, _msize(str)); //��������� ���������� ������������� ��������� � ������ ������� ��� �������� ���������
	int init_ctr = 0;			 //���������� ��� ������ ����� ������� ������ ����� ������������ � ����������
	int* arr = new int[size] {}; //������ ��� �������� ������� �������� ��������, ��� ������� ����������. ����� ��� ����, ����� �� ��������� ���� for ������
	int j = 0;					 //������� ����������
	for (int i = 0; i < size; i++)
	{
		int length = ptr[i]->Get_init_ctr() + 1;
		char* src = new char[length];
		strcpy_s(src, length, ptr[i]->Get_init());
		_strlwr_s(src, length);
		if (strstr(src, str) != NULL)
		{
			int temp_init = ptr[i]->Get_init_ctr();
			if (init_ctr < temp_init)init_ctr = temp_init;
			arr[j++] = i;
		}
		delete[]src;
	}
	cout << "�  ";
	(init_ctr > 6) ? cout << setw(init_ctr / 2 + 3) << "�.�.�." << setw(init_ctr % 2 == 0 ? init_ctr / 2 - 3 : init_ctr / 2 - 2) << "" << " " : cout << "�.�.�. ";
	cout << "�������� �������  ������� �������  ������� ������� ���. ���������� \n\n";
	for (int i = 0; i < j; i++)
	{
		cout << arr[i] + 1 << "  ";
		ptr[arr[i]]->Print(init_ctr);
	}
	delete[]arr;
}

void Ptr::SaveFile()
{
	SetFileAttributes(L"���������� �����.txt", FILE_ATTRIBUTE_NORMAL);
	ofstream result("���������� �����.txt", ios_base::trunc);
	if (result.is_open()) {
		streambuf* backup = cout.rdbuf();
		cout.rdbuf(result.rdbuf());
		Print();
		cout.rdbuf(backup);
		result.close();
		/*wstring put = L"���������� �����.txt";
		LPCWSTR name2 = put.c_str();*/
		SetFileAttributes(L"���������� �����.txt", FILE_ATTRIBUTE_READONLY);
		cout << "���� ������� ������.\n";
	}
	else
	{
		cout << "�� ������� ������� ���� �� �����\n";
	}
	system("pause");
}

void Ptr::LoadFile()
{
	int counter = 0;
	string str;
	ifstream count("���������� �����.txt");
	if (count.is_open())
	{
		while (!count.eof())
		{
			getline(count, str);
			if (str == "\0")
			{
				continue;
			}
			counter++;
		}
		count.close();
		for (int i = 0; i < size; i++)
		{
			delete ptr[i];
		}
		delete[]ptr;
		ptr = new Subscriber * [--counter];
		Ptr::size = counter;
		for (int i = 0; i < size; i++)
			ptr[i] = new Subscriber(0);
		ifstream spisok("���������� �����.txt");
		if (spisok.is_open()) {
			getline(spisok, str);
			int name_ctr = 5; //������������ ������ ���� "�.�.�.": ���������� ��� ����� 6, �� ������� ������ ����� ��������� ���������� ������ 5
			for (int i = 9; str[i] != '�'; i++, name_ctr++) {} //������ 3 ������� - ��� �����, ��������� 6 ����� ����������� �.�.�. ����� �������� � 9-�� �������
			for (int i = 0; i < size; i++)
			{
				getline(spisok, str);
				if (str == "\0") { i--; continue; }
				int length_ctr = name_ctr + 1;
				counter = 3;
				for (counter; counter < name_ctr + 3; counter++, length_ctr--)
				{
					if (str[counter] == char(32))
						continue;
					else
					{
						char* initials = new char[length_ctr];
						for (int x = 0; counter < name_ctr + 3; counter++)
						{
							initials[x++] = str[counter];
						}
						initials[length_ctr - 1] = '\0';
						ptr[i]->Set_Init(initials);
						break;
					}
				}
				char* cursor = ptr[i]->GetHomePh();
				++counter;
				for (int i = 0, j = 0; i < 16; i++, counter++)
				{
					if (str[counter] == char(32))
						continue;
					cursor[j++] = str[counter];
				}
				cursor = ptr[i]->GetWorkPh();
				++counter;
				for (int i = 0, j = 0; i < 16; i++, counter++)
				{
					if (str[counter] == char(32))
						continue;
					cursor[j++] = str[counter];
				}
				cursor = ptr[i]->GetCellPh();
				++counter;
				for (int i = 0, j = 0; i < 16; i++, counter++)
				{
					if (str[counter] == char(32))
						continue;
					cursor[j++] = str[counter];
				}
				++counter;
				length_ctr = 0;
				for (int i = counter; str[i] != '\0'; i++, length_ctr++)
				{
				}
				char* info = new char[length_ctr + 1];
				int x = 0;
				for (x, counter; x < length_ctr; )
				{
					info[x++] = str[counter++];
				}
				info[x] = str[counter];
				ptr[i]->Set_Info(info);
			}
			spisok.close();
			cout << "���� ������� ��������.\n";
		}
	}
	else
	{
		cout << "�� ������� ��������� ���� � �����\n";
	}
	system("pause");
}