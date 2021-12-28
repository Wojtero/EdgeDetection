#include <iostream>
#include <EdgeDetection.hpp>

int main(int argc, char* argv[])
{
	using namespace EdgeDetection;

	auto files = InputParser{}.parseInput(argc, argv);

	if (!files.has_value())
	{
		std::cout << "Usage: EdgeDetection <pathToInput> <pathToOutput>\n";
		return 1;
	}

	auto image = Utility::loadImage(files.value().at(0).string());
	auto grayImage = Utility::toGrayscale(image);
	PixelMatrix pixelMatrix(grayImage);

	// Here goes the detection algorithm on pixel matrix

	// Noise reduction
	NoiseReductionFilter{}.filterPixelMatrix(pixelMatrix);

	// ?

	// Profit
	Utility::saveImage(pixelMatrix.toImage(), files.value().at(1).string());

	return 0;
}
