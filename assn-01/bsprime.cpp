#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 103000000
 
vector<pair<int, int> > pairs;
long long cnt = 0;
int in = 1, sz = 0;
 

//Segmented Sieve GeeksForGeeksდან ავიღე
void simpleSieve(int limit, vector<int> &prime, vector<int>& answers){
    vector<bool> mark(limit + 1, true);
    
    for (int p=2; p*p<limit; p++){
        if (mark[p] == true){
            for (int i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }

    for (int p=2; p<limit; p++){
        if (mark[p] == true)
        {
            prime.push_back(p);
            int p1 = p;
 
            int count = __builtin_clz(p);
            p1 <<= count;
 
            while(count != 32){
                if(p1 < 0){
                    cnt++;
                }
 
 
                while(pairs[sz].first == 0){
                    answers[pairs[sz].second]=0;
                    sz++;
                }
 
                while(pairs[sz].first == in){
                    answers[pairs[sz].second] = cnt;
                    sz++;
                    if(pairs.size() == sz){
                        return;
                    } 
                }
                in++;
                count++;
                p1 <<= 1;
            }
        }
    }
}

void segmentedSieve(int n, vector<int>& answers){
    int limit = floor(sqrt(n))+1;
    vector<int> prime;
    prime.reserve(limit);
    simpleSieve(limit, prime, answers);
    
    if(pairs.size() == sz){
        return;
    }
 
    int low = limit;
    int high = 2*limit;
 
    while (low < n){
        if (high >= n)
           high = n;
         
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        for (int i = 0; i < prime.size(); i++){
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];

            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 
        for (int i = low; i<high; i++){
            if (mark[i - low] == true){
                int p1 = i;
 
                int count = __builtin_clz(i);
                p1 <<= count;
 
                while(count != 32){
                    if(p1 < 0){
                        cnt++;
                    }
 
                    while(pairs[sz].first == 0){
                        answers[pairs[sz].second]=0;
                        sz++;
                    }
 
 
 
                    while(pairs[sz].first == in){
                        answers[pairs[sz].second] = cnt;
                        sz++;
                        if(pairs.size() == sz){
                            return;
                        } 
                    }
                    in++;
                    count++;
                    p1 <<= 1;
                }
            }
        }
 
        low = low + limit;
        high = high + limit;
    }
}
 
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int t_case;
        scanf("%d", &t_case);
 
        pairs.push_back(make_pair(t_case, i + 1));
    }
 
    sort(pairs.begin(), pairs.end());
    vector<int> answers(t + 1);
 
    segmentedSieve(MAXN, answers);
 
 
    for(int i = 1; i < answers.size(); i++){
        printf("%d\n", answers[i]);
    }
 
    return 0;
} 