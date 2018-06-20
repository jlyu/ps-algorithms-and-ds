/*********************************************************************
*
* Vector3D - �򵥵�3D������
*
**********************************************************************/
#include <math.h>


class Vector3D {
public:
	Vector3D() {}
	Vector3D(float dx, float dy, float dz) : x(dx), y(dy), z(dz) { }
	Vector3D(const Vector3D& v) : x(v.x), y(v.y), z(v.z) { }
//***** override operator
	Vector3D& operator= (const Vector3D& rhs) {
		if (*this == rhs) return *this;
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}

	bool operator== (const Vector3D& rhs) const {
		return (x==rhs.x) && (y==rhs.y) && (z==rhs.z);
	}
	
	bool operator!= (const Vector3D& rhs) const {
		return !(*this==rhs);
	}
//***** vector operation
	//*** set zero vector
	void zero() { x=y=z=0.0f; }

	//*** ������
	Vector3D operator- () const { return Vector3D(-x, -y, -z); }

	//*** �����ӡ���
	Vector3D operator+ (const Vector3D& rhs) { return Vector3D(x+rhs.x, y+rhs.y, z+rhs.z); }
	Vector3D operator- (const Vector3D& rhs) { return Vector3D(x-rhs.x, y-rhs.y, z-rhs.z); }

	//*** ������ĳˡ���
	Vector3D operator* (const float f)const { return Vector3D(f*x, f*y, f*z); }
	Vector3D operator/ (const float f)const { ASSERT(f==0.00000); return Vector3D(x/f, y/f, z/f); }

	//*** �����ĸ���������
	Vector3D& operator+= (const Vector3D& rhs) { 
		x+=rhs.x; y+=rhs.y; z+=rhs.z;
		return *this; }

	Vector3D& operator-= (const Vector3D& rhs) {
		x-=rhs.x; y-=rhs.y; z-=rhs.z;
		return *this; }

	Vector3D& operator*= (const float n) {
		x*=n; y*=n; z*=n;
		return *this; }

	Vector3D& operator/= (const float n) {
		x/=n; y/=n; z/=n;
		return *this; }

	//***** ������׼��
	void Normalize() {
		const float magSq = x*x + y*y + z*z;
		if (magSq > 0.0f)
		{
			float oneOver = 1.0f / sqrt(magSq);
			x *= oneOver;
			y *= oneOver;
			z *= oneOver;
		}
	}

	//***** �������
	float operator* (const Vector3D& rhs) {
		return x*rhs.x + y*rhs.y + z*rhs.z;
	}

private:
	float x;
	float y;
	float z;
};


/*********************************************************************
* Vector3D�ǳ�Ա����
**********************************************************************/

//***** ������ģ
inline float VectorMod(const Vector3D& rhs) {
	return sqrt(rhs.x*rhs.x + rhs.y*rhs.y + rhs.z*rhs.z);
}

//***** �������
inline Vector3D CrossProduct(const Vector3D& lhs, const Vector3D& rhs) {
	return Vector3D(lhs.y*rhs.z - lhs.z*rhs.y, 
							lhs.z*rhs.x - lhs.x*rhs.z, 
							lhs.x*rhs.y - lhs.y*rhs.x);
}

//***** �������
inline Vector3D operator* (const float k, const Vector3D& rhs) {
	return Vector3D(k*rhs.x, k*rhs.y, k*rhs.z);
}

//***** �����������
inline float Distance(const Vector3D& lhs, const Vector3D& rhs) {
	return sqrt((rhs.x - lhs.x)*(rhs.x - lhs.x) + (rhs.y - lhs.y)*(rhs.y - lhs.y) + (rhs.z - lhs.z)*(rhs.z - lhs.z));
}