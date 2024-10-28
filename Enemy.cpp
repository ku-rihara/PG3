#include"Enemy.h"
#include <stdio.h>

void Enemy::Update() {

	if (time_ <= 2) {
		/// 接近フェーズ
		phase_ = Phase::APPROACH;

	}
	else if (time_ <= 4) {
		/// 攻撃フェーズ
		phase_ = Phase::ATTACK;

	}
	else {
		/// 離脱フェーズ
		phase_ = Phase::AECESSION;
	}

	// 前回のフェーズと異なる場合のみ実行
	if (phase_ != prePhase_) {
		(this->*spFuncTable_[static_cast<size_t>(phase_)])();
		prePhase_ = phase_; // 現在のフェーズを保存
	}

	time_ += 1.0f / 60.0f;
}

void Enemy::Approach() {
	printf("接近\n");
}
void Enemy::Attack() {
	printf("攻撃\n");
}
void Enemy::Aecession() {
	printf("離脱\n");
}

void (Enemy::* Enemy::spFuncTable_[])() = {
	&Enemy::Approach,/// 0
	&Enemy::Attack,/// 1
	&Enemy::Aecession,/// 2
};