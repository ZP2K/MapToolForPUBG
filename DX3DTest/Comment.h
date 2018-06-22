#pragma once
/*
typedef enum {
	//���� ���ʸ� ������, ������ ���� ������ ���� �����Ѵ�.
	D3DXMESHOPT_COMPACT = 0x01000000, 

	//�Ӽ� ���� ������Ʈ�� ������ �ٿ�, ID3DXBaseMesh::DrawSubset �� �����ս��� 
	//�ø���(����)������, ���� ���ʸ� ������ ����ȭ�� �ǽ��Ѵ�.
	D3DXMESHOPT_ATTRSORT = 0x02000000, 

	//���� ���ʸ� ������, ���� ĳ���� ĳ�� ��Ʈ���� ����Ų��.
	D3DXMESHOPT_VERTEXCACHE = 0x04000000,
	
	//���� ���ʸ� ������, �����ϴ� �ﰢ���� ���̸� �ִ�� �Ѵ�.
	D3DXMESHOPT_STRIPREORDER = 0x08000000,

	//�鸸�� ����ȭ��, ������ ����ȭ���� �ʴ´�.
	D3DXMESHOPT_IGNOREVERTS = 0x10000000,

	//�Ӽ��� ��Ʈ�߿�, �Ӽ� �׷찣�� �����ϰ� �ִ� ������ �������� �ʴ´�.
	D3DXMESHOPT_DONOTSPLIT = 0x20000000,

	//���� ĳ���� ����� ������ �ش�. �� �÷��׸� ����ϸ� 
	//������ �ϵ����� ���� ���� ����ϴ� ����Ʈ�� ���� ĳ�� ����� �����ȴ�.
	D3DXMESHOPT_DEVICEINDEPENDENT = 0x40000000
} D3DXMESHOPT;

//����ȭ �÷����� D3DXMESHOPT_STRIPREORDER �� D3DXMESHOPT_VERTEXCACHE �� ���� ���� ��Ÿ���̴�.
*/

//////////
//FVF
//////////
//	1. Position ������ ��ǥ x,y,z(float)				: D3DFVF_XYZ
// 	2. RHW (float)                                  : D3DFVF_XYZRHW (D3DFVF_XYZ �Ǵ� D3DFVF_NORMAL�� ���� ���Ұ�)
// 	3. Blending Weight Data ���� ����ġ (float)		: D3DFVF_XYZB1 ~ D3DFVF_XYZB5
// 	4. Vertex Normal ������ ���� ���� x,y,z(float)	: D3DFVF_NORMAL
// 	5. Vertex Point Size ������ �� ũ�� (float)		: D3DFVF_PSIZE
// 	6. Diffuse Color (DWORD)						: D3DFVF_DIFFUSE
// 	7. Specular Color (DWORD)						: D3DFVF_SPECULAR
// 	8. Texture Coordinate Set 1 (float)             : D3DFVF_TEX0 - D3DFVF_TEX8


//////////
//RENDER STATE
//////////
/*
DX::GetDevice()->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
DX::GetDevice()->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);

DX::GetDevice()->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
DX::GetDevice()->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
DX::GetDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

DX::GetDevice()->SetRenderState(D3DRS_ZENABLE, true);

DX::GetDevice()->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
*/