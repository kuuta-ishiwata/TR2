#include "MATH.h"
#include "Mause.h"
#include "Model.h"
#include "WorldTransform.h"
#include <assert.h>
#include "ReleaseMause.h"


void ReleaseMause::Initialize(Model* model, const Vector2& positon, Novice* Novice) {

	assert(model);
	model_ = model;

	int ReleasepositionX = 0;
	int ReleasepositionY = 0;
	worldtransform_.Initialize();

	Novice::GetMousePosition(&ReleasepositionX, &ReleasepositionY);


}

Vector2 ReleaseMause::GetWorldPosition() {

	// ���[���h���W������ϐ�
	Vector2 worldPos;
	// ���[���h�s��̕��s�ړ��������擾(���[���h���W)

	worldPos.x = worldtransform_.matWorld_.m[3][0];
	worldPos.y = worldtransform_.matWorld_.m[3][1];

	return worldPos;

}

void ReleaseMause::Release(Vector2& position)
{

    Vector2 ReleaseMause = releasemause_->GetWorldPosition();
	Vector2 mausePos = GetWorldPosition();

	Vector2 Result = 
	{
	    ReleaseMause.x - mausePos.x, ReleaseMause.y - mausePos.y

	};

	Vector2 ResultNomalize = Normalize(Result);

}


void ReleaseMause::Update()
{

	


}

void Draw(const Vector2 position) { 
	
	Model* model_ = nullptr; 

}
