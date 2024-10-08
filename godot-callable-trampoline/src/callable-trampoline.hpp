#pragma once
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/callable.hpp>
using namespace godot;

namespace gdbind {
/// @brief godot-csharp does not support CallableCustom, but only member method.
///        CallableTrampoline wrap an Callable as member method to let godot-csharp happy to it.
class CallableTrampoline : public RefCounted {
    GDCLASS(CallableTrampoline, RefCounted);

  public:
    Callable callable;
    CallableTrampoline() : RefCounted() {};
    CallableTrampoline(Callable callable) : RefCounted(), callable(callable) {
    }

    virtual ~CallableTrampoline() {
        UtilityFunctions::print("~CallableTrampoline");
    }

  public:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("get_caller"), &CallableTrampoline::get_caller);
        ClassDB::bind_vararg_method(METHOD_FLAG_NORMAL, "trampoline", &CallableTrampoline::trampoline,
                                    MethodInfo("trampoline"));

        ClassDB::bind_static_method("CallableTrampoline", D_METHOD("wrap", "callable"), &CallableTrampoline::wrap);
    }

  public:
    /// @brief helper function, wrap given callable to CallableTrampoline*.
    static CallableTrampoline *wrap(godot::Callable callable) {
        return memnew(CallableTrampoline(callable));
    };

  protected:
    /// @brief helper function, return a Callable which godot-csharp can access correctly.
    Callable get_caller() {
        return Callable(this, "trampoline");
    }
    /// @brief The trampoline transfer all arguments to the real callable.
    Variant trampoline(const godot::Variant **p_arguments, GDExtensionInt p_argcount,
                       GDExtensionCallError &r_call_error) {
        if (!callable.is_valid()) {
            return nullptr;
        }
        godot::Array arguments;
        arguments.resize(p_argcount);
        for (auto i = 0; i < p_argcount; i++) {
            arguments[i] = (*p_arguments[i]);
        }
        return callable.callv(arguments);
    }
};
} // namespace gdbind
