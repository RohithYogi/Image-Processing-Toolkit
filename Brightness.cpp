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

# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

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

int * Brightness::Threshold(){
	int *arr = new int[256];
	for (int i = 0; i < 256; ++i)
	{
		/* code */
		arr[i]=0;
	}
	smoothness(arr,Bright,5);
	// int prev=-1,current,next;
	// for (int i = 5; i < 255-5; ++i)
	// {
	// 	/* code */
	// 	int before[5],after[5];
	// 	before[0]=Bright[i-5];
	// 	before[1]=Bright[i-4];
	// 	before[2]=Bright[i-3];
	// 	before[3]=Bright[i-2];
	// 	before[4]=Bright[i-1];
	// 	//prev = minimum(Bright[i-3],Bright[i-2],Bright[i-1]);
	// 	prev = min(before);
	// 	current=Bright[i];

	// 	after[0]=Bright[i+1];
	// 	after[1]=Bright[i+2];
	// 	after[2]=Bright[i+3];
	// 	after[3]=Bright[i+4];
	// 	after[4]=Bright[i+5];
	// 	//next = minimum(Bright[i+1],Bright[i+2],Bright[i+3]);
	// 	next = min(after);
	// 	if(prev>current && current<next){
	// 		arr[i]=current;
	// 	}
	// 	prev=current;
	// 	current=next;
	// }
	return arr;
}


