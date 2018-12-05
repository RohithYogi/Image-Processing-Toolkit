#include "Labelledim.h"
#include "Labelledpix.h"
#include "Color.h"
using namespace std;
Labelledim::Labelledim(){
}
Labelledim::~Labelledim(){
}
Labelledim::Labelledim(Image img) :Image(img){
	lpix = new Labelledpix*[img.get_height()];
	for (unsigned int i = 0;i < img.get_height();i++) {
		lpix[i] = new Labelledpix[img.get_width()];
	}
}
ostream& operator<<(ostream &os, Labelledim &m) {
	os << "P3" << endl;
	os << m.get_width() << " " << m.get_height() << endl;
	os << 255 << endl;
	for (unsigned int i = 0; i < m.get_height(); ++i) {
		for (unsigned int j = 0; j < m.get_width(); ++j) {
			os << (int)m.lpix[i][j].get_c().get_red() << " " << (int)m.lpix[i][j].get_c().get_green() << " " << (int)m.lpix[i][j].get_c().get_blue() << " ";
		}
		os << endl;
	}
	return os;
}
Labelledpix** Labelledim::get_pix() {
	return lpix;
}
void Labelledim::set_i_j(int i, int j, Color c) {
	lpix[i][j].set_c(c);
	lpix[i][j].set_x(i);
	lpix[i][j].set_y(j);
}