//-------------------------------------------------------------------------------------------

// 个人副本：XXX

//-------------------------------------------------------------------------------------------

#ifndef __SPECIAL_XXX_H__
#define __SPECIAL_XXX_H__

#include "scene/speciallogic/speciallogic.hpp"

class SpecialXxX: public SpecialLogic
{
public:
	SpecialXxX(Scene *scene);
	virtual ~SpecialXxX();

	virtual void OnRoleEnterScene(Role *role);
	virtual bool OnTimeout();
	virtual void Update(unsigned long interval, time_t now_second);

private:
	Role * GetOwnerRole();

	void OnFinish(bool is_pass);
	void SyncFBSceneLogicInfo(bool is_active_leave_fb = false);	// 发送副本信息

	virtual void OnAllMonsterDead();
	
	ObjID m_owner_objid;										// 副本拥有者对象ID
	UserID m_owner_user_id;										// 副本拥有者用户ID
	
	bool m_is_finish;											// 是否结束
	bool m_is_pass;												// 是否通关
};

#endif // __SPECIAL_DAILY_TASK_FB_H__