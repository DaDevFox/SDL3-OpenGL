file( GLOB game_SOURCES *.cpp )
add_library( game ${game_SOURCES} )
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(game PRIVATE SDL3::SDL3)
