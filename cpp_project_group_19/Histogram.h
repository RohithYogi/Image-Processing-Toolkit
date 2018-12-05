#ifndef Histogram_h_
#define Histogram_h_

#include <iostream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Image.h"

class Histogram
{
private:
	Image ima;
public:
	Histogram(Image i);
	
	~Histogram();

	Image histo_Image();
	
};


#endif
