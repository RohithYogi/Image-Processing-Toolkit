#include<iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Image.h"
#include "Pixel.h"
#include "Color.h"
#include "reverseImage.h"
#include "CompositeImage.h"
using namespace std;

class Histogram:public Image
{
private:
	vector<int> ary;
	vector<int> loc_min;
	int *hist;
	int count;
  public:
	  Histogram(int x, int y): Image(x,y)
	  {
        	count=0;
			hist=new int[255];

	  }
	  Histogram(Histogram &h)
	  {

	  }

	~Histogram()
	{
	}

	void arithmetic(int r,int g,int b)
		{
			int mean;
			mean=(int)(r+g+b)/3;
			ary.push_back(mean);
			hist[mean]+=1;
		}


	void threshold()
	{
		for(int i=1;i<255;i++)
		{
			if(hist[i]<hist[i-1] && hist[i]<hist[i+1])
			{
				loc_min.push_back(i);
			}
	   }
   }
   int size()
   {
   	return loc_min.size();
   }

   	void color_select(Pixel** p,int x,int y,int i)
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

   void color()
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

	
	
	
};


int main(int argc, char *argv[])
{
		ifstream inFile;
		ofstream  output("output_task-4_imt2016093.ppm");
		string Line;
		int width, height, maxval;
		int i = 0;

		inFile.open(argv[1]);

		if (!inFile) {
			cout << "Unable to open file";
			exit(1); // terminate with error
		}
	
		while (getline(inFile, Line))
		{
			i++;
			if (i == 2)
			{
				width = atoi(Line.c_str());
				height = atoi(Line.c_str());
     	
			}
			if (i == 3)
			{
				maxval = atoi(Line.c_str());
				break;
			}
		}
		 Image z(width, height);
		 
		Histogram b(width, height);

	     Image g(width,height);
		
		 float red, green, blue;
        for(int i=0;i<height;i++)
         {
        	for(int j=0;j<width;j++)
		 		{
             	inFile >> red >> green >> blue;
					b.get_pix()[i][j].set_c(Color(red,green,blue));
					g.get_pix()[i][j].set_c(Color(red,green,blue));
					z.get_pix()[i][j].set_c(Color(red,green,blue));
		 			b.arithmetic(red, green, blue);
		 		}
       }
       
       
       
		  b.threshold();
		 
	 	  b.color();
	 	  Image f(width,height);
	 	  
	 	    if(b.size()==0)
		  {
		     
		  	reverseImage rev(g);
       		rev.Side_ways();
       		Image hh = rev.get_ima();
       		g=hh;
		    
		    CompositeImage d(z,g);
		    
		    f=d.Composition(0.4);
	     }
	     else
	     {
		 
    	   CompositeImage d(z,b);
		    f=d.Composition(0.4);
    	    
         }
         output<<f;
	 	 inFile.close();
	 	 return 0;

}
