#pragma once

#include <vector>

namespace bmb
{

class Actor;
class IRenderable;

class RenderGroup
{
public:
    using RenderableContainer = std::vector< IRenderable* >;

    bool addUnique( IRenderable& renderable_ );

    RenderableContainer const& getRenderables() const {
        return _renderables;
    }
protected:
    RenderableContainer _renderables;
};

}