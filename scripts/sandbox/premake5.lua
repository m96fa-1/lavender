project "sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect (cppver)
    cdialect (cver)
    staticruntime "Off"
    systemversion "latest"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "src",
        "../lavender/src",
        "../lavender/vendor/glfw/include",
        "../lavender/vendor/glad/include",
        "../lavender/vendor/glm",
        "../lavender/vendor/stb_image",
        "../lavender/vendor/imgui",
        "../lavender/vendor/spdlog/include",
    }

    links {
        "lavender"
    }

    filter "system:windows"
        defines "LV_WINDOWS"

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
        kind "WindowedApp"
        defines "LV_DIST"
        runtime "Release"
        optimize "On"
        symbols "On"