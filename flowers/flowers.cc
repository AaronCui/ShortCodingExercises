// Solution to Flowers Question from HackerRank (question is in PDF file in same folder
//	By Aaron
//	Feb 15 2015

#include<iostream>
#include<algorithm>
#include<vector>


int main(void){

 

//Helpers for input and output

    int numFlowers, numPeople;
    int maxPurchase;
    int total = 0; 
    
    std::cin >> numFlowers >> numPeople;
    int C[numFlowers];
    for(int i = 0; i < numFlowers; i++){
       std::cin >> C[i];
    }
    //maxPurchase = N/K;
    //bool extraFlag = 0; 
    std::vector<int> prices (C, C+numFlowers);
    std::sort(prices.begin(), prices.end(), std::greater<int>());
    if (numFlowers % numPeople == 0)
        maxPurchase = numFlowers/numPeople;
    else 
        maxPurchase = numFlowers/numPeople + 1;
    
    int iterator = 0;
    for (int j = 1; j < maxPurchase + 1; j++){
        //std::cout << "SIZE" << prices.size() << std::endl;
        for (int k = 0; k < numPeople; k++){
            //std::cout << "ITERATOR IS　" << iterator << std::endl;
            if (iterator < prices.size()){
                total += j * prices[iterator];
                iterator++;
            }
            //std::cout << "Current Total " << total << std::endl;
        }
        
    }
    
    std::cout << total << std::endl;
   //int result = 100/51;
 //  cout << result << "\n";
   
   return 0;
}
