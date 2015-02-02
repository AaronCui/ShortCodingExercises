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

#include<cstdlib>
#include<iostream>
#include<stack>
#include<string>
#include<vector>

int solution(std::string S) {
    std::stack<char> inQ; 
    for (unsigned int i = 0; i < S.length(); i++){
        if (S[i] == '(' || S[i] == '[' || S[i] == '{')  {
            inQ.push(S[i]);
        }
        else if (inQ.empty()){
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
    
    if(!inQ.empty()){
        return 0;
    }
    
    return 1;

}

int main() {
	// this is here simply to run the code, without a pre written code to test it as originally on codility
	int result;
	std::string s1 ("()[]{}");
	std::string s2 ("([{()()}])");
	std::string s3 ("([{]})");
	std::string s4 (")()()");
	std::vector<std::string> errthing;
	errthing.push_back(s1);
	errthing.push_back(s2);
	errthing.push_back(s3);
	errthing.push_back(s4);
	std::cout << " Testing: s1 " << s1 << "s2 " << s2 << "s3 " << s3 << "s4 " << s4 << std::endl;
	for (int i = 0; i < errthing.size(); i++){
		std::string S = errthing[i];
		result = solution (S);
		if (result)
			std::cout << "Passed" << std::endl;
		if (!result)
			std::cout << "Wrong" << std::endl;
		if (result != 0 && result != 1)
			std::cout << "something F'd up" << std::endl;
	}
	return 0;
}
	