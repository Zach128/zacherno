workspace "ZaCherno"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ZaCherno"
	location "ZaCherno"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"ZaCherno/vendor/spdlog/include"
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
			symbols "On"

		filter "configurations:Release"
			defines "ZC_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "ZC_DIST"
			optimize "Off"

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
			symbols "On"

		filter "configurations:Release"
			defines "ZC_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "ZC_DIST"
			optimize "Off"