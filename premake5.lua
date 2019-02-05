workspace "ZaCherno"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "ZaCherno/vendor/GLFW/include"
IncludeDir["GLFW"] = "ZaCherno/vendor/GLFW/include"
IncludeDir["Glad"] = "ZaCherno/vendor/Glad/include"
IncludeDir["ImGui"]= "ZaCherno/vendor/imgui/include"

include "ZaCherno/vendor/GLFW"
include "ZaCherno/vendor/Glad"
include "ZaCherno/vendor/imgui"

project "ZaCherno"
	location "ZaCherno"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "zcpch.h"
	pchsource "ZaCherno/src/zcpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"premake5.lua",
	}

	includedirs
	{
		"%{prj.name}/src",
		"ZaCherno/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
		defines
		{
			"ZC_PLATFORM_WINDOWS",
			"ZC_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "ZC_DEBUG"
			buildoptions "/MDd"
			symbols "On"

		filter "configurations:Release"
			defines "ZC_RELEASE"
			buildoptions "/MD"
			optimize "On"

		filter "configurations:Dist"
			defines "ZC_DIST"
			buildoptions "/MD"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"ZaCherno/vendor/spdlog/include",
		"ZaCherno/src"
	}

	links
	{
		"ZaCherno"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
		defines
		{
			"ZC_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "ZC_DEBUG"
			buildoptions "/MDd"
			symbols "On"

		filter "configurations:Release"
			defines "ZC_RELEASE"
			buildoptions "/MD"
			optimize "On"

		filter "configurations:Dist"
			defines "ZC_DIST"
			buildoptions "/MD"
			optimize "Off"