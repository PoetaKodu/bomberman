#pragma once

namespace sf {
class RenderTarget;
}

namespace bmb
{

class IRendereble {
public:
    virtual void render(sf::RenderTarget& rt_) {}
};

}