project "imgui"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "*.h",
        "*.cpp"
    }

    filter "system:windows"
        cppdialect (cppver)
        staticruntime "On"
        systemversion "latest"