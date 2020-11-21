// Implementation of public API.
// All symbols with Tri_ prefix are internal.

#include "tri.h"

#include "internal/context.h"
#include "internal/renderer.h"
#include "internal/renderBufferCpu.h"
#include "internal/renderBufferCuda.h"

#include <cassert>

TriStatus
TriContextCreatePreferred(TriContext& context)
{
    TriDevice device = Tri_SelectPreferredDevice();
    return Tri_ContextCreate(context, device);
}

TriStatus
TriContextCreate(TriContext& context, TriDevice requestedDevice)
{
    // Check for device availability.
    if (requestedDevice == TriDevice_CUDA && !Tri_IsCUDASupported()) {
        return TriStatus_UnsupportedDevice;
    }

    return Tri_ContextCreate(context, requestedDevice);
}

TriStatus
TriContextDestroy(TriContext& context)
{
    return Tri_ContextDestroy(context);
}

TriStatus
TriContextGetDevice(const TriContext& context, TriDevice& device)
{
    Tri_Context* ctx = Tri_ContextGet(context.id);
    if (ctx == nullptr) {
        return TriStatus_ObjectNotFound;
    }

    device = ctx->device;
    return TriStatus_Success;
}

TriStatus
TriRenderBuffersCreate(TriRenderBuffers& buffers,
                       const TriContext& context,
                       int width,
                       int height)
{
    Tri_Context* ctx = Tri_ContextGet(context.id);
    if (ctx == nullptr) {
        return TriStatus_ObjectNotFound;
    }

    if (ctx->device == TriDevice_CPU) {
        return Tri_RenderBuffersCreateCPU(buffers, width, height);
    } else {
        assert(ctx->device == TriDevice_CUDA);
        return Tri_RenderBuffersCreateCUDA(buffers, width, height);
    }
}

TriStatus
TriRenderBuffersDestroy(TriRenderBuffers& buffers)
{
    return TriStatus_Success;
}

TriStatus
TriRendererCreate(TriRenderer& renderer, const TriContext& context)
{
    Tri_Context* ctx = Tri_ContextGet(context.id);
    if (ctx == nullptr) {
        return TriStatus_ObjectNotFound;
    }

    return Tri_RendererCreate( renderer, ctx );
}

TriStatus
TriRendererDestroy(TriRenderer& renderer)
{
    return TriStatus_Success;
}
