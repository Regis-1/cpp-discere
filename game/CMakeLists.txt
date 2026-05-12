add_library(game
  src/Game.cpp)

target_include_directories(game
  PUBLIC include)

target_link_libraries(game
  PUBLIC engine)
