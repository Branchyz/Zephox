workspace "Zephox"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Zephox"
	location "Zephox"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "zppch.h"
	pchsource "Zephox/src/zppch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
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
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
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

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

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