#include <stdio.h>
#include <time.h>

int RBinSearch(int a[], int l, int h, int key)
{

    int mid = 0;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinSearch(a, l, mid - 1, key);
    }
    else
        return RBinSearch(a, mid + 1, h, key);
    return -1;
}

int main()
{   int n;
printf("enter the no of elements\n");
scanf("%d",&n);
int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int key;int res;
    printf("find the element to be searched in the array \n");
    scanf("%d",&key);
   res= RBinSearch(arr,0,n,key);
   printf("the key is found at index %d",res);
  

}
