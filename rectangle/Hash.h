//
// Created by User on 2020-04-04.
//
#include "Rectangle.h"
#include <iostream>
#include <vector>
using namespace std;

//all of the rectangle classes are stores in this hash table
//they are stored in a hash table to make the search time constant

class Hash {
private:
    int size;
    vector<Rectangle*>* hash;
public:
    Hash();
    ~Hash();
    void insert(Rectangle* r); //inserts a new rectangle into the hash
    bool exists(int n); //gets the rectangle object from it's id
    Rectangle* find(int n);
};

Hash::Hash(){
    size = 13;
    hash = new vector<Rectangle*>[size];
}

Hash::~Hash(){
    for(int i= 0; i<size; i++){
        vector<Rectangle*> r = hash[i];
        for(int q=0; q < r.size(); q++){
            delete r[q];
        }
        r.clear();
    }
    delete[] hash;
}

void Hash::insert(Rectangle* r){
    int id = r->id_val();
    int mod = id % 13;
    hash[mod].push_back(r);
}

bool Hash::exists(int n){
    int mod = n % 13;
    vector<Rectangle*> r = hash[mod];
    for (int q =0; q < r.size(); q++){
        if(r[q]->id_val() == n){
            return true;
        }
    }
    return false;
}

Rectangle* Hash::find(int n){
    int mod = n % 13;
    vector<Rectangle*> r = hash[mod];
    for (int q =0; q < r.size(); q++){
        if(r[q]->id_val() == n){
            return r[q];
        }
    }
    throw illegal_command();
}