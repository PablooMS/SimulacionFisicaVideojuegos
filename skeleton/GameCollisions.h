#pragma once
#include <PxPhysicsAPI.h>
#include "CollisionLayers.h"
#include "GameSolids.h"

using namespace physx;

class GameCollisions : public PxSimulationEventCallback
{
    void onContact(PxContactPairHeader const& pairHeader, PxContactPair const* pairs, PxU32 nbPairs) override;

    void onTrigger(PxTriggerPair*, PxU32) override {}
    void onConstraintBreak(PxConstraintInfo*, PxU32) override {}
    void onWake(PxActor**, PxU32) override {}
    void onSleep(PxActor**, PxU32) override {}
    void onAdvance(const PxRigidBody* const*, const PxTransform*, const PxU32) override {}
};

