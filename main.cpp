#include <iostream>
using namespace std;
#include <Windows.h>
#include "Ptr.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");
    Ptr base;
    char inp;
    char* str=nullptr;
    do
    {
        do
        {
            cout << "\t\t���������� �����\n1-����� �������\n2-������� ��������\n3-����� �� �.�.�.\n4-�������� ����\n5-��������� � ����\n6-��������� �� �����\n0-�����\n\n";
            cin >> inp;
            cin.ignore(cin.rdbuf()->in_avail());
            system("cls");
        } while (inp < 48 || inp>54);
        switch (inp)
        {
        case '1':
            base.Add();
            break;
        case '2':
            base.Print();
            int num;
            do
            {
                cout << "������� ����� �������: ";
                cin >> num;
            } while (num < 1|| num>base.GetSize());
            base.Delete(num);
            break;
        case '3':
            cout << "������� ������: ";
            str = Name();
            base.Search(str);
            delete[]str;
            str = nullptr;
            cout << endl;
            system("pause");
            break;
        case '4':
            base.Print();
            cout << endl;
            system("pause");
            break;
        case '5':
            base.SaveFile();
            break;
        case '6':
            base.LoadFile();
            break;
        }
    system("cls");
    } while (inp!='0');
}
