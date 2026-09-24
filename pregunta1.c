#include <stdio.h>

int main() {
  unsigned int registro;
  unsigned int registro2;
  unsigned char n;
  int c;
  for (;;) {
    char c = getchar();
    if (c == 'q' || c == '0') {
      break;
    }
    switch (c) { 
      case '1':
        scanf("%d", n); //validar entre 0 y 31
        printf("%d", n);
        registro |= (1 << (n-1));
        printf("bit %d prendido\n", n);
        break;
      case '2':
        scanf("%d", n); //validar entre 0 y 31
        registro &= (2 * (1 << (n)) - 1 - (1 << (n-1)));
        printf("bit %d apagado\n", n);
        break;
      case '3':
        scanf("%d", n); //validar entre 0 y 31
        if ((registro >> (n-1)) % 2 == 0)
          registro |= (1 << (n-1));
        else
          registro &= (2 * (1 << (n)) - 1 - (1 << (n-1)));
        printf("bit %d alternado\n", n);
        break;
      case '4':
        scanf("%d", n); //validar entre 0 y 31
        char* rpta = "encendido";
        if ((registro >> (n-1)) % 2 == 0) rpta = "apagado";
        printf("el bit %d esta %s\n", n, rpta);
        break;
      case '5':
        // char* buffer = "";
        // unsigned int registro2 = registro;
        // // 1100
        // for (;;) {
        //   buffer = (registro2 % 2) + registro2;
        //   registro2 = registro >> 1;
        // }
        // printf("%s", buffer);


        c = 0;  // counter
        registro2 = registro;
        for (;;) {
          if (registro2 == 0) break;
          if (registro2 % 2 != 0) c++;
          registro2 = registro2 >> 1;
        }


        printf("Registro: \n");
        printf("Hex     : %x\n", registro);
        printf("Decimal : %d\n", registro);
        printf("Unos    : %d\n", c);
      case '6':
        int c = 0;  // counter
        unsigned int registro2 = registro;
        for (;;) {
          if (registro2 == 0) break;
          if (registro2 % 2 != 0) c++;
          registro2 = registro2 >> 1;
        }
        printf("hay %d bit%s encendidos\n", c, c != 1 ? "s" : "");
        break;
      case '7':
        registro ^= ((1 << (n + 1)) - 1);
        printf("se ha invertido el registro");
      default:
        break;
    }
  }
  printf("programa terminado");
  return 0;
}