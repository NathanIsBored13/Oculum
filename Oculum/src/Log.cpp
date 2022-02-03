#include "ocpch.h"
#include "Log.h"

namespace Oculum
{
#ifndef OC_DIST
	Log Log::log;

	Log::Log() :
		startTime(std::chrono::steady_clock::now())
	{
		if (GetConsoleWindow() == NULL)
		{
			AllocConsole();
			AttachConsole(GetCurrentProcessId());

			freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
			freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);
			freopen_s((FILE**)stdin, "CONOUT$", "r", stdin);
		}

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		OC_INFO("Logger initialised");
	}

	Log::~Log()
	{

	}

	void Log::Trace(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		log.Print(fmt, "TRACE", FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY, args);
		va_end(args);
	}

	void Log::Info(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		log.Print(fmt, "INFO ", FOREGROUND_GREEN, args);
		va_end(args);
	}

	void Log::Warn(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		log.Print(fmt, "WARN ", FOREGROUND_RED | FOREGROUND_GREEN, args);
		va_end(args);
	}

	void Log::Error(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		log.Print(fmt, "ERROR", FOREGROUND_RED, args);
		va_end(args);
	}

	void Log::Print(const char* fmt, const char* level, WORD attributes, va_list args)
	{
		size_t t_mili = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - startTime).count();
		size_t t_hour = (size_t)std::floor(t_mili / 3600000);
		t_mili -= t_hour * 3600000;
		size_t t_min = (size_t)std::floor(t_mili / 60000);
		t_mili -= t_min * 60000;
		size_t t_sec = (size_t)std::floor(t_mili / 1000);
		t_mili -= t_sec * 1000;

		char prefixBuffer[] = "[00:00:00.000] ##### : ";
		PaddedInsert(prefixBuffer, 1, std::to_string(t_hour).c_str(), 2);
		PaddedInsert(prefixBuffer, 4, std::to_string(t_min).c_str(), 2);
		PaddedInsert(prefixBuffer, 7, std::to_string(t_sec).c_str(), 2);
		PaddedInsert(prefixBuffer, 10, std::to_string(t_mili).c_str(), 3);
		memcpy(prefixBuffer + 15, level, 5);

		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hConsole, &csbi);

		SetConsoleTextAttribute(hConsole, attributes);
		printf(prefixBuffer);
		vprintf_s(fmt, args);
		printf("\n");

		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}

	void Log::PaddedInsert(char* msg, int start, const char* str, int padlen)
	{
		size_t len = strlen(str);
		memcpy(msg + start + padlen - len, str, len);
	}
#endif
}