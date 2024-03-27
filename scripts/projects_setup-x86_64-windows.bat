copy Lavender\premake5.lua ..
copy glfw\premake5.lua ..\Lavender\vendor\glfw
copy glad\premake5.lua ..\Lavender\vendor\glad
copy imgui\premake5.lua ..\Lavender\vendor\imgui
cd ..
vendor\premake5-x86_64-windows\premake5.exe vs2022
del premake5.lua
del Lavender\vendor\glfw\premake5.lua
del Lavender\vendor\glad\premake5.lua
del Lavender\vendor\imgui\premake5.lua
pause