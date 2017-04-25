#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Functions.h"
#include "minunit.h"
#include "Tests.h"

int tests_run = 0;

//-------Tests_Functions
static char *test_functionF(){
    float x = 0, result;
    result = functionF(x);

    mu_assert("Error Function F", result == 2);
    return 0;
}

static void *test_absoluted_error(){
    closed_interval c1;
    c1.a   = -1;
    c1.b   = 1;
    c1.tol = pow(10, (-5));

    int n_iteracoes = absoluted_error(&c1);

    mu_assert("Error at absoluted error\n", n_iteracoes == 17);
    return 0;
}

static void *test_calcRoot(){//Este teste verifica para a função f(x) = (1 - x);
    closed_interval c1;
    c1.a   = -3;
    c1.b   = 4;
    c1.tol = pow(10, (-1));
    int n = absoluted_error(&c1);
    int i, e;
    double c = calcRoot(&c1);

    printf("C: %f\n", c);


    //Verifica se C está contido entre o limite inteiro e o limite considerando a tolerancia
    mu_assert("Error at Calc Function Root", (c > 1 && c < (1 + c1.tol)));
}

static char *all_tests(){
    mu_run_test(test_functionF);
    mu_run_test(test_absoluted_error);
    mu_run_test(test_calcRoot);
    return 0;
}

static void test_routine(){
    char *result = all_tests();
    if(result != 0){
        printf("%s\n", result);
    }
    else{
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

}
