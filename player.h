#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include <assert.h>
#include<Input.h>
#include<list>

class  Player {


public:

	//<summry>
	//初期化
	//<summry>

	void Initialize(Model* model, const Vector2 PlayerPosition );


	//<summry>
	// デストラクタ
	//<summry>

	~Player(){};
	//<summry>
	// 更新
	//<summry>
	void Update(Vector2& posiiton);


	//<summry>
	// 描画
	//<summry>

	void Draw(const Vector2 position);

	//<summry>
	// 攻撃
	//<summry>

	void Shot(Vector2& position);

	Vector2 GetWorldPosition();


private:

	WorldTransform worldtransform_;
	ViewProjection viewprojection_;

		
	// 速度
	Vector3 velocity_;

	// モデルのポインタ
	Model* model_ = nullptr;



};
