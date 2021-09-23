begin_project(QtUtilsLibTest EXECUTABLE OPTIONAL)

enable_automoc()

require_library(Qt6 MODULES Core Gui Widgets)

require_library(GTest)

require_project(utilsLib PATH utilsLib)
require_project(QtUtilsLib)

add_source_directory(test)
