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

class Histogram:public Image
{
private:
	Image ima;
	vector<int> ary;
	vector<int> loc_min;
	int *hist;
	int count;
public:
	Histogram(Image i);
	
	~Histogram();

	Histogram(int x, int y);

	Histogram(Histogram &h);

	Image histo_Image();

	void arithmetic(int r,int g,int b);

	void threshold();

	int size();

	void color_select(Pixel** p,int x,int y,int i);

	void color();


};


#endif
