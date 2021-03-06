#pragma once

#include "Zephox/Core.h"
#include "Zephox/Events/Event.h"

namespace Zephox {
	
	class ZP_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		//~Layer();
		
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}
		
		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
	
}
