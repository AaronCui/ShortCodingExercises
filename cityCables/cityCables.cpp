#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; 


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int blocks;
    int cities;
    cin >> blocks;
   // cout << blocks;
    
    for (int i = 0; i < blocks; i++){
        cin>> cities;
        long int position[cities];
        long int population[cities];
        
        long int distance = 0;
        long int max = 0;
        long long int total = 0;
        //unsigned long int j, k, l = 0;
        
        for (unsigned long long int j = 0; j < cities; j++){
            cin >> position[j];
            //cout << position[j] <<endl;
        }
        for (unsigned long long int k = 0; k < cities; k++){
            cin >> population[k];
            //cout << population[k] <<endl;
        }
        for (unsigned long long int l = 0; l < cities-1; l++){
            for (unsigned long long int m = l+1; m < cities; m++){
                if (population[l]>population[m])
                    max = population[l];
                else
                    max = population[m];
                
                distance = abs(position[m]-position[l]);
                
                
                //cout<< "max is " <<max << endl;
                //cout<< "distance is " <<distance << endl;
                
                total += max * distance; 
                if (total > 1000000007)
                    total = total % 1000000007;
            }
        }
        cout << total % 1000000007 << endl;
     //cout << "one block end" <<endl;
    }
    return 0;
    //int locations[];
    //int populations[];
}