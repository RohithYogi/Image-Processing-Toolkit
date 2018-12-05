#ifndef ReverseImage_h_
#define ReverseImage_h_

#include <iostream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Image.h"

class ReverseImage:public Image
{
private:
	Image ima;
public:
	ReverseImage(Image i);
	
	~ReverseImage();

	void Upside_down();

	void Side_ways();

	Image get_ima();

};


#endif
