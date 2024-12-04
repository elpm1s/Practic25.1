#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int rand10(int mmax); //целое число от 1 до mmax
double rand_double(double dmin, double dmax); //вещественное число в заданном диапазоне
int* randd(int n, int mmax); //n целых чисел от 1 до mmax
double* randd2(int n, double dm); //n вещественных чисел в диапазоне от -dm до +dm

int main()
{
	setlocale(LC_ALL, "RUS");

	//перва€ функци€
	srand(time(NULL));
	int mmax = 10, r;
	r = rand10(mmax);
	printf("÷елое число от 1 до 10: %d\n", r);

	//втора€ функи€
	double min, max, a;
	printf("%s", "¬ведите диапазон min и max:\n");
	scanf("%lf%lf", &min, &max);
	a = rand_double(min, max);
	printf("¬ещественное число в диапазоне от %.0lf до %.0lf = %.2lf\n", min, max, a);

	//треть€ функиц€
	printf("%s", "¬ведите n целых чисел и mmax:\n");
	const int b, mmmax;
	scanf("%d%d", &b, &mmmax);
	int w;
	w = *randd(b, mmmax);

	//четвЄрта€ функци€
	printf("%s", "¬ведите n вещественных чисел и диапазон dm:\n");
	const double c, ddm;
	scanf("%lf%lf", &c, &ddm);
	double z;
	z = *randd2(c, ddm);
	
}
//‘”Ќ »÷я 1
int rand10(int mmax)
{
	return 1 + rand() % mmax;
}

//‘”Ќ ÷»я 2
double rand_double(double dmin, double dmax)
{
	double x;
	x = dmin + 1.f * (dmax - dmin) * rand() / RAND_MAX;
	return x;
}

//‘”Ќ ÷»я 3
int* randd(int n, int mmax)
{
	int array[100];
	for (int i = 1; i < n + 1; i++)
	{
		array[i] = rand10(mmax);
		printf("„исло %d = %d\n", i, array[i]);
	}
	return array;
}

//‘”Ќ ÷»я 4
double* randd2(int n, double ddm)
{
	double array2[100];
	for (int i = 1; i < n + 1; i++)
	{
		array2[i] = -ddm + 1.f * (+ddm - -ddm) * rand() / RAND_MAX;
		printf("„исло %d = %.2lf\n", i, array2[i]);
	}
	return array2;
}