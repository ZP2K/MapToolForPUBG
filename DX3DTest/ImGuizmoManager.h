#pragma once
#include "ImGuizmo.h"
//#include <fstream>
class IDisplayObject;
class Camera;
class BoxCollider;

enum ObjList {
    BANDAGE,
    CHURCH,
    //TREE,
    //ROCK,
    //WAREHOUSE,
    COUNT
};
///���⿡ add �Ҷ�, �Ʒ��� ***count ���� ������ ���ְ� init���� 0���� �ֱ�ȭ
//ComboObjectList[] �ʾ��ֱ� 
//ContainObject �߰��� �ֱ�
///ObjectLoader(int index) switch �� �߰����ֱ�
///Open Scene �ٲپ� �ֱ� 
///+ Init() �ʱ�ȭ �Ҷ��� switch ���� �־��ֱ� (�̺κ��� ���� ���߰� �ϱ� ���ؼ� ���� �ڵ�)
struct ObjInfo 
{
    int                 ID;
    ObjList             list;
    string              m_ObjName;
    D3DXVECTOR3         m_Position;
    D3DXVECTOR3         m_Rotation;
    D3DXVECTOR3         m_Scale;
    D3DXMATRIXA16       m_matTransform;
    IDisplayObject*     objPtr;
    vector<BoxCollider*> m_vecBoxCollider;
    
    ObjInfo()
        :  m_Position(0.0f, 0.0f, 0.0f), 
           m_Rotation(0.0f, 0.0f, 0.0f), 
           m_Scale(1.0f, 1.0f, 1.0f)
    {
        D3DXMatrixIdentity(&m_matTransform);
    }
    ObjInfo(int id, ObjList _list)
        : ObjInfo()
    {
        ID = id;
        list = _list;
    }

};

class ImGuizmoManager 
{
public:
    string m_currentSceneName;
    Camera* m_pCamera;

    //IDisplayObject* m_pBoxCollider;

    vector<IDisplayObject*> m_vecObjectContainer;   //contains Displayable Objects
    map<ObjList, int> m_mapCount;                   //contains number of Objects
    map<string, ObjInfo*> m_mapObject;
    //vector<> m_vecSavedScene;
    ObjInfo* m_pCurrentObject;
    
    LPDIRECT3DTEXTURE9 m_pButtonTexture_Handle;
    LPDIRECT3DTEXTURE9 m_pButtonTexture_Translation;
    LPDIRECT3DTEXTURE9 m_pButtonTexture_Rotation;
    LPDIRECT3DTEXTURE9 m_pButtonTexture_Scale;

    ImGuizmo::OPERATION mCurrentGizmoOperation;
    ImGuizmo::MODE mCurrentGizmoMode;

    int hierarchySelectedObjIndex;  //Hierarchy obj tab
    int hierarchySelectedColliderIndex;  //Hierarchy obj tab
    int comboSelect;
    //int bandageCount;
    //int churchCount;
    //int treeCount;
    //int rockCount;
    //int wareHouseCount;

    bool isRenderCollider;

    // Camera view & projection
    bool isPerspective;
    float viewWidth;
    float cameraProjection[16];
    float cameraView[16];
    float objectMatrix[16];

public:
    ImGuizmoManager();
    ~ImGuizmoManager();

    void Init();
    void Update();
    void Render();

    void SetCurrentObject(ObjInfo* obj)
    {
        m_pCurrentObject = obj;
        //resetting the position to origin
        MatChangeDX2Float(objectMatrix, &m_pCurrentObject->m_matTransform);
    }

    void MenuBarImGui();
    void HierarchyImGui();
    void LoadObjectImGui();
    void InspectorImGui();

    void NewScene();
    void OpenScene(string& fileName );
    void SaveScene(string& fileName );
    void ContainObject();
    void EditTransform(const float *cameraView, float *cameraProjection, float* matrix);
    void ObjectLoader(int index);
    void AddBoxCollider();
    void DeleteObject();

    void MouseHandleMove();
    void MatChangeDX2Float(OUT float * m16, IN D3DXMATRIXA16 * mat);
    void MatChangeFloat2DX(OUT D3DXMATRIXA16 * mat, IN float * m16);
};

