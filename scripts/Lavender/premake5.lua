project "lavender"
    kind "SharedLib"
    language "C++"
    cppdialect (cppver)
    cdialect (cver)
    staticruntime "Off"
    systemversion "latest"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.h",
        "src/**.cpp",
        "vendor/glm/glm/**.hpp",
        "vendor/glm/glm/**.inl"
    }

    includedirs {
        "src",
        "vendor/glfw/include",
        "vendor/glad/include",
        "vendor/glm",
        "vendor/stb_image",
        "vendor/imgui",
        "vendor/spdlog/include",
    }

    defines {
        "GLFW_INCLUDE_NONE",
        "STB_IMAGE_IMPLEMENTATION"
    }

    links {
        "glfw",
        "glad",
        "imgui",
        "Opengl32",
    }

    pchheader "lvpch.h"
    pchsource "src/lvpch.cpp"

    filter "system:windows"
        defines {
            "LV_WINDOWS",
            "LV_BUILD_DLL"
        }

        postbuildcommands {
            ("IF NOT EXIST \"../bin/" .. outputdir .. "/sandbox/\" (mkdir \"../bin/" .. outputdir .. "/sandbox/\")"),
            ("{COPYFILE} \"%{cfg.buildtarget.relpath}\" \"../bin/" .. outputdir .. "/sandbox/\"")
        }

    filter "system:macosx"
        defines "LV_MACOSX"

    filter "system:linux"
        defines "LV_LINUX"

    filter "configurations:Debug"
        defines "LV_DEBUG"
        runtime "Debug"
        symbols "On"
        
    filter "configurations:Release"
        defines "LV_RELEASE"
        runtime "Release"
        optimize "On"
        symbols "On"
        
    filter "configurations:Dist"
        defines "LV_DIST"
        runtime "Release"
        optimize "On"
        symbols "On"