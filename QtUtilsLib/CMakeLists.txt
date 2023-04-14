begin_project(QtUtilsLib LIBRARY)

enable_automoc()

require_library(Qt MODULES Core)

require_project(utilsLib PATH utilsLib)

add_source_directory(include)
add_source_directory(src)

add_include_directory(include)
