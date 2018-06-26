#include "stdafx.h"
#include "BoxCollider.h"
#define CUBE_INDEX_SIZE 36
#define CUBE_VERTEX_SIZE 8

BoxCollider::BoxCollider(string name)
    : m_Parentname(name)
    , m_vExtent(0.0f, 0.0f, 0.0f)
    , m_color()
{
    //D3DXMatrixIdentity(&m_matWorld);
}

BoxCollider::~BoxCollider()
{
    //SAFE_RELEASE(m_pVB);
    //SAFE_RELEASE(m_pIB);
}

void BoxCollider::Init(const D3DXVECTOR3& min, const D3DXVECTOR3& max)
{
    m_vMax = max;
    m_vCenter = (min + max) * 0.5f;
    m_vExtent = max - m_vCenter;
    SetVertex(-m_vExtent, m_vExtent);
}

void BoxCollider::Update()
{
    m_matWorld = m_mTransform * m_mParentTransform;

    m_vCenter = D3DXVECTOR3(0, 0, 0);
    D3DXVec3TransformCoord(&m_vCenter, &m_vCenter, &m_matWorld);
    //ImGui::Text("%f %f %f", m_vExtent.x, m_vExtent.y, m_vExtent.z);
    ImGui::Text("%f %f %f", m_vCenter.x, m_vCenter.y, m_vCenter.z);
}

//ImGui::Text("%f %f %f", m_vertices[0].p.x, m_vertices[0].p.y, m_vertices[0].p.z);
//ImGui::Text("%f %f %f", m_vertices[1].p.x, m_vertices[1].p.y, m_vertices[1].p.z);
//ImGui::Text("%f %f %f", m_vertices[2].p.x, m_vertices[2].p.y, m_vertices[2].p.z);
//ImGui::Text("%f %f %f", m_vertices[3].p.x, m_vertices[3].p.y, m_vertices[3].p.z);
//ImGui::Text("%f %f %f", m_vertices[4].p.x, m_vertices[4].p.y, m_vertices[4].p.z);
//ImGui::Text("%f %f %f", m_vertices[5].p.x, m_vertices[5].p.y, m_vertices[5].p.z);
//ImGui::Text("%f %f %f", m_vertices[6].p.x, m_vertices[6].p.y, m_vertices[6].p.z);
//ImGui::Text("%f %f %f", m_vertices[7].p.x, m_vertices[7].p.y, m_vertices[7].p.z);
void BoxCollider::Render()
{

    vector<WORD> indices =
    {
        0, 1, 1, 2, 2, 3, 3, 0,
        4, 5, 5, 6, 6, 7, 7, 4,
        0, 4, 1, 5, 2, 6, 3, 7,
    };

    const auto pD = DX::GetDevice();
    pD->SetRenderState(D3DRS_LIGHTING, false);
    pD->SetTransform(D3DTS_WORLD, &m_matWorld);
    pD->SetTexture(0, nullptr);
    pD->SetFVF(VERTEX_PC::FVF);
    pD->DrawIndexedPrimitiveUP(D3DPT_LINELIST, 0, m_vertices.size(),
        indices.size() / 2, indices.data(), D3DFMT_INDEX16, m_vertices.data(),
        sizeof VERTEX_PC);
    pD->SetRenderState(D3DRS_LIGHTING, true);
}

void BoxCollider::SetVertex(const D3DXVECTOR3 & min, const D3DXVECTOR3 & max)
{
    m_vertices.resize(8);
    m_vertices[0] = VERTEX_PC(D3DXVECTOR3(min.x, min.y, min.z), D3DCOLOR_XRGB(0, 255, 0));
    m_vertices[1] = VERTEX_PC(D3DXVECTOR3(min.x, max.y, min.z), D3DCOLOR_XRGB(0, 255, 0));
    m_vertices[2] = VERTEX_PC(D3DXVECTOR3(max.x, max.y, min.z), D3DCOLOR_XRGB(0, 255, 0));
    m_vertices[3] = VERTEX_PC(D3DXVECTOR3(max.x, min.y, min.z), D3DCOLOR_XRGB(0, 255, 0));
    m_vertices[4] = VERTEX_PC(D3DXVECTOR3(min.x, min.y, max.z), D3DCOLOR_XRGB(0, 255, 0));
    m_vertices[5] = VERTEX_PC(D3DXVECTOR3(min.x, max.y, max.z), D3DCOLOR_XRGB(0, 255, 0));
    m_vertices[6] = VERTEX_PC(D3DXVECTOR3(max.x, max.y, max.z), D3DCOLOR_XRGB(0, 255, 0));
    m_vertices[7] = VERTEX_PC(D3DXVECTOR3(max.x, min.y, max.z), D3DCOLOR_XRGB(0, 255, 0));
}

void BoxCollider::SetMatrix(const D3DXMATRIXA16 & transform, const D3DXMATRIXA16 & parentTransform)
{
    m_mTransform = transform;
    m_mParentTransform = parentTransform;
}

//void BoxCollider::SetVertex(vector<VERTEX_PC>& vecVertexOut, vector<WORD>& vecIndexOut, vector<D3DXVECTOR3> vecPos)
//{
//    WORD g_aCubeIndex[24] = {
//        //0, 1, 2, 0, 2, 3,	// ��
//        //7, 6, 5, 7, 5, 4,	// ��
//        //4, 5, 1, 4, 1, 0,	// ��
//        //3, 2, 6, 3, 6, 7,	// ��
//        //1, 5, 6, 1, 6, 2,	// ��
//        //4, 0, 3, 4, 3, 7	// ��
//        0,1,1,2,2,3,3,0,
//        0,4,1,5,2,6,3,7,
//        4,7,7,6,6,5,5,4,
//    };
//    D3DCOLOR green = D3DCOLOR_XRGB(0, 255, 0);
//
//    vecVertexOut.push_back(VERTEX_PC(vecPos[0], green));
//    vecVertexOut.push_back(VERTEX_PC(vecPos[1], green));
//    vecVertexOut.push_back(VERTEX_PC(vecPos[2], green));
//    vecVertexOut.push_back(VERTEX_PC(vecPos[3], green));
//    vecVertexOut.push_back(VERTEX_PC(vecPos[4], green));
//    vecVertexOut.push_back(VERTEX_PC(vecPos[5], green));
//    vecVertexOut.push_back(VERTEX_PC(vecPos[6], green));
//    vecVertexOut.push_back(VERTEX_PC(vecPos[7], green));
//
//    for (size_t i = 0; i < CUBE_INDEX_SIZE; i++)
//    {
//        vecIndexOut.push_back(g_aCubeIndex[i]);
//    }
//}
//
//void BoxCollider::SetBuffer(LPDIRECT3DVERTEXBUFFER9 & pVb, LPDIRECT3DINDEXBUFFER9 & pIb, vector<VERTEX_PC>& vecVertex, vector<WORD>& vecIndex)
//{																						 //�ٷ��� pool���� ���ּ���
//    DX::GetDevice()->CreateVertexBuffer(vecVertex.size() * sizeof(VERTEX_PC), 0, VERTEX_PC::FVF, D3DPOOL_MANAGED, &pVb, NULL);
//
//    VERTEX_PC* pVertex;
//    pVb->Lock(0, 0, (LPVOID*)&pVertex, 0);
//    memcpy(pVertex, &vecVertex[0], vecVertex.size() * sizeof(VERTEX_PC));
//    pVb->Unlock();
//    vecVertex.clear();//�� �־��־����� �ʿ����.
//
//    DX::GetDevice()->CreateIndexBuffer(vecIndex.size() * sizeof(WORD), NULL, D3DFMT_INDEX16, D3DPOOL_MANAGED, &pIb, NULL);
//    WORD* pIndex;
//    pIb->Lock(0, 0, (LPVOID*)&pIndex, 0);
//    memcpy(pIndex, &vecIndex[0], vecIndex.size() * sizeof(WORD));
//    pIb->Unlock();
//    vecIndex.clear();
//}
//BoxCollider::BoxCollider()
//{
//    D3DXVECTOR3(0, 0, 0);
//    D3DXVECTOR3(5, 5, 5);
//}
//
//BoxCollider::~BoxCollider()
//{
//}
//
//void BoxCollider::Init()
//{
//    D3DXVECTOR3 min = m_min;
//    D3DXVECTOR3 max = m_max;
//
//    m_center = (min + max) * 0.5f;
//    m_vExtent = max - m_center;
//
//    m_vertices.resize(8);
//    m_vertices[0] = VERTEX_PC(D3DXVECTOR3(min.x, min.y, min.z), m_color);
//    m_vertices[1] = VERTEX_PC(D3DXVECTOR3(min.x, max.y, min.z), m_color);
//    m_vertices[2] = VERTEX_PC(D3DXVECTOR3(max.x, max.y, min.z), m_color);
//    m_vertices[3] = VERTEX_PC(D3DXVECTOR3(max.x, min.y, min.z), m_color);
//    m_vertices[4] = VERTEX_PC(D3DXVECTOR3(min.x, min.y, max.z), m_color);
//    m_vertices[5] = VERTEX_PC(D3DXVECTOR3(min.x, max.y, max.z), m_color);
//    m_vertices[6] = VERTEX_PC(D3DXVECTOR3(max.x, max.y, max.z), m_color);
//    m_vertices[7] = VERTEX_PC(D3DXVECTOR3(max.x, min.y, max.z), m_color);
//}
//
//void BoxCollider::Update()
//{
//}
//void BoxCollider::Render()
//{
//    if (!m_isRender) return;
//
//    const auto pD = DX::GetDevice();
//    pD->SetRenderState(D3DRS_LIGHTING, false);
//    pD->SetTransform(D3DTS_WORLD, &m_matWorld);
//    pD->SetTexture(0, nullptr);
//    pD->SetFVF(VERTEX_PC::FVF);
//    pD->DrawIndexedPrimitiveUP(D3DPT_LINELIST, 0, m_vertices.size(),
//        m_vertices.size() / 2, &m_vertices[0], D3DFMT_INDEX16,
//        &m_vertices[0], sizeof VERTEX_PC);
//}


