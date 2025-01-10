#pragma once
#include "Melancholy/Core.h"
#include <string>

namespace Melancholy {

	namespace Math {
		MAPI float Sin(float x);
		MAPI float Cos(float x);

		MAPI float Sqrt(float x);

		MAPI float Radians(float degrees);
		MAPI float Degrees(float radians);
		
		MAPI float Lerp(float a, float b, float f);
	}

	MAPI struct Vector2 {
		float x;
		float y;

		Vector2() = default;
		Vector2(const Vector2& copy) = default;
		Vector2(float x, float y) : x(x), y(y) { }
	};

	MAPI struct Vector3 {
		static float Length(Vector3 a);
		static float LengthSqr(Vector3 a);

		static Vector3 Normalized(Vector3 a);

		float x;
		float y;
		float z;

		Vector3() = default;
		Vector3(const Vector3& copy) = default;
		Vector3(float x, float y, float z) : x(x), y(y), z(z) { }
		Vector3(const Vector2& xy, float z) : x(xy.x), y(xy.y), z(z) { }

		Vector3 operator+(Vector3 b) { return (Vector3){ x + b.x, y + b.y, z + b.z }; }

		Vector3 operator-(Vector3 b) { return (Vector3){ x - b.x, y - b.y, z - b.z }; }

		Vector3 operator*(Vector3 b) { return (Vector3){ x * b.x, y * b.y, z * b.z }; }
		Vector3 operator*(float b) { return (Vector3){ x * b, y * b, z * b }; }

		Vector3 operator/(Vector3 b) { return (Vector3){ x / b.x, y / b.y, z / b.z }; }
		Vector3 operator/(float b) { return (Vector3){ x / b, y / b, z / b }; }

		std::string ToString();
	};

	MAPI struct Vector4 {
		float x;
		float y;
		float z;
		float w;

		Vector4() = default;
		Vector4(const Vector4& copy) = default;
		Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }
		Vector4(const Vector3& xyz, float w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) { }

	};

}
