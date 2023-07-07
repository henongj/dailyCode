#pragma once

#include"mesh.h"

class C_MESHMGR
{
private:
	C_MESH** m_ppBuffer;
	int m_nBufferLength;

public:
	C_MESHMGR() = default;
	void load();
	C_MESH* getMesh(int nMeshIndex);
	void clear();
};