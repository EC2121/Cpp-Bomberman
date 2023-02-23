#pragma once
#include "IUpdatable.h"
#include<memory>
namespace Core {
	class Time : public IUpdatable {

	public:
		~Time() = default;
		Time(const Time&) = default;
		Time& operator=(const Time&) = delete;
	private:
		Time();

	public:
		static void Init();
		static float GetDeltatime(){ return deltatime; }
		void Update() override;
	private:
		static float now;
		static float last;
		static float deltatime;
		static std::unique_ptr<Time> instance;

	};
}