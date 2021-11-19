#include <stdio.h>

int fun(int a[], int s, int start,int *n,int bool){
    //printf("======%d======",bool);
    if(bool==1){
        return 1;
    }
    else if(start>=*n){
       return bool;
    }
    else{
    for(int i=start;i<*n;i++){
        if(s>0&&i<*n&&bool==0){
            printf("-----%d------",a[i]);
            bool = fun(a,s-a[i],i+1,n,bool);
            if (bool==1){
                return 1;
            }
            printf("======%d======",bool);    
        }
        else if(s==0){
            return 1;
        }
        else{
            printf("======%d======",bool);
            return bool;
        }
    }
    return bool;
    } 
}

int main(){
    int n,s;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&s);
    int val = fun(a,s,0,&n,0);
    if(val==1){
        printf("\nYES\n");
    }
    else if(val==0){
        printf("\nNO\n");
    }
    return 0;
}