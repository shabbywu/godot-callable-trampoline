using Godot;
using System;

public partial class Csharp : Node
{
	public Callable OriginalLambda { get; set; }
	public Callable Lambda { get; set; }
	public Callable OriginalBind{ get; set; }
	public Callable Bind{ get; set; }

	public void TestLambda()
	{
		try
		{
			OriginalLambda.Call();
		}
		catch (Exception e)
		{
			GD.Print("failed to call original lambda");
		}
		Lambda.Call();
	}

	public int TestBind(int b)
	{
		Variant o = OriginalBind.Call(b);
		if (o.Obj == null)
		{
			GD.Print("failed to call original bind");
		}
		return (int)Bind.Call(b);
	}
	
	public void Collect(){GC.Collect();}
}
