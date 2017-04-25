#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "Tests.h"

//-------Método Principal
void main(){

    //test_routine();
    closed_interval *c1 = closedInterval();
    printf("A raiz da função é: %f\n", calcRoot(c1));

}





