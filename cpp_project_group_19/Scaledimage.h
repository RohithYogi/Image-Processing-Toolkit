#ifndef Scaledimage_h_
#define Scaledimage_h_

#include <iostream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Image.h"
class Scaledimage:public Image{
public:
	Scaledimage();

  ~Scaledimage();

  Scaledimage(unsigned int a,unsigned int b);

  Image scaled_first();

  Image scaled_second();

  Image scaled_third();

  Image scaled_fourth();

  Image joining();

  Image get_Image();

  Image scaleit(Image k);

  Image half();

	friend istream& operator>> (istream &is,Scaledimage &m);

};
#endif
