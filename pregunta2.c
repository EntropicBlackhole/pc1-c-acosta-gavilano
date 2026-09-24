#include <stdio.h>
#include <math.h> // <-- Compilation will require flag -lm

int main() {

    #define INVALID 0
    #define NOT_A_TRIANGLE 1
    #define EQUILATERAL 2
    #define ISOSCELES 3
    #define SCALENE 4

    int a, b, c, type, isRect;
    double area;

    scanf("%d %d %d", &a, &b, &c);

    #define MAX_INT 2147000000 // approximated

    if (a > MAX_INT || b > MAX_INT || c > MAX_INT) {
        fprintf(stderr, "input exceeded max int size.\n");
    }

    if (a <= 0 || b <= 0 || c <= 0) {
        type = INVALID;
    }
    else if (!(a + b > c && a + c > b && b + c > a)) {
        type = NOT_A_TRIANGLE;
    }
    else {

        long long int hyp = a, cat1 = b, cat2 = c;
        long long int aux;

        if (hyp < cat1) {
            aux = cat1;
            cat1 = hyp;
            hyp = aux;
        }

        if (hyp < cat2) {
            aux = cat2;
            cat2 = hyp;
            hyp = aux;
        }

        isRect = (hyp * hyp) == (cat1 * cat1) + (cat2 * cat2);

        if (a == b && b == c) {
            type = EQUILATERAL;
        }
        else if (a == b || b == c || a == c) {
            type = ISOSCELES;
        }
        else {
            type = SCALENE;

            // find area by Heron's Formula
            double p = (a + b + c) / 2;
            area = sqrt(p * (p - a) * (p - b) * (p - c));
        }
    }

    char *typestr;
    switch (type) {
        case INVALID:
            typestr = "Lados invalidos";
            isRect = 0;
            area = 0;
            break;

        case NOT_A_TRIANGLE:
            typestr = "No forman un triangulo";
            isRect = 0;
            area = 0;
            break;

        case EQUILATERAL:
            typestr = "Equilatero";
            area = 0;    
            break;

        case ISOSCELES:
            typestr = "Isosceles";
            area = 0;
            break;

        case SCALENE:
            typestr = "Escaleno";
            break;
    }

    printf("Lados      : %d %d %d\n", a, b, c);
    printf("Tipo       : %s\n", typestr);
    printf("Rectangulo : %s\n", isRect ? "Si" : "No");
    printf("Area       : %.3f\n", area);

    return 0;
}