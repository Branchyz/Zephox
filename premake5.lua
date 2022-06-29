workspace "Zephox"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Zephox/vendor/GLFW/include"

include "Zephox/vendor/GLFW"

project "Zephox"
	location "Zephox"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "zppch.h"
	pchsource "Zephox/src/zppch.cpp"

	staticruntime "off"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links {
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"ZP_PLATFORM_WINDOWS",
			"ZP_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "ZP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZP_DIST"
		optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"Zephox/vendor/spdlog/include",
		"Zephox/src"
	}

	links {
		"Zephox"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"ZP_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "ZP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZP_DIST"
		optimize "On"