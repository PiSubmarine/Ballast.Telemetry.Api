include("${PISUBMARINE_BUILD_SYSTEM}")

message("Adding library: ${PISUBMARINE_MODULE_NAME}")
add_library(${PISUBMARINE_MODULE_NAME} INTERFACE
        "../public/PiSubmarine/Ballast/Telemetry/Api/IProvider.h"
        "../public/PiSubmarine/Ballast/Telemetry/Api/State.h")
target_include_directories(${PISUBMARINE_MODULE_NAME} INTERFACE "../public")
PiSubmarineInitTarget(${PISUBMARINE_MODULE_NAME})

PiSubmarineAddDependency("https://github.com/PiSubmarine/Error.Api.git" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} INTERFACE PiSubmarine.Error.Api)

PiSubmarineAddDependency("https://github.com/PiSubmarine/Units.git" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} INTERFACE PiSubmarine.Units)
