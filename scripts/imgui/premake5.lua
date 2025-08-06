project "imgui"
    kind "StaticLib"
    language "C++"
    staticruntime "On"
    cppdialect (cppver)
    systemversion "latest"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "*.h",
        "*.cpp"
    }