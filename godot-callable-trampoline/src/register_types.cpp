/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include "callable-trampoline.hpp"

using namespace godot;

void initialize_callable_trampoline_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    GDREGISTER_CLASS(gdbind::CallableTrampoline);
}

void uninitialize_callable_trampoline_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT callable_trampoline_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
                                                            GDExtensionClassLibraryPtr p_library,
                                                            GDExtensionInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

    init_obj.register_initializer(initialize_callable_trampoline_module);
    init_obj.register_terminator(uninitialize_callable_trampoline_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}
}
