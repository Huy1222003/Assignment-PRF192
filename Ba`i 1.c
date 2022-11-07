#include<stdio.h>
int gt(int n)
{
    int i,s=1;
    for ( i=2;i<=n;i++)
        s=s*i;
    return s;
}
int main()
{	FILE *f;
    f = fopen ("bai1 ass.txt", "ab");
    int k,n;
    scanf ("%d %d",&n,&k);
    fscanf(f,"%d %d",&n,&k);
    fprintf (f,"%d %d\n",n,k);
    while (n<0)
    {
        return 0;
    }
    while (k<0 || (k>n))
    {
		return 0;
    }
    k=gt(n)/(gt(k)*gt(n-k));
    printf ("%d\n", k);
    fprintf(f,"\n%d\n",k);
}

