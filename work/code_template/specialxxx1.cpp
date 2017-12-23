#include "specialxxx.hpp"
#include "gamecommon.h"
#include "protocal/msgfb.h"

SpecialXxX::SpecialXxX(Scene *scene) : SpecialLogic(scene), 
	m_owner_objid(INVALID_OBJ_ID), m_owner_user_id(INVALID_USER_ID), 
	m_is_finish(false), m_is_pass(false)
{
}

SpecialXxX::~SpecialXxX()
{
}

void SpecialXxX::Update(unsigned long interval, time_t now_second)
{
	SpecialLogic::Update(interval, now_second);

	if (m_is_finish || INVALID_USER_ID == m_owner_user_id) return;

	this->CheckSceneMonsterStatus(interval, now_second);
}

void SpecialXxX::OnRoleEnterScene(Role *role)
{
	if (m_is_finish)
	{
		this->DelayKickOutRole(role, CHANGE_SCENE_REASON_FB_FINISH);
	}
	else
	{
		bool is_first_enter = (INVALID_USER_ID == m_owner_user_id);
		if (is_first_enter)
		{
			
		}

		m_owner_user_id = role->GetUserId();
		m_owner_objid = role->GetId();
		this->SyncFBSceneLogicInfo();
	}
}

bool SpecialXxX::OnTimeout()
{
	this->KillAllMonster();
	this->OnFinish(false);

	return m_is_pass;
}

Role * SpecialXxX::GetOwnerRole()
{
	Obj *obj = m_scene->GetObj(m_owner_objid);
	if (NULL != obj && Obj::OBJ_TYPE_ROLE == obj->GetObjType())
	{
		Role *role = (Role*)obj;
		if (m_owner_user_id == role->GetUserId()) 
		{
			return role;
		}
	}

	return NULL;
}

void SpecialXxX::OnAllMonsterDead()
{
	
}

void SpecialXxX::OnFinish(bool is_pass)
{
	if (!m_is_finish)
	{
		m_is_finish = true;
		m_is_pass = is_pass;

		Role *role = this->GetOwnerRole();
		if (NULL != role)
		{
			if (m_is_pass)
			{
				role->Recover();
			}
		}

		this->SyncFBSceneLogicInfo();
	}
}

void SpecialXxX::SyncFBSceneLogicInfo(bool is_active_leave_fb)
{
	Role *role = this->GetOwnerRole();
	if (!role) return;
	
	using namespace Protocol;
	sc_fb_common_info.reset();

	sc_fb_common_info.time_out_stamp = m_scene->GetSceneTimeOutStamp();
	sc_fb_common_info.scene_type = this->GetSceneType();

	sc_fb_common_info.is_finish = m_is_finish ? 1 : 0;
	sc_fb_common_info.is_pass = m_is_pass ? 1 : 0;
	sc_fb_common_info.is_active_leave_fb = is_active_leave_fb ? 1 : 0;

	sc_fb_common_info.total_boss_num = 0;
	sc_fb_common_info.total_allmonster_num = 0;
	sc_fb_common_info.kill_boss_num = 0;
	sc_fb_common_info.kill_allmonster_num = 0;

	sc_fb_common_info.pass_time_s = this->GetPassTime();

	sc_fb_common_info.coin = 0;
	sc_fb_common_info.exp = 0;

	sc_fb_common_info.param1 = 0;
	sc_fb_common_info.param2 = 0;
	sc_fb_common_info.param3 = 0;

	EngineAdapter::Instance().NetSend(role->GetNetId(), (const char*)&sc_fb_common_info, sizeof(sc_fb_common_info));
}