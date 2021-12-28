#include "EdgeDetection/Vector2Int.hpp"

#define PI 3.14159

namespace EdgeDetection
{
	Direction angleToDirection(float angle)
	{
		if (angle > PI * 7 / 8)
			return Direction::West;

		else if (angle > PI * 5 / 8)
			return Direction::SouthWest;

		else if (angle > PI * 3 / 8)
			return Direction::South;

		else if (angle > PI * 1 / 8)
			return Direction::SouthEast;

		else if (angle > PI * (-1) / 8)
			return Direction::East;

		else if (angle > PI * (-3) / 8)
			return Direction::NorthEast;

		else if (angle > PI * (-5) / 8)
			return Direction::North;

		else if (angle > PI * (-7) / 8)
			return Direction::NorthWest;
		
		return Direction::West;
	}

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