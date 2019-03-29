#include<iostream>
#include<cstdlib>
template <class type, int length>
class Disarray{
    int size;
    type *darr= new type[length];
public:
    void output();
    type at(int index);
    type front();
    type back();
    type* data();
    type* begin();
    type* end();

    type& operator[](int location){return darr[location];};
};

template <class type, int length>
void Disarray<type,length>::output(){


    for(int i = 0; i<length;i++){
        std::cout<<darr[i]<<std::endl;
    }

}

template <class type, int length>
type Disarray<type,length>::at(int index){
    if(index > length)
    return -99999;

    else
    return darr[index];
}

template <class type, int length>
type Disarray<type,length>::front(){
    return darr[0];
}

template <class type, int length>
type Disarray<type,length>::back(){
    return darr[length-1];
}

template <class type, int length>
type* Disarray<type,length>::data(){
    return &darr[0];
}

template <class type, int length>
type* Disarray<type,length>::begin(){
    return darr;
}

template <class type, int length>
type* Disarray<type,length>::end(){
    return &darr[length];
}
