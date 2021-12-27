#pragma once
#include "EdgeDetection/PixelMatrix.hpp"

namespace EdgeDetection 
{
	/*
	Based on gradient intensity and direction at each pixel,
	suppresses intensities which aren't maximums within the direction.
	Returns the remaining gradient intensities
	*/
	void suppressNonMaximums(const PixelMatrix& gradientIntensity, const PixelMatrix& gradientDirection, PixelMatrix& output);
}