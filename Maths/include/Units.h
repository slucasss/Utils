#pragma once
#include "PrimitiveTypes.h"

using degrees = float32;
using radians = float32;

namespace Maths{
	inline constexpr float32 PI = 3.14159265358979323846f;

	inline constexpr float32 RADIANS_TO_DEGREES = 180.0f / PI;
	inline constexpr float32 DEGREES_TO_RADIANS = PI / 180;
}