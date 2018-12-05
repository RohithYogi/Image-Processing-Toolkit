#include "BinaryImage.h"
#include "Image.h"
#include "DFS.h"

#include <iostream>
#include <time.h>
#include<sstream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

BinaryImage::BinaryImage(Image i){
	ima=i;
}
	
BinaryImage::~BinaryImage(){

}

Image BinaryImage::Binary_Image(int Th,Color c){

	Image bin(ima.get_width(),ima.get_height());

	for (unsigned int i = 0; i < ima.get_height(); ++i)
	{
		/* code */
		for (unsigned int j = 0; j < ima.get_width(); ++j)
		{
			/* code */
			float Bright = (ima.get_pix()[i][j].get_c().get_red()+ima.get_pix()[i][j].get_c().get_green()+ima.get_pix()[i][j].get_c().get_blue())/3;
			int brightness = (int)Bright;
			if(brightness < Th){
				bin.get_pix()[i][j].set_c(c);
			}
			else{
				Color dum(255,255,255);
				bin.get_pix()[i][j].set_c(dum);
			}
		}
	}
	return bin;


}
