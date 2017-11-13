// 01 representacion_numerica.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "common.h"
#include "ejercicio1.h"
#include "ejercicio2.h"
#include "ejercicio3.h"
#include "ejercicio4.h"
#include "ejercicio5.h"
#include "ejercicio6.h"
#include <iostream>

using namespace std;

int main()
{
	string binary = "010";
	int number = 19;
	
	cout << intFromBinary(binary) << endl;

	cout << binaryFromInt(number) << endl;

	printIntAsBinary(number);

	ejercicio1();
	ejercicio2();
	ejercicio3();
	ejercicio4();
	ejercicio5();
	ejercicio6();
	getchar();
    return 0;
}

