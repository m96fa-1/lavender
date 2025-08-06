#pragma once
////////// Standard C++ Library //////////
// streams and other data management libraries
#include <print>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <memory>
#include <functional>

// algorithm libraries
#include <string>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

////////// 3rd Party Libraries //////////
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

////////// Core Files //////////
#include "lavender/logger.h"

#ifdef LV_WINDOWS
// -------- WinAPI --------
#include <Windows.h>
// ------------------------
#endif