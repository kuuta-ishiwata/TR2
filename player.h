#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include <assert.h>
#include<Input.h>
#include<list>

class  Player {


public:

	//<summry>
	//������
	//<summry>

	void Initialize(Model* model, const Vector2 PlayerPosition );


	//<summry>
	// �f�X�g���N�^
	//<summry>

	~Player(){};
	//<summry>
	// �X�V
	//<summry>
	void Update(Vector2& posiiton);


	//<summry>
	// �`��
	//<summry>

	void Draw(const Vector2 position);

	//<summry>
	// �U��
	//<summry>

	void Shot(Vector2& position);

	Vector2 GetWorldPosition();


private:

	WorldTransform worldtransform_;
	ViewProjection viewprojection_;

		
	// ���x
	Vector3 velocity_;

	// ���f���̃|�C���^
	Model* model_ = nullptr;



};
