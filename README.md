# godot-callable-trampoline
GDExtension let godotsharp can call `CallableCustom` such as `GDScriptLambdaCallable` or `CallableCustomBind/Unbind`.
> Unofficial available fix for [known bug](https://github.com/godotengine/godot/issues/97358)

## Installation
1. donwload prebuilt GDExtension from [github release page](https://github.com/shabbywu/godot-callable-trampoline/releases/tag/v1.0.0)
2. unzip the archive downloaded from `step 1` to your godot project rootdir.

## Usage
```gdscript
var wrap = CallableTrampoline.wrap(func(): return "Hello Callable Trampoline")

# `wrap.get_caller()` can transfer to csharp context
var callable = wrap.get_caller()
```

## Requirement
- Godot 4.2.1 or upper
