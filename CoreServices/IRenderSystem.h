#pragma once

/*!\brief Interface for a system who wants to be the renderer*/
class IRenderSystem {
public:
    virtual void render() = 0;
};

