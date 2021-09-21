begin_project(QtIocLib LIBRARY)

enable_automoc()

require_library(Qt6 MODULES Core Gui Widgets)

require_project(iocLib PATH iocLib)

add_source_directory(include)
add_source_directory(src)

add_include_directory(include)
