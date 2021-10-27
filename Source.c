#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
  int N = 0, min = 0, max = 0, i = 0, j = 0;
  double sum = 0;
  double* mas1;
  double* mas2;
  printf("N =\t");
  scanf_s("%d", &N);
  if (N <= 0)
  {
    printf("ERROR N<=0!!!");
    return 0;
  }
  printf("Min =\t");
  scanf_s("%d", &min);
  printf("Max =\t");
  scanf_s("%d", &max);
  if (max < min)
  {
    printf("ERROR max<min!!!");
    return 0;
  }
  //Выделение памяти
  mas1 = (double*)malloc(N * sizeof(double));
  if (mas1 == 0)
  {
    printf("ERROR mas1 == 0!!!");
    return 0;
  }
  mas2 = (double*)malloc(N * sizeof(double));
  for (i = 0; i < N; i++)
  {
    mas1[i] = ((double)rand() / RAND_MAX) * (max - min) + min;
    //printf("mas1[%d] = %lf\n", i, mas1[i]);
  }
  for (i = 0; i < N; i++)
  {
    mas2[i] = (mas1[i] - (int)mas1[i]) * 1000;
    //printf("mas2[%d] = %lf\n", i, mas2[i]);
  }
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
      if ((int)mas2[j] == i)
        mas2[j] = 0;
  }
  /*for (j = 0; j < N; j++)
    printf("mas2[%d] = %lf\n", j, mas2[j]);*/
  for (i = 0; i < N; i++)
  {
    if (mas2[i] == 0)
      sum = sum - mas1[i];
    else
      sum = sum + mas1[i];
  }
  printf("Sum = %lf\n", sum);
  free(mas1);
  free(mas2);
  return 0;
}