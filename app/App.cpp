#include <iostream>
#include <EdgeDetection.hpp>

#define MAXVAL 180
#define MINVAL 160

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

	// Calculating gradient
	PixelMatrix horizontalGradient(pixelMatrix); // Copy input
	PixelMatrix& verticalGradient = pixelMatrix;

	HorizontalEdgeFilter horizontalEdgeFilter;
	horizontalEdgeFilter.filterPixelMatrix(horizontalGradient);

	VerticalEdgeFilter verticalEdgeFilter;
	verticalEdgeFilter.filterPixelMatrix(verticalGradient);

	PixelMatrix gradientIntensities(pixelMatrix.getWidth(), pixelMatrix.getHeight());
	PixelMatrix gradientDirections(pixelMatrix.getWidth(), pixelMatrix.getHeight());
	calculateGradient(horizontalGradient, verticalGradient, gradientIntensities, gradientDirections);

	PixelMatrix suppressedIntensities(pixelMatrix.getWidth(), pixelMatrix.getHeight());
	suppressNonMaximums(gradientIntensities, gradientDirections, suppressedIntensities);

	// Threshold hystheresis
	PixelMatrix thresheld(pixelMatrix.getWidth(), pixelMatrix.getHeight());
	thresholdHysteresis(suppressedIntensities, MAXVAL, MINVAL, thresheld);

	// Profit
	Utility::saveImage(suppressedIntensities.toImage(), files.value().at(1).string());


	return 0;
}
