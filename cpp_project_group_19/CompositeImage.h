#ifndef CompositeImage_h_
#define CompositeImage_h_

#include <iostream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Image.h"

class CompositeImage:public Image
{
private:
	Image A;
	Image B;
public:
	CompositeImage(Image I1,Image I2);
	
	~CompositeImage();

	Image Composition(float alpha);

	
};


#endif
