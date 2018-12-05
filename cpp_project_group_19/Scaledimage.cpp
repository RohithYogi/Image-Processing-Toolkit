#include "Scaledimage.h"
#include "ReverseImage.h"
#include "CompositeImage.h"
#include<fstream>
#include <iostream>
#include <time.h>
#include<sstream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

Scaledimage::Scaledimage(){Image();}
Scaledimage::~Scaledimage(){}
Scaledimage::Scaledimage(unsigned int a,unsigned int b):Image(a,b){}

Image Scaledimage::get_Image(){
	Image i=Image(get_width(),get_height());
	i.set_pix(get_pix());
	return i;
}

Image Scaledimage::scaleit(Image k){
  unsigned int width=get_width();
  unsigned int height=get_height();
  Pixel **q2;
  q2 = new Pixel*[height];
  for(unsigned int i=0;i<height;i++){
    q2[i] = new Pixel[width];
  }
  Image k1=Image(width/2,height/2);int q=0;
  for(int i=0;i<height;i=i+2){
    int l=0;
    for(int j=0;j<width;j=j+2){
      if((q<height/2)&&(l<width/2)){
        float r,g,b;
        r=(k.get_pix()[i][j].get_c().get_red()+k.get_pix()[i+1][j].get_c().get_red()+k.get_pix()[i][j+1].get_c().get_red()+k.get_pix()[i+1][j+1].get_c().get_red())/4;
        g=(k.get_pix()[i][j].get_c().get_green()+k.get_pix()[i+1][j].get_c().get_green()+k.get_pix()[i][j+1].get_c().get_green()+k.get_pix()[i+1][j+1].get_c().get_green())/4;
        b=(k.get_pix()[i][j].get_c().get_blue()+k.get_pix()[i+1][j].get_c().get_blue()+k.get_pix()[i][j+1].get_c().get_blue()+k.get_pix()[i+1][j+1].get_c().get_blue())/4;
        Color c=Color(r,g,b);
        q2[q][l].set_c(c);q2[q][l].set_x(q);q2[q][l].set_y(l);
        l++;
      }
    }
    q++;
  }
  k1.set_pix(q2);
  return k1;
}

Image Scaledimage::scaled_first(){
	unsigned int width=get_width();
	unsigned int height=get_height();
	Image i4=Image(width,height);
  i4.set_pix(get_pix());
  ReverseImage r1=ReverseImage(i4);
  r1.Side_ways();
  Image k=r1.get_ima();
  Image k1=scaleit(k);
	Image k2=Image(width,height);
	Pixel **q3;
	q3 = new Pixel*[height];
	for(unsigned int i=0;i<height;i++){
		q3[i] = new Pixel[width];
	}
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			if((i<height/2)&&(j>width/2)){
				Color c = k1.get_pix()[i][j-(width/2)].get_c();
				q3[i][j].set_c(c);
				q3[i][j].set_x(i);q3[i][j].set_y(j);
			}
			else{
				Color c=Color(255,255,255);
				q3[i][j].set_c(c);
				q3[i][j].set_x(i);q3[i][j].set_y(j);
			}
		}
	}
	k2.set_pix(q3);
	return k2;
}

Image Scaledimage::scaled_second(){
	unsigned int width=get_width();
	unsigned int height=get_height();
	Image k=Image(width,height);
	k.set_pix(get_pix());
	Image k1=scaleit(k);
	Image k2=Image(width,height);
	Pixel **q3;
	q3 = new Pixel*[height];
	for(unsigned int i=0;i<height;i++){
		q3[i] = new Pixel[width];
	}
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			if((i<height/2)&&(j<width/2)){
				q3[i][j]=k1.get_pix()[i][j];
				q3[i][j].set_x(i);q3[i][j].set_y(j);
			}
			else{
				Color c=Color(255,255,255);
				q3[i][j].set_c(c);
				q3[i][j].set_x(i);q3[i][j].set_y(j);
			}
		}
	}
	k2.set_pix(q3);
	return k2;
}

Image Scaledimage::scaled_third(){
	unsigned int width=get_width();
	unsigned int height=get_height();
  Image i4=Image(width,height);
  i4.set_pix(get_pix());
  ReverseImage r1=ReverseImage(i4);
  r1.Upside_down();
  Image k=r1.get_ima();
  Image k1=scaleit(k);
	Image k2=Image(width,height);
	Pixel **q3;
	q3 = new Pixel*[height];
	for(unsigned int i=0;i<height;i++){
		q3[i] = new Pixel[width];
	}
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			 if((i>height/2)&&(j<width/2)){
			 	Color c = k1.get_pix()[i-(height/2)][j].get_c();
				q3[i][j].set_c(c);
			 	q3[i][j].set_x(i);q3[i][j].set_y(j);
			 }
			else{
				Color c=Color(255,255,255);
				q3[i][j].set_c(c);
				q3[i][j].set_x(i);q3[i][j].set_y(j);
			}
		}
	}
	k2.set_pix(q3);
	return k2;
}

Image Scaledimage::scaled_fourth(){
	unsigned int width=get_width();
	unsigned int height=get_height();
  Image i4=Image(width,height);
  i4.set_pix(get_pix());
  ReverseImage r1=ReverseImage(i4);
  r1.Upside_down();
  r1.Side_ways();
  Image k=r1.get_ima();
  Image k1=scaleit(k);
	Image k2=Image(width,height);
	Pixel **q3;
	q3 = new Pixel*[height];
	for(unsigned int i=0;i<height;i++){
		q3[i] = new Pixel[width];
	}
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			if((i>height/2)&&(j>width/2)){
				Color c=k1.get_pix()[i-(height/2)][j-(width/2)].get_c();
				q3[i][j].set_c(c);
				q3[i][j].set_x(i);q3[i][j].set_y(j);
			}
			else{
				Color c=Color(255,255,255);
				q3[i][j].set_c(c);
				q3[i][j].set_x(i);q3[i][j].set_y(j);
			}
		}
	}
	k2.set_pix(q3);
	return k2;
}

Image Scaledimage::joining(){
	unsigned int width=get_width();
	unsigned int height=get_height();
	Image k1=scaled_first();
	Image k2=scaled_second();
	Image k3=scaled_third();
	Image k4=scaled_fourth();
	CompositeImage I1=CompositeImage(k1,k2);
  Image sam1=I1.Composition(0.5);
  CompositeImage I2=CompositeImage(k3,k4);
  Image sam2=I2.Composition(0.5);
  CompositeImage I3=CompositeImage(sam1,sam2);
  Image k=I3.Composition(0.5);
  ofstream file("kk.ppm");
  file<<k;
	return k;
}

Image Scaledimage::half(){
  unsigned int width=get_width();
  unsigned int height=get_height();
  Image i1=joining();
  //cout<<"half"<<endl;
  Pixel **q;
  q = new Pixel*[height];
	for(unsigned int i=0;i<height;i++){
		q[i] = new Pixel[width];
	}
  //cout<<width<<height<<endl;
  unsigned int k1,q1,k2,q2;
  k1=((height/2)-(height/4));
  q1=((width/2)-(width/4));
  k2=((height/2)+(height/4));
  q2=((width/2)+(width/4));
  //cout<<k1<<" "<<q1<<" "<<k2<<" "<<q2<<endl;
  for(unsigned int i=0;i<height;i++){
    for(unsigned int j=0;j<width;j++){
      //cout<<"yupee"<<endl;
      //cout<<"yupee"<<endl;
      if(((i>=k1)&&(j>=q1))&&((i<=k2)&&(j<=q2))){
        float r=i1.get_pix()[i][j].get_c().get_red();
        float g=i1.get_pix()[i][j].get_c().get_green();
        float b=i1.get_pix()[i][j].get_c().get_blue();
        Color c(r,g,b);
        //cout<<"so now"<<i<<" "<<j<<endl;
        q[i][j].set_c(c);q[i][j].set_x(i);q[i][j].set_y(j);
      }
      else{
        Color c(255,255,255);
        q[i][j].set_c(c);q[i][j].set_x(i);q[i][j].set_y(j);
      }
    }
  }
  //cout<<"bye"<<endl;
  i1.set_pix(q);
  return i1;
}

istream& operator>> (istream &is,Scaledimage &m){

	//is>>m.str;
	string s;
	is>>s;
	//cout<<m.str;
	int width,height;
	is>>width>>height;
	m = Scaledimage(width,height);
	//m.str=s;
	//cout<<"given width height"<<endl;
	int ver;
	is>>ver;
	Pixel **q;
	q = new Pixel*[height];
	for(unsigned int i=0;i<height;i++){
		q[i] = new Pixel[width];
	}
	//cout<<"Correct"<<endl;
	for (unsigned int i = 0; i < m.get_height(); ++i)
	{
		/* code */
		for (unsigned int j = 0; j < m.get_width(); ++j)
		{
			/* code */
			int r,g,b;
			is>>r>>g>>b;
			q[i][j].set_x(i);
			q[i][j].set_y(j);
			//cout<<"Correct"<<endl;
			Color c((float)r,(float)g,(float)b);
			q[i][j].set_c(c);


		}
	}
	//cout << "given pixel" << endl;
	m.set_pix(q);
}
