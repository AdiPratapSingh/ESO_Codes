#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int sep = a[0];
    int curr = n-1;
    int flag = 0;
    int hold;
    for(int i=n-1;i>=0;i--){
        if(!flag){
            if(a[i]<sep){
                flag = 1;
                curr = i;
            }
        }
        if(a[i]>=sep&&flag){
            hold = a[i];                //swap(a[i],a[curr]);
            a[i] = a[curr];
            a[curr]= hold;
            curr--;
        }
    }
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}