#include<ctime>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

void shuffle(string data[],int num){
for(auto i = 0;i <num;i++){
    int n = rand()%num;
    string temp = data[i];
    data[i] = data[n];
    data[n] = temp;
}
};
void bubble(string arr[], int num )
{
        int n=num;
       for(auto i =0; i <n-1;i++){
        for(auto j=0; j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
              swap(arr[j],arr[j++])   ;
            }
        }
    }
};
void ssort(string arr[],int num){
for(auto i = 1;i<num;i++){
    for(auto j =i;j>0 && arr[j-1]>arr[j];j--)
    swap(arr[j],arr[j-1]);
}
}

void qsort(){
    
}
int main(){
    srand(time(NULL));
    ifstream file("names.txt");
    ofstream ofile("sort.txt");
    string arr[5494];
    for(auto i=0;i<5494;i++){
        file>>arr[i];
    }
    shuffle(arr,5494);
    ssort(arr,5494);

    for(auto i=0;i<5494;i++){
        ofile<<arr[i];
        ofile<<'\n';
    }
    file.close();
    ofile.close();
    return 0;



}