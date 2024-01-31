#include <bits/stdc++.h>
using namespace std;

#define ARR_SIZE 1024
#define STR_SIZE 5

void generate_answers(vector<string>& arr, string curr_str){
    if(curr_str.length() == STR_SIZE){
        arr.push_back(curr_str);
        return;
    }

    for(int i = 0; i < 4; i++){
        char ch = 'A' + i;
        generate_answers(arr, curr_str + ch);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> generated_answers;
    generate_answers(generated_answers, "");

    int t;
    //scanf("%d", &t);
    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        //scanf("%d", &n);
        cin >> n;
        int number_of_answers = 0;
        vector<string> answers;
        vector<int> quiz_scores;
        for(int j = 0; j < n; j++){
            string s;
            int p;
            cin >> s >> p;
            answers.push_back(s);
            quiz_scores.push_back(p);
        }

        unordered_map<string, int> suffix_freq;

        for(int j = 0; j < generated_answers.size(); j++){
            string s = generated_answers[j];
            bool flag = true;
            string key = "";
            for(int l = 0; l < answers.size(); l++){
                string str = answers[l];
                int entry = 0;
                for(int k = 5; k < 10; k++){
                    if(s[k - 5] == str[k]){
                        entry += 10;
                    }
                }

                if(entry <= quiz_scores[l]){
                    entry /= 10;
                    char ch = '0' + entry;
                    key += ch;
                }else{
                    flag = false;
                }
            }
            if(flag){
                suffix_freq[key]++;
            }
        }

        for(int j = 0; j < generated_answers.size(); j++){
            string s = generated_answers[j];
            string key = "";
            bool flag = true;
            for(int l = 0; l < answers.size(); l++){
                string str = answers[l];
                int entry = 0;
                for(int k = 0; k < 5; k++){
                    if(s[k] == str[k]){
                        entry += 10;
                    }
                }
    
                if(entry <= quiz_scores[l]){
                    int add = (quiz_scores[l] - entry) / 10;
                    char ch = '0' + add;
                    key += ch;
                }else{
                    flag = false;
                }                    
            }
            if(flag){
                number_of_answers += suffix_freq[key];
            }
        }

        // printf("%d\n", number_of_answers);
        cout << number_of_answers << endl;
    }
    
    //cout << endl;
    return 0;
}