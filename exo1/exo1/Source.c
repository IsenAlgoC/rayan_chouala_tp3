#include<stdio.h>
#include<stdlib.h>
#define carre(x) (x) * (x)

int main() {
	int nb = 4;
	printf("%u\n", carre(nb));
	printf("%u\n", carre(nb + 1));
	system("pause");
	return(EXIT_SUCCESS);
}