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

	NoiseReductionFilter{}.filterPixelMatrix(pixelMatrix);

	PixelMatrix horizontalMatrix(pixelMatrix);
	HorizontalSobelFilter{}.filterPixelMatrix(horizontalMatrix);

	PixelMatrix verticalMatrix(pixelMatrix);
	VerticalSobelFilter{}.filterPixelMatrix(verticalMatrix);

	auto gradient = PixelMatrix::getEdgeGradient(horizontalMatrix, verticalMatrix);
	auto angle = PixelMatrix::getAngle(horizontalMatrix, verticalMatrix);

	suppressNonMaximums(gradient, angle, pixelMatrix);

	Utility::saveImage(pixelMatrix.toImage(), files.value().at(1).string());

	return 0;
}
