#include "ocpch.h"
#include "Log.h"

namespace Oculum
{
#ifndef OC_DIST
    Log Log::log;

	Log::Log() : clk(std::chrono::steady_clock::now())
	{
		AllocConsole();
		AttachConsole(GetCurrentProcessId());

#pragma warning(push)
#pragma warning(disable: 4996)
		freopen("CON", "w", stdout);
		freopen("CON", "w", stderr);
		freopen("CON", "r", stdin);
#pragma warning (pop)

		OC_INFO("Logger Initialised");
	}

	Log::~Log()
	{

	}

	void Log::Trace(const char* fmt, ...)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		va_list args;
		va_start(args, fmt);
		log.Print(fmt, "TRACE", args);
	}

	void Log::Info(const char* fmt, ...)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		va_list args;
		va_start(args, fmt);
		log.Print(fmt, "INFO ", args);
	}

	void Log::Warn(const char* fmt, ...)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
		va_list args;
		va_start(args, fmt);
		log.Print(fmt, "WARN ", args);
	}

	void Log::Error(const char* fmt, ...)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		va_list args;
		va_start(args, fmt);
		log.Print(fmt, "ERROR", args);
	}

	void Log::Print(const char* fmt, const char* level, va_list args)
	{
		__int64 t_micro = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - clk).count();
		int t_hour = (int)std::floor(t_micro / 3600000000);
		t_micro -= (__int64)t_hour * 3600000000;
		int t_min = (int)std::floor(t_micro / 60000000);
		t_micro -= (__int64)t_min * 60000000;
		int t_sec = (int)(std::floor(t_micro / 1000000));
		t_micro -= (__int64)t_sec * 1000000;
		int t_mili = (int)std::floor(t_micro / 1000);
		t_micro -= (__int64)t_mili * 1000;

		std::cout << (t_hour < 10 ? "[0" : "[") << t_hour << (t_min < 10 ? ", 0" : ", ") << t_min << (t_sec < 10 ? ", 0" : ", ") << t_sec << (t_mili < 100 ? (t_mili < 10 ? ", 00" : ", 0") : ", ") << t_mili << (t_micro < 100 ? (t_micro < 10 ? ", 00" : ", 0") : ", ") << t_micro << "] " << level << " : ";

		size_t len = std::strlen(fmt);
		char* mod = new char[len + 2];
		strcpy_s(mod, len + 1, fmt);
		mod[len] = '\n';
		mod[len + 1] = '\0';

		vprintf(mod, args);
		va_end(args);
	}
#endif
}