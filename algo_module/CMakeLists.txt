# add the library that runs
file(GLOB_RECURSE ALG_SOURCES *.cpp)
file(GLOB_RECURSE ALG_INCLUDES *.hpp)
add_library(algo ${ALG_SOURCES} ${ALG_INCLUDES})

set(ALGO_INCLUDES ${ALG_INCLUDES})

target_include_directories(algo PUBLIC
	"${PROJECT_SOURCE_DIR}/algo_module/include"
	)

message("algo module source dir ${PROJECT_SOURCE_DIR}" )
message("algo module source files ${ALG_SOURCES}" )
message("algo module source includes ${ALG_INCLUDES}" )

install(TARGETS algo DESTINATION lib)
install(FILES ${ALG_INCLUDES} DESTINATION include)
