/*
Define a structure to represent a polynomial of d degree having floating point numbers as its coefficients and input variable. Write a
function EvaluatePoly(P, x) to evaluate the value of the polynomial for input x. Write another function AddPoly() which takes as input two
polynomials P1, P2, and return their sum P3 = P1+P2. Call the above functions from the main program for test inputs.
*/

#include <stdio.h>
#include <math.h>

typedef struct { //defining structure for storing the details of a polynomial
    int deg;
    float coeffs[100];
    float var;
} poly;

float EvaluatePoly (poly P, float x) //function evaluates the polynomial at the value x
{
    P.var = x;
    int i;
    float term, sum = 0;
    for(i = 0; i <= P.deg; i++) {
        term = P.coeffs[i] * pow(P.var, i);
        sum = sum + term;
    }
    
    return sum;
}

float AddPoly (poly P1, poly P2) //function adds 2 polynomials P1, P2 
{
    return EvaluatePoly(P1, P1.var) + EvaluatePoly(P2, P2.var);
}

int main ()
{
    poly P1, P2;
    float P3;
    int i;
    
    //first set of printf, scanf statements and for loop to obtain degree, variable value and coefficients for P1
    printf("Enter degree of polynomial P1: ");
    scanf("%d", &P1.deg);
    printf("Enter the value of variable x for which the polynomial, P1 is to be evaluated: ");
    scanf("%f", &P1.var);
    
    printf("Enter coefficients for polynomial P1:\n");
    for(i = 0; i <= P1.deg; i++ ) {
        printf("Type coefficient of x^%d: ", i);
        scanf("%f", &P1.coeffs[i]);
    }
    
    printf("The value of P1 evaluated at %f is: %f\n", P1.var, EvaluatePoly (P1, P1.var)); //prints value of P1
    
    //first set of printf, scanf statements and for loop to obtain degree, variable value and coefficients for P2
    printf("Enter degree of polynomial P2: ");
    scanf("%d", &P2.deg);
    printf("Enter the value of variable x for which the polynomial, P2 is to be evaluated: ");
    scanf("%f", &P2.var);
    
    printf("Enter coefficients for polynomial P2:\n");
    for(i = 0; i <= P2.deg; i++ ) {
        printf("Type coefficient of x^%d: ", i);
        scanf("%f", &P2.coeffs[i]);
    }
    
    printf("The value of P2 evaluated at %f is: %f\n", P2.var, EvaluatePoly (P2, P2.var)); //prints value of P2
    
    P3 = AddPoly (P1, P2); //P3 stores the sum of P1, P2 evaluated at their respective variable values
    
    printf("The sum of the polynomials is %f ", P3);
    
    return 0;
}