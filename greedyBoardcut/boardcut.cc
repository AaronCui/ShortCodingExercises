//Aaron Cui
// HackerRank Practice Question Solution
// Question included as PDF in same folder 
// Simple Greedy Algorithm 


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int cases;
    std::cin >> cases;
    for (int i = 0; i < cases; i++){
        long long int xcuts = 0;
        long long int ycuts = 0;
        std::cin >> xcuts >> ycuts;
        xcuts--;
        ycuts--;
        //std::vector<int> xvals;
        //std::vector<int> yvals;
        std::vector<long long int> errthing;
        //xvals.clear();
        //yvals.clear();
        errthing.clear();
        long long int temp;
        for (int j = 0; j < xcuts; j++){
            std::cin >> temp;
            errthing.push_back(temp);
        } 
        for (int j = 0; j < ycuts; j++){
            std::cin >> temp;
            errthing.push_back(temp);
        }
        
        // in errthing -> from begin to begin + xcuts = portion of xvals
        // from being + xcuts + 1 to end = portion of yvals
        
        std::sort(errthing.begin(), errthing.begin() + xcuts, std::greater<int>());        
        std::sort(errthing.begin() + xcuts, errthing.end(), std::greater<int>());
        
        long long int indexx = 0;
        long long int indexy = xcuts; //start of ycut values 
        long long int max = 0;
        long long int xcutted = 1;
        long long int ycutted = 1;
        long long int total = 0;
        while ((indexx < xcuts) && (indexy < (xcuts + ycuts))){
            if (errthing[indexx] > errthing[indexy]){
                total += ycutted * errthing[indexx];         
                indexx++;
                xcutted++;                
            }
            //remember there's an equal case, for now assuming doesnt matter
            else{
                total += xcutted * errthing[indexy];
                indexy++;
                ycutted++;
            } 
        } //end of while loop only x or y has run out, the other one has ones left
        
        //if x ran out, all y left have to go thru current xcutted
        if (indexx == xcuts){
            while (indexy < (xcuts + ycuts)){
                total += xcutted * errthing[indexy];
                indexy++;
            }
        }
        
        else{
            while (indexx < xcuts){
                total += ycutted * errthing[indexx];
                indexx++;
            }
        }
        
        long long int longlongint = 1000000007; 
        total = total % longlongint;
        std::cout << total << std::endl;
        
    }
    
    
    return 0;
}
