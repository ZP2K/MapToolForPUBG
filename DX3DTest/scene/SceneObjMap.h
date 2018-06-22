#pragma once

class ObjMap;
class Cubeman;

class SceneObjMap : public IScene
{
public:
	ObjMap *				m_pObjMap;
	Cubeman*				m_pCubeman;

	SceneObjMap();
	~SceneObjMap();
	// IScene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
};

