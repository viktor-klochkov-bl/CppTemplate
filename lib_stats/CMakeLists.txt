set(SOURCES
  Stats.cpp
)

string(REPLACE ".cpp" ".hpp" HEADERS "${SOURCES}")
add_library(libStats SHARED ${SOURCES})

if(BUILD_TESTS)
  include(GoogleTest)
  enable_testing()
  set(TEST_SOURCES
    Stats.test.cpp)

  add_executable(libStats_Tests ${TEST_SOURCES})
  target_link_libraries(libStats_Tests PRIVATE libStats gtest_main)
  gtest_discover_tests(libStats_Tests TEST_PREFIX libStats)
endif()
