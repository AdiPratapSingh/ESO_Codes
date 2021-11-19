#include <stdio.h>

int find_min(int * a,int start,int end){
    int mid = (start + end)/2;
    if((a[mid]<a[mid - 1])&&(a[mid]<a[mid + 1])){
        return a[mid];
    }
    else if((a[start]<a[start + 1])){
        return a[start];
    }
    else if((a[end]<a[end - 1])){
        return a[end];
    }
    else if(a[mid]>a[mid-1]){
        end = mid -1;
        return find_min(a,start,end);
    }
    else if(a[mid]>a[mid+1]){
        start = mid +1;
        return find_min(a,start,end);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans = find_min(a,0,n-1);
    printf("%d",ans);
    return 0;
}