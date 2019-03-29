// Challenge 03: Closest Numbers
// Name:  Preston Smith

// Brief description: finds the elements in a vector with the shortest distance between them

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(int argc, char *argv[])
{

    // input for vector size for resizing
    int vecSize;
    //vector to hold inserted numbers
    vector<int> insertionVec;
    //vector to hold pairs to put put
    vector<int> outputVec;

    while (cin >> vecSize)
    {
        // start with difference set to the max integer difference value for base case;
        int difference = numeric_limits<int>::max();

        //resize based on user input
        insertionVec.resize(vecSize);
        //populate insertVec
        for (int i = 0; i < insertionVec.size(); i++)
        {
            cin >> insertionVec[i];
        }
        //sort it for easier testing
        std::sort(insertionVec.begin(), insertionVec.end());
        //loop for testing. checks for absolute value differences
        //if difference is smaller than previous difference, clear the output vector and set difference to new value
        for (int elems = 0; elems < insertionVec.size()-1; elems++)
        {
            if (abs((insertionVec[elems] - insertionVec[elems + 1])) < difference)
            {
                outputVec.clear();
                difference = abs((insertionVec[elems] - insertionVec[elems + 1]));
                outputVec.push_back(insertionVec[elems]);
                outputVec.push_back(insertionVec[elems + 1]);
            }
            else if (abs((insertionVec[elems] - insertionVec[elems + 1])) == difference)
            {
                outputVec.push_back(insertionVec[elems]);
                outputVec.push_back(insertionVec[elems + 1]);
            }
        }

        //output
        for (int i = 0; i < outputVec.size(); i++)
        {
            cout << outputVec[i];
            if(i== outputVec.size()){
                break;
            }else{
                cout<<" ";
            }

          
        }
        //clear buffer
        cout << endl;
        //reset vectors;
        insertionVec.clear();
        outputVec.clear();
    }
}
