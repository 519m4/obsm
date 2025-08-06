set(
	Codes
	src/Algorithms/chacha20.c
	src/Algorithms/chacha20.h
	src/cryptor.c
	src/main.c
	src/main.h
)

add_executable (obsmV2 ${Codes})

#Tui
target_link_libraries(obsmV2 PRIVATE "${CMAKE_SOURCE_DIR}/src/lib/Sigma-tui.lib")

target_include_directories(obsmV2 PRIVATE "${CMAKE_SOURCE_DIR}/src/lib/includes")

#rtlzeromemory2
target_link_libraries(obsmV2 PRIVATE volatileaccessu.lib)

#Static link
if (MSVC)
	
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
	
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
	
	set_property(TARGET obsmV2 PROPERTY CXX_STANDARD 20)
	
endif()