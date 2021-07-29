#pragma once
#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>

char* Name();

class Subscriber
{
private:
    char* initials;
    char homePh[17];
    char workPh[17];
    char cellPh[17];
    char* info;
public:
    Subscriber();
    Subscriber(bool i);
    ~Subscriber();
    int Get_init_ctr();
    char* Get_init();
    char* Get_info();
    char* GetHomePh();
    char* GetWorkPh();
    char* GetCellPh();
    void Set_Init(char* initials);
    void Set_Info(char* info);
    void Print(int init_ctr);
};

