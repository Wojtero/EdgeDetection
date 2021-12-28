#pragma once
#include "PixelMatrix.hpp"

namespace EdgeDetection
{
	void calculateGradient(
		const PixelMatrix& horizontalGradient,
		const PixelMatrix& verticalGradient,
		PixelMatrix& resultIntensity,
		PixelMatrix& resultDirection );
}