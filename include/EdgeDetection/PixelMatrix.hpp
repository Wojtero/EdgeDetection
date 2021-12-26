#pragma once

#include <vector>
#include "EdgeDetectionTypes.hpp"

namespace EdgeDetection
{
	/**
	 * Grayscale image as pixel matrix.
	 */
	class PixelMatrix
	{
	  public:

		PixelMatrix() = delete;

		explicit PixelMatrix(const Types::Image& image);

		[[nodiscard]]
		inline Types::Byte& at(int x, int y);

		[[nodiscard]]
		inline Types::Byte at(int x, int y) const;

		[[nodiscard]]
		inline int getWidth() const;

		[[nodiscard]]
		inline int getHeight() const;

		[[nodiscard]]
		inline const std::vector<Types::Byte>& getPixels() const;

		[[nodiscard]]
		Types::Image toImage() const;

	  private:

		int width {};

		int height {};

		std::vector<Types::Byte> pixels {};

	};
}
