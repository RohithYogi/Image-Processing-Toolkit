#include<iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Image.h"
#include "Pixel.h"
#include "Color.h"
#include "ReverseImage.h"
#include "CompositeImage.h"
#include "Segmentation.h"
using namespace std;


Segmentation::Segmentation(int x, int y): Image(x,y)
{
	count=0;
	hist=new int[255];

}
Segmentation::Segmentation(Segmentation &h)
{

}

Segmentation::~Segmentation()
{
}

void Segmentation::arithmetic(int r,int g,int b)
{
	int mean;
	mean=(int)(r+g+b)/3;
	ary.push_back(mean);
	hist[mean]+=1;
}


void Segmentation::threshold()
{
for(int i=1;i<255;i++)
{
	if(hist[i]<hist[i-1] && hist[i]<hist[i+1])
	{
		loc_min.push_back(i);
	}
}
}
int Segmentation::size()
{
return loc_min.size();
}

void Segmentation::color_select(Pixel** p,int x,int y,int i)
{
if (i == 0)
{
	p[x][y].set_c(Color(255, 0, 0));
}
if (i == 1)
{
	p[x][y].set_c( Color(0,255, 0));
}
if (i == 2)
{
	p[x][y].set_c(Color(0,0,255));
}
if (i == 3)
{
	p[x][y].set_c(Color( 255, 255, 0));
}
if (i == 4)
{
	p[x][y].set_c(Color( 255, 0, 255));
}
if (i == 5)
{
	p[x][y].set_c(Color( 0, 255, 255));
}
if(i==6){
	p[x][y].set_c(Color(0,0,0));

}

}

void Segmentation::color()
{
int flag=0,mean;
//cout<<loc_min.size()<<endl;
for(int i=0;i<get_height();i++){
	for(int j=0;j<get_width();j++){
		mean=(get_pix()[i][j].get_c().get_red()+get_pix()[i][j].get_c().get_blue()+get_pix()[i][j].get_c().get_green())/3;
	//	cout<<" mean: "<< mean<<endl;
		for(int k=0;k<loc_min.size();k++){
			if(mean<=loc_min[k]){flag=k;break; }
		}

		if(flag>5){color_select(get_pix(),i,j,6);}
		else{color_select(get_pix(),i,j,flag);}
		flag=0;
	}
}
}






