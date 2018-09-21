#pragma once

#include <Ogre.h>
#include <OgreMath.h>
#include <OgreApplicationContext.h>
#include <OgreInput.h>
#include <OgreRTShaderSystem.h>
#include <OgreApplicationContext.h>

#include <iostream>

#include "ECS/EventManager.h"
#include "ECS/EntityManager.h"
#include "ECS/ComponentManager.h"
#include "GameObject.h"
#include "Ball.h"
#include "Events.h"
#include "EventSubscribers.h"

#define WALL_TEX "cube.mesh"
#define BALL_TEX "sphere.mesh"
#define OGRE_TEX "ogrehead.mesh"

using namespace Ogre;
using namespace OgreBites;

namespace Game
{
    class BasicTutorial1
            : public ApplicationContext
            , public InputListener
    {
    public:
        BasicTutorial1();
        virtual ~BasicTutorial1();

        void setup();
        bool keyPressed(const KeyboardEvent& evt);

        bool frameRenderingQueued(const Ogre::FrameEvent& evt);

    private:
        Root* mRoot;
        SceneManager* mScnMgr;
        RTShader::ShaderGenerator* mShadergen;

        std::unique_ptr<ECS::EventManager> mEventManager;

        // Game specific member vars
        SceneNode* mMainLightNode;

        SceneNode* mWallNode1;
        SceneNode* mWallNode2;
        SceneNode* mWallNode3;
        SceneNode* mWallNode4;
    };
} //namespace Game
