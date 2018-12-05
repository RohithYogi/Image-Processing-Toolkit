#ifndef Image_h_
#define Image_h_

#include <iostream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Pixel.h"

class Image{
	private:
		unsigned int width;
		unsigned int height;
		Pixel **pix;
	public:

		

		Image(unsigned int w,unsigned int h);

		Image();

		~Image();

		Image(const Image& i);

		//void print();

		friend ostream& operator<<(ostream &os,Image &m);

	    friend istream& operator>> (istream &is,Image &m);

		//Image filter(int r,int g,int b,float alpha);

		//void find(int a,int b,int c);

		//Image Noise_Image();

		//virtual Image generating_color(float a,float b){}

		Pixel **get_pix();

	    //float noise(unsigned int x,unsigned int y);

		unsigned int get_width();

		unsigned int get_height();
	
};

#endif