#include "stdafx.h"
#include "Bank.h"
#include "Transaction.h"
#include <fstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    Bank test;
    test.buildQueue("BankTransIn.txt");
    test.useQueue();
    return 0;
}