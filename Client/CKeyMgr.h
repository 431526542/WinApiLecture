#pragma once

//1. 프레임 동기화
//동일 프레임 내에서 같은 키에 대해, 동일한 이벤트를 가져간다.

//2. 키 입력 이벤트 처리
//tap, hold, away

enum class KEY_STATE
{
	NONE,
	TAP,
	HOLD,
	AWAY,
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,

	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	Z,
	X,
	C,
	V,
	B,
	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LBTN,
	RBTN,

	last,

};

struct tKeyInfo
{
	KEY_STATE eState;
	bool	bPrevPush;
};

class CKeyMgr
{
	SINGLE(CKeyMgr);

private:
	vector<tKeyInfo> m_vecKey;

	Vec2			 m_vCurMousePos;

public:
	void init();
	void update();

public:
	KEY_STATE GetKeyState(KEY _eKey) 
	{
		return m_vecKey[(int)_eKey].eState;
	}
	Vec2 GetMousePos()
	{
		return m_vCurMousePos;
	}
};

