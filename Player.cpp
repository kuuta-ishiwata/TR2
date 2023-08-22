#include "Player.h"
#include <assert.h>
#include <ImGuiManager.h>
#include "MATH.h"
#include "Mause.h"


void Player::Initialize(Model* model_, const Vector2 PlayerPosition)
{
	assert(model_);
	model_ = model_;


	worldtransform_.Initialize();
	
}

Vector2 Player::GetWorldPosition() {
	// ワールド座標を入れる変数
	Vector2 worldPos;
	// ワールド行列の平行移動成分を取得(ワールド座標)
	worldPos.x = worldtransform_.matWorld_.m[3][0];
	worldPos.y = worldtransform_.matWorld_.m[3][1];
	

	return worldPos;
}

void Shot(Vector2& position)
{




}

void Player::Update(Vector2& posiiton) 
{

	const float Playerspeed = 2.0f;

     Vector2 playervelocity(Playerspeed, Playerspeed);


	Player* Playerposition = new Player();

	Playerposition->Initialize(model_, posiiton);

	

}

void Player::Draw(const Vector2 position)
{ 
	
     Novice::DrawEllipse(position.x, position.y, 50, 50, 0.0f, RED, kFillModeSolid);

} 