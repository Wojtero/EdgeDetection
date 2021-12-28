#include "EdgeDetection/HorizontalEdgeFilter.hpp"

namespace EdgeDetection
{
	HorizontalEdgeFilter::HorizontalEdgeFilter()
	{
		const size_t filterSize = 3;

		int** factors = new int*[filterSize];
		size_t center = filterSize / 2;
		for (size_t x = 0; x < filterSize; x++)
		{
			// Column
			factors[x] = new int[filterSize];

			for (size_t y = 0; y < filterSize; y++)
			{
				if (y < center)
				{
					// Row above the center
					factors[x][y] = -1;
				}
				else if (y > center)
				{
					// Row below the center
					factors[x][y] = 1;
				}
				else
				{
					factors[x][y] = 0;
				}
			}
		}

		init(filterSize, factors);
	}
}