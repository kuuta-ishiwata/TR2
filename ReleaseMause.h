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
	/// ������
	///  </summary>
	void Initialize(Model* model, const Vector2& positon, Novice* Novice);

	///< summary>
	/// �X�V
	///  </summary>
	void Update();

	void Release(Vector2& position);

	///< summary>
	// �`��
	///</summary>
	void Draw(const Vector2 position);

	Vector2 GetWorldPosition();

private:
	// ���[���h�ύX�f�[�^
	WorldTransform worldtransform_;
	ViewProjection viewProjection_;
	// ���f���̃|�C���^
	Model* model_ = nullptr;

	// �e�N�X�`���n���h��

	ReleaseMause* releasemause_ = nullptr;
	Input* input_ = nullptr;
};
