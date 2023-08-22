#pragma once
#include "Model.h"
#include "PrimitiveDrawer.h"
#include "WorldTransform.h"
#include <Input.h>
#include <Novice.h>
#include <assert.h>


class ReleaseMause {

public:
	///< summary>
	/// 初期化
	///  </summary>
	void Initialize(Model* model, const Vector2& positon, Novice* Novice);

	///< summary>
	/// 更新
	///  </summary>
	void Update();

	void Release(Vector2& position);

	///< summary>
	// 描画
	///</summary>
	void Draw(const Vector2 position);

	Vector2 GetWorldPosition();

private:
	// ワールド変更データ
	WorldTransform worldtransform_;
	ViewProjection viewProjection_;
	// モデルのポインタ
	Model* model_ = nullptr;

	// テクスチャハンドル

	ReleaseMause* releasemause_ = nullptr;
	Input* input_ = nullptr;
};
