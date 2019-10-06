#include <Bomberman/GameBase/RenderGroup.hpp>

#include <algorithm>

namespace bmb
{

/////////////////////////////////////////////////////////////////
bool RenderGroup::addUnique( IRenderable& renderable_ )
{
    auto it = std::find( _renderables.begin(), _renderables.end(), &renderable_ );

    if (it != _renderables.end())
        return false;

    _renderables.push_back( &renderable_ );
}


}