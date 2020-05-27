#pragma once

#include "ocpch.h"
#include "Core.h"

#include <stdarg.h>
#include <chrono>
#include <ratio>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>

namespace Oculum
{
#ifndef OC_DIST
	#define OC_TRACE(...) ::Oculum::Log::Trace(__VA_ARGS__)
	#define OC_INFO(...) ::Oculum::Log::Info(__VA_ARGS__)
	#define OC_WARN(...) ::Oculum::Log::Warn(__VA_ARGS__)
	#define OC_ERROR(...) ::Oculum::Log::Error(__VA_ARGS__)
	class OC_API Log
	{
	public:
		static void Trace(const char*, ...);
		static void Info(const char*, ...);
		static void Warn(const char*, ...);
		static void Error(const char*, ...);
	private:
		Log();
		~Log();
		void Print(const char*, const char*, va_list);
		static Log log;
		const std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> clk;
	};
#else
	#define OC_TRACE(...)
	#define OC_INFO(...)
	#define OC_WARN(...)
	#define OC_ERROR(...)
#endif
}