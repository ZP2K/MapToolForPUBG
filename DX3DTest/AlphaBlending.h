#pragma once

class AlphaBlending : public IDisplayObject
{
private:
	vector<VERTEX_PC> m_vecVertex;
	vector<VERTEX_PC> m_vecVertex1;
	
public:
	AlphaBlending();
	~AlphaBlending();

	// IDisplayObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
};

