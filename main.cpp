#include <Novice.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <string.h>
#include <windows.h>
#include <assert.h>
#include <Windows.h>
#include <worldtransform.h>


const char kWindowTitle[] = "LE2C_02_イシワタクウタ";

struct Vector2 {
	float x, y;
};

enum BLOCK { NOME, block };

struct Matrix3x3 {
	float m[2][2];
};


Vector2 Add(const Vector2 v1, const Vector2& v2) {
	Vector2 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return result;
};

Matrix3x3 Multiply(const Matrix3x3& m1, const Matrix3x3& m2) {

	Matrix3x3 result;

	result.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] +
	                 m1.m[0][3] * m2.m[3][0];
	result.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] +
	                 m1.m[0][3] * m2.m[3][1];
	result.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] +
	                 m1.m[0][3] * m2.m[3][2];
	result.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] +
	                 m1.m[0][3] * m2.m[3][3];

	result.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] +
	                 m1.m[1][3] * m2.m[3][0];
	result.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] +
	                 m1.m[1][3] * m2.m[3][1];
	result.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] +
	                 m1.m[1][3] * m2.m[3][2];
	result.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] +
	                 m1.m[1][3] * m2.m[3][3];

	result.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] +
	                 m1.m[2][3] * m2.m[3][0];
	result.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] +
	                 m1.m[2][3] * m2.m[3][1];
	result.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] +
	                 m1.m[2][3] * m2.m[3][2];
	result.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] +
	                 m1.m[2][3] * m2.m[3][3];
	/*
	result.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] +
	                 m1.m[3][3] * m2.m[3][0];
	result.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] +
	                 m1.m[3][3] * m2.m[3][1];
	result.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] +
	                 m1.m[3][3] * m2.m[3][2];
	result.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] +
	                 m1.m[3][3] * m2.m[3][3];
					 */
	return result;
}

Matrix3x3 Inverse(const Matrix3x3& m) {
	Matrix3x3 result;
	float determinant = m.m[0][0] * m.m[1][1] * m.m[2][2]+
	                    m.m[0][0] * m.m[1][2] * m.m[2][3]+
	                    m.m[0][0] * m.m[1][3] * m.m[2][1]-
	                    m.m[0][0] * m.m[1][3] * m.m[2][2]-
	                    m.m[0][0] * m.m[1][2] * m.m[2][1]-
	                    m.m[0][0] * m.m[1][1] * m.m[2][3]-
	                    m.m[0][1] * m.m[1][0] * m.m[2][2]-
	                    m.m[0][2] * m.m[1][0] * m.m[2][3]-
	                    m.m[0][3] * m.m[1][0] * m.m[2][1]+
	                    m.m[0][3] * m.m[1][0] * m.m[2][2]+
	                    m.m[0][2] * m.m[1][0] * m.m[2][1]+
	                    m.m[0][1] * m.m[1][0] * m.m[2][3]+
	                    m.m[0][1] * m.m[1][2] * m.m[2][0]+
	                    m.m[0][2] * m.m[1][3] * m.m[2][0]+
	                    m.m[0][3] * m.m[1][1] * m.m[2][0]-
	                    m.m[0][3] * m.m[1][2] * m.m[2][0]-
	                    m.m[0][2] * m.m[1][1] * m.m[2][0]-
	                    m.m[0][1] * m.m[1][3] * m.m[2][0]-
	                    m.m[0][1] * m.m[1][2] * m.m[2][3]-
	                    m.m[0][2] * m.m[1][3] * m.m[2][1]-
	                    m.m[0][3] * m.m[1][1] * m.m[2][2]+
	                    m.m[0][3] * m.m[1][2] * m.m[2][1]+
	                    m.m[0][2] * m.m[1][1] * m.m[2][3]+
	                    m.m[0][1] * m.m[1][3] * m.m[2][2];

	float rectdeterminant = 1 / determinant;

	// 0行列
	result.m[0][0] = (m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[1][2] * m.m[2][3] * m.m[3][1] +
	                  m.m[1][3] * m.m[2][1] * m.m[3][2] - m.m[1][3] * m.m[2][2] * m.m[3][1] -
	                  m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[1][1] * m.m[2][3] * m.m[3][2]) *
	                 rectdeterminant;

	result.m[0][1] = (-m.m[0][1] * m.m[2][2] * m.m[3][3] - m.m[0][2] * m.m[2][3] * m.m[3][1] -
	                  m.m[0][3] * m.m[2][1] * m.m[3][2] + m.m[0][3] * m.m[2][2] * m.m[3][1] +
	                  m.m[0][2] * m.m[2][1] * m.m[3][3] + m.m[0][1] * m.m[2][3] * m.m[3][2]) *
	                 rectdeterminant;

	result.m[0][2] = (m.m[0][1] * m.m[1][2] * m.m[3][3] + m.m[0][2] * m.m[1][3] * m.m[3][1] +
	                  m.m[0][3] * m.m[1][1] * m.m[3][2] - m.m[0][3] * m.m[1][2] * m.m[3][1] -
	                  m.m[0][2] * m.m[1][1] * m.m[3][3] - m.m[0][1] * m.m[1][3] * m.m[3][2]) *
	                 rectdeterminant;

	result.m[0][3] = (-m.m[0][1] * m.m[1][2] * m.m[2][3] - m.m[0][2] * m.m[1][3] * m.m[2][1] -
	                  m.m[0][3] * m.m[1][1] * m.m[2][2] + m.m[0][3] * m.m[1][2] * m.m[2][1] +
	                  m.m[0][2] * m.m[1][1] * m.m[2][3] + m.m[0][1] * m.m[1][3] * m.m[2][2]) *
	                 rectdeterminant;

	// 1行列
	result.m[1][0] = (-m.m[1][0] * m.m[2][2] * m.m[3][3] - m.m[1][2] * m.m[2][3] * m.m[3][0] -
	                  m.m[1][3] * m.m[2][0] * m.m[3][2] + m.m[1][3] * m.m[2][2] * m.m[3][0] +
	                  m.m[1][2] * m.m[2][0] * m.m[3][3] + m.m[1][0] * m.m[2][3] * m.m[3][2]) *
	                 rectdeterminant;

	result.m[1][1] = (m.m[0][0] * m.m[2][2] * m.m[3][3] + m.m[0][2] * m.m[2][3] * m.m[3][0] +
	                  m.m[0][3] * m.m[2][0] * m.m[3][2] - m.m[0][3] * m.m[2][2] * m.m[3][0] -
	                  m.m[0][2] * m.m[2][0] * m.m[3][3] - m.m[0][0] * m.m[2][3] * m.m[3][2]) *
	                 rectdeterminant;

	result.m[1][2] = (-m.m[0][0] * m.m[1][2] * m.m[3][3] - m.m[0][2] * m.m[1][3] * m.m[3][0] -
	                  m.m[0][3] * m.m[1][0] * m.m[3][2] + m.m[0][3] * m.m[1][2] * m.m[3][0] +
	                  m.m[0][2] * m.m[1][0] * m.m[3][3] + m.m[0][0] * m.m[1][3] * m.m[3][2]) *
	                 rectdeterminant;

	result.m[1][3] = (m.m[0][0] * m.m[1][2] * m.m[2][3] + m.m[0][2] * m.m[1][3] * m.m[2][0] +
	                  m.m[0][3] * m.m[1][0] * m.m[2][2] - m.m[0][3] * m.m[1][2] * m.m[2][0] -
	                  m.m[0][2] * m.m[1][0] * m.m[2][3] - m.m[0][0] * m.m[1][3] * m.m[2][2]) *
	                 rectdeterminant;

	// 2行列
	result.m[2][0] = (m.m[1][0] * m.m[2][1] * m.m[3][3] + m.m[1][1] * m.m[2][3] * m.m[3][0] +
	                  m.m[1][3] * m.m[2][0] * m.m[3][1] - m.m[1][3] * m.m[2][1] * m.m[3][0] -
	                  m.m[1][1] * m.m[2][0] * m.m[3][3] - m.m[1][0] * m.m[2][3] * m.m[3][1]) *
	                 rectdeterminant;

	result.m[2][1] = (-m.m[0][0] * m.m[2][1] * m.m[3][3] - m.m[0][1] * m.m[2][3] * m.m[3][0] -
	                  m.m[0][3] * m.m[2][0] * m.m[3][1] + m.m[0][3] * m.m[2][1] * m.m[3][0] +
	                  m.m[0][1] * m.m[2][0] * m.m[3][3] + m.m[0][0] * m.m[2][3] * m.m[3][1]) *
	                 rectdeterminant;

	result.m[2][2] = (m.m[0][0] * m.m[1][1] * m.m[3][3] + m.m[0][1] * m.m[1][3] * m.m[3][0] +
	                  m.m[0][3] * m.m[1][0] * m.m[3][1] - m.m[0][3] * m.m[1][1] * m.m[3][0] -
	                  m.m[0][1] * m.m[1][0] * m.m[3][3] - m.m[0][0] * m.m[1][3] * m.m[3][1]) *
	                 rectdeterminant;

	result.m[2][3] = (-m.m[0][0] * m.m[1][1] * m.m[2][3] - m.m[0][1] * m.m[1][3] * m.m[2][0] -
	                  m.m[0][3] * m.m[1][0] * m.m[2][1] + m.m[0][3] * m.m[1][1] * m.m[2][0] +
	                  m.m[0][1] * m.m[1][0] * m.m[2][3] + m.m[0][0] * m.m[1][3] * m.m[2][1]) *
	                 rectdeterminant;

	/*
	// 3行列
	result.m[3][0] = (-m.m[1][0] * m.m[2][1] * m.m[3][2] - m.m[1][1] * m.m[2][2] * m.m[3][0] -
	                  m.m[1][2] * m.m[2][0] * m.m[3][1] + m.m[1][2] * m.m[2][1] * m.m[3][0] +
	                  m.m[1][1] * m.m[2][0] * m.m[3][2] + m.m[1][0] * m.m[2][2] * m.m[3][1]) *
	                 rectdeterminant;

	result.m[3][1] = (m.m[0][0] * m.m[2][1] * m.m[3][2] + m.m[0][1] * m.m[2][2] * m.m[3][0] +
	                  m.m[0][2] * m.m[2][0] * m.m[3][1] - m.m[0][2] * m.m[2][1] * m.m[3][0] -
	                  m.m[0][1] * m.m[2][0] * m.m[3][2] - m.m[0][0] * m.m[2][2] * m.m[3][1]) *
	                 rectdeterminant;

	result.m[3][2] = (-m.m[0][0] * m.m[1][1] * m.m[3][2] - m.m[0][1] * m.m[1][2] * m.m[3][0] -
	                  m.m[0][2] * m.m[1][0] * m.m[3][1] + m.m[0][2] * m.m[1][1] * m.m[3][0] +
	                  m.m[0][1] * m.m[1][0] * m.m[3][2] + m.m[0][0] * m.m[1][2] * m.m[3][1]) *
	                 rectdeterminant;

	result.m[3][3] = (m.m[0][0] * m.m[1][1] * m.m[2][2] + m.m[0][1] * m.m[1][2] * m.m[2][0] +
	                  m.m[0][2] * m.m[1][0] * m.m[2][1] - m.m[0][2] * m.m[1][1] * m.m[2][0] -
	                  m.m[0][1] * m.m[1][0] * m.m[2][2] - m.m[0][0] * m.m[1][2] * m.m[2][1]) *
	                 rectdeterminant;
					 */
	return result;
};

// スケーリング行列を宣言
Matrix3x3 matScale(const Vector2 scale) {
	Matrix3x3 result;
	result.m[0][0] = scale.x;
	result.m[1][1] = scale.y;
	//result.m[2][2] = 1.0f;
	return result;
}

Matrix3x3 matRotX(float rotation) {

	Matrix3x3 result;
	result.m[0][0] = 1.0f;
	result.m[1][1] = cos(rotation);
	//result.m[2][1] = sin(rotation);
	//result.m[1][2] = sin(rotation);
	//result.m[2][2] = cos(rotation);
	return result;
}

Matrix3x3 matRotY(float rotation) {

	Matrix3x3 result;
	result.m[0][0] = cos(rotation);
	result.m[1][1] = 1.0f;
	//result.m[0][2] = sin(rotation);
	//result.m[2][0] = sin(rotation);
	//result.m[2][2] = cos(rotation);
	return result;
}
Matrix3x3 matRotZ(float rotation) {
	Matrix3x3 result;

	result.m[0][0] = cos(rotation);
	result.m[1][0] = sin(rotation);
	result.m[0][1] = -sin(rotation);
	result.m[1][1] = cos(rotation);
	//result.m[2][2] = 1.0f;
	
	return result;
}

Matrix3x3 matRotXY(float rotationX, float rotationY) {

	Matrix3x3 rotateXmAtrix = matRotX(rotationX);
	Matrix3x3 rotateYmAtrix = matRotY(rotationY);
	
	Matrix3x3 matrotXYZ = Multiply(rotateXmAtrix, rotateYmAtrix);

	return matrotXYZ;
}

// 平行移動行列を宣言
Matrix4x4 matTrans(const Vector3 translation) {
	Matrix4x4 result;

	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;
	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;
	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;
	result.m[3][0] = translation.x;
	result.m[3][1] = translation.y;
	result.m[3][2] = translation.z;
	result.m[3][3] = 1.0f;

	return result;
}

Matrix3x3 MakeAffineMatrix(const Vector2& scale, const Vector2& rot) {

	Matrix3x3 result;

	Matrix3x3 scale_ = {0};
	scale_ = matScale(scale);

	Matrix3x3 rot_ = { 0 };
	rot_ = matRotXY(rot.x, rot.y);


	return result;
}

Vector2 TransformNomal(const Vector2& v, const Matrix3x3& m) {
	Vector2 result{
	    v.x * m.m[0][0] + v.y * m.m[1][0],
	    v.x * m.m[0][1] + v.y * m.m[1][1],
	};

	return result;
}

// 内積
float Dot(const Vector2& v1, const Vector2& v2) {
	float result;

	result = v1.x * v2.x + v1.y * v2.y;

	return result;
}

// 長さ
float Length(const Vector2& v) {
	float result;
	result = sqrt(Dot(v, v));
	return result;
}

// 正規化
Vector2 Nomalize(const Vector2& v) {
	Vector2 result;

	result.x = v.x / Length(v);
	result.y = v.y / Length(v);

	return result;
}




struct Player {
	Vector2 position
		= { 300,300 };
	int radius = 32;
	Vector2 speed;
	Vector2 progress;
	bool flag;
	int timer;
	//Vector2 GetWorldPosition();
	//Vector2 WorldTransform();
};

struct Mark
{
	Vector2 position;
	int radius;
	int speed;
	Vector2 progress;
	bool flag;
	int timer;
	//Vector2 GetWorldPosition();
};

/*
struct ReleaseMark {
	Vector2 position;
	int radius;
	int speed;
	Vector2 progress;
	bool flag;
	int timer;
	Vector2 GetWorldPosition();
};
*/
Matrix3x3 matWorld_;
WorldTransform worldtransform_;


Vector2 GetWorldPosition() {
	// ワールド座標を入れる変数
	Vector2 worldPos;
	// ワールド行列の平行移動成分を取得(ワールド座標)
	worldPos.x = worldtransform_.matWorld_.m[2][0];
	worldPos.y = worldtransform_.matWorld_.m[2][1];

	return worldPos;
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 800, 800);
	
	
	Player player =  Player();
	int kk = 0;
	int px = 0;
	int py = 0;


	Mark mark;
	mark.position = {500, 500};
	mark.radius = 16;
	mark.speed = 8;
	mark.flag = true;

	Vector2 objepos = {0};
	Vector2 mausepos = {0,0};

	int grahHandle = Novice::LoadTexture("./mark.png");
	
	int MauseX = 0;
	int MauseY = 0;

	int ReleaseMauseX = 0;
	int ReleaseMauseY = 0;

	int Fall = false;

// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		// 左上

		/*
		// 矢印回転
		 float theta = 0.0f;
		int scale = 1.0f;
		int speed = 0.01f;

		scale += speed;

		theta += 1.0f / 360.0f * 3.14f;

		if (kmax < scale) {

		    scale = kmax - (scale - kmax);

		    speed = -0.01;
		}


		else if (scale < kmax)
		{
		    scale = kmin - (scale - kmin);
		    speed = -0.01;
		}

		     Vector2 a =
		     {

		         mauseX * cosf(theta) - mauseX * sinf(theta) - mauseX * tanf(theta),
		         mauseY * cosf(theta) + mauseY * sinf(theta) + mauseY * tanf(theta)

		     };

		    a.x *= scale;
		    a.y *= scale;


		     Vector2 b = {mauseXX + a.x, mauseYY + a.y };

		     if (Novice::IsTriggerMouse(0))
		     {
		        mauseXX = mauseX;
		        mauseYY = mauseY;
		     }
	*/

		//マウスを離して飛ばす
		
		
		
		Fall = true;

		if (Novice::IsPressMouse(0))
		{
			Fall = false;
		}

		if (Fall == false)
		{
			if (Novice::IsPressMouse(0))
			{
				 px = 0;
				 py = 0;
				 
				 Vector2 MausePos(MauseX, MauseY);
				 Vector2 ReleaseMausePos(ReleaseMauseX, ReleaseMauseY);

				 MausePos = GetWorldPosition();
				 ReleaseMausePos = GetWorldPosition();

				 Vector2 Result =
				 {
					 MausePos.x - ReleaseMausePos.x,
					 MausePos.y - ReleaseMausePos.y

				 };
				
				 Vector2 ResultNomalize = Nomalize(Result);
				 Vector2 PlayerVelocity =
				 {
					ResultNomalize.x * player.speed.x,
					ResultNomalize.y * player.speed.y
				 };


				 player.position.x += PlayerVelocity.x;
				 player.position.y += PlayerVelocity.y;
			}
		}

		if (Fall == true)
		{
			px = MauseX;
			py = MauseY;
		    
			player.position.x;
			player.position.y;

		}
	
		
		Novice::GetMousePosition(&MauseX, &MauseY);



		Novice::GetMousePosition(&ReleaseMauseX, &ReleaseMauseY);





		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		
		Novice::ScreenPrintf(0, 20, "mauseX = %d", px);
		Novice::ScreenPrintf(0, 40, "mauseY = %d", py);


		//if (Novice::IsPressMouse(0))
		//{
		//
		//	Novice::DrawSprite(mauseXX, mauseYY, grahHandle,b.x ,b.y, 0.0f, WHITE);
		//
		//}
	
		Novice::DrawEllipse(player.position.x, player.position.y, player.radius, player.radius, 0.0f, RED, kFillModeSolid);
		

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
