from utils import *
from setup_python import python_configuration

def main():
  python_configuration.validate()

  os.chdir("..")
  
  print("\nCleaning up premake5.lua files if there are any...")
  delete_files("premake5.lua")
  delete_files("sandbox/premake5.lua")
  delete_files("lavender/premake5.lua")
  delete_files("lavender/vendor/**/premake5.lua")
  
  print("\nCleaning up your project...")
  system = platform.system()
  if system == "Windows":
    delete_dir(".vs")
    delete_files("*.sln")
    delete_files("sandbox/*.vcxproj*")
    delete_files("lavender/*.vcxproj*")
    delete_files("lavender/vendor/glfw/*.vcxproj*")
    delete_files("lavender/vendor/glad/*.vcxproj*")
    delete_files("lavender/vendor/imgui/*.vcxproj*")
  elif system == "Linux":
    delete_dir(".vscode")

  delete_dir("bin")
  delete_dir("bin-int")
  delete_dir("lavender/vendor/glfw/bin")
  delete_dir("lavender/vendor/glfw/bin-int")
  delete_dir("lavender/vendor/glad/bin")
  delete_dir("lavender/vendor/glad/bin-int")
  delete_dir("lavender/vendor/imgui/bin")
  delete_dir("lavender/vendor/imgui/bin-int")
  
  input("\nCleaning completed, press Enter/Return to exit...\n")

if __name__ == "__main__":
  main()