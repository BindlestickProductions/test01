
#include "test01_precompiled.h"
#include <platform_impl.h>

#include <AzCore/Memory/SystemAllocator.h>

#include "test01SystemComponent.h"
#include "Components/TickTockComponent.h"

#include <IGem.h>

namespace test01
{
    class test01Module
        : public CryHooksModule
    {
    public:
        AZ_RTTI(test01Module, "{30451E28-D893-4CCA-A26A-4FB31DEFE23C}", CryHooksModule);
        AZ_CLASS_ALLOCATOR(test01Module, AZ::SystemAllocator, 0);

        test01Module()
            : CryHooksModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                test01SystemComponent::CreateDescriptor(),
				TickTockComponent::CreateDescriptor()
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<test01SystemComponent>(),
            };
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(test01_6679e2872fdb44908db769a5552e90dc, test01::test01Module)
