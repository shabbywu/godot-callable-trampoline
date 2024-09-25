extends Node2D


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	var csharp = get_node("Csharp")
	
	csharp.OriginalLambda = func(): print("Hello Callable")
	csharp.Lambda = CallableTrampoline.wrap(func(): print("Hello Callable Trampoline")).get_caller()
	# csharp.TestLambda()

	var add = func(a, b): return a + b
	csharp.OriginalBind = add.bind(1);
	csharp.Bind = CallableTrampoline.wrap(add.bind(1)).get_caller()
	print("add(1, 2) = ", csharp.TestBind(2))

	# free reference
	csharp.Lambda = null
	csharp.Bind = null
	csharp.Collect()
