#include<stdio.h>
void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void merge(int a[],int lb,int mid,int ub)
{
	int b[32];
	int i=lb;
	int j=mid+1;
	int k=lb;
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(i=lb;i<=ub;i++)
	{
		a[i]=b[i];
	}
}
void mergesort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		mergesort(a,lb,mid);
		mergesort(a,mid+1,ub);
		merge(a,lb,mid,ub);
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
	mergesort(arr,0,size-1);
	printf("After sorting elements are ");
	print(arr,size);
}
