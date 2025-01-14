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

		float Tan(float x)
		{
			return std::tanf(x);
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

	/* Matrix4 */

	Matrix4 Matrix4::Identity() {
        return {
            {
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
            }
        };
    }

    Matrix4 Matrix4::Translate(float x, float y, float z) {
        return {
            {
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                x, y, z, 1
            }
        };
    }

    Matrix4 Matrix4::Translate(const Vector3& translation) {
        return Translate(translation.x, translation.y, translation.z);
    }

    Matrix4 Matrix4::Scale(float x, float y, float z) {
        return {
            {
                x, 0, 0, 0,
                0, y, 0, 0,
                0, 0, z, 0,
                0, 0, 0, 1
            }
        };
    }

    Matrix4 Matrix4::Scale(const Vector3& scale) {
        return Scale(scale.x, scale.y, scale.z);
    }

    Matrix4 Matrix4::RotateX(float angle) {
        float s = Math::Sin(angle);
        float c = Math::Cos(angle);

        return {
            {
                1, 0, 0, 0,
                0, c,-s, 0,
                0, s, c, 0,
                0, 0, 0, 1
            }
        };
    }

    Matrix4 Matrix4::RotateY(float angle) {
        float s = Math::Sin(angle);
        float c = Math::Cos(angle);

        return {
            {
                c, 0, s, 0,
                0, 1, 0, 0,
               -s, 0, c, 0,
                0, 0, 0, 1
            }
        };
    }

    Matrix4 Matrix4::RotateZ(float angle) {
        float s = Math::Sin(angle);
        float c = Math::Cos(angle);

        return {
            {
                c, s, 0, 0,
               -s, c, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1 
            }
        };
    } 

    Matrix4 Matrix4::Ortho(float left, float right, float bottom, float top, float near, float far) {
        float m00 = 2.0f / (right - left);
        float m11 = 2.0f / (top - bottom);
        float m22 = -2.0f / (far - near);

        float x = -(right + left) / (right - left);
        float y = -(top + bottom) / (top - bottom);
        float z = -(far + near) / (far - near);

        return {
            {
                m00, 0, 0, 0,
                0, m11, 0, 0,
                0, 0, m22, 0,
                x, y, z, 1
            }
        };
    }

    Matrix4 Matrix4::Perspective(float fov, float aspect, float near, float far) {
        float tanHalfFov = Math::Tan(fov * 0.5f);    
        return {
            {
                1.0f / (aspect * tanHalfFov), 0, 0, 0,
                0, 1.0f / tanHalfFov, 0, 0,
                0, 0, -(far + near) / (far - near), -1,
                0, 0, (-2.0f * far * near) / (far - near), 0
            }
        };
    }

}
