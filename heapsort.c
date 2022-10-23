#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void
swap (int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void
heapify (int arr[], int n, int i)
{

  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;


  if (largest != i)
    {
      swap (&arr[i], &arr[largest]);
      heapify (arr, n, largest);
    }
}


void
heapSort (int arr[], int n)
{

  for (int i = n / 2 - 1; i >= 0; i--)
    heapify (arr, n, i);


  for (int i = n - 1; i >= 0; i--)
    {
      swap (&arr[0], &arr[i]);


      heapify (arr, i, 0);
    }
}


void
printArray (int arr[], int n)
{
  for (int i = 0; i < n; ++i)
    printf ("%d ", arr[i]);
  printf ("\n");
}


void
reverse (int a[], int n)
{
  int temp;
  for (int i = 0; i <= n / 2; i++)
    {
      temp = a[i];
      a[i] = a[n - i - 1];
      a[n - i - 1] = temp;
    }
}



int
main ()
{
  int n;
  srand (time (0));
  clock_t start, end;
  printf ("enter the size of the array");
  scanf ("%d", &n);
  int a[n];
  printf ("the array elements before sort \n");

  for (int i = 0; i < n; i++)
    {
      a[i] = (rand () % 60) + 1;
    }

  printArray (a, n);
  printf ("\nafter sorting \n");
  start = clock ();
  heapSort (a, n);

  printArray (a, n);
  end = clock ();
  double total = (double) (end - start) / CLOCKS_PER_SEC;
  printf ("total time :%fs\n", total);

  start = clock ();
  heapSort (a, n);

  printArray (a, n);
  end = clock ();
  total = (double) (end - start) / CLOCKS_PER_SEC;
  printf ("total time :%fs\n", total);

  reverse (a, n);
  printArray (a, n);

  start = clock ();
  heapSort (a, n);
  printArray (a, n);
  end = clock ();
  total = (double) (end - start) / CLOCKS_PER_SEC;
  printf ("total time :%fs\n", total);


}
