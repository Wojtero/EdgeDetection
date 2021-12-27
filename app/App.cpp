#include <EdgeDetection.hpp>

int main()
{
	using namespace EdgeDetection;

	auto image = Utility::loadImage("../input/Lenna.jpg");
	auto grayImage = Utility::toGrayscale(image);
	PixelMatrix pixelMatrix(grayImage);

	// Here goes the detection algorithm on pixel matrix

	// Noise reduction
	NoiseReductionFilter noiseReductionFilter {};
	noiseReductionFilter.filterPixelMatrix(pixelMatrix);

	Utility::saveImage(pixelMatrix.toImage(), "../output/Lenna.jpg");

	return 0;
}
