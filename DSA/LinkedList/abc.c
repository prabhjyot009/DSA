#include<stdio.h>
#include<math.h>
float g(float x)
{
    return(x*exp(x)-1);
}
float f(float x)
{
    return(exp(x)*(x+1));
}
float pr(float x,float y,float z)
{
    return((x)-((y)/(z)));
}
int main()
{
    float x1,x2,x3,x4,f1,f2,r;
    int i=1;
    printf("\n Enter intervals:");
    scanf("%f%f",&x1,&x2);
    x3=(x1+x2)/2;
    do
    {
        printf("\n Iteration %d",i);
        printf("\nx3=%f",x3);
        f1=g(x3);
        printf("\tf1=%f",f2);
        r=pr(x3,f1,f2);
        printf("\t value=%f\n",r);
        x3=r;
        i++;
        }
        while(fabs(g(x3))>0.00001);
        printf("\n\nfinal root is %f",x3);
        return 0;
}

