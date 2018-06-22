#pragma once

class AseObject;
class Aura;

class AseUnit : public IUnitObject
{
public:
	ASE_SCENE	m_aseScene;
	AseObject*	m_pCurrentObj;
	AseObject*	m_pStandObj;
	AseObject*	m_pRunObj;

	AseUnit();
	virtual ~AseUnit();
	// IDisplayObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	void Load(OUT AseObject* &rootObj, LPCTSTR filepath, LPCTSTR filename);
	void SetCurrentObject(AseObject* pObj);
};

