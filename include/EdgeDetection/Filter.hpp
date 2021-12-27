#pragma once

#include "EdgeDetectionTypes.hpp"
#include "PixelMatrix.hpp"

namespace EdgeDetection
{
	/**
	 * Generic filter that can be applied to pixel matrix.
	 */
	class Filter
	{
	  public:

		void filterPixelMatrix(PixelMatrix& pixelMatrix);

	  protected:

		virtual void filterPixel(const PixelMatrix& input, PixelMatrix& output, int x, int y) = 0;

	};
}
