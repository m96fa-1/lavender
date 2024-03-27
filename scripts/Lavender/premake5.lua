outputdir = "%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}"
workspc = "Lavender"
prj1 = "Lavender"
prj2 = "Sandbox"
cppver = "C++20"
cver = "C17"

-------------------------------------------------
--------------------Workspace--------------------
-------------------------------------------------
workspace (workspc)
    architecture "x86_64"
    configurations { "Debug", "Release", "Dist" }
    startproject (prj2)

IncludeDir = {}
IncludeDir["spdlog"] = (prj1 .. "/vendor/spdlog/include")
IncludeDir["glfw"] = (prj1 .. "/vendor/glfw/include")
IncludeDir["glad"] = (prj1 .. "/vendor/glad/include")
IncludeDir["imgui"] = (prj1 .. "/vendor/imgui")

include (prj1 .. "/vendor/glfw")
include (prj1 .. "/vendor/glad")
include (prj1 .. "/vendor/imgui")

-------------------------------------------------
--------------------Project 1--------------------
-------------------------------------------------
project (prj1)
    location (prj1)
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "%{prj.name}/src",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.imgui}",
    }

    links {
        "glfw",
        "glad",
        "imgui",
        "Opengl32",
    }

    pchheader "lvpch.h"
    pchsource "%{prj.name}/src/lvpch.cpp"

    filter "system:windows"
        cppdialect (cppver)
        cdialect (cver)
        systemversion "latest"

        defines {
            "LV_PLATFORM_WINDOWS",
            "LV_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
        }

        postbuildcommands {
            ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/" .. prj2 .. "/" .. prj1 .. ".dll")
        }

    filter "configurations:Debug"
        defines {
            "LV_DEBUG",
            "LV_ENABLE_ASSERT",
        }
        symbols "On"

    filter "configurations:Release"
        defines "LV_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "LV_DIST"
        optimize "On"

-------------------------------------------------
--------------------Project 2--------------------
-------------------------------------------------
project (prj2)
    location (prj2)
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        (prj1 .. "/src"),
        "%{IncludeDir.spdlog}"
    }

    links {
        (prj1)
    }

    filter "system:windows"
        cppdialect (cppver)
        cdialect (cver)
        systemversion "latest"

        defines {
            "LV_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "LV_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LV_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "LV_DIST"
        optimize "On"