#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Functions.h"
#include "Tests.h"

//Função a ser encontrada a raiz
double functionF(float x){

    return ((cos(2*x) + pow(2, x)) - (pow(x, 2)) - (1.0/3));
}

//Função calcula o erro absoluto dado determinado intervalo fechado
double absoluted_error(closed_interval *closed){

    double e0 = (closed->b - closed->a);
    double n = ((log10(e0) - log10(closed->tol))/log10(2));

        if(n < 0)
            return (n * (-1));
        else
            return n;
}

//Função Cria uma Estrutura para Armazenar o intervalo de continuidade e a tolerância
closed_interval *closedInterval(){
    closed_interval *closed = malloc(1*sizeof(closed_interval));
    double a, b;

    printf("Seja f : [a, b] -> R\n\n");
    printf("F(x) : [a, b]\n a = ");
    scanf("%lf", &a);
    closed -> a = a;

    printf("F(x) : [%lf, b]\n b = ", a);
    scanf("%lf", &b);
    closed -> b = b;

    printf("F(x) : [%f, %f]\n", closed->a, closed->b);

    closed -> tol = pow(10, (-5));

    return closed;
}

// Função calcula a raiz da funcão dada o coeficiente de tolerância
double calcRoot(closed_interval *c1){
    int i;
    double c;
    int n = absoluted_error(c1);
    printf("%d\n", n);

    for(i = 0; i <= n; i++){// Executará N interações de acordo com o Erro absoluto calculado;
        c = ((c1->a + c1->b)/ 2); // C torna-se termo intermediár

        if(functionF(c) == 0){ //Verifica se a raiz da função não é Zero
            return c;
        }
        else if(((functionF(c1->a)) * (functionF(c))) < 0){// Verifica se a raiz esta o intervalo [a, c]. Condição F(a)*F(c) < 0
            c1->b = c;
            printf("C1 F(x) : [%f, %f]\n", c1->a, c1->b);
        }
            else if(((functionF(c1->a)) * (functionF(c))) > 0){// Verifica se a raiz esta o intervalo [c, b]. Condição F(b)*F(c) > 0
            c1->a = c;
            printf("C1 F(x) : [%f, %f]\n", c1->a, c1->b);
        }
    }
        printf("C: %f\n\n", c);
        return c;
}
