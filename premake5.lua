workspace "Oculum"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Oculum"
	location "Oculum"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	pchheader "ocpch.h"
	pchsource "Oculum/ocpch.cpp"
	
	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}
	
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"
	
	includedirs
	{
		"%{prj.name}"
	}

	filter "configurations:Debug"
		defines "OC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OC_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "WindowedApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		"Oculum"
	}

	links
	{
		"Oculum"
	}
	
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

	filter "configurations:Debug"
		defines "OC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OC_DIST"
		optimize "On"