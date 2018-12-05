#include "DFS.h"
#include "FinalColoredImg.h"
#include <iostream>
#include <time.h>
#include<sstream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

FinalColoredImg::FinalColoredImg(Image i){
	img = i;
}

FinalColoredImg::~FinalColoredImg(){

}

Image FinalColoredImg::ColoredImg(){
	DFS con_com(img);
	con_com.findConnectedComponents();
	return img;
}
