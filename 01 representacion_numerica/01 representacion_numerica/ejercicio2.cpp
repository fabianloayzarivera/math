#include "stdafx.h"
#include "ejercicio2.h"



void ejercicio2() {
	cout << "Ejercicio 2: " << endl;
	cout << "Ejercicio 2.1: " << endl;

	string bin = "01010";
	int dec;

	dec = intFromBinary(bin);

	cout << "Bin: " << bin << " Dec: " << dec <<endl;

	cout << "Applying NOT" << endl;

	dec = ~dec;

	bin = binaryFromInt(dec);

	cout << "Bin: " << bin << " Dec: " << dec << endl;

	cout << "Ejercicio 2.2: " << endl;

	dec = dec << 1;
	cout << binaryFromInt(dec) << endl;
	
	dec = dec << 3;
	cout << binaryFromInt(dec) << endl;

	dec = dec << 2;
	cout << binaryFromInt(dec) << endl;

	cout << "Ejercicio 2.3: " << endl;

	bin = "111111111111111111111111111111";
	int number = intFromBinary(bin);
	unsigned int unsignedNumber = static_cast<unsigned int>(intFromBinary(bin));
	
	
	printf("signed=%d\n", number);
	printf("unsigned = %u\n",unsignedNumber);

	cout << "Ejercicio 2.3.1: " << endl;
	number = number << 3;
	unsignedNumber = unsignedNumber << 3;

	printf("signed=%d\n", number);
	printf("unsigned = %u\n", unsignedNumber);

	number = number >> 4;
	unsignedNumber = unsignedNumber >> 4;
		
	printf("signed=%d\n", number);
	printf("unsigned = %u\n", unsignedNumber);

	cout << "Ejercicio 2.3.2: " << endl;
	number += 1;
	unsignedNumber = 0;
	unsignedNumber = unsignedNumber -1;

	printf("signed=%d\n", number);
	printf("unsigned = %u\n", unsignedNumber);

	cout << "Ejercicio 2.3.3: " << endl;
	int pink = 0xCC6699;

	int r = pink >> 16;
	cout << "R: "<< r<<endl;
	int g = pink << 16;
	g = g >> 24;
	cout << "G: " << g << endl;
	int aux = 255;
	int b = pink << 24;
	b = b >> 24;
	b = b & aux;
	cout << "B: " << b << endl;
}


