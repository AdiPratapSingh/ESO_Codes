#include <bits/stdc++.h>
#include <time.h>
using namespace std;
// Reference Lecture 15 Quick Sort
int voilater(vector<int> &a, int start, int end){
    for(int i=start;i<end;i++){
        if(a[i]>a[i+1]){
            return i;
        }
    }
    return -1;
}

int Quick_Sort(vector<int>&a, int start, int end){
    int index = voilater(a,start,end);          // returns the index of a number which violates acending order
    if(index==-1)
    return -1;
    int val;
    int big_index;
    int small_index;
    val = a[index];     // val is the value stored at index which violated acending order
    big_index = end;
    int flag = 0;         //used as indecator that a value grater than val is spotted
    int r;
    while(big_index >= index){
        if(!flag){
            if(a[big_index]<val){
                small_index = big_index;
                big_index--;
                flag = 1;      //once a number smaller than val is spotted we swith off this loop ans
            }
        }
        // Now as the big_index iterates over the array, we swap its value with value at small index whenever a[big_index]>=val
        if(flag&&a[big_index]>=val&&big_index>=index){   // in this way the values less than val are collected on the left of small_index
            r = small_index;
            int hold = a[small_index];                   
            a[small_index] = a[big_index];
            a[big_index] = hold;
            small_index--;
        }
        big_index--;
    }
    return r;          
}

void Controller(vector<int>&a, int start, int end){
    if(start<end){
        int index = Quick_Sort(a,start,end);    
        if(index!=-1){
            if(start<index-1)
            Controller(a,start,index-1);
            if(end>index+1)
            Controller(a,index+1,end);
        }
    // for(int i=start;i<=end;i++){
    //     printf("%d ",a[i]);
    // }
    }
    return;
}

int main(){
    time_t start = time(NULL);
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i = 0;i<n;i++){
        a[i] = rand();
    }
    Controller(a,0,n-1);
    // for(int i=0;i<n;i++){
    //     printf("%d ",a[i]);
    // }
    time_t end = time(NULL);
    printf("%f\n",difftime(end,start));
    int diff = (int)difftime(end,start);
    int seconds = diff % 60;
    int minutes = ((diff - seconds)/60) % 60;
    int hours = ((diff -seconds - 60*minutes)/3600);
    printf("Time taken is %d:%d:%d\n",hours,minutes,seconds);
    return 0;
}
