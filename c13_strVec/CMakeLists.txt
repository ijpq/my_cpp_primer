project(strvec)
#aux_source_directory(main.cpp  SRC)
set(CMAKE_CXX_STANDARD 11)
add_executable(strVec main.cpp strVec.cpp TextQuery.cc)