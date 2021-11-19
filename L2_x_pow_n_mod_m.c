#include <stdio.h>
#include <math.h>

int rem(int x,int n,int m){
    if(m==1){
        return 0;
    }
    else if(n==0){
        return 1;
    }
    else if(n%2==0){
        return ((int)pow((rem(x,n/2,m)%m),2))%m;
    }
    else return ((int)(x*pow((rem(x,(n-1)/2,m)%m),2)))%m;
}

int main(){
    int x;
    int n;
    int m;
    scanf("%d %d %d", &x, &n, &m);
    printf("%d\n",rem(x,n,m));
    return 0;
}