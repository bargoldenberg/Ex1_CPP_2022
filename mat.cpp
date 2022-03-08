#include<string.h>
#include<iostream>
#include"mat.hpp"
/* AUTHOR: BAR GOLDENBERG 209894286 */
using namespace std;
/**
 * @brief This function loops a 2d array and fills it with a character.
 * 
 * @param arr 
 * @param l 
 * @param w 
 * @param minwidth 
 * @param minlength 
 * @param c 
 */
/*
Draws a rectangle in a matrix given a set of bounds and a character.
*/
void ariel::loop(char **arr,int originalwidth, int originallength,int minwidth,int minlength,char c){
    for(int i=minwidth;i<originallength;i++){
        arr[minlength][i]=c;
        arr[originalwidth-1][i]=c;
    }
    for(int i=minlength;i<originalwidth;i++){
        arr[i][minwidth]=c;
        arr[i][originallength-1]=c;
    }
  
}
/**
 * @brief this function uses the loop function to create a carpet type string.
 * question from: https://codegolf.stackexchange.com/questions/241219/mat-printing-matrix
 * 
 * @param w 
 * @param l 
 * @param c 
 * @param spacing 
 * @return string 
 */
string ariel::mat(int w,int l,char c,char spacing){
    string ans;
    /*
    Throw Exceptions if input is illegal.
    */
    if(l%2==0||w%2==0){
        throw invalid_argument("Mat size is always odd");
    }else if(l<0||w<0){
        throw invalid_argument("Mat size is always positive");
    }
    char** arr;
    arr = new char* [l];
    for(int i=0;i<l;i++){
        arr[i] = new char[w];
    }
    int newwidth=w;
    int newlength=l;
    int k=0;
    /*
    Create carpets by using loop to draw smaller and smaller rectangles, untill we receive the desiered carpet.
    */
    while(k<=w/2&&k<=l/2){
        if(k%2==0){
            ariel::loop(arr,newlength,newwidth,k,k,c);
        }else{
            ariel::loop(arr,newlength,newwidth,k,k,spacing);
        }
        newwidth--;
        newlength--;
        k++;
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<w;j++){
            ans.push_back(arr[i][j]);
        }
        ans+="\n";
    }
    /*
    Free alocated memory.
    */
    for(int i=0;i<l;i++){
        delete[] arr[i];
    }
    delete[] arr;
    /*
    return answer.
    */
    return ans;
    
}