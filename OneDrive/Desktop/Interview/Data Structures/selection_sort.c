#include<stdio.h>
void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void selection_sort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			int temp=a[min];
			a[min]=a[i];
			a[i]=temp;
		}
	}
}
void main()
{
	int arr[30],i,size;
	printf("Enter size of an array ");
	scanf("%d",&size);
	printf("Enter elements in an array ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Before sorting elements are ");
	print(arr,size);
	selection_sort(arr,size);
	printf("After sorting elements are ");
	print(arr,size);
}
