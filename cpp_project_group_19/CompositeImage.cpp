#include "CompositeImage.h"
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

CompositeImage::CompositeImage(Image I1,Image I2){
	A=I1;
	B=I2;
}

CompositeImage::~CompositeImage(){

}


Image CompositeImage::Composition(float alpha){

	Image C(A.get_width(),A.get_height());
	//final.ver=ver;
	//final.str=str;

	for (unsigned int i = 0; i < C.get_height(); ++i)
	{
		/* code */
		for (unsigned int j = 0; j < C.get_width(); ++j)
		{
			/* code */
			float red = ((1 - alpha)*(A.get_pix()[i][j].get_c().get_red()) + (alpha)*(B.get_pix()[i][j].get_c().get_red()));
			float green = ((1 - alpha)*(A.get_pix()[i][j].get_c().get_green()) + (alpha)*(B.get_pix()[i][j].get_c().get_green()));
			float blue = ((1 - alpha)*(A.get_pix()[i][j].get_c().get_blue()) + (alpha)*(B.get_pix()[i][j].get_c().get_blue()));
			C.get_pix()[i][j].set_x(i);
			C.get_pix()[i][j].set_y(j);
			Color dum(red,green,blue);
			C.get_pix()[i][j].set_c(dum);
		}
	}
	return C;

}