add_executable(main "main.cpp")  # 需要编译的所有 .cpp 文件
target_set_options(main)

find_package(miraipp CONFIG REQUIRED)
target_link_libraries(main PRIVATE miraipp::miraipp)
