#include "EdgeDetection/VerticalSobelFilter.hpp"

namespace EdgeDetection
{
	void VerticalSobelFilter::filterPixel(const PixelMatrix& input, PixelMatrix& output, int x, int y)
	{
		const auto currentPixel = input.at(x, y);
		float result = 0.f;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				result += static_cast<float>(input.atSafe(x + i - 1, y + j - 1, currentPixel))
					* factors.at(i).at(j);
			}
		}

		output.at(x, y) = static_cast<Types::Byte>(result);
	}
}
