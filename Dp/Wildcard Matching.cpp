#include<bits/stdc++.h>
//pre req=> distinct subsequences
using namespace std;

class Solution {
    private:
    bool fun(int i, int j, string s, string p){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0){
           for(int jj=0; jj<=j; jj++){
               if(p[jj] !='*') return false;
           }
            return true;
        }
         if(s[i]==p[j] || p[j] !='?'){
             return fun(i-1, j-1, s, p);
         }
        if(p[j] =='*'){
            return fun(i-1, j, s, p) | fun(i, j-1, s, p);
        }
        return false;

    }
public:
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        return fun(n-1, m-1, s, p);
    }
};


//https://leetcode.com/problems/wildcard-matching/description/