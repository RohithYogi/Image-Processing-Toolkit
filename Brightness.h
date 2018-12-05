#ifndef Brightness_h_
#define Brightness_h_

#include <iostream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Image.h"

class Brightness:public Image
{
private:
	Image ima;
	int *Bright;
public:
	Brightness(Image i);

	//Brightness(int * arr)
	
	~Brightness();

	void Analysis();

	int * get_brightness();

	int *Threshold();

	
};


#endif
