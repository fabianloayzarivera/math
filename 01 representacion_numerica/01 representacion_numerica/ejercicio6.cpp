#include "stdafx.h"
#include "ejercicio6.h"

void ejercicio6() {

	cout << "Ejercicio 6: " << endl;
	cout << "Ejercicio 6.1: " << endl;
	float point2 = 0.2f;
	printf("%1.16f\n", point2);
	cout << "Ejercicio 6.2: " << endl;
	cout << "Aparecen numeros desconocido en los ultimos 8 decimales" << endl;
	cout << "Ejercicio 6.3: " << endl;
	float f = 0.1f;
	printf("%1.16f\n", f);
	cout << "Ejercicio 6.4: " << endl;
	float sum = 0;
	for (int i = 0; i < 100; ++i)
		sum += f;

	float product = f * 100;
	printf("%1.16f\n", sum);
	printf("%1.16f\n", product);

	cout << "Ejercicio 6.5: " << endl;
	cout << "Son diferentes por que al momento de hacer el producto desaparece la aproximacion a 0.1 que hace el ordenador, en cambio al sumar simplemente anhadimos una y otra vez el mismo valor sin que los decimales de aproximacion desaparezcan " << endl;

	cout << "Ejercicio 6.6: " << endl;

	if (sum == product)
		cout << "Iguales!" << endl;
	else
		cout << "Diferentes!" << endl;

	cout << "En la sentencia del IF preguntamos si es que la diferencia entre ambas variables es menor a epsilon para saber si son iguales o no" << endl;
	if (fabs(sum-product) < FLT_EPSILON)
		cout << "Iguales!" << endl;
	else
		cout << "Diferentes!" << endl;

}