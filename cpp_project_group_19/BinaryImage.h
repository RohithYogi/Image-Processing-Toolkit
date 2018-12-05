#ifndef BinaryImage_h_
#define BinaryImage_h_

#include <iostream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Image.h"
#include "DFS.h"

class BinaryImage:public Image
{
private:
	Image ima;
public:
	BinaryImage(Image i);
	
	~BinaryImage();

	Image Binary_Image(int Th,Color c);

};


#endif
