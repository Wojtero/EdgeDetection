#include "EdgeDetection/Filter.hpp"
#include "EdgeDetection/PixelMatrix.hpp"

namespace EdgeDetection
{

	void Filter::filterPixelMatrix(PixelMatrix& pixelMatrix)
	{
		PixelMatrix output (pixelMatrix);

		const auto width = pixelMatrix.getWidth();
		const auto height = pixelMatrix.getHeight();

		for (int i = 0; i < width; ++i)
		{
			for (int j = 0; j < height; ++j)
			{
				filterPixel(pixelMatrix, output, i, j);
			}
		}

		pixelMatrix = output;
	}
}
