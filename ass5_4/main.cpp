#include "stdafx.h"
#include "Account.h"
#include "Bank.h"
#include "BSTree.h"
#include "Transaction.h"
#include "FundType.h"
#include <iostream>


using namespace std;

int main(int argc, _TCHAR* argv[])
{
    string fileName = "BankTransIn.txt";
    Bank JollyBank;
    JollyBank.ReadTxtFile(fileName);
    JollyBank.ProceedQue();
    JollyBank.DisplayAllAccount();
    cin.get();
    return 0;
}