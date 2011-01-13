#include <stdio.h>
#include <stdlib.h>

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

int newton1(int n, int k) // poprawnie działa dla maksymlanie n = 33, suma przekracza inta, wolna
{
    if(k == 0) return 1;
    if(k == 1) return n;
    if(k > n - k) return newton1(n, n-k);
    return newton1(n-1,k-1) + newton1(n-1,k);
}

int newton2(int n, int k) // poprawnie działa dla maksymlanie n = 12, silnia(12) przekracza inta, szybka
{
    return silnia2(n)/(silnia2(k)*silnia2(n-k));
}


int main(void) {
    printf("%d\n", newton1(33,16)); 
    printf("%d\n", newton2(12,6)); 
    return EXIT_SUCCESS;
}
