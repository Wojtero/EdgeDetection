#include <EdgeDetection.hpp>
#include <iostream>

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

	// Calculating gradient
	PixelMatrix horizontalGradient = PixelMatrix(pixelMatrix); // Copy input
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

	// Profit
	Utility::saveImage(suppressedIntensities.toImage(), "../output/Lenna.jpg");

	return 0;
}
