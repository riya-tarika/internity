#include<cstdio>
#include<conio.h>
 
main(){
	int e,n,d;
	printf("enter no of edges in a graph: ");
	scanf("%d",&e);
	printf("\ndegree of each node: ");
	scanf("%d",&d);
	n=(2*e)/d;
	printf("\n%d total no. of nodes in a graph",n);
	getch();
}
