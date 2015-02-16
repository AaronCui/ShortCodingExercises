//Aaron Cui
//Feb 16 - 2015
//HackerRank The Love-Letter Mystery Solution 
//Question in same folder as PDF

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string line;
    int cases;

    std::cin >> cases;
    int hotfix = 0;
    for (int i = 1; i < cases; i++){
        while (getline(std::cin, line)) {
        if (hotfix != 0){
                
            int middle = line.size()/2;
            int counter = 0;

            for (int j = 0; j < middle; j++){
                int back = line.size() - 1 - j;
                if (line[j] != line[back]){
                       
                    if (line[j]<line[back]){                        
                        counter += (line[back] - line[j]);
                        line[back] = line[j];
                    }
                        
                    else{                            
                        counter += (line[j] - line[back]);
                        line[j] = line[back]; 
                    }
                }
            }
                        
            //std::cout << line << std::endl;
            std::cout << counter << std::endl;

        }
        
        else {
            hotfix = 1;
        }
        
        }
        
    }
    
    return 0;
}
