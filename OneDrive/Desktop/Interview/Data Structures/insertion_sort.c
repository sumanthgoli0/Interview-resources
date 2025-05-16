#include<stdio.h>
void print(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void insertion_sort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int temp=a[i];
		int j=i-1;
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
void main()
{
	int arr[30],size;
	printf("Enter size of an array ");
	scanf("%d",&size);
	printf("Enter elements in an array ");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Before sorting elements are ");
	print(arr,size);
	insertion_sort(arr,size);
	printf("After sorting elements are ");
	print(arr,size);
}
