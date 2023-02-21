#pragma once
namespace Core {
	class IUpdatable {
	public:
		IUpdatable();

	public:
		virtual void  Update() {};
	};
}
