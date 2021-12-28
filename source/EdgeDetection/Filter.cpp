#include "EdgeDetection/Filter.hpp"
#include "EdgeDetection/PixelMatrix.hpp"

#include <algorithm>
#include <execution>

namespace EdgeDetection
{
	void Filter::filterPixelMatrix(PixelMatrix& pixelMatrix)
	{
		PixelMatrix output (pixelMatrix);

		const auto width = pixelMatrix.getWidth();
		const auto height = pixelMatrix.getHeight();

		std::vector<int> widthVec (width, 0);
		std::iota(std::begin(widthVec), std::end(widthVec), 0);

		std::for_each(std::execution::par, std::begin(widthVec), std::end(widthVec),
			[&](const auto i)
		{
			for (int j = 0; j < height; ++j)
			{
				filterPixel(pixelMatrix, output, i, j);
			}
		});

//		for (int i = 0; i < width; ++i)
//		{
//			for (int j = 0; j < height; ++j)
//			{
//				filterPixel(pixelMatrix, output, i, j);
//			}
//		}

		pixelMatrix = output;
	}
}
