/**
 \brief Luogu P2580
 A Trie template. 
 \author Diac
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

class trie
{
private:
    int cnt_;
    vector<vector<int> > next_;
    vector<bool> exist_;
    
public:
    trie(int alphabet_size, int string_num) // string number should be the number of strings multiplied by the maximum number of characters
    {
        cnt_ = 0;
        next_.resize(string_num, vector<int>(alphabet_size, 0));
        exist_.resize(string_num, false);
    }

    void insert(char *str, int len)
    {
        int p = 0;
        for(int i = 0; i < len; ++i)
        {
            int index = str[i] - 'a';
            if(!next_[p][index])
                next_[p][index] = ++cnt_;
            p = next_[p][index];
        }
        exist_[p] = true;
    }

    bool find(char *str, int len)
    {
        int p = 0;
        for(int i = 0; i < len; ++i)
        {
            int index = str[i] - 'a';
            if(!next_[p][index])
                return false;
            p = next_[p][index];
        }
        return exist_[p];
    }
};


int main()
{
    int n; 
    scanf("%d", &n);
    trie t(26, n * 51);
    for(int i = 0; i < n; ++i)
    {
        char str[51];
        scanf("%s", str);
        t.insert(str, strlen(str));
    }
    
    map<string, int> cnt; 
    int m; 
    scanf("%d", &m);
    for(int i = 0; i < m; ++i)
    {
        char str[51];
        scanf("%s", str);
        if(t.find(str, strlen(str)) && !cnt[str])
            printf("OK\n"), cnt[str] = 1;
        else if (cnt[str])
            printf("REPEAT\n");
        else         
            printf("WRONG\n");
    }
}