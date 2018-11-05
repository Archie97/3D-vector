

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Vector
{
public:
    //* Constructors
   
    // Default Constructor to Sets the x, y and z components of this Vector to zero.
    
    Vector ();
      // Component Constructor that Sets the x, y and z components of this Vector to corresponding passed x, y and z parameters.
   
    Vector (float x, float y, float z);
    // Copy Constructor that  Sets the x, y and z components of this Vector to equal the x, y 
    // and z components of Vector v.
    Vector (const Vector &v);
  
    //* Friend Operators Stream Insertion Operator
    // Writes the Vector v into the output stream in the format (x,y,z) 
    // so it can be used by various iostream functions.
    friend std::ostream &operator << (std::ostream &os, const Vector &v);
    // Equal To Operator Compares the x, y and z components of Vector v1 and to the x, y 
    // and z components of Vector v2 and returns true if they are 
    // identical. Otherwise, it returns false.
    friend bool operator == (const Vector &v1, const Vector &v2);
   
    // Not Equal To Operator Compares the x, y and z components of Vector v1 and to the x, y 
    // and z components of Vector v2 and returns true if they are not 
    // identical. Otherwise, it returns false.
    friend bool operator != (const Vector &v1, const Vector &v2);
    // Addition Operator Adds the x, y and z components of Vector v1 to the x, y and z 
    // compenents of Vector v2 and returns the result.
    friend Vector operator + (const Vector &v1, const Vector &v2);
    // Subtraction Operator Subtracts the x, y and z components of Vector v2 to the x, y and 
    // z compenents of Vector v1 and returns the result.
    friend Vector operator - (const Vector &v1, const Vector &v2);
    // Multiplication Operator Multiplies the x, y and z components of Vector v with a scalar 
    // value and returns the result.
    friend Vector operator * (const Vector &v, float scalar);
    friend Vector operator * (float scalar, const Vector &v);
    // Division Operator Divides the x, y and z components of Vector v with a scalar 
    // value and returns the result.
    friend Vector operator / (const Vector &v, float scalar);
    friend Vector operator / (float scalar, const Vector &v);
    //* Friend Functions DotProduct
    // Computes the dot product between Vector v1 and Vector v2 and  returns the result.
    friend float DotProduct (const Vector &v1, const Vector &v2);
    // CrossProduct Computes the cross product between Vector v1 and Vector v2 and  returns the result.
    friend Vector CrossProduct (const Vector &v1, const Vector &v2);
    // Lerp Returns a linear interpolation between Vector v1 and Vector v2  for paramater t, in the closed interval [0, 1].
    
    friend Vector Lerp (const Vector &v1, const Vector &v2, float t);
       // Clamp - Clamps this Vector's x, y and z components to lie within min and max.
   
    friend Vector Clamp (const Vector &v1, float min, float max);
    // Min Returns a Vector whos x, y and z components are the minimum components found in Vector v1 and Vector v2.
    
    friend Vector Min (const Vector &v1, const Vector &v2);
    // Max Returns a Vector whos x, y and z components are the maximum  components found in Vector v1 and Vector v2.
    friend Vector Max (const Vector &v1, const Vector &v2);
    // DistanceBetween Returns the scalar distance between the Vector v1 and the Vector  v2.
    friend float DistanceBetween (const Vector &v1, const Vector &v2);
    // DistanceBetweenSquared Returns the scalar squared distance between the Vector v1 and  the Vector v2.
    friend float DistanceBetweenSquared (const Vector &v1, const Vector &v2);
    //* Operators Copy Assignment Operator Assigns this Vector's components to be equal to Vector v's  components.
    Vector &operator = (const Vector &v);
    // Addition Assignment Operator Adds to this Vector's components the components of Vector v.
    Vector &operator += (const Vector &v);
    // Subtraction Assignment Operator Subtract from this Vector's components the components of Vector  v.
    Vector &operator -= (const Vector &v);
    // Multiplication Assignment Operator Multiply this Vector's components by a scalar value.
    Vector &operator *= (float scalar);
    // Division Assignment Operator
    // Divide this Vector's components by a scalar value.
    Vector &operator /= (float scalar);
    // Unary Minus Operator Negate the components of this Vector.
    Vector &operator - ();
    // Array Subscript Operator Allows access to the x, y and z components through an array  subscript notation.
    float &operator [] (int i);
    
    //* Methods
    // Returns the x component of this Vector.
    float X ();
    // Returns the y component of this Vector.
    float Y ();
    // Returns the z component of this Vector.
    float Z ();
    // Sets the x, y and z components of this Vector to the paramaters  of this function.
    void Set (float x, float y, float z);
    // MakeZero Sets the x, y and z components of this Vector to zero.
    void MakeZero ();
    // IsZero Returns true if the x, y and z components of this Vector are  equal to zero.
    bool IsZero ();
    // LengthSquared Returns the magnitude of the x, y and z components squared.
    float LengthSquared ();
    // Length Returns the magnitude of the x, y and z components.
    float Length ();
    // Normalize Sets the components of this Vector in such a way that their  magnitude is equal to one.
    void Normalize ();
    // IsNormalized Compares the magnitude of this Vector to one.
    bool IsNormalized ();
private:
    float x;
    float y;
    float z;
};

inline Vector::Vector() : x(0.0f), y(0.0f), z(0.0f) {}

inline Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

inline Vector::Vector(const Vector &v) : x(v.x), y(v.y), z(v.z) {}

inline std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    os << '(' << v.x << ',' << v.y << ',' << v.z << ')';
    return os;
}

inline bool operator==(const Vector &v1, const Vector &v2)
{
    return (AreEqual(v1.x, v2.x)&& AreEqual(v1.y, v2.y) &&AreEqual(v1.z, v2.z));
}

inline bool operator!=(const Vector &v1, const Vector &v2)
{
    return (!AreEqual(v1.x, v2.x) ||
            !AreEqual(v1.y, v2.y)||!AreEqual(v1.z, v2.z));
}

inline Vector operator+(const Vector &v1, const Vector &v2)
{
    return Vector(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
}

inline Vector operator-(const Vector &v1, const Vector &v2)
{
    return Vector(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);
}

inline Vector operator*(const Vector &v, float scalar)
{
    return Vector(v.x*scalar, v.y*scalar, v.z*scalar);
}

inline Vector operator*(float scalar, const Vector &v)
{
    return Vector(v.x*scalar, v.y*scalar, v.z*scalar);
}

inline Vector operator/(const Vector &v, float scalar)
{
    assert(!EqualsZero(scalar));
    scalar = 1.0f / scalar;
    return Vector(v.x*scalar, v.y*scalar, v.z*scalar);
}

inline Vector operator/(float scalar, const Vector &v)
{
    assert(!EqualsZero(scalar));
    scalar = 1.0f / scalar;
    return Vector(v.x*scalar, v.y*scalar, v.z*scalar);
}

inline float DotProduct (const Vector &v1, const Vector &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Vector CrossProduct(const Vector &v1, const Vector &v2)
{
    return Vector(v1.y*v2.z - v1.z*v2.y,
                  v1.z*v2.x - v1.x*v2.z,
                  v1.x*v2.y - v1.y*v2.x);
}

inline Vector Lerp(const Vector &v1, const Vector &v2, float t)
{
    return Vector(Lerp(v1.x, v2.x, t),
                  Lerp(v1.y, v2.y, t),
                  Lerp(v1.z, v2.z, t));
}

inline Vector Clamp(const Vector &v, float min, float max)
{
    return Vector(Clamp(v.x, min, max),
                  Clamp(v.y, min, max),
                  Clamp(v.z, min, max));
}

inline Vector Min(const Vector &v1, const Vector &v2)
{
    return Vector(Min(v1.x, v2.x),
                  Min(v1.y, v2.y),
                  Min(v1.z, v2.z));
}

inline Vector Max(const Vector &v1, const Vector &v2)
{
    return Vector(Max(v1.x, v2.x),
                  Max(v1.y, v2.y),
                  Max(v1.z, v2.z));
}

inline float DistanceBetween(const Vector &v1, const Vector &v2)
{
    Vector distance = v1 - v2;
    return distance.Length();
}

inline float DistanceBetweenSquared (const Vector &v1, const Vector &v2)
{
    Vector distance = v1 - v2;
    return distance.LengthSquared();
}

inline Vector &Vector::operator=(const Vector &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
} 

inline Vector &Vector::operator+=(const Vector &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline Vector &Vector::operator-=(const Vector &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

inline Vector &Vector::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

inline Vector &Vector::operator/=(float scalar)
{
    assert(!EqualsZero(scalar));
    scalar = 1.0f / scalar;
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

inline Vector &Vector::operator-()
{
    x = -x;
    y = -y;
    z = -z;
    return *this;
}

inline float &Vector::operator[](int i)
{
    if (i == 0) {
        return x;
    } else if (i == 1) {
        return y;
    } else if (i == 2) {
        return z;
    } else {
        assert("[] Access error!");
    }
}

inline float Vector::X()
{
    return x;
}

inline float Vector::Y()
{
    return y;
}

inline float Vector::Z()
{
    return z;
}

inline void Vector::Set(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

inline void Vector::MakeZero()
{
    x = y = z = 0.0f;
}

inline bool Vector::IsZero()
{
    return EqualsZero(x) &&
           EqualsZero(y) &&
           EqualsZero(z);
}

inline float Vector::LengthSquared()
{
    return x*x + y*y + z*z;
}

inline float Vector::Length()
{
    return Sqrt(LengthSquared());
}

inline void Vector::Normalize()
{
    float magnitude = Length();
    assert(!EqualsZero(magnitude));

    magnitude = 1.0f / magnitude;

    x *= magnitude;
    y *= magnitude;
    z *= magnitude;
}

inline bool Vector::IsNormalized()
{
    return AreEqual(Length(), 1.0f);
}

