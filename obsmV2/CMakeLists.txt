set(
	
	Codes

	src/chacha20.c
	src/chacha20.h
	src/cryptor.c
	src/main.c
	src/main.h

)

add_executable (obsmV2 ${Codes})

target_link_libraries(obsmV2 PRIVATE "${CMAKE_SOURCE_DIR}/src/lib/Sigma-tui.lib")
target_include_directories(obsmV2 PRIVATE "${CMAKE_SOURCE_DIR}/src/lib/includes")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET obsmV2 PROPERTY CXX_STANDARD 20)
endif()