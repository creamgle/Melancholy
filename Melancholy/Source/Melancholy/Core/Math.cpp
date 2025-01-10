#include "Math.h"
#include "fmt/format.h"
#include <cmath>

namespace Melancholy {
	
	namespace Math {
		
		float Sin(float x)
		{
			return std::sinf(x);
		}

		float Cos(float x)
		{
			return std::cosf(x);
		}

		float Sqrt(float x)
		{
			return std::sqrtf(x);
		}

		float Radians(float degrees)
		{
			return -1.0f;
		}

		float Degrees(float radians)
		{
			return -1.0f;
		}

		float Lerp(float a, float b, float f)
		{
			return a * (1.0f - f) + (b * f);
		}

	} // Math

	/* Vector3 */
	
	float Vector3::Length(Vector3 a)
	{
		return Math::Sqrt(Vector3::LengthSqr(a));	
	}

	float Vector3::LengthSqr(Vector3 a)
	{
		return (a.x * a.x + a.y * a.y + a.z * a.z);
	}

	Vector3 Vector3::Normalized(Vector3 a)
	{
		float lengthSqr = LengthSqr(a);
		if (lengthSqr == 0 || lengthSqr == 1) 
		{
			// Already normalized
			return a;
		}
		
		float lengthInv = 1 / Math::Sqrt(lengthSqr);
		return a * lengthInv;
	}

	std::string Vector3::ToString()
	{
		return fmt::format("[{}, {}, {}]", x, y, z);
	}

}
