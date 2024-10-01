
vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO "godotengine/godot-cpp"
    REF "godot-${VERSION}-stable"
    SHA512 "4012e2c8cbdbccf5362b139a6318785af6e2cfdc99848734d5e3825afba8b8a46cdd7fff63887e2503cf3195efe79c0bd39a900b535322ab0fb51c3452dc07f5"
    HEAD_REF "master"
    PATCHES
        "install.patch"
)
file(INSTALL "${CMAKE_CURRENT_LIST_DIR}/cmake/install.cmake" DESTINATION "${SOURCE_PATH}")


vcpkg_find_acquire_program(PYTHON3)
vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    WINDOWS_USE_MSBUILD
)

vcpkg_cmake_install()
vcpkg_copy_pdbs()

vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE.md")

file(
    INSTALL "${CMAKE_CURRENT_LIST_DIR}/usage"
    DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}"
)
file(
    INSTALL "${CMAKE_CURRENT_LIST_DIR}/cmake/godot-cpp-config.cmake"
    DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}"
)

file(REMOVE_RECURSE
    "${CURRENT_PACKAGES_DIR}/debug/include"
    "${CURRENT_PACKAGES_DIR}/debug/share"
)