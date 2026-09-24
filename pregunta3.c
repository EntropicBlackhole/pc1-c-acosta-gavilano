#include <stdio.h>

int main() {

    int vowels = 0, consonants = 0, digits = 0, whitespaces = 0, other = 0;
    int thisLength = 0, maxLength = 0, fullLength = 0;
    
    for (;;) {

        int c = getchar();

        if (c == '\n' || c == 0) {
            break;
        }
        else if (c == ' ' || c == '\t') {
            whitespaces++;

            if (maxLength < thisLength) {
                maxLength = thisLength;
                thisLength = 0;
            }
        }
        else if (c >= 'A' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowels++;
            }  
            else {
                consonants++;
            }

            thisLength++;
        }      
        else if (c >= '0' && c <= '9') {
            digits++;
        }  
        else {
            other++;
        }
    
        fullLength++;
    }

    if (fullLength == 0) {
        printf("linea vacia\n");
    }
    else {
        printf("Vocales              : %d\n", vowels);
        printf("Consonantes          : %d\n", consonants);
        printf("Digitos              : %d\n", digits);
        printf("Espacios             : %d\n", whitespaces);
        printf("Otros                : %d\n", other);
        printf("Longitud de palabra  : %d\n", maxLength);
        printf("Longitud total       : %d\n", fullLength);
    }

    return 0;
}