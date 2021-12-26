#include <iostream>
#include <CImg.h>
#include <EdgeDetection.hpp>

int main()
{
	using namespace std;
	using namespace cimg_library;
	using namespace EdgeDetection;

	auto image = Utility::loadImage("../input/Lenna.jpg");

	auto grayImage = Utility::toGrayscale(image);

	Utility::saveImage(grayImage, "../output/Lenna.jpg");

	return 0;
}
