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
	kind "SharedLib"
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

	defines
	{
		"OC_BUILD_DLL"
	}
	
	includedirs
	{
		"%{prj.name}"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "OC_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "OC_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "OC_DIST"
		buildoptions "/MD"
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
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "OC_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "OC_DIST"
		buildoptions "/MD"
		optimize "On"