#pragma once
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")
#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")

#include "../SwapChain/SwapChain.h"
#include "../DeviceContext/DeviceContext.h"
#include "../VertexBuffer/VertexBuffer.h"
#include "../Shaders/VertexShader.h"
#include "../Shaders/PixelShader.h"

class GraphicsEngine {
    public:
        GraphicsEngine();
        ~GraphicsEngine();
        bool init();
        bool release();
        static GraphicsEngine* get();

        SwapChain* createSwapChain();
        DeviceContext* getImmediateDeviceContext();

        VertexBuffer* createVertexBuffer();

        bool createShaders();
        bool setShaders();
        void getShaderBufferAndSize(void** bytecode, size_t* size);

        VertexShader* createVertexShader(const void* shader_byte_code, size_t byte_code_size);
        bool compileVertexShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_size, size_t* byte_code_size);
        PixelShader* createPixelShader(const void* shader_byte_code, size_t byte_code_size);
        bool compilePixelShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_size, size_t* byte_code_size);

        void releaseCompiledShader();
    private:
        ID3D11Device* m_d3d_device;
        D3D_FEATURE_LEVEL m_feature_level;
        ID3D11DeviceContext* m_imm_context;

        IDXGIDevice* m_dxgi_device;
        IDXGIAdapter* m_dxgi_adapter;
        IDXGIFactory* m_dxgi_factory;

        DeviceContext* m_imm_device_context;

        ID3DBlob* m_blob = nullptr;
        ID3DBlob* m_vsblob = nullptr;
        ID3DBlob* m_psblob = nullptr;
        ID3D11VertexShader* m_vs = nullptr;
        ID3D11PixelShader* m_ps = nullptr;

        friend class SwapChain;
        friend class VertexBuffer;
        friend class VertexShader;
        friend class PixelShader;
};