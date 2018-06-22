#pragma once

class TextureBlending : public IDisplayObject
{
private:
	vector<VERTEX_PCT> m_vecVertex;
	LPDIRECT3DTEXTURE9 m_pTex;
	LPDIRECT3DTEXTURE9 m_pTex1;
	
public:
	TextureBlending();
	~TextureBlending();

	// IDisplayObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
};

