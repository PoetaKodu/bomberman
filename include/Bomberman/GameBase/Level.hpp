#pragma once

#include <memory>
#include <vector>

namespace bmb
{

class Actor;
class RenderGroup;

class Level
{
public:
    using ActorOwnPtr = std::shared_ptr< Actor >;
    using ActorUniquePtr = std::unique_ptr< Actor >;
    using ActorRawPtr = Actor*;
    using ActorContainer = std::vector< ActorOwnPtr >;
    using ActorRawContainer = std::vector< ActorRawPtr >;

    Actor& add( ActorUniquePtr actor_ );

    Actor& add( ActorUniquePtr actor_, RenderGroup* renderGroup_ );

    bool remove( Actor const& actor_ );

    bool contains( Actor const& actor_ ) const;

    ActorContainer const& getActors() const {
        return _actors;
    }

    ActorRawContainer getRawActors() const {
        return ActorRawContainer( _actors.begin(), _actors.end() );
    }

protected:

    ActorContainer _actors;
};

}