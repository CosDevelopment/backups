#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

template <class U>
class Umap
{
  private:
    int hash(string key)
    {
        int index;
        for (char x : key)
        {
            index += (int)(x);
        }
        index *= 23;
        index %= 100;
        return index;
    }

  public:
    U *dataArray[100];
    Umap()
    {
        for (int i = 0; i < 100; i++)
        {
            dataArray[i] = new U;
        }
    }
    bool insert(std::string key, U data)
    {
        int index = hash(key);
        while (dataArray[index] == NULL && index < 100)
        {
            index++;
        }
        if (index == 100)
        {
            return false;
        }
        else
        {
            dataArray[index] = &data;
            return true;
        }
    }
    bool remove(string key)
    {
        int index = hash(key);
        if (dataArray[index] != NULL)
        {
            dataArray[index] = NULL;
            return true;
        }
        else
            return false;
    }

    bool search(string key)
    {
        int index = hash(key);
        if (dataArray[index] != NULL)
        {
            return true;
        }
        else
        {
            cout << "value not found" << endl;
            return false;
        }
    }
};