#include<stdio.h>
void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int lb,int ub)
{
	int start=lb;
	int end=ub;
	int pivot=a[lb];
	while(start<end)
	{
		while(a[start]<=pivot && start<ub)
		{
			start++;
		}
		while(a[end]>pivot && end>lb)
		{
			end--;
		}
		if(start<end)
		{
			swap(&a[start],&a[end]);
		}
	}
	swap(&a[lb],&a[end]);
	return end;
}
void quicksort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
		int loc=partition(a,lb,ub);
		quicksort(a,lb,loc-1);
		quicksort(a,loc+1,ub);
	}
}
void main()
{
	int arr[30],size,i;
	printf("Enter size of an array ");
	scanf("%d",&size);
	printf("Enter elements in an array ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Before sorting elements are ");
	print(arr,size);
	quicksort(arr,0,size-1);
	printf("After sorting elements are ");
	print(arr,size);
}
				
