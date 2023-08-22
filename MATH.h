#pragma once
#include "Player.h"
#include "MATH.h"
#include <assert.h>
#include <ImGuiManager.h>


Vector3 Add(const Vector2 v1, const Vector2& v2);

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 Inverse(const Matrix4x4& m);

// スケーリング行列を宣言
Matrix4x4 matScale(const Vector2 scale);

Matrix4x4 matRotX(float rotation);

Matrix4x4 matRotY(float rotation);

Matrix4x4 matRotZ(float rotation);

Matrix4x4 matRotXYZ(float rotationX, float rotationY, float rotationZ);

// 平行移動行列を宣言
Matrix4x4 matTrans(const Vector2 translation);

Matrix4x4 MakeAffineMatrix(const Vector2& scale, const Vector2& rot);

Vector2 TransformNomal(const Vector2& v, const Matrix4x4& m);

// 正規化
Vector2 Normalize(const Vector2& v);

// 長さ
float Length(const Vector2& v);

// 内積
float Dot(const Vector2& v1, const Vector2& v2);