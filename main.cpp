// Ruddyard Eduardo Castro Chavez
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

#define numero_Candidatos 5
#define yearElectorales 4
#define NUMERO_NOTAS 4
#define MAX_CALIFICACION 1000000
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100

void llamaCiclo();
int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[numero_Candidatos][NUMERO_NOTAS + 1]);
void imprimirMatrizLinea();
float imprimirMatriz(float matriz[numero_Candidatos][NUMERO_NOTAS + 1], char alumnos[numero_Candidatos][MAXIMA_LONGITUD_CADENA], string nombrecicloElectoral);
int main()
{
    srand(getpid());
    llamaCiclo();
    return 0;
}
void llamaCiclo()
{
    float matriz_cicloElectoral_1[numero_Candidatos][NUMERO_NOTAS + 1];
    float matriz_cicloElectoral_2[numero_Candidatos][NUMERO_NOTAS + 1];
    float matriz_cicloElectoral_3[numero_Candidatos][NUMERO_NOTAS + 1];
    char opcion;
    bool repetir = true;

    float promedio_cicloElectoral_1;
    float promedio_cicloElectoral_2;
    float promedio_cicloElectoral_3;

    char alumnos[numero_Candidatos][MAXIMA_LONGITUD_CADENA] = {"Carlos","Luis","Maria","Pedro","Juan"};
    do
    {
        system("cls");
        promedio_cicloElectoral_1=0;
        promedio_cicloElectoral_2=0;
        promedio_cicloElectoral_3=0;
        cout << "*** Comparativo de cicloElectorales ***" << endl << endl;
        llenarMatriz(matriz_cicloElectoral_1);
        promedio_cicloElectoral_1 = imprimirMatriz(matriz_cicloElectoral_1, alumnos, "cicloElectoral de 2017");
        llenarMatriz(matriz_cicloElectoral_2);
        promedio_cicloElectoral_2 = imprimirMatriz(matriz_cicloElectoral_2, alumnos, "cicloElectoral de 2019");
        llenarMatriz(matriz_cicloElectoral_3);
        promedio_cicloElectoral_3 = imprimirMatriz(matriz_cicloElectoral_3, alumnos, "cicloElectoral de 2019");
        if (promedio_cicloElectoral_1 > promedio_cicloElectoral_2 && promedio_cicloElectoral_1 > promedio_cicloElectoral_3)
        {
            cout << " La cicloElectoral con el mejor promedio es : " << "cicloElectoral de 2017" << " Promedio: " << promedio_cicloElectoral_1 << endl;
        } else
        if (promedio_cicloElectoral_2 > promedio_cicloElectoral_1 && promedio_cicloElectoral_2 > promedio_cicloElectoral_3)
        {
            cout << " La cicloElectoral con el mejor promedio es : " << "cicloElectoral de 2019" << " Promedio: " << promedio_cicloElectoral_2 << endl;
        } else
        if (promedio_cicloElectoral_3 > promedio_cicloElectoral_2 && promedio_cicloElectoral_3 > promedio_cicloElectoral_1)
        {
            cout << " La cicloElectoral con el mejor promedio es : " << "cicloElectoral de 2019" << " Promedio: " << promedio_cicloElectoral_3 << endl;
        } else
        {
            cout << " Algunas cicloElectorales tienen el mismo promedio " << endl << endl;
        }
        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n')
        {
            repetir=false;
        }
    } while (repetir);
}
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz(float matriz[numero_Candidatos][NUMERO_NOTAS + 1])
{
    int y, x;
    for (y = 0; y < numero_Candidatos; y++)
    {
        float suma = 0;
        int calificacion = 0;
        for (x = 0; x < NUMERO_NOTAS; x++)
        {
            if (x == 0 || x == 3)  //primer parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 20);
            } else if (x == 1)  //segundo parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 25);
            } else if (x == 2)  //examen final
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 35);
            }
            suma += (float)calificacion;
            matriz[y][x] = calificacion;
            calificacion=0;
        }
        // Agregar promedio

        matriz[y][NUMERO_NOTAS] = suma;
    }
}

void imprimirMatrizLinea()
{
    int x;

    cout << "+--------";
    for (x = 0; x < NUMERO_NOTAS + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}
float imprimirMatriz(float matriz[numero_Candidatos][NUMERO_NOTAS + 1], char alumnos[numero_Candidatos][MAXIMA_LONGITUD_CADENA], string nombrecicloElectoral)
{
    //Funci�n que imprime la matriz en pantalla y realizando los calculos necesarios del promedio
    int y, x;

    float promedioMayor = matriz[0][NUMERO_NOTAS];
    float promedioMenor = matriz[0][NUMERO_NOTAS];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char mayor[MAXIMA_LONGITUD_CADENA];
    char promMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(mayor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(promMenor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    cout << nombrecicloElectoral << endl;
    cout << "(Nota1)=>Primer Parcial  (Nota2)=>Segundo Parcial (Nota3)=>Final (Nota4)=>Actividades" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Alumno";
    for (x = 0; x < NUMERO_NOTAS; x++)
    {
        cout << setw(9) << "Nota" << x + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < numero_Candidatos; y++)
    {
        cout << "!" << setw(8) << alumnos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_NOTAS; x++)
        {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz[y][NUMERO_NOTAS];
        totalGeneral += matriz[y][NUMERO_NOTAS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(mayor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(promMenor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    promedioGeneral = totalGeneral / numero_Candidatos;
    cout << " mayor: " << setw(10) << mayor <<  setw(10) << promedioMayor << endl;
    cout << " menor: " << setw(10) << promMenor <<  setw(10) << promedioMenor << endl;
    cout << "Nota prom : " << setw(10) <<  promedioGeneral << endl << endl;
    return promedioGeneral;
}

