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


		friend ostream& operator<<(ostream &os,Image &m);

	    friend istream& operator>> (istream &is,Image &m);


		Pixel **get_pix();

	    void set_pix(Pixel **q);

		unsigned int get_width();

		unsigned int get_height();

    void set_width(unsigned int a);

    void set_height(unsigned int a);
};

#endif
