#pragma once

class SceneGrid : public IScene
{
public:
	SceneGrid();
	~SceneGrid();

	// IScene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetLight();
};

