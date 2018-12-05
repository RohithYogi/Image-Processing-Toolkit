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

// void Image::print(){
// 	for(unsigned int i=0;i<height;i++){
// 		for(unsigned int j=0;j<width;j++){
// 			pix[i][j].set_x(i);
// 			pix[i][j].set_y(j);
			
// 			pix[i][j].set();
			
// 			if(pix[i][j].get_c().get_status()){
// 				cout<<"+ ";
// 			}
// 			else{
// 				cout<<"o ";
// 			}
			
// 		}
// 		cout<<endl;
// 	}
// }

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


// Image Image::filter(int r,int g,int b,float alpha){

// 	Image final(width,height);
// 	//final.ver=ver;
// 	//final.str=str;

// 	for (unsigned int i = 0; i < final.height; ++i)
// 	{
// 		/* code */
// 		for (unsigned int j = 0; j < final.width; ++j)
// 		{
// 			/* code */
// 			float red = ((1 - alpha)*(pix[i][j].get_c().get_red()) + (alpha)*r);
// 			float green = ((1 - alpha)*(pix[i][j].get_c().get_green()) + (alpha)*g);
// 			float blue = ((1 - alpha)*(pix[i][j].get_c().get_blue()) + (alpha)*b);
// 			final.pix[i][j].set_x(i);
// 			final.pix[i][j].set_y(j);
// 			Color dum(red,green,blue);
// 			final.pix[i][j].set_c(dum);
// 		}
// 	}
// 	return final;

// }

// Image Image::Noise_Image(){
	
// 	Image final(width,height);
// 	srand(time(NULL));
// 	//final.ver=ver;
// 	//final.str=str;

// 	for (unsigned int i = 0; i < final.height; ++i)
// 	{
// 		/* code */
// 		for (unsigned int j = 0; j < final.width; ++j)
// 		{
// 			/* code */
// 			float red = abs(rand()%256);
// 			float green = red;
// 			float blue = red;
// 			final.pix[i][j].set_x(i);
// 			final.pix[i][j].set_y(j);
// 			Color dum(red,green,blue);
// 			final.pix[i][j].set_c(dum);
// 		}
// 	}
// 	return final;

// }

Pixel **Image::get_pix(){
	return pix;
}

// float Image::noise(unsigned int x,unsigned int y){
	
// 	return pix[x][y].get_c().get_red();

// }


unsigned int Image::get_width(){
	return width;
}

unsigned int Image::get_height(){
	return height;
}

// void Image::find(int a,int b,int d){

// 	for (unsigned int i = 0; i < height; ++i)
// 	{
// 		/* code */
// 		for (unsigned int j = 0; j < width; ++j)
// 		{
// 			/* code */
// 			int c=0;
// 			int red =(pix[i][j].get_c().get_red());
// 			int green =(pix[i][j].get_c().get_green());
// 			int blue = (pix[i][j].get_c().get_blue());
// 			if(red==a){
// 				c+=1;
// 			}
// 			if(green==b){
// 				c+=1;
// 			}
// 			if(blue==d){
// 				c+=1;
// 			}
// 			if(c==3){
// 				cout<<"("<<i<<","<<j<<")"<<endl;
// 				return;
// 			}
// 		}
// 	}
// 	return;

// }
