#include "StdAfx.h"
#include "IObject.h"
#include "./manager/ObjectManager.h"

IObject::IObject()
	: m_nRefCount(1)
{
	ObjectManager::Get()->AddObject(this);
}

IObject::~IObject()
{
	ObjectManager::Get()->RemoveObject(this);
	assert(m_nRefCount <= 0 && "Release�� �̿��ؼ� ��ü�� �����ϼ���.");
}

void IObject::AddRef()
{
	++m_nRefCount;
}

void IObject::Release()
{
	--m_nRefCount;
	if (m_nRefCount <= 0)
	{
		delete this;
	}
}
