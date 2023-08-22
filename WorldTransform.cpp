#include "MATH.h"
#include <assert.h>
#include "WorldTransform.h"

void WorldTransform::UpdateMatrix() {

	// �X�P�[���A��]�A���s�ړ�
	matWorld_ = MakeAffineMatrix(scale_, rotation_, translation_);

	// �萔�o�b�t�@�ɓ]��
	TransferMatrix();

	if (parent_) {
		Multiply(matWorld_, parent_->matWorld_);
	}
}
