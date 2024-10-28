#pragma once

/// <summary>
/// エネミークラス
/// </summary>
class Enemy {
private:///enum
	enum class Phase {
		APPROACH,
		ATTACK,
		AECESSION,
		NONE,
	};

private:/// メンバ変数

	Phase phase_;/// フェーズ
	Phase prePhase_=Phase::NONE;/// 前のフェーズ

	Enemy* phaseFunc_;/// 敵の移動パターンの関数ポインタ

	float time_;/// 時間

public:/// public関数

	void Update();/// 更新

	void Approach();/// 接近
	void Attack();/// 攻撃
	void Aecession();/// 離脱

private:/// private関数

	/// メンバ関数のポインタテーブル
	static void (Enemy::* spFuncTable_[])();
};