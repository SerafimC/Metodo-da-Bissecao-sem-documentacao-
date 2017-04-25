#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//-------Structs---------
typedef struct _closed_interval{
    double a, b;
    float tol;
    float absolute_error;
}closed_interval;

//-------System_Functions

//Função a ser encontrada a raiz
double functionF(float x);

//Função calcula o erro absoluto dado determinado intervalo fechado
double absoluted_error(closed_interval *closed);

//Função Cria uma Estrutura para Armazenar o intervalo de continuidade
closed_interval *closedInterval();

double calcRoot(closed_interval *c1);

