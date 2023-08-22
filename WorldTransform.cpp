#include "MATH.h"
#include <assert.h>
#include "WorldTransform.h"

void WorldTransform::UpdateMatrix() {

	// スケール、回転、平行移動
	matWorld_ = MakeAffineMatrix(scale_, rotation_, translation_);

	// 定数バッファに転送
	TransferMatrix();

	if (parent_) {
		Multiply(matWorld_, parent_->matWorld_);
	}
}
