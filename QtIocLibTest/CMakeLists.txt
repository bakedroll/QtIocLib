begin_project(QtIocLibTest EXECUTABLE OPTIONAL)

enable_automoc()

require_library(Qt6 MODULES Core Gui Widgets)

require_library(GTest)

require_project(iocLib PATH iocLib)
require_project(QtIocLib)

add_source_directory(test)
