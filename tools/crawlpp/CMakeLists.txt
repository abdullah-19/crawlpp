
set (SOURCES
  crawlpp.cpp
  ${INCLUDE_DIRECTORIES}
)

add_executable(crawlpp ${SOURCES})
target_link_libraries(crawlpp ${CRAWLPP_LIBRARY})