// https://codility.com/demo/results/demo4EP3DN-RYC/
// Above link shows the question for this solution is for
// As well as a recording of my entire time line of completing the code and failing / passing the tests

//DoubleAce
//Feb2

#include<cstdlib>
#include<iostream>
#include<vector>
#include<stack>


int solution(std::vector<int> &A, std::vector<int> &B) {
    std::stack<int> stacky;
    int survive = 0;
    for (int i = 0; i < B.size(); i++){
        if (stacky.empty() && B[i] == 0){
        //when top fishes are going up, they live to see another day
            survive++;
        }
        if (B[i] == 1){
        //all fishes going down will be considered for fight, until left alone in stacky
            stacky.push(A[i]);
        }
        
        if (!stacky.empty() && B[i] == 0){
        //if fishes looking for fight and one rises up to the wrong neighborhood
            while (!stacky.empty() && stacky.top() < A[i]){
                //while down fish is losing to up fish
                stacky.pop();
                //for bottom fish rising to le top
                if (stacky.empty()){
                    survive++;
                }
            //loop for bottom fish eating up until eaten or finish eatting and survive
            }

        }
    }    
    // after all the started bottom now we heres are done, check how many happily sinks down forever
    survive += stacky.size();

    return survive;    
                
}

int main(){
	std::cout<< "Testing with [6,5,4,3,2,1],[1,0,0,0,0,0] and [1,2,3,4,5,6],[0,0,0,1,1,1]" <<std::endl;
	//hard coded, original code has passed much more extensive testing
	int a1t[6] = {6,5,4,3,2,1};
	int a2t[6] = {1,0,0,0,0,0};
	int b1t[6] = {1,2,3,4,5,6};
	int b2t[6] = {0,0,0,1,1,1};
	std::vector<int> a1, b1, a2, b2;
	for (int i = 0; i <6 ; i++){ 
		a1.push_back(a1t[i]);
		b1.push_back(b1t[i]);
		a2.push_back(a2t[i]);
		b2.push_back(b2t[i]);
	}
	std::cout<< "result 1 is: " << solution (a1,b1) << std::endl;
	std::cout<< "result 2 is: " << solution (a2,b2) << std::endl;
	return 0;
}