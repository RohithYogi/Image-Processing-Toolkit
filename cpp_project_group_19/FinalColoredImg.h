#ifndef FinalColoredImg_h_
#define FinalColoredImg_h_

#include <iostream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Image.h"
#include "Color.h"

class FinalColoredImg:public Image
{
private:
	Image img;
public:
	FinalColoredImg(Image i);

	~FinalColoredImg();

	Image ColoredImg();
};


#endif
