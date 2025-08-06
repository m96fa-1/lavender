from utils import *
from setup_python import python_configuration

def main():
  python_configuration.validate()

  # Configuring libraries
  print("\nConfiguring libraries...")

  answer = input("Would you like to replace current vendor libraries with new ones? [Y/N]: ").lower().strip()[:1]
  if answer == 'y':
    print("\nRemoving old vendor directories...")
    delete_dir("../lavender/vendor/glfw")
    delete_dir("../lavender/vendor/glm")
    delete_dir("../lavender/vendor/imgui")
    delete_dir("../lavender/vendor/spdlog")

    print("\nDownloading new libraries as zip files...")
    download_file("https://github.com/glfw/glfw/archive/refs/heads/master.zip", "../lavender/vendor/glfw.zip")
    download_file("https://github.com/g-truc/glm/archive/refs/heads/master.zip", "../lavender/vendor/glm.zip")
    download_file("https://github.com/ocornut/imgui/archive/refs/heads/master.zip", "../lavender/vendor/imgui.zip")
    download_file("https://github.com/gabime/spdlog/archive/refs/heads/v1.x.zip", "../lavender/vendor/spdlog.zip")

    print("\nExtracting downloaded files...")
    extract_zip("../lavender/vendor/glfw.zip", "../lavender/vendor/")
    extract_zip("../lavender/vendor/glm.zip", "../lavender/vendor/")
    extract_zip("../lavender/vendor/imgui.zip", "../lavender/vendor/")
    extract_zip("../lavender/vendor/spdlog.zip", "../lavender/vendor/")

    print("\nCleaning up zip files...")
    delete_files("../lavender/vendor/glfw.zip")
    delete_files("../lavender/vendor/glm.zip")
    delete_files("../lavender/vendor/imgui.zip")
    delete_files("../lavender/vendor/spdlog.zip")

    print("\nRenaming library folders...")
    rename_dir("../lavender/vendor/glfw-master", "../lavender/vendor/glfw")
    rename_dir("../lavender/vendor/glm-master", "../lavender/vendor/glm")
    rename_dir("../lavender/vendor/imgui-master", "../lavender/vendor/imgui")
    rename_dir("../lavender/vendor/spdlog-1.x", "../lavender/vendor/spdlog")

  # Setting up workspace
  print("\nSetting up the workspace")
  copy_file("premake5.lua", "..")
  copy_file("sandbox/premake5.lua", "../sandbox")
  copy_file("lavender/premake5.lua", "../lavender")
  copy_file("glfw/premake5.lua", "../lavender/vendor/glfw")
  copy_file("glad/premake5.lua", "../lavender/vendor/glad")
  copy_file("imgui/premake5.lua", "../lavender/vendor/imgui")

  os.chdir("..")

  print("\nRunning premake...")
  run_premake()

  print("\nCleaning up...")
  delete_files("premake5.lua")
  delete_files("sandbox/premake5.lua")
  delete_files("lavender/premake5.lua")
  delete_files("lavender/vendor/glfw/premake5.lua")
  delete_files("lavender/vendor/glad/premake5.lua")
  delete_files("lavender/vendor/imgui/premake5.lua")

  input("\nSetup completed, press Enter/Return to exit...\n")

if __name__ == "__main__":
  main()
