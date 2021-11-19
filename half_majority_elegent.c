#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int cand = a[0];
    int count= 1;
    for(int i=0;i<n;i++){
        if(count==0){
            cand=a[i];
        }
        if(a[i] == cand){
            count++;
        }
        else{
            count--;
        }
    }
    printf("%d",cand);
    return 0;
}