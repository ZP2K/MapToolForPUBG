#pragma once

class Ray
{
public:
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_dir;
	
	Ray() : m_pos(0, 0, 0), m_dir(0, 0, 1) {}
	Ray(D3DXVECTOR3 pos, D3DXVECTOR3 dir) :m_pos(pos), m_dir(dir) {}
	~Ray() {}

	static Ray RayAtViewSpace(int x, int y);
	static Ray RayAtWorldSpace(int x, int y);

	bool CalcIntersectSphere(BoundingSphere* pSphere);
	bool CalcIntersectTri(D3DXVECTOR3* pStart, float *distance);
};

 