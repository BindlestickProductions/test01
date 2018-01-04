#pragma once

#include <AzCore/Component/Component.h>
#include "AzCore/Component/TickBus.h"
#include <AzCore/Component/TransformBus.h>
#include <LmbrCentral/Physics/CryCharacterPhysicsBus.h>
#include <AzCore/Serialization/EditContext.h>



namespace test01
{
    class TickTockComponent
        : public AZ::Component
		, public AZ::TickBus::Handler
    {
    public:
		//Register component, can get new UUID with MSVC developer console command "uuidgen"
        AZ_COMPONENT(TickTockComponent,"{edf8a6fd-7636-4672-9880-c422a847457c}");

		~TickTockComponent() override = default;

        static void Reflect(AZ::ReflectContext* context);

		// AZ::Component interface implementation
		void Activate() override;
		void Deactivate() override;

		// AZ::TickBus interface implementation
		void OnTick(float deltaTime,
			AZ::ScriptTimePoint time) override;

    private:

		AZ::u32 m_tickCounter = 0;
		AZ::u32 m_tickOverflow = 100;
		bool ticktock = false;

    };
}