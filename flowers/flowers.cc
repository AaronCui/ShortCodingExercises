// Solution to Flowers Question from HackerRank (question is in PDF file in same folder
//	By Aaron
//	Feb 15 2015

#include<iostream>
#include<algorithm>
#include<vector>


int main(void){

    int numFlowers, numPeople;
    int total = 0; 
    std::vector<int> prices;
	
    std::cin >> numFlowers >> numPeople;
	int temp;
    for(int i = 0; i < numFlowers; i++){
       std::cin >> temp;
	   prices.push_back(temp);
    }
	
	std::sort(prices.begin(), prices.end(), std::greater<int>());
	
	for (int j = 0, multiplyer = 1; j < prices.size(); j++){
		total += multiplyer * prices[j];
		if ((j+1) % numPeople == 0)
			multiplyer ++;   
    }
    
    std::cout << total << std::endl;
   
   return 0;
}
