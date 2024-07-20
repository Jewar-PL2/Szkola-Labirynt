FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)

set(SFML_BUILD_EXAMPLES OFF)
set(SFML_BUILD_NETWORK OFF)

FetchContent_MakeAvailable(SFML)
