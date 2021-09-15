#include <stdio.h>

int minmax(int a[],int n);
int main()
{
    int a[1000],i,n;
   
    printf("Enter size of an array : ");
    scanf("%d", &n);
 
    printf("Enter elements in an array : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    minmax(a,n);    
}
int minmax(int a[],int n)
{
 	int min,max,i;
 	min=max=a[0];
    for(i=1; i<n; i++)
    {
         if(min>a[i])
		  min=a[i];   
		   if(max<a[i])
		    max=a[i];       
    }
    
    printf("Minimum of array is : %d",min);
    printf("\nMaximum of array is : %d",max);
}