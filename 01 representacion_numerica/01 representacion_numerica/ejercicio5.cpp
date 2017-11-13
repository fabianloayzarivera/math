#include "stdafx.h"
#include "ejercicio5.h"

void ejercicio5() {

	cout << "Ejercicio 5: " << endl;
	int a = 4;
	int b = -4;

	cout << binaryFromInt(a) << endl;
	cout << binaryFromInt(b) << endl;

	cout << "Ejercicio 5.1: " << endl;

	cout << binaryFromInt(a+b) << endl;

	cout << "Ejercicio 5.2: " << endl;
	cout << "Al hacer una resta es como si estuvieramos usando el operador & y siendo todos los bits contrarios, se queda todo en 0" << endl;

	cout << "Ejercicio 5.4: " << endl;
	char c = (char)255;
	unsigned char uc = (unsigned char)255;

	string binC = binaryFromInt(c);
	string binUC = binaryFromInt(uc);
	
	printf("signed   = %s\n", binC.c_str());
	printf("unsigned = %s\n", binUC.c_str());

	printf("signed   = %d\n", intFromBinary(binC));
	printf("unsigned = %d\n", intFromBinary(binUC));

	cout << "Ejercicio 5.5: " << endl;
	cout << "No tienen la misma representacion, por que existe el bit mas significativo que generalmente el ordenador lo toma en cuenta como el bit del signo es por eso que al convertir el signed se vuelve 127 en vez de 255" << endl;

	cout << "Ejercicio 5.6: " << endl;
	char d = (char)128; 
	char e = (char)-128;

	string binD = binaryFromInt(d);
	string binUD = binaryFromInt(e);

	printf("pos   = %s\n", binD.c_str());
	printf("neg   = %s\n", binUD.c_str());

	cout << "Ejercicio 5.7: " << endl;
	printf("pos   = %s\n", binD.c_str());
	printf("neg   = %s\n", binUD.c_str());

	printf("pos   = %d\n", intFromBinary(binD));
	printf("neg   = %d\n", intFromBinary(binUD));

	cout << "Son el mismo numero por que no alcanzan 8 bits para almacenar el 128 por lo tanto se queda en 0 positivo o negativo lo cual transformado a decimal es 0 igualmente" << endl;


}