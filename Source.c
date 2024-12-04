#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int rand10(int mmax); //����� ����� �� 1 �� mmax
double rand_double(double dmin, double dmax); //������������ ����� � �������� ���������
int* randd(int n, int mmax); //n ����� ����� �� 1 �� mmax
double* randd2(int n, double dm); //n ������������ ����� � ��������� �� -dm �� +dm

int main()
{
	setlocale(LC_ALL, "RUS");

	//������ �������
	srand(time(NULL));
	int mmax = 10, r;
	r = rand10(mmax);
	printf("����� ����� �� 1 �� 10: %d\n", r);

	//������ ������
	double min, max, a;
	printf("%s", "������� �������� min � max:\n");
	scanf("%lf%lf", &min, &max);
	a = rand_double(min, max);
	printf("������������ ����� � ��������� �� %.0lf �� %.0lf = %.2lf\n", min, max, a);

	//������ �������
	printf("%s", "������� n ����� ����� � mmax:\n");
	const int b, mmmax;
	scanf("%d%d", &b, &mmmax);
	int w;
	w = *randd(b, mmmax);

	//�������� �������
	printf("%s", "������� n ������������ ����� � �������� dm:\n");
	const double c, ddm;
	scanf("%lf%lf", &c, &ddm);
	double z;
	z = *randd2(c, ddm);
	
}
//������� 1
int rand10(int mmax)
{
	return 1 + rand() % mmax;
}

//������� 2
double rand_double(double dmin, double dmax)
{
	double x;
	x = dmin + 1.f * (dmax - dmin) * rand() / RAND_MAX;
	return x;
}

//������� 3
int* randd(int n, int mmax)
{
	int array[100];
	for (int i = 1; i < n + 1; i++)
	{
		array[i] = rand10(mmax);
		printf("����� %d = %d\n", i, array[i]);
	}
	return array;
}

//������� 4
double* randd2(int n, double ddm)
{
	double array2[100];
	for (int i = 1; i < n + 1; i++)
	{
		array2[i] = -ddm + 1.f * (+ddm - -ddm) * rand() / RAND_MAX;
		printf("����� %d = %.2lf\n", i, array2[i]);
	}
	return array2;
}