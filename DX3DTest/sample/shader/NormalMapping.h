#pragma once
#include "stdafx.h"

class NormalMapping : public IDisplayObject
{
private:
	LPD3DXMESH	 m_pMesh;
	LPD3DXEFFECT m_pEffect;
	LPDIRECT3DCUBETEXTURE9 m_pCubeTex;

public:
	~NormalMapping();

	// IDisplayObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
};