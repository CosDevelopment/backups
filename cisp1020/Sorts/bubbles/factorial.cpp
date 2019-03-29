 #include<iostream>

int calcFactorials(int array[],int size);

 int main(){


    int factorials[21];
    int size =21;
    factorials[0]=1;
    calcFactorials(factorials,size);
    for(int i=0;i<size;i++){
        std::cout<<factorials[i]<<std::endl;
    }

    return 0;
}
int calcFactorials(int array[],int size){
    int factorial = 1;
    if(size ==0)
        return 0;
    for(int i=size;i>=1;i--){
        factorial *= i;
    }
    array[size]=factorial;
    size --;
    calcFactorials(array,size);
    return 0;


}