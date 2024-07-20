cmake_minimum_required(VERSION 3.15)
project(SchoolProject)

if (MSVC)
    set(FLAGS /W4 /WX)
else()
    set(FLAGS -Wall -Wextra -Wpedantic -Werror)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty)

add_custom_target(
    CopyAssets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)

add_executable(game)
add_dependencies(game CopyAssets)
target_sources(game PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}/source/GameState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/GameContext.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/states/GameOverState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/states/JumpscareState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/states/LevelState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/states/MenuState.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/main.cpp
)
target_compile_options(game PRIVATE ${FLAGS})
target_include_directories(game PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(game PRIVATE sfml-graphics sfml-system sfml-window sfml-audio)

# prebuild and postbuild commands for Windows systems
if (WIN32)
    add_custom_command(
        TARGET game
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD 
        COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:game>
        VERBATIM
    )

    if (BUILD_SHARED_LIBS)
        add_custom_command(
            TARGET game
            COMMENT "Copy DLL files for shared libs building" 
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-graphics>
            $<TARGET_FILE:sfml-window>
            $<TARGET_FILE:sfml-system>
            $<TARGET_FILE:sfml-audio>
            $<TARGET_FILE_DIR:game>
        )
    endif()
endif()

install(TARGETS game)