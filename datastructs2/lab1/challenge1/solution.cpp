
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>


/*/////////////////////////////////////////////////////////
Preston Smith
Cosc 302/307
Teacher Dr.Emerich
std::rotate found in the algorithms library in the std library


////////////////////////////////////////////////////////////*/
using namespace std;
int main(){
    std::vector<int> intVec;
    char direction;
    int vecSize;
    int shiftAmount;

    //take in the size of the vector, the amount to shift, then the direction
    while(std::cin>>vecSize){
    std::cin>>shiftAmount>>direction;
    intVec.resize(vecSize);
  
  
    //add the integers from 1 to vecSize to the vector
    for(int i=0; i <vecSize;i++){
        std::cin>>intVec[i];
    }

    // rotates left using rotate, the second parameter is the middle value in the vector to be moved in the middle of the vector.
    if(direction=='L'){
    std::rotate(intVec.begin(),intVec.begin()+shiftAmount,intVec.end());
    for(int i =0; i< intVec.size()-1;i++){
        cout<<intVec[i]<<" ";
    }
    }

    // rotates right using rotate, the second parameter is the middle value in the vector to be moved in the middle of the vector.
    if(direction == 'R'){
        std::rotate(intVec.rbegin(),intVec.rbegin()+shiftAmount,intVec.rend());
    for(int i =0; i< intVec.size()-1;i++){
        cout<<intVec[i]<<" ";
    }
    }
    cout<<intVec[intVec.size()-1]<<endl;


}
return 0;
}