#include <stdio.h>
#include <time.h>

int main(){     // Fabonaci through if else
    int n;
    scanf("%d",&n);
    // time_t start, end;
    time_t start = time(NULL);
    long long int a=1,b=1,h;
    if(n==1||n==2){
        printf("1");
    }
    else{
        for(int i=2;i<n;i++){
            h=b%2014;
            b=a+b;
            a=h;
        }
    }
    printf("%lld\n",b%2014);
    time_t end = time(NULL);
    printf("%f\n",difftime(end,start));
    int diff = (int)difftime(end,start);
    int seconds = diff % 60;
    int minutes = ((diff - seconds)/60) % 60;
    int hours = ((diff -seconds - 60*minutes)/3600);
    printf("Time taken is %d:%d:%d\n",hours,minutes,seconds);
    return 0;
}