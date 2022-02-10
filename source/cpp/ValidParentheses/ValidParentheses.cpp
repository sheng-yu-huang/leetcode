/**********************************************************************************
*
* Valid Parentheses
* Source: https://leetcode.com/problems/valid-parentheses/
* @author Sam Huang
* @version Nov 23, 2021
*
*
* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* An input string is valid if:
* Open brackets must be closed by the same type of brackets.
* Open brackets must be closed in the correct order.
*
* Example:
*
* Input: s = "()[]{}"
* Output: true
*
*
**********************************************************************************/

class Solution {
public:
    bool isValid(string s) {
        int s_length = s.length();
        if(s_length % 2 != 0)
            return false;
        if(s[0]==')' || s[0] == ']' || s[0] == '}')
            return false;
        stack<int> st;
        
        for(int i=0; i<s_length; i++){
            char c = s[i];
            if((c == '(') || (c == '[') || (c == '{')){
                st.push(c);
            } else if (c == ')'){
                if(st.empty() || ( (char)st.top() !='('))
                    return false;
                st.pop();
            } else if (c == ']'){
                if(st.empty() || ((char)st.top() !='['))
                    return false;
                st.pop();
            } else if (c == '}'){
                if(st.empty() || ((char)st.top() !='{'))
                    return false;
                st.pop();
            } else {
                return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};