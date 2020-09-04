add_executable(test test.c)
add_executable(diskmanager diskManager.c)

target_link_libraries(diskmanager disk)