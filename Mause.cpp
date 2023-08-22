#include "Mause.h"
#include "MATH.h"
#include <assert.h>
#include "WorldTransform.h"
#include "Model.h"
#include"ReleaseMause.h"


void Mause::Initialize(Model* model, const Vector2& positon, Novice* Novice)
{

	assert(model);
	model_ = model;

	int positionX = 0;
	int positionY = 0;
	worldtransform_.Initialize();
 
	Novice::GetMousePosition(&positionX, &positionY);
	int grahHandle = Novice::LoadTexture("./mark.png");



}

Vector2 Mause::GetWorldPosition()
{

	// ワールド座標を入れる変数
	Vector2 worldPos;
	// ワールド行列の平行移動成分を取得(ワールド座標)

	worldPos.x = worldtransform_.matWorld_.m[3][0];
	worldPos.y = worldtransform_.matWorld_.m[3][1];

	return worldPos;

}


void Mause::Release(Vector2& position) { 
	
	
	
	Vector2 Mause =  mause_->GetWorldPosition();
	Vector2 ReleaseMause = GetWorldPosition();

	Vector2 Result = {
	    ReleaseMause.x - Mause.x, ReleaseMause.y - Mause.y

	};

	Vector2 ResultNomalize = Normalize(Result);

	ResultNomalize.x = position.x;
	ResultNomalize.y = position.y;

}

void Mause::Update()
{
	

}


void Draw(Vector2 position) {

	Model* model_ = nullptr;

	if (Novice::IsPressMouse(0)) {

		Novice::DrawBox(position.x, position.y, 50, 50, RED, 0.0f, kFillModeSolid);
	}


}
