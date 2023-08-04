#pragma once

//SINGLE Macros
#define	SINGLE(type)					\
		public:							\
				static type* GetInst()	\
				{						\
					static type mgr;	\
					return &mgr;		\
				}						\
		private:						\
				type();					\
				~type();


//Get DeltaTimer in CTimeMgr
#define fDT CTimeMgr::GetInst()->GetfDT()
#define DT	CTimeMgr::GetInst()->GetDT()

//Scene
enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MISSILE,
	MONSTER,


	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,


	END,
};
				
//Key 
#define KEY_CHECK(key,state) CKeyMgr::GetInst()->GetKeyState(key) == state
#define KEY_HOLE(key) KEY_CHECK(key,KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key,KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key,KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key,KEY_STATE::NONE)

//PI
#define PI 3.1415926535f