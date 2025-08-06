#include "lvpch.h"
#include "glfw_opengl_imgui_layer.h"

#include "lavender/application.h"

#include "platform/glfw/imgui_glfw_renderer.h"
#include "platform/opengl/imgui_opengl_renderer.h"

#include <GLFW/glfw3.h>

namespace lv {

	glfw_opengl_imgui_layer::glfw_opengl_imgui_layer()
		: imgui_layer("GLFW & OpenGL ImGui Layer") {

	}

	glfw_opengl_imgui_layer::~glfw_opengl_imgui_layer() {

	}

	void glfw_opengl_imgui_layer::on_attach() {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
		ImGui::StyleColorsDark();

		GLFWwindow* window = (GLFWwindow*)application::get().get_window().get_native_window();
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 460 core");
	}

	void glfw_opengl_imgui_layer::on_detach() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void glfw_opengl_imgui_layer::on_update() {
		ImGuiIO& io = ImGui::GetIO();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		m_time = glfwGetTime();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void glfw_opengl_imgui_layer::on_event(event& event) {

	}

}