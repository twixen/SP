#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int silnia1(int n)
{
    if(n == 0) return 1;
    return n*silnia1(n-1);
}

int silnia2(int n)
{
    int w;
    for(w = 1; n ; n--) w *= n;
    return w;
}

int newton1(int n, int k) // poprawnie dzia³a dla maksymlanie n = 33, suma przekracza inta, wolna
{
    if(k == 0) return 1;
    if(k == 1) return n;
    if(k + k > n) return newton1(n, n-k);
    return newton1(n-1,k-1) + newton1(n-1,k);
}

int newton2(int n, int k) // poprawnie dzia³a dla maksymlanie n = 12, silnia(12) przekracza inta, szybka
{
    return silnia2(n)/(silnia2(k)*silnia2(n-k));
}

int newton3(int n, int k) // poprawnie dzia³a dla maksymlanie n = 29, c przekracza inta, najszybsza
{
    if(k + k > n) k = n - k;
    int c = 1;
    int i = 0;
    while(i < k)
    {
        c *= n - i;
        c /= ++i;
    }
    return c;
}

int main(void) {
    struct timeval tim;
    double t1, t2;
    
    gettimeofday(&tim, NULL);
    t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("%d", newton1(33,16));
    gettimeofday(&tim, NULL);
    t2=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf(" %.6lf\n", t2-t1);
      
    gettimeofday(&tim, NULL);
    t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("%d", newton2(12,6)); 
    gettimeofday(&tim, NULL);
    t2=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf(" %.6lf\n", t2-t1);
    
    gettimeofday(&tim, NULL);
    t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf("%d", newton3(29,14)); 
    gettimeofday(&tim, NULL);
    t2=tim.tv_sec+(tim.tv_usec/1000000.0);
    printf(" %.6lf\n", t2-t1);

    return EXIT_SUCCESS;
}
