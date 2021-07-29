#include "Subscriber.h"

char* Name()
{
    char* buf = new char[256];
    cin.getline(buf, 256);
    cin.ignore(cin.rdbuf()->in_avail());
    char* temp = new char[strlen(buf) + 1];
    strcpy_s(temp, strlen(buf) + 1, buf);
    delete[]buf;
    return temp;
}

template <size_t N>
void Input(char(&var)[N])
{
    if (!(cin.get(var, N, '\n')))
    {
        cin.clear();
        cin.sync();
    }
    cin.ignore(cin.rdbuf()->in_avail());
}

Subscriber::Subscriber ()
{
    {
            cout << "������� �.�.�.: ";
            Subscriber::initials = Name();
            cout << "�������� �������: ";
            Input(Subscriber::homePh);
            cout << "������� �������: ";
            Input(Subscriber::workPh);
            cout << "������� �������: ";
            Input(Subscriber::cellPh);
            cout << "�������������� ���������� � ��������: ";
            info = Name();
            cout << endl;
    }
}

Subscriber:: Subscriber(bool i)
{
        Subscriber::initials = nullptr;
        Subscriber::info = nullptr;
}

Subscriber::~Subscriber()
{
    delete[]this->initials;
    delete[]this->info;
}

char* Subscriber::Get_init()
{
    return this->initials;
}

char* Subscriber::Get_info()
{
    return this->info;
}

int Subscriber::Get_init_ctr()
{
    return strlen(this->initials);
}

char* Subscriber::GetHomePh()
{
    return Subscriber::homePh;
}
char* Subscriber::GetWorkPh()
{
    return Subscriber::workPh;
}
char* Subscriber::GetCellPh()
{
    return Subscriber::cellPh;
}
void Subscriber::Set_Init(char* initials)
{
    Subscriber::initials = initials;
}
void Subscriber::Set_Info(char* info)
{
    Subscriber::info = info;
}

void Subscriber::Print(int init_ctr)
{
        (init_ctr > 6) ? cout << setw(init_ctr) << initials<<" " : cout << setw(6)<<initials<<" ";
        cout << setw(16)<<homePh<<" " << setw(16) << workPh<<" " << setw(16) <<cellPh<<" ";
        cout << info<<endl;
}
