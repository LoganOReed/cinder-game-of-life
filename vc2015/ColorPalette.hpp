#ifndef COLOR_PALETTE_HPP
#define COLOR_PALETTE_HPP

#include "cinder/app/App.h"

#include <vector>
#include <string>

using namespace ci;
using namespace ci::app;

class MyColorPalette {
public:
	MyColorPalette();
	std::vector<Color> ages;
};

MyColorPalette::MyColorPalette() {
	ages.push_back(Color(241.0 / 255.0, 196.0 / 255.0, 15.0 / 255.0));
	ages.push_back(Color(230.0 / 255.0, 126.0 / 255.0, 34.0 / 255.0));
	ages.push_back(Color(231.0 / 255.0, 76.0 / 255.0, 60.0 / 255.0));
	ages.push_back(Color(192.0 / 255.0, 57.0 / 255.0, 43.0 / 255.0));
}

#endif
