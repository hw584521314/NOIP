#include<algorithm>
#include<cstdio>
using namespace std;
char a[]="ABCD";

int main()
{
	int count=0;
	do{
		printf("%s\n",a);
		count++;
	}
	while(next_permutation(a,a+4));	
	printf("%d",count);
} 
