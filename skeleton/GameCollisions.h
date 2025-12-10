#pragma once
#include <PxPhysicsAPI.h>
#include "CollisionLayers.h"
#include "GameSolids.h"

using namespace physx;

class GameCollisions : public PxSimulationEventCallback
{
    void onContact(PxContactPairHeader const& pairHeader,
        PxContactPair const* pairs, PxU32 nbPairs) override
    {
        for (PxU32 i = 0; i < nbPairs; i++)
        {
            const PxContactPair& cp = pairs[i];

            PxShape* a = cp.shapes[0];
            PxShape* b = cp.shapes[1];

            PxFilterData fa = a->getSimulationFilterData();
            PxFilterData fb = b->getSimulationFilterData();

            if ((fa.word0 & LAYER_BULLET) != 0 && (fb.word0 & LAYER_ENEMY) != 0 ||
                (fb.word0 & LAYER_BULLET) != 0 && (fa.word0 & LAYER_ENEMY) != 0 ||
                (fa.word0 & LAYER_FLOOR) != 0 && (fb.word0 & LAYER_ENEMY) != 0 ||
                (fb.word0 & LAYER_FLOOR) != 0 && (fa.word0 & LAYER_ENEMY) != 0)
            {
                PxRigidActor* enemyActor;

                if ((fa.word0 & LAYER_ENEMY) != 0)
                    enemyActor = pairHeader.actors[0];
                else
                    enemyActor = pairHeader.actors[1];

                Enemy* enemy = reinterpret_cast<Enemy*>(enemyActor->userData);

                //MATA AL ENEMIGO Y BÁÑATE EN SU SANGRE
            }

            if ((fa.word0 & LAYER_BULLET) != 0 && (fb.word0 & LAYER_BARREL) != 0 ||
                (fb.word0 & LAYER_BULLET) != 0 && (fa.word0 & LAYER_BARREL) != 0)
            {
                PxRigidActor* barrelActor;

                if ((fa.word0 & LAYER_BARREL) != 0)
                    barrelActor = pairHeader.actors[0];
                else
                    barrelActor = pairHeader.actors[1];

                Barrel* barrel = reinterpret_cast<Barrel*>(barrelActor->userData);

                //EXPLOSION
            }
        }
    }

    void onTrigger(PxTriggerPair*, PxU32) override {}
    void onConstraintBreak(PxConstraintInfo*, PxU32) override {}
    void onWake(PxActor**, PxU32) override {}
    void onSleep(PxActor**, PxU32) override {}
    void onAdvance(const PxRigidBody* const*, const PxTransform*, const PxU32) override {}
};

