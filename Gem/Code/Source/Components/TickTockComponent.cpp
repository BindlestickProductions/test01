//#include "StdAfx.h" Not anymooooree :)
#include "test01_precompiled.h"
#include <Components\TickTockComponent.h>

using namespace AZ;
using namespace test01;


void TickTockComponent::OnTick(float deltaTime,
	ScriptTimePoint)
{
	m_tickCounter++;
	if (m_tickCounter > m_tickOverflow)
	{
		if (ticktock)
		{
			ticktock = !ticktock;
			AZ_Printf("Tick! ", " %d", m_tickCounter);
		}
		else
		{
			ticktock = !ticktock;
			AZ_Printf("Tock! ", " %d", m_tickCounter);
		}

		m_tickCounter = 0;
	}	
}

void TickTockComponent::Reflect(
    ReflectContext* context)
{
    auto sc = azrtti_cast<SerializeContext*>(context);
	if (sc)
	{
		sc->Class<TickTockComponent, Component>()
			 ->Field("Tick Count Overflow",
				 &TickTockComponent::m_tickOverflow)
			->Version(1);

		if (EditContext* ec = sc->GetEditContext())
		{
			ec->Class<TickTockComponent>(
				"TickTock Component",
				"Game Tick Events")
				->ClassElement(Edit::ClassElements::EditorData,
					"")
				->Attribute(Edit::Attributes::Category,
					"GridMate Players")
				->Attribute(Edit::Attributes::
					AppearsInAddComponentMenu,
					AZ_CRC("Game"))
				->DataElement(nullptr,
					&TickTockComponent::m_tickOverflow,
					"Tick Count Overflow", "");
		}
	}

}

void TickTockComponent::Activate()
{
		TickBus::Handler::BusConnect();
}

void TickTockComponent::Deactivate()
{
		TickBus::Handler::BusDisconnect();
}
