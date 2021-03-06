#pragma once

class HeightMap :	public IMap
{
protected:
	LPD3DXMESH	m_pMesh;
	MTLTEX*		m_pMtlTex;
	
	vector<D3DXVECTOR3>	m_vecSurfaceVertex;
	//vector<D3DXVECTOR3>	m_vecObstacleVertex;

public:
	HeightMap();
	virtual ~HeightMap();

	void Load(LPCTSTR fullPath, D3DXMATRIXA16 * pMat = NULL);
	void SetMtlTex(D3DMATERIAL9 &Mtl, LPDIRECT3DTEXTURE9 pTex);

	// IMap을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual bool GetHeight(OUT float & height, const D3DXVECTOR3 & pos) override;
	virtual bool CalcPickedPosition(D3DXVECTOR3 &vOut, WORD screenX, WORD screenY) override;
	
	void SetSurface();
	//void SetObstacle();
	
};


/*
파일 정보 읽기
fopen_s(&fp, szFullPath, "rb");
y = (unsigned char)fgetc(fp)

하이트맵 사이즈 257 * 257

버텍스의 갯수 257 * 257
타일의 갯수 256 * 256

1. 버텍스 좌표 설정(노말은 0, 1, 0)
인덱스 번호 = z * 257 + x
y = 색정보 / 10.0f; 분모로 높이 조절

2. 인덱스 구성(시계방향)
1--3	0 = z * 257 + x
|\ |	1 = (z + 1) * 257 + x
| \|	2 = z * 257 + x + 1
0--2	3 = (z + 1) * 257 + x + 1

3. 노말값 셋팅
---u---
|\ |\ |
| \| \|
l--n--r
|\ |\ |
| \| \|
---d---

du 벡터와 lr 벡터를 외적해서
n위치의 노말 값을 구한다.

4. 메쉬를 생성(최적화까지)

5. MtlTex 정보 셋팅

== == == == == == == == == == == == == == == == == == ==
GetHeight 함수
캐릭터의 높이 설정
1. 기준 페이스 선택
1--3	0의 x y 좌표 찾기
|\ |	x = (int)위치x
| \|	y = (int)위치y
0--2	deltaX = 위치x - x
deltaY = 위치y - y

deltaX + deltaY <  1 : 아래쪽 삼각형
deltaX + deltaY	>= 1 : 위쪽 삼각형

2. 실제 높이 계산하기

1--3	두 점 사이의 높이 차이 계산
|\ |	아래쪽 삼각형일 경우 : 0 + 높이차이 * 델타값
| \|	위쪽 삼각형일 경우 : 3 + 높이차이 * 델타값
0--2
*/
