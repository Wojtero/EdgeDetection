#pragma once
#include "Filter.hpp"

namespace EdgeDetection
{
	/*
	Filter saving signed chars
	*/
	class SignedFilter : public Filter
	{
	public:
		~SignedFilter();

	protected:
		void init(size_t size, int** factors);

		void filterPixel(const PixelMatrix& input, PixelMatrix& output, int x, int y) override;

	private:
		size_t size;
		int** factors;

		Types::Byte clampResult(float result) const;
	};
}