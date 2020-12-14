#include<stdio.h>
#include<stdlib.h>

int main() {
	unsigned int a;
	printf("entrer un nombre :\n");
	scanf_s("%u", &a);
	unsigned char tmp = a;
	int b;
	b = sizeof(a);
	int c;
	c = b * 8;
	printf("le nombre d'octets utilise est : %u\n", b);
	printf("le nombre de bits utilise est : %u\n", c);
	int i;
	for (i = 0; i < 8; i++) {
		printf("bit %u", i);
		if ((tmp & 1) == 1) {
			printf(": on\n");
		}
		else {
			printf(": off\n");
		}
		tmp >>= 1;
	}
	printf("\n");
	printf("bye!\n");
	system("pause");
	return("EXIT_SUCCESS");
}