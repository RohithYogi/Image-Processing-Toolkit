#include "Labelledpix.h"
#include "Image.h"
#include "Color.h"
using namespace std;


Labelledpix::Labelledpix(){
}
Labelledpix::~Labelledpix(){
}
Labelledpix::Labelledpix(Pixel img):Pixel(img) {
}
void Labelledpix::set_sl(bool t)
{
	setl = t;
}
bool Labelledpix::get_sl()
{
	return setl;
}
void Labelledpix::set_label(int i) {
	label = i;
}
int Labelledpix::get_label() {
	return label;
}
