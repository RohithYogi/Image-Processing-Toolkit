#include "Histogram.h"
#include "Brightness.h"

#include <iostream>
#include <time.h>
#include<sstream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

Histogram::Histogram(Image I){
	ima = I;
}
	
Histogram::~Histogram(){

}

Histogram::Histogram(int x, int y): Image(x,y){
	count=0;
	hist=new int[255];

}

Histogram::Histogram(Histogram &h){

}

void Histogram::arithmetic(int r,int g,int b)
{
	int mean;
	mean=(int)(r+g+b)/3;
	ary.push_back(mean);
	hist[mean]+=1;
}


void Histogram::threshold()
{
	for(int i=1;i<255;i++)
	{
		if(hist[i]<hist[i-1] && hist[i]<hist[i+1])
		{
			loc_min.push_back(i);
		}
   }
}

int Histogram::size()
{
	return loc_min.size();
}

void Histogram::color_select(Pixel** p,int x,int y,int i)
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

void Histogram::color()
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

Image Histogram::histo_Image(){
	int max=-1;
	Brightness B(ima);
	//B.Analysis();
	for (int i = 0; i < 256; ++i)
	{
		/* code */
		if(max<B.get_brightness()[i]){
			max=B.get_brightness()[i];
		}
	}
	//cout<<max<<endl;
	Image histo(256,max+1);
	//cout<<"corr\n";
	for (unsigned int i = 0; i < max+1; ++i)
	{
		/* code */
		for (unsigned int j = 0; j < 256; ++j)
		{
			/* code */
			Color c(255,255,255);
			histo.get_pix()[i][j].set_c(c);
		}
	}
	//cout<<"corr\n";
	for (unsigned int j = 0; j < 256; ++j)
	{
		/* code */
		int in = max-B.get_brightness()[j];
		//cout<<in<<endl;
		Color c(0,0,0);
		histo.get_pix()[in][j].set_c(c);
		
	}

	for (unsigned int i = 0; i < max+1; ++i)
	{
		/* code */
		for (unsigned int j = 0; j < 256; ++j)
		{
			/* code */
			if(histo.get_pix()[i][j].get_c().get_red()==0){
				int a =i;
				//int b =j;
				while(a!=max+1)
				{
					Color c(0,0,0);
					histo.get_pix()[a][j].set_c(c);
					a++;
				}

			}
		}
	}

	//cout<<"corr\n";

	return histo;
}