#include <iostream>
#include <fstream>
#include "fucos.h"

void MPPoint::Write(std::ostream& file) const {
	file << "POINT" << x << "" << y << "" << Pointshape << std::endl;
}
void MPLine::Write(std::ostream& file) const {
	file << "LINE" << std::endl;
	first.Write(file);
	last.Write(file);
}
void GeometricScene::Scale(double s) {
	if (s <= MINIMAL_NONZERO)
		return;
	for (unsigned int I = 0; I < shapeIndex; I++)
		shapes[I]->Scale(s);
}

void GeometricScene::Write(const char* path) const {
	std::ofstream file(path, std::ios::out);
	for (unsigned int I = 0; I < shapeIndex; I++)
		shapes[I]->Write(file);
}		
