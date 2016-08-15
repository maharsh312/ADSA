#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main()
{
	int n,temp,i,j;
ofstream out;
	out.open("values_is.csv");	

for(n=50;n<=20000;n=n+50)
{
	
	int a[n];
 
 	
     
    for(int i=0; i<n; i++)
   {a[i] = (rand()%100)+1;}

    clock_t begin = clock();

	for(i=1;i<n;i++)
	{
		for(j=i;j>=1;j--)
		{
			if(a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
			else
				break;
		}
	}

	clock_t end = clock();


	double time = ((double)end-begin)/CLOCKS_PER_SEC;
	out<<n<<","<<time<<"\n";
}
	
}

