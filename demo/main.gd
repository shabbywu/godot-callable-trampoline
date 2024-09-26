extends Node2D


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	var csharp = get_node("Csharp")
	
	csharp.OriginalLambda = func(): return "Hello Callable Trampoline"
	csharp.Lambda = CallableTrampoline.wrap(func(): return "Hello Callable Trampoline").get_caller()
	csharp.TestLambda()

	var add = func(a, b): return a + b
	csharp.OriginalBind = add.bind(1);
	csharp.Bind = CallableTrampoline.wrap(add.bind(1)).get_caller()
	print("add(1, 2) = ", csharp.TestBind(2))

	# test free reference
	## csharp.Lambda = null
	## csharp.Bind = null
	# csharp hold a reference, only gc can release it.
	# maybe it's not necessary to call gc manually in many case. here just for test.
	## csharp.Collect()
