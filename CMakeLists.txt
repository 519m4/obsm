cmake_minimum_required (VERSION 3.8)

set(
	Codes
	"obsmV2/src/Algorithms/chacha20.c"
	"obsmV2/src/Algorithms/chacha20.h"
	"obsmV2/src/cryptor.c"
	"obsmV2/src/main.c"
	"obsmV2/src/main.h"
	"obsmV2/src/test.c"
	
)

if (POLICY CMP0141)

  cmake_policy(SET CMP0141 NEW)

  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")

endif()

project ("obsm")

add_executable (obsmV2 ${Codes})

target_link_libraries(obsmV2 PRIVATE "${CMAKE_SOURCE_DIR}/obsmV2/src/lib/Sigma-tui.lib")

target_include_directories(obsmV2 PRIVATE "${CMAKE_SOURCE_DIR}/obsmV2/src/lib/includes")

target_link_libraries(obsmV2 PRIVATE volatileaccessu.lib)

if (MSVC)
	
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
	
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
	
	set_property(TARGET obsmV2 PROPERTY CXX_STANDARD 20)
	
endif()