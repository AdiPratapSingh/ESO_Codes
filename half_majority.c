#include <stdio.h>
// O(n) time complexity
int alt = -1;

int solve(int n, int*a){
    if(n==1){
        return a[0];
    }
    int new_a[n/2];
    int count = 0;
    for(int i=0;i<n-1;i=i+2){
        if(a[i]==a[i+1]){
            new_a[count] = a[i];
            count ++;
        }
    }
    if(count==0){
        if(n%2){
            return a[n-1];
        }
        else{
            alt = a[1];
            return a[0];
        }
    }
    return solve(count,new_a);
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    // while(!flag){
    //     int arr[m/2];
    //     int count = 0;
    //     m=m/2;
    //     for(int i=0;i<m-1;i=i+2){
    //         if(a[i]==a[i+1]){
    //             arr[count] = a[i];
    //             count ++;
    //         }
    //     }
    // }
    int ans = solve(n,a);
    int count1 = 0,count2 = 0;
    for(int i=0;i<n;i++){
        if(a[i]==ans){
            count1++;
        }
        if(a[i]==alt){
            count2++;
        }
    }
    if(count1>=(n+1)/2){
        printf("%d",ans);
    }
    else if(count2>=(n+1)/2){
        printf("%d",alt);
    }
    return 0;
}