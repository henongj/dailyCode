#pragma once

class C20230404_SKILLMOTION;
class C20230404_SOUND;
class C20230404_EFFECT;
class C20230404_DAMAGE;
class C20230404_VOICE;

class C20230404_SKILL_SLOT;

__interface I20230404_factory_attack
{
public:
	void init(void);
	void release(void);
	void update(void);
	
	virtual void setSkillMotion(C20230404_SKILLMOTION* pSkillMotion) abstract;
	virtual void setSound(C20230404_SOUND* pSound) abstract;
	virtual void setEffect(C20230404_EFFECT* pEffect) abstract;
	virtual void setDamage(C20230404_DAMAGE* pDamage) abstract;
	virtual void setVoice(C20230404_VOICE* pVoice) abstract;
	virtual void setSkillSlot(C20230404_SKILL_SLOT* pSkillSlot) abstract;
	
	virtual C20230404_SKILLMOTION* getSkillMotion(void) abstract;
	virtual C20230404_SOUND* getSound(void) abstract;
	virtual C20230404_EFFECT* getEffect(void) abstract;
	virtual C20230404_DAMAGE* getDamage(void) abstract;
	virtual C20230404_VOICE* getVoice(void) abstract;
	virtual C20230404_SKILL_SLOT* getSkillSlot(void) abstract;

	virtual void createSkillMotion(void) abstract;
	virtual void createSound(void) abstract;
	virtual void createEffect(void) abstract;
	virtual void createDamage(void) abstract;
	virtual void createVoice(void) abstract;
	virtual void createSkillSlot(void) abstract;
};


//공격 : 사운드, 보이스, 슬롯
//슬롯 : 스킬모션, 이펙트, 데미지
class C20230404_factory_attack abstract : public I20230404_factory_attack
{
private:
	C20230404_SKILLMOTION* m_pSkillMotion;
	C20230404_SOUND* m_pSound;
	C20230404_EFFECT* m_pEffect;
	C20230404_DAMAGE* m_pDamage;
	C20230404_VOICE* m_pVoice;

	C20230404_SKILL_SLOT* m_pSkillSlot;

public:
	C20230404_factory_attack() = default;
	virtual ~C20230404_factory_attack() = default;

	
};
	
