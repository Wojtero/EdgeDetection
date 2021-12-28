#include "EdgeDetection/SignedFilter.hpp"

namespace EdgeDetection
{
	void SignedFilter::init(size_t size, int** factors)
	{
		this->size = size;
		this->factors = factors;
	}

	SignedFilter::~SignedFilter()
	{
		for (size_t i = 0; i < size; i++)
		{
			delete[] factors[i];
		}

		delete[] factors;
	}

	void SignedFilter::filterPixel(const PixelMatrix& input, PixelMatrix& output, int x, int y)
	{
		const auto currentPixel = input.at(x, y);
		float result = 0.f;

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				result += static_cast<float>(input.atSafe(x + i - 2, y + j - 2, currentPixel))
					* factors[i][j];
			}
		}

		output.at(x, y) = clampResult(result);
	}

	Types::Byte SignedFilter::clampResult(float result) const
	{
		signed char s = static_cast<signed char>(result);
		Types::Byte b = reinterpret_cast<Types::Byte&>(s);
		return b;
	}
}