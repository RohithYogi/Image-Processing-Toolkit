#ifndef DFS_h_
#define DFS_h_

#include <iostream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Image.h"

class DFS
{
private:
	Image img;
public:
	DFS(Image i);

	~DFS();

	void findConnectedComponents();

	void mergeGroups(vector<vector<int> > &groups, int grp1, int grp2);
};


#endif
