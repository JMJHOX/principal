#include <iostream>
#include<string>
#include <cmath>
#include <Windows.h>
#include<stdio.h>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>

#define MAX 10000
using namespace std;


/* Funcion gotoxy sirve para asignar un plano cartesiano en la consola de salida e imprimir en ese punto con las coordenadas X  y Y dadas.*/
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}


/* Función para imprimir los marcos en cada sección del programa*/
void Marcodepantalla(int lowx,int upx,int lowy,int upy,int gotox1,int gotox2,int gotoy1,int gotoy2)
{
		for (int x = lowx; x <= upx; x++)
		{
			gotoxy(x, gotoy1);
			putchar('*');
			gotoxy(x, gotoy2);
			putchar('*');

		}
		for (int y = lowy; y <= upy; y++)
		{
			gotoxy(gotox1, y);
			putchar('*');
			gotoxy(gotox2, y);
			putchar('*');
		}	
}
void limpiarpantalla(const char* color)
{
			system("cls");
			system(color);	
}
//No borrar del programa
/*long convertirBinarioaDecimal(long double); 
void pausa();*/
long long unsigned numero;

long convertirBinarioaDecimal(long double)
{
	long long numeroDecimal = 0, i = 0, recordatorio;

	while (numero != 0)
	{
		recordatorio = numero % 10;
		numero /= 10;
		numeroDecimal += recordatorio * pow(2, i);
		++i;
	}
	return numeroDecimal;
}


void pausa()
{
	cout << "Pulsa una tecla para continuar................";
	getwchar();
	getwchar();
}





int main()
{
	
	setlocale(LC_ALL,""); //Nos permite utilizar acentos en la salida del programa
	char texto[1024];
	long long contador = 0, num, resultado, cerosunos[1024], i;//variables de convertir texto a número
	long long unsigned numerodecimal, exp, digito; double long binario; //variables del convertidor de decimal a binario
	long numerobin, resto, cociente; long numeroctal[1024], brand, rad, exponente, digit; double numerodeci; //variables binario a octal
	char binnum[MAX], hexa[MAX]; long  temp; long  den, alex;//variables binario a hexadecimal
	bool bandera = false;
	char tecla;
	do
	{


		system("cls");
		cin.clear();
		Marcodepantalla(1,119,4,14,0,119,4,14);
		gotoxy(1, 0);
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "|                                            CALCULADORA DE CONVERSIONES                                                \n";
		cout << "------------------------------------------------------------------------------------------------------------------------\n" << endl;
		system("color 02");
		gotoxy(0, 6);
		cout << "\t1 .-  Convertir de Binario a Decimal \n";
		gotoxy(0, 7);
		cout << "\t2 .-  Convertir de Decimal a Binario \n";
		gotoxy(0, 8);
		cout << "\t3 .-  Convertir de Binario a Octal \n";
		gotoxy(0, 9);
		cout << "\t4 .-  Convertir de Binario a Hexadesimal \n";
		gotoxy(0, 10);
		cout << "\t5 .-  Convertir de Texto a Binario\n";
		gotoxy(0, 11);
		cout << "\t6 .-  Creditos y Reparto " << endl;
		gotoxy(0, 12);
		cout << "\t7 .-  Salir de el programa " << endl;
		gotoxy(1, 16);
		cout << "Elige una opcion: ";
		cin >> tecla;
		switch (tecla)
		{
		case '1':
			limpiarpantalla("color 2");
			Marcodepantalla(1,130,4,10,0,119,4,11);
			gotoxy(1, 0);
			cout << "-----------------------------------------------------------------------------------------------------------------------\n";
			cout << "                                Has elegido convertir de  Binario a Decimal. \n" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------\n";
			gotoxy(1, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "Nota: Solo introduce los numeros 0 y 1, ya que equivalen al lenguaje del código binario" << endl << endl;
			gotoxy(3, 5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "Introduce el numero a convertir: " << endl;
			gotoxy(4, 6);
			cin >> numero;
			cout << "" << endl;
			gotoxy(4, 7);
			cout << "El numero binario = " << convertirBinarioaDecimal(numero) << " en decimal." << endl;
			gotoxy(2, 15);
			pausa();
			break;

		case '2':
			limpiarpantalla("color 06");
			Marcodepantalla(1,118,4,10,0,119,4,11);
			gotoxy(1, 0);
			cout << "--------------------------------------------------------------------------------------------------------------------\n";
			cout << "                                    Has elegido convertir de Decimal a Binario. \n";
			cout << "---------------------------------------------------------------------------------------------------------------------\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "Nota: ingresa solo números decimales enteros y positivos " << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			gotoxy(4, 5);
			cout << "Introduce el número decimal a convertir: " << endl;
			gotoxy(4, 6);
			cin >> numerodecimal;
			exp = 0;
			binario = 0;
			while (numerodecimal / 2 != 0)
			{
				digito = numerodecimal % 2;
				binario = binario + digito * pow(10.0, exp);
				exp++;
				numerodecimal = numerodecimal / 2;
			}
			binario = binario + numerodecimal * pow(10.0, exp);
			gotoxy(4, 6);
			cout << fixed << setprecision(0);
			gotoxy(4, 7);
			cout << "El número decimal ingresado convertido en binario es = " << binario << endl;
			gotoxy(4, 14);
			pausa();
			break;

		case '3':
			limpiarpantalla("color 04");
			Marcodepantalla(1,118,4,10,0,118,4,11);
			gotoxy(1, 0);
			cout << "---------------------------------------------------------------------------------------------------------------------\n";
			cout << "                                      Has elegido convertir de Binario a Octal. \n";
			cout << "---------------------------------------------------------------------------------------------------------------------\n";
			gotoxy(1, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "Nota: Introduce solo los números 0 y 1 equivalente al codigo binario" << endl << endl;
			cout << "El sistema octal reconoce por 3 espacios numéricos, en este programa no hay necesidad de rellenar los 0 faltantes, ya que él solo los complementa al número binario ingresado" << endl << endl;
			gotoxy(3, 5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "Introduce el número binario a convertir en el sistema octal: " << endl;
			gotoxy(4, 6);
			cin >> numerobin;
			exponente = 0;
			numerodeci = 0;
			brand = 1;
			rad = 0;
			cociente = 0;
			numeroctal[rad] = 0;
			digit = 0;
			while (((int)(numerobin / 10)) != 0)
			{
				digit = (int)numerobin % 10;
				numerodeci = numerodeci + digit * pow(2.0, exponente);
				exponente++;
				numerobin = (int)(numerobin / 10);
			}
			numerodeci = numerodeci + numerobin * pow(2.0, exponente);
			cociente = numerodeci;
			while (cociente != 0)
			{
				numeroctal[brand++] = cociente % 8;
				cociente = cociente / 8;
			}
			for (rad = brand - 1; rad > 0; rad--)
				cout << numeroctal[rad];
			cout << " Es número del sistema octal equivalente al número binario ingresado" << endl;
			gotoxy(1, 19);
			pausa();
			break;

		case '4':
			limpiarpantalla("color 03");
			Marcodepantalla(1,118,4,10,0,118,4,11);
			gotoxy(1, 0);
			cout << "------------------------------------------------------------------------------------------------------------------------\n";
			cout << "                                      Has elegido convertir de Binario a Hexadecimal. \n";
			cout << "------------------------------------------------------------------------------------------------------------------------\n";
			gotoxy(3, 5);
			cout << "Introduzca el número binario para comvertir al sistema hexadecimal : " << endl;
			gotoxy(4, 6);
			cin >> binnum;
			gotoxy(1, 4);
			cout << "Nota: Introduce solo los números 0 y 1 equivalente al código binario" << endl;
			den = 0;
			alex = 0;
			while (binnum[den])
			{
				binnum[den] = binnum[den] - 48;
				++den;
			}
			--den;
			while (den - 2 >= 0)
			{
				temp = binnum[den - 3] * 8 + binnum[den - 2] * 4 + binnum[den - 1] * 2 + binnum[den];
				if (temp > 9)
					hexa[alex++] = temp + 55;
				else
					hexa[alex++] = temp + 48;
				den = den - 4;
			}
			if (den == 1)
				hexa[alex] = binnum[den - 1] * 2 + binnum[den] + 48;
			else if (den == 0)
				hexa[alex] = binnum[den] + 48;
			else
				--alex;
			gotoxy(4, 7);
			cout << "En Hexadecimal es: ";
			while (alex >= 0)
			{
				cout << hexa[alex--];
			}
			gotoxy(4, 8);
			cout << endl; gotoxy(4, 9);
			pausa();
			break;

		case '5':
			limpiarpantalla("color 2");
			Marcodepantalla(1,118,4,10,0,118,4,11);
			gotoxy(1, 0);
			cout << "---------------------------------------------------------------------------------------------------------------------\n";
			cout << "                              Has elegido la opcion convertir un Texto a número Binario\n";
			cout << "---------------------------------------------------------------------------------------------------------------------\n";
			cout << "introduce letras o palabras, carácteres especiales y números determinados por la tabla ascii" << endl << endl;
			gotoxy(1, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "Nota: Este programa por el momento no reconoce la tecla espacio. Estamos trabajando para solucionarlo, por el momento solo lee de palabra, no importa su extensión o puedes separar las palabras con comas. " << endl << endl;
			gotoxy(3, 5);
			cout << "Introduce el texto a convertir: " << endl;
			gotoxy(3, 6);
			cin >> texto;
			gotoxy(4, 7);
			num = 0;
			i = 0;
			resultado = 0;
			cerosunos[i] = 0;
			contador = 0;
			while (contador < strlen(texto))
			{

				i = 1;

				num = texto[contador];

				while (num > 0)

				{

					resultado = num % 2;

					if (resultado == 0)

					{

						cerosunos[i] = 0;

						i = i + 1;

					}

					else

					{

						cerosunos[i] = 1;

						i = i + 1;

						num = num - 1;

					}

					num = num / 2;

				}

				i = i - 1;

				while (i > 0)

				{

					cout << cerosunos[i];

					i = i - 1;

				}

				cout << " ";
				contador = contador + 1;

			}
			cout << " Equivale al codigo binario del texto ingresado " << endl;
			gotoxy(3, 15);
			pausa();
			break;

		case '6':
			limpiarpantalla("color 0b");
			cout << "---------------------------------------------------------------------------------------------------------------------\n";
			cout << "                                            Créditos y Reparto del programa \n";
			/*Insertar nombres de los integrantes*/
			pausa();
			break;
		case '7':
			bandera = true;
			//exist(1)
			break;
		default:
			limpiarpantalla("color a5");
			cout << "Opción no válida. Ingrese una de las 6 opciones mostradas \a \n";
			pausa();
			break;

		}

	} while (bandera != true);

}

/*
#include <stdio.h>
#include <cstdlib>

#include <windows.h>
#include <stdlib.h>
#include <iostream>
#define MenuInicio 1     // Establecer el primer numero del menu
#define MenuFin 7	 // Establecer último numero del menu
#define LineaDeInicio 2  // Establecer la linea donde empieza el menu
using namespace std;
// ir a una línea determinada
void goy(int y);

int main() {
	int Menu; // Controla el menu seleccionado actualmente
	system("color F3");
	
	cout << "---CALCULADORA DE CONVERSIONES---\nSeleccione opcion:";
	// ir a la linea de inicio, DEBE ir antes del menu seleccionable!!! No olvidar
	goy(LineaDeInicio); 
	cout <<"\t1. Convertir de Binario a Decimal \n";
	cout <<"\t2. Convertir de Decimal a Binario \n";
	cout <<"\t3. Convertir de Binario a Octal \n";
	cout <<"\t4. Convertir de Binario a Hexadecimal \n";
	cout <<"\t5. Convertir de Texto a Binario\n";
	cout <<"\t6. Creditos y Reparto \n";
	cout <<"\t7. Salir de el programa\n";

	Menu = 1;
	goy(LineaDeInicio);
	cout << "---->";

	while(true) {
		// Retrasar el ciclo un poco
		Sleep(100);
		// Saber si la flecha de arriba fue pulsada
		if (GetAsyncKeyState(VK_UP)) {
			// Si Menu == 1, Menu = MenuFin, sino, Menu = Menu -1
			Menu = Menu == MenuInicio ? MenuFin: --Menu;
			// Eliminar la flecha actual
			cout << "\r     ";
			// Ir a la linea del próximo menu
			goy(LineaDeInicio + Menu-1);
			// Poner la nueva flecha
			cout << "---->";
		} else if (GetAsyncKeyState(VK_DOWN)) {
			Menu = Menu == MenuFin ? MenuInicio: ++Menu;
			cout << "\r     ";
			goy(LineaDeInicio + Menu-1);
			cout << "---->";
		} else if (GetAsyncKeyState(VK_RETURN)) { 
			break;
		}
	}

	// Opcional... Mostrar en pantalla el numero seleccionado
	goy(10);
	printf("Has seleccionado la opcion %d!\n\n\n", Menu);
	if(Menu ==1){
		printf("hola");
	}
	/*
	
	AQUI SE PUEDE HACER EL TIPICO SWITCH ANALIZANDO LA OPCION
        QUE SELECCIONÓ EL USUARIO
	
	*/

	system("pause");
}


void goy(int y) {
	// Obtener handle de la consola
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Establecer posición del nuevo cursor
	COORD pos;
	pos.X = 0;
	pos.Y = y;
	// Colocar el cursor en el nuevo sitio
	SetConsoleCursorPosition(hConsole, pos);
}

*/

