/*A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:
S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.
Write a function:
int solution(string &S);
that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.
For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.
Assume that:
N is an integer within the range [0..200,000];
string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N) (not counting the storage required for input arguments).
Copyright 2009–2015 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.*/

#include<iostream>
#include<stack>


int solution(string &S) {
    std::stack<char> inQ; 
    for (unsigned int i = 0; i < S.length(); i++){
        if (S[i] == '(' || S[i] == '[' || S[i] == '{')  {
            inQ.push(S[i]);
        }
        else{
            if (inQ.empty()){
                return 0;
            }
            else{
                if (S[i] == ')'){
                    if (inQ.top() != '(' ){
                    return 0;
                    }  
                    else{
                        inQ.pop();
                    }
                }
                if (S[i] == ']'){
                    if (inQ.top() != '[' ){
                        return 0;
                    }
                    else{
                        inQ.pop();
                    }
                }
                if (S[i] == '}'){
                    if(inQ.top() != '{' ){
                        return 0;
                    }  
                    else{
                        inQ.pop();
                    }
                }
            }
        }
    }
    
    if(!inQ.empty()){
        return 0;
    }
    
    return 1;

}