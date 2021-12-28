#include "EdgeDetection/VerticalEdgeFilter.hpp"

namespace EdgeDetection
{
	VerticalEdgeFilter::VerticalEdgeFilter()
	{
		const size_t filterSize = 3;

		int** factors = new int* [filterSize];
		size_t center = filterSize / 2;
		for (size_t x = 0; x < filterSize; x++)
		{
			// Column
			factors[x] = new int[filterSize];

			int columnValue = 0;
			if (x < center)
			{
				columnValue = -1;
			}
			else if (x > center)
			{
				columnValue = 1;
			}

			for (size_t y = 0; y < filterSize; y++)
			{
				factors[x][y] = columnValue;
			}
		}

		init(filterSize, factors);
	}
}