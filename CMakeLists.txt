project(yomo)

cmake_minimum_required(VERSION 2.8.12)

find_package(ECM 0.0.14 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

include(FeatureSummary)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)

set(REQUIRED_QT_VERSION 5.0)
find_package(Qt5 ${REQUIRED_QT_VERSION} CONFIG REQUIRED Core)
find_package(KF5CoreAddons 5.0.0 REQUIRED)
find_package(KF5I18n 5.0.0 REQUIRED)
find_package(KF5Service 5.0.0 REQUIRED)

add_executable(yomo main.cpp)
target_link_libraries(yomo KF5::CoreAddons KF5::I18n KF5::Service)
install(TARGETS yomo ${INSTALL_TARGETS_DEFAULT_ARGS} )

install(DIRECTORY DESTINATION /kf5)
install(DIRECTORY DESTINATION /kf5/etc)
install(DIRECTORY DESTINATION /kf5/usr)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
