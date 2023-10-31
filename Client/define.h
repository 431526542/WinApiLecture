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
	TILE,
	PLAYER,
	MONSTER,
	PROJ_PLAYER,
	PROJ_MONSTER,

	UI = 31, 
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
#define KEY_HOLD(key) KEY_CHECK(key,KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key,KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key,KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key,KEY_STATE::NONE)
#define MOUSE_POS CKeyMgr::GetInst()->GetMousePos()

//PI
#define PI 3.1415926535f

#define TILE_SIZE 64


//자주사용하는 브러시 밑 펜
enum class BRUSH_TYPE
{
	HOLLOW,
	END,
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END,
};

//이벤트메니져
enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,



	END,
};

//오브젝트 클론함수
#define CLONE(type) type* Clone() {return new type(*this);}