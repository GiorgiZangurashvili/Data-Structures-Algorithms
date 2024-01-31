#include <bits/stdc++.h>

using namespace std;

int cnt_min_moves(int* nums, int n){
    if(n < 1) return 0;
    vector<int> lis;
    lis.push_back(nums[0]);

    for(int i = 1; i < n; i++){
        if(nums[i] > lis[lis.size() - 1]){
            lis.push_back(nums[i]);
        }else{
            int l = 0, r = lis.size() - 1;
            int idx = -1;

            while(l <= r){
                int m = l + (r - l) / 2;

                if(nums[i] <= lis[m]){
                    idx = m;
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
            if(idx != -1){
                lis[idx] = nums[i];
            }
        }
    }

    return n - lis.size();
}

void construct_heap(vector<int>& heap, int heap_idx, int* arr, int& arr_idx, unordered_map<int, int>& map){
    if(heap_idx >= heap.size()) return;
    construct_heap(heap, 2 * heap_idx + 1, arr, arr_idx, map);
    heap[heap_idx] = arr[arr_idx];
    arr_idx++;
    construct_heap(heap, 2 * heap_idx + 2, arr, arr_idx, map);
}

void construct_map(vector<int>& heap, unordered_map<int, int>& map){
    for(int i = 0; i < heap.size(); i++){
        if(i == 0){
            map[heap[i]] = -1;
        }else{
            map[heap[i]] = heap[(i - 1) / 2];
        }
    }
}

int main(){
    int t_case;
    scanf("%d", &t_case);
    int min_move_ans[t_case];

    for(int i = 0; i < t_case; i++){
        int n;
        scanf("%d", &n);
        int nums[n];
        int cnt = 0;
        int num;

        while(cnt < n){
            scanf("%d", &num);
            nums[cnt] = num;
            cnt++;
        }

        int ans = cnt_min_moves(nums, n);
        sort(nums, nums + n);
        vector<int> heap(n);
        int arr_idx = 0;
        unordered_map<int, int> map;
        construct_heap(heap, 0, nums, arr_idx, map);
        construct_map(heap, map);

        printf("Case %d:\n", i + 1);
        printf("Minimum Move: %d\n", ans);
        string s = "";
        for(int i = 0; i < n; i++){
            s += to_string(map[nums[i]]);
            if(i != n - 1)
                s += " ";
        }
        printf("%s\n", s.c_str());
    }
    
    return 0;
}