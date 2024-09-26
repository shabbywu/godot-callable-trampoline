using Godot;
using System;

public partial class Csharp : Node
{
	public Callable OriginalLambda { get; set; }
	public Callable Lambda { get; set; }
	public Callable OriginalBind{ get; set; }
	public Callable Bind{ get; set; }

	public Label LabelLambda { get; set; }
	public Label LabelBind { get; set; }

	public override void _Ready()
	{
		LabelLambda = GetNode<Label>("VBoxContainer/Text/Lambda");
		LabelBind = GetNode<Label>("VBoxContainer/Text/Bind");
		
		GetNode<Button>("VBoxContainer/Control/Lambda").Connect("pressed", Callable.From(() =>
		{
			LabelLambda.Text = Lambda.Call().AsString();
		}));

		var i = 0;
		GetNode<Button>("VBoxContainer/Control/Bind").Connect("pressed", Callable.From(() =>
		{
			LabelBind.Text = $"1+{i}={Bind.Call(i).AsString()}";
			i = Bind.Call(i).AsInt32();
		}));
	}

	public void TestLambda()
	{
		GD.Print(OriginalLambda.Call());
		GD.Print(Lambda.Call());
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
