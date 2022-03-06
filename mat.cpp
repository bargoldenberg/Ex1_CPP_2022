#include<string.h>
#include<iostream>
#include"mat.hpp"
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

void ariel::loop(char **arr,int l, int w,int minwidth,int minlength,char c){
    for(int i=minwidth;i<w;i++){
        arr[minlength][i]=c;
        arr[l-1][i]=c;
    }
    for(int i=minlength;i<l;i++){
        arr[i][minwidth]=c;
        arr[i][w-1]=c;
    }
  
}
string ariel::mat(int w,int l,char c,char spacing){
    string ans = "";
    if(l<=0||w<=0||l%2==0 ||w%2==0){
        throw invalid_argument("length or width arguments are invalid");
    }
    char** arr;
    arr = new char* [l];
    for(int i=0;i<l;i++){
        arr[i] = new char[w];
    }
    int newwidth=w;
    int newlength=l;
    int k=0;
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
    return ans;
    
}