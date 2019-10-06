#include <Bomberman/GameBase/Level.hpp>

#include <Bomberman/GameBase/Actor.hpp>
#include <Bomberman/GameBase/RenderGroup.hpp>

#include <algorithm>

namespace bmb
{

//////////////////////////////////////////////////////
Actor& Level::add( ActorUniquePtr actor_ )
{
    return this->add( std::move(actor_), _defaultRenderGroup );
}

//////////////////////////////////////////////////////
Actor& Level::add( ActorUniquePtr actor_, RenderGroup* renderGroup_ )
{
    Actor& ref = *actor_;
    _actors.push_back( std::move( actor_ ) );

    if (renderGroup_) {
        renderGroup_->addUnique(actor_);
    }

    return ref;
}

//////////////////////////////////////////////////////
bool Level::remove( Actor const& actor_ )
{
    auto it = std::find_if( _actors.begin(), _actors.end(),
            [&actor_]( std::shared_ptr<Actor> const& el )
            {
                return el.get() == &actor_;
            }
        );

    if (it != _actors.end())
    {
        _actors.erase(it);
        return true;
    }
    return false;
}

//////////////////////////////////////////////////////
bool Level::contains( Actor const& actor_ ) const
{
    return std::find_if( _actors.begin(), _actors.end(),
            [&actor_]( std::shared_ptr<Actor> const& el )
            {
                return el.get() == &actor_;
            }
        ) != _actors.end();
}

}