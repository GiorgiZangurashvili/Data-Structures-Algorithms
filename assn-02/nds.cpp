#include <bits/stdc++.h>

using namespace std;

int solve(int* nums, int n, int seq_len){
    vector<int> dp;
    for(int i = 0; i < n; i++){
        if(dp.empty() || nums[i] > dp[dp.size() - 1]){
            dp.push_back(nums[i]);
        }else{
            int l = 0, r = dp.size() - 1;

            int res = -1;
            while(l <= r){
                int m = l + (r - l) / 2;

                if(nums[i] <= dp[m]){
                    r = m - 1;
                    res = m;
                }else{
                    l = m + 1;
                }
            }
            if(res != -1){
                dp[res] = nums[i];
            }
        }
    }

    if(seq_len - 1 >= dp.size())
        return -1;
    return dp[seq_len - 1];
}

int main(){
    int t_case;
    scanf("%d", &t_case);
    int ans[t_case];

    for(int i = 0; i < t_case; i++){
        int n;
        scanf("%d", &n);
        int nums[n];
        int count = 0;
        int num;

        while(count < n){
            scanf("%d", &num);
            nums[count] = num;
            count++;
        }
        int seq_len;
        scanf("%d", &seq_len);
        if(seq_len > n || seq_len == 0){
            ans[i] = -1;
        }else{
            ans[i] = solve(nums, n, seq_len);
        }
    }

    for(int i = 0; i < t_case; i++){
        printf("%d\n", ans[i]);
    }

    return 0;
}