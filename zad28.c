#include<stdio.h>
#include<gmp.h>
#include<stdlib.h>

void silnia1(mpz_t w, int n)
{
    mpz_set_ui(w,1);
    do
    {
        mpz_mul_ui(w, w, n);
    }
    while(--n);
}

void newton1(mpz_t w, int n, int k)
{
    mpz_t x;
    mpz_init(x);
    silnia1(w, k);
    silnia1(x, n-k);
    mpz_mul(w, w, x);
    silnia1(x, n);
    mpz_divexact(w, x, w);
    mpz_clear(x);
}

int newton2(int n, int k)
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

int main(void){
    
    mpz_t foo;
    mpz_init(foo);
    newton1(foo, 29, 14);
    mpz_out_str(stdout, 10, foo);
    printf("\n"); 
    mpz_clear(foo);
    
    printf("%d\n", newton2(29, 14)); 
    return EXIT_SUCCESS;
}
