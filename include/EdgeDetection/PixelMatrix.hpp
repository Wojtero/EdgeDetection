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

		PixelMatrix(const PixelMatrix& pixelMatrix) = default;

		Types::Byte& at(int x, int y);

		[[nodiscard]]
		Types::Byte at(int x, int y) const;

		[[nodiscard]]
		Types::Byte atSafe(int x, int y, Types::Byte alternative) const;

		[[nodiscard]]
		int getWidth() const;

		[[nodiscard]]
		int getHeight() const;

		[[nodiscard]]
		const std::vector<Types::Byte>& getPixels() const;

		[[nodiscard]]
		Types::Image toImage() const;

	  private:

		int width {};

		int height {};

		std::vector<Types::Byte> pixels {};

	};
}
