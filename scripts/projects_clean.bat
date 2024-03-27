cd ..
rd /s /q .vs
rd /s /q bin
rd /s /q bin-int
del *.sln
del Lavender\*.vcxproj*
del Sandbox\*.vcxproj*
cd Lavender\vendor\glfw
rd /s /q bin
rd /s /q bin-int
del *.vcxproj*
cd Lavender\vendor\glad
rd /s /q bin
rd /s /q bin-int
del *.vcxproj*
cd Lavender\vendor\imgui
rd /s /q bin
rd /s /q bin-int
del *.vcxproj*
pause