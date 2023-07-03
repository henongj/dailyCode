#include "mesh.h"
#include "dxFunc.h"

HRESULT C_MESH::load(const char* strFileName)
{
    UNREFERENCED_PARAMETER(strFileName);
	//파일로 부터 로드
    SimpleVertex vertices[] =
    {
        { XMFLOAT3(-1.0f, 1.0f, -1.0f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },
        { XMFLOAT3(1.0f, 1.0f, -1.0f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
        { XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f) },
        { XMFLOAT3(-1.0f, 1.0f, 1.0f), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f) },
        { XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f) },
        { XMFLOAT3(1.0f, -1.0f, -1.0f), XMFLOAT4(1.0f, 1.0f, 0.0f, 1.0f) },
        { XMFLOAT3(1.0f, -1.0f, 1.0f), XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f) },
        { XMFLOAT3(-1.0f, -1.0f, 1.0f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) },
    };
    WORD indices[] =
    {
        3,1,0,        2,1,3,
        0,5,4,        1,5,0,
        3,4,7,        0,4,3,
        1,6,5,        2,6,1,
        2,7,6,        3,7,2,
        6,4,5,        7,4,6,
    };

    m_iStride = sizeof(SimpleVertex);
    if (FAILED(C_DXFUNC::createBuffer(sizeof(SimpleVertex) * 8, D3D11_BIND_VERTEX_BUFFER, vertices, &g_pVertexBuffer)))
        return S_FALSE;

    if (FAILED(C_DXFUNC::createBuffer(sizeof(WORD) * 36, D3D11_BIND_INDEX_BUFFER, indices, &g_pIndexBuffer)))
        return S_FALSE;

    m_Indexformat = DXGI_FORMAT_R16_UINT;

    return S_OK;
}

ID3D11Buffer* const* C_MESH::getVertexBuffer()
{
    return &g_pVertexBuffer;
}

ID3D11Buffer* C_MESH::getIndexBuffer()
{
    return g_pIndexBuffer;
}

const UINT* C_MESH::getStride()
{
    return &m_iStride;
}

DXGI_FORMAT C_MESH::getIndexFormat()
{
    return m_Indexformat;
}

void C_MESH::release()
{
    if (g_pVertexBuffer) g_pVertexBuffer->Release();
    if (g_pIndexBuffer) g_pIndexBuffer->Release();
}
