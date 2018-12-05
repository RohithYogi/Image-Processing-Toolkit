#include "Pixel.h"
#include "Color.h"


#include <iostream>
#include <time.h>
#include<sstream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

Pixel::Pixel(){

}

Pixel::Pixel(unsigned int x,unsigned int y){
	xlocation=x;
	ylocation=y;
}
Pixel::~Pixel(){

}
Pixel::Pixel(const Pixel& p){
	xlocation=p.xlocation;
	ylocation=p.ylocation;
}

void Pixel::set_x(unsigned int x){
	xlocation=x;
}

void Pixel::set_y(unsigned int x){
	ylocation=x;
}

void Pixel::set_c(Color c){
	colour=c;
}

vector<unsigned int> Pixel::fib(unsigned int n){
	vector<unsigned int> l;
	l.push_back(1);
	l.push_back(2);
	for(unsigned int i=2;i<n;i++)
	{
		l.push_back(l[i-1]+l[i-2]);
		if(l[i]>n)
		{
          l.pop_back();
          break;
		}
		else if(l[i]==n)
		{
            break;
		}
	}
	return l;
}

void Pixel::set(){
	unsigned int v[21];
	unsigned int k=0;
	
	for(unsigned int i=0;i<fib(20).size();i++){
		
		if(fib(20)[i]==xlocation)
		{
			k=1;
		}
	}

	for(unsigned int i=0;i<fib(20).size();i++){
		
			if(fib(20)[i]==ylocation && k==1)
			{
			k=2;
		}
	}
	if(k==2)
	{
			colour.set_red(0);
			colour.set_blue(0);
			colour.set_green(0);

		}
		else{
			colour.set_red(1);
			colour.set_blue(1);
			colour.set_green(1);

		}
}

Color Pixel::get_c(){
	return colour;
}
