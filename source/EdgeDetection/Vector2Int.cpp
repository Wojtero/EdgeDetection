#include "EdgeDetection/Vector2Int.hpp"

namespace EdgeDetection
{

	Vector2Int::Vector2Int(int x, int y)
		: x(x), y(y) {

	}

	Vector2Int Vector2Int::fromDirection(Direction direction)
	{
		switch (direction)
		{
		case Direction::North:
			return Vector2Int(0, -1);

		case Direction::NorthEast:
			return Vector2Int(1, -1);

		case Direction::East:
			return Vector2Int(1, 0);

		case Direction::SouthEast:
			return Vector2Int(1, 1);

		case Direction::South:
			return Vector2Int(0, 1);

		case Direction::SouthWest:
			return Vector2Int(-1, 1);

		case Direction::West:
			return Vector2Int(-1, 0);

		case Direction::NorthWest:
			return Vector2Int(-1, -1);

		default:
			return Vector2Int(0, 0);
		}
	}

	Vector2Int operator+(const Vector2Int& right, const Vector2Int& left)
	{
		return Vector2Int(
			right.x + left.x,
			right.y + left.y
		);
	}

	Vector2Int operator*(float multiplier, const Vector2Int& left)
	{
		return Vector2Int(
			multiplier * left.x,
			multiplier * left.y
		);
	}
}