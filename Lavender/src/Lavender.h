#pragma once

// To be used by Lavender applications

#include "lavender/application.h"
#include "lavender/logger.h"
#include "lavender/events.h"
#include "lavender/layer.h"

#include "lavender/input.h"
#include "lavender/key_codes.h"

#ifdef LV_WINDOWS
#include "platform/imgui/glfw_opengl_imgui_layer.h"
#endif

// -------Main Entry Point-------
#include "lavender/entry_point.h"
// ------------------------------