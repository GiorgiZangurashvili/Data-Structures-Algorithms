#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

/* 
   inverse-ის საპოვნელი ფუნქციები ჩემი დაწერილი არ არის. მაქვს აღებული codeforce-ის ერთ-ერთი ბლოგიდან.
   ამ ბლოგის ლინკი მითითებული მაქვს README ფაილში. 
*/
long long mod_exp(long long a, long long b, long long mod){
    a %= mod;
    if(a == 0){
        return 0;
    } 
    long long res = 1;
    while(b > 0){
        if(b & 1){    // you can also use b % 2 == 1
            res *= a;
            res %= mod;
            b--;
        }

        a *= a;
        a %= mod;
        b >>= 1;
    }

    return res;
}

long long inverse(long long a, long long mod){
    return mod_exp(a, mod - 2, mod);
}

long long nCk(long long n, long long k, long long mod, long long fact[]){
    return ((fact[n] * inverse(fact[k], mod) % mod) * inverse(fact[n - k], mod)) % mod;
}

int main(){
    int n;
    scanf("%d", &n);

    int t[n];
    for(int i = 0; i < n - 1; i++){
        int num;
        scanf("%d", &num);
        t[i] = num;
    }

    long long fact[n + 1];
    fact[0] = 1;
    long long fact_i = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = fact_i;
        if(i < n){
            fact_i *= (i + 1);
            fact_i %= mod;
        }
    }

    long long res = 1;
    for(int i = 1; i <= n - 2; i++){
        res = (res * nCk(t[i] + 1, t[i - 1], mod, fact)) % mod;
    }
    printf("%lld\n", res);
    

    return 0;
}