#pragma once

class SceneTest : public IScene
{
public:
	LPDIRECT3DCUBETEXTURE9 m_pCubemap;

	SceneTest();
	~SceneTest();

	// IScene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
};

