#ifndef ENGINE_MESHCOLLIDER_H
#define ENGINE_MESHCOLLIDER_H

#include <glm/glm.hpp>

#include "Collider.h"

namespace Engine
{

    class MeshCollider : public Collider
    {
    public:
        MeshCollider(std::shared_ptr<GameObject> obj, std::shared_ptr<Input> input) : Collider(obj, input) { }
    };

}

#endif //ENGINE_MESHCOLLIDER_H