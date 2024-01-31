#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++){
        int time;
        scanf("%d", &time);
        arr[i] = time;
    }

    if(n == 1){
        printf("%d", arr[0]);
        return;
    }else if(n == 2){
        printf("%d", arr[1]);
        return;
    }else if(n == 3){
        printf("%d", arr[0] + arr[1] + arr[2]);
        return;
    }

    int res = 0;
    int first = arr[0];
    int second = arr[1];
    for(int i = n - 1; (i - 1) >= 0; i -= 2){
        if(i - 1 == 1){
            res += first + second + arr[i];
        }else if(i - 1 == 0){
            res += second;
            break;
        }else{
            int before_last = arr[i - 1];
            int last = arr[i];
            int st_1 = before_last + last + 2 * first;
            int st_2 = 2 * second + first + last;
            res += min(st_1, st_2);
        }
    }

    printf("%d", res);
}

int main(){
    solve();
    return 0;
}