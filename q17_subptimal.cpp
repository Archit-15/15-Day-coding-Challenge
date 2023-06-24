// 3. Longest Substring Without Repeating Characters
// time complexity - O(2n)
#include<iostream>
#include<vector>
#include<set>
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    int left = 0;
    int right = 0;
    int len = 0;
    set<char> st;
    for(right=0;right<s.length();++right){
        if(st.find(s[right])!=st.end()){
            st.erase(s[left]);
            ++left;
        }
        st.insert(s[right]);
        len = max(len,(right-left)+1);
    }
    return len;
}

int main()
{
    string s = "abcabcbb";
    int ans = lengthOfLongestSubstring(s);
    cout<<ans;
    return 0;
}