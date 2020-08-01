using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using Xunit;

namespace Personal.CSharp.UnitTest
{
    public class CompositeTests
    {
        [Fact]
        public void CompositeTest1()
        {
            //creating a TREE structure.
            Composite com1 = new Composite(200, new List<Component>() {new Leaf(10), new Leaf(20)}); //Composite 1
            Composite root = new Composite(100, new List<Component>() {com1, new Leaf(30)});// Root
            //Leaf l1 = new Leaf(10);//Leaf1
            //Leaf l2 = new Leaf(20);//Leaf2
            //Add two leafs to composite1
            //com1.AddChild(l1);
            //com1.AddChild(l2);
            //Leaf l3 = new Leaf(30);//Leaf3
            //root.AddChild(com1);//Add composite1 to root
            //root.AddChild(l3);//Add Leaf3 directlt to root
            //root.Traverse();//Single method for both types.

            Assert.Equal(com1.Traverse().Prepend(100).Append(30), root.Traverse());
        }

        [Theory]
        [InlineData(456532, new int[] {1,2})]
        [InlineData(34241, new int[] {2222,2})]
        public void TestNestedYield(int val, IEnumerable<int> list)
        {
            Assert.Equal(test(val, list), list.Append(val));
        }

        // https://stackoverflow.com/questions/2504352/c-sharp-yield-in-nested-method
        #region Nested YieldMethods
        public static IEnumerable<int> test(int val)
        {
            yield return val;

        }
        public static IEnumerable<int> test(int val, IEnumerable<int> parameter)
        {
            foreach (int value in parameter)
            {
                yield return value;
            }

            foreach(int i in test(val))
            {
                yield return i;
            }
        }
        #endregion
    }
}
