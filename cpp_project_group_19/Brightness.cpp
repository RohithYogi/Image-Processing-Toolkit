#include "Brightness.h"
#include "Image.h"

#include <iostream>
#include <time.h>
#include<sstream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>


Brightness::Brightness(Image i){
	ima=i;
	Analysis();
}

//Brightness(int * arr)

Brightness::~Brightness(){

}

void Brightness::Analysis(){
	Bright = new int[256];
	for (int i = 0; i < 256; ++i)
	{
		/* code */
		Bright[i]=0;
	}
	for (unsigned int i = 0; i < ima.get_height(); ++i)
	{
		/* code */
		for (unsigned int j = 0; j < ima.get_width(); ++j)
		{
			/* code */
			float Bri = (ima.get_pix()[i][j].get_c().get_red()+ima.get_pix()[i][j].get_c().get_green()+ima.get_pix()[i][j].get_c().get_blue())/3;
			Bright[(int)Bri]+=1;
		}
	}
}

int * Brightness::get_brightness(){
	return Bright;
}

int minimum(int a,int b,int c){
	if(a>b){
		if(b>c){
			return c;
		}
		else{
			return b;
		}
	}
	else{
		if(a>c){
			return c;
		}
		else{
			return a;
		}
	}
}

int min(vector<int> arr){
	int small = 1000000;
	//int size = my_sizeof(arr)/my_sizeof(arr[0]);
	//cout<<"size: "<<size;
	//cout<<"size "<<arr.size()<<endl;
	for (int i = 0; i < arr.size(); ++i)
	{
		/* code */
		if(arr[i]<small){
			small=arr[i];
		}
	}
	//cout<<"min "<<small<<endl;
	return small;
}

void smoothness(int *thre,int * Bright,int factor){

	int prev,current,next;
	for (int i = factor; i < 255-factor; ++i)
	{
		/* code */
		vector<int> before;
		vector<int> after;
		for(int j = 0;j<factor;j++){
			before.push_back(Bright[i-(j+1)]);
			after.push_back(Bright[i+j+1]);
		}
		prev=min(before);
		current=Bright[i];
		next = min(after);

		if(prev>current && current<next){
			thre[i]=current;
		}
		before.clear();
		after.clear();

	}

}

void smoothness(vector<int> &arr,int * Bright){
	for (int i = 1; i < 255; ++i){
        if(Bright[i-1] > Bright[i] && Bright[i+1] >= Bright[i]){
            arr.push_back(i);
        }
    }
}

int * Brightness::Threshold(){
	int *arr = new int[256];
	for (int i = 0; i < 256; ++i)
	{
		/* code */
		arr[i]=0;
	}
	smoothness(arr,Bright,5);
	return arr;
}

vector<int> Brightness::threshold(){
	vector<int> arr;
	smoothness(arr,Bright);
	return arr;
}

int Brightness::median(vector<int> arr){
	int length = arr.size();
	return arr[length/2];
}


