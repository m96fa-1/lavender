outputdir = "%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}"
cppver = "C++23"
cver = "C17"

workspace "lavender"
   architecture "x86_64"
   configurations { "Debug", "Release", "Dist" }
   startproject "sandbox"

group "dependencies"
    include "lavender/vendor/glfw"
    include "lavender/vendor/glad"
    include "lavender/vendor/imgui"
group ""

group "core"
    include "lavender"
group ""

group "client"
    include "sandbox"
group ""