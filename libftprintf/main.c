#include "header.h"
#include <stdio.h>

int main()
{
	char		**matr;

	matr = ft_matrdup("hello", "wprld", "kjafjakfjk", NULL);
	printf("matr[0] = %s\n", matr[0]);
	printf("matr[1] = %s\n", matr[1]);
	printf("matr[2] = %s\n", matr[2]);
	printf("matr[3] = %s\n", matr[3]);
}