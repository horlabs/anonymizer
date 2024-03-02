#include<stdio.h>
#include<math.h>

typedef long long ll;

int isPalindrome(ll n) {
    int digits[20], i, j;
    
    for(i = 0; n > 0; i++, n /= 10) {
        digits[i] = n % 10;
    }
    
    for(i--, j = 0; i > j; i--, j++) {
        if(digits[i] != digits[j]) {
            return 0;
        }
    }
    
    return 1;
}

int countPalindrome(ll a, ll b) {
    ll i, j, l;
    int count = 0;
    
    l = sqrt(b);
    
    for(i = sqrt(a); i <= l; i++) {
        if(isPalindrome(i)) {
            j = i * i;
            if(j >= a && j <= b && isPalindrome(j)) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    freopen("C:\\Users\\anonymous\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\anonymous\\Desktop\\out.txt","w",stdout);

    int i, t, cs;
    ll a, b;
    
    scanf("%d", &cs);
    
    for(t = 1; t <= cs; t++) {
        scanf("%lld %lld", &a, &b);
        printf("Case #%d: %d\n", t, countPalindrome(a, b));
    }
    
    return 0;
}