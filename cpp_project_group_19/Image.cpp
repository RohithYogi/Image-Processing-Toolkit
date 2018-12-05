#include "Image.h"
#include "Pixel.h"


#include <iostream>
#include <time.h>
#include<sstream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

Image::Image(unsigned int w,unsigned int h){
	width=w;
	height=h;
	pix = new Pixel*[height];
	for(unsigned int i=0;i<height;i++){
		pix[i] = new Pixel[width];
	}
}

Image::Image(){

}

Image::~Image(){

}

Image::Image(const Image& i){
	width=i.width;
	height=i.height;
	pix=i.pix;
}

void Image::set_width(unsigned int a){width=a;}

void Image::set_height(unsigned int a){height=a;}

ostream& operator<<(ostream &os,Image &m){

	os<<"P3"<<endl;
	os<<m.width<<" "<<m.height<<endl;
	os<<255<<endl;
	for (unsigned int i = 0; i < m.height; ++i)
	{
		/* code */
		for (unsigned int j = 0; j < m.width; ++j)
		{
			/* code */
			os<<(int)m.pix[i][j].get_c().get_red()<<" "<<(int)m.pix[i][j].get_c().get_green()<<" "<<(int)m.pix[i][j].get_c().get_blue()<<" ";

		}
		os<<endl;
	}

}

istream& operator>> (istream &is,Image &m){

	//is>>m.str;
	string s;
	is>>s;
	//cout<<m.str;
	is>>m.width>>m.height;
	m = Image(m.width,m.height);
	//m.str=s;
	int ver;
	is>>ver;

	//cout<<"Correct"<<endl;
	for (unsigned int i = 0; i < m.height; ++i)
	{
		/* code */
		for (unsigned int j = 0; j < m.width; ++j)
		{
			/* code */
			int r,g,b;
			is>>r>>g>>b;
			m.pix[i][j].set_x(i);
			m.pix[i][j].set_y(j);
			//cout<<"Correct"<<endl;
			Color c((float)r,(float)g,(float)b);
			m.pix[i][j].set_c(c);


		}
	}
}


Pixel **Image::get_pix(){
	return pix;
}

void Image::set_pix(Pixel **q){
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			pix[i][j].set_x(i);
			pix[i][j].set_y(j);
			pix[i][j].set_c(q[i][j].get_c());
		}
	}
}

unsigned int Image::get_width(){
	return width;
}

unsigned int Image::get_height(){
	return height;
}
