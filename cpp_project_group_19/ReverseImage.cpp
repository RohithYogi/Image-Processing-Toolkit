#include "ReverseImage.h"
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


ReverseImage::ReverseImage(Image i){
	ima=i;
}
	
ReverseImage::~ReverseImage(){

}

Image ReverseImage::get_ima(){
	return ima;
}

void ReverseImage::Upside_down(){
	Pixel **temp;
	temp = new Pixel*[ima.get_height()];
	for(unsigned int i=0;i<ima.get_height();i++){
		temp[i] = new Pixel[ima.get_width()];
	}
	for (unsigned int i = 0; i < ima.get_height(); ++i)
	{
		/* code */
		for (unsigned int j = 0; j < ima.get_width(); ++j)
		{

			/* code */
			float r = ima.get_pix()[ima.get_height()-i-1][j].get_c().get_red();
			float g = ima.get_pix()[ima.get_height()-i-1][j].get_c().get_green();
			float b = ima.get_pix()[ima.get_height()-i-1][j].get_c().get_blue();
			Color c(r,g,b);
			temp[i][j].set_c(c);
		}
	}

	for (unsigned int i = 0; i < ima.get_height(); ++i)
	{
		/* code */
		for (unsigned int j = 0; j < ima.get_width(); ++j)
		{

			/* code */
			float r = temp[i][j].get_c().get_red();
			float g = temp[i][j].get_c().get_green();
			float b = temp[i][j].get_c().get_blue();
			Color c(r,g,b);
			ima.get_pix()[i][j].set_c(c);
		}
	}
}



void ReverseImage::Side_ways(){
	Pixel **temp;
	temp = new Pixel*[ima.get_height()];
	for(unsigned int i=0;i<ima.get_height();i++){
		temp[i] = new Pixel[ima.get_width()];
	}
	for (unsigned int i = 0; i < ima.get_height(); ++i)
	{
		/* code */
		for (unsigned int j = 0; j < ima.get_width(); ++j)
		{

			/* code */
			float r = ima.get_pix()[i][ima.get_width()-j-1].get_c().get_red();
			float g = ima.get_pix()[i][ima.get_width()-j-1].get_c().get_green();
			float b = ima.get_pix()[i][ima.get_width()-j-1].get_c().get_blue();
			Color c(r,g,b);
			temp[i][j].set_c(c);
		}
	}

	for (unsigned int i = 0; i < ima.get_height(); ++i)
	{
		/* code */
		for (unsigned int j = 0; j < ima.get_width(); ++j)
		{

			/* code */
			float r = temp[i][j].get_c().get_red();
			float g = temp[i][j].get_c().get_green();
			float b = temp[i][j].get_c().get_blue();
			Color c(r,g,b);
			ima.get_pix()[i][j].set_c(c);
		}
	}
}