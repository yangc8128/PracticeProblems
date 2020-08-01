// Source Code: https://www.c-sharpcorner.com/article/composite-patterns-in-C-Sharp/
// Proof IList<Component> is feasible: https://www.dofactory.com/net/composite-design-pattern

// Structural Pattern:COMPOSITE
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
//the single interface for primitives & composite types.|
public abstract class Component
{
    //abstract public void AddChild(Component c);
    abstract public IEnumerable<int> Traverse();
}
//A primitive type.
public class Leaf : Component
{
    private int value = 0;
    public Leaf(int val)
    {
        value = val;
    }
    //public override void AddChild(Component c)
    //{
        //no action; This method is not necessary for Leaf
    //}
    public override IEnumerable<int> Traverse()
    {
        Console.WriteLine("Leaf:"+value);
        yield return value;
    }
}
//A composite type.
public class Composite : Component
{
    private int value = 0;
    private IEnumerable<Component> ComponentList;
    public Composite(int val, IEnumerable<Component> list)
    {
        this.value = val;
        this.ComponentList = list;
    }
    public override IEnumerable<int> Traverse()
    {
        Console.WriteLine("Composite:"+value);
        yield return value;
        foreach (Component c in ComponentList)
        {
            foreach (int compVal in c.Traverse())
            {
                yield return compVal;
            }
        }
    }
}
 