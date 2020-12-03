#pragma once
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

class QSGTexture;
class QQuickWindow;

namespace QQuickBgfx {
template<bgfx::RendererType::Enum T>
bgfx::Init init(void *windowHandle, void *context, const uint16_t width, const uint16_t height);

inline bool initialized()
{
    return bgfx::getInternalData()->context;
}

inline void frame()
{
    if (initialized())
    {
        bgfx::frame();
    }
}

template<bgfx::RendererType::Enum T>
QSGTexture *qsgTexture(void *texture, QQuickWindow *window, int w, int h);

}    // namespace QQuickBgfx
