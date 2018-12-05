#ifndef Segmentation_h_
#define Segmentation_h_

#include<iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Image.h"
#include "Pixel.h"
#include "Color.h"
#include "ReverseImage.h"
#include "CompositeImage.h"
using namespace std;

class Segmentation:public Image
{
private:
	vector<int> ary;
	vector<int> loc_min;
	int *hist;
	int count;
  public:
	  Segmentation(int x, int y);

	  Segmentation(Segmentation &h);

	~Segmentation();

	void arithmetic(int r,int g,int b);


	void threshold();

   int size();

   	void color_select(Pixel** p,int x,int y,int i);

   void color();

	
	
	
};

#endif