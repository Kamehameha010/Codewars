using System;
using System.Linq;
using System.Text.RegularExpressions;
using System.Collections;
using System.Collections.Generic;

namespace codewars
{
    class Program
    {

        public static int[] ArrayDiff(int[] a, int[] b)
        {
            /**
                a.Where(x => !b.Contains(x)).ToArray();
            **/
            return (from c in a
                    where !b.Contains(c)
                    select c).ToArray();
        }
        public static int Solution(int value)
        {
            /**
                Enumerable.Range(0,value).Sum( i=> (i % 3 == 0) || (i % 5 == 0) ? i : 0);
            **/
            int sum = 0;
            for (int i = 0; i < value; ++i)
            {
                sum += (i % 3 == 0) || (i % 5 == 0) ? i : 0;
            }
            return sum;
        }
        public static string Maskify(string cc)
        {
            return string.Join("", Enumerable.Repeat("#", cc.Length - 4)) + string.Join("", cc.TakeLast(4)); ;
        }
        public static IEnumerable<int> GetIntegersFromList(List<object> listOfItems)
        {
            //return listOfItems.OfType<int>();
            return listOfItems.Where(x => x.GetType() == typeof(int)).Cast<int>();
        }
        public static string SpinWords(string sentence)
        {
            string result = "";
            foreach (var str in sentence.Split(" "))
            {
                result += str.Length > 4 ? $"{String.Join("", str.Reverse())} " : $"{str} ";
            }
            return result.Trim();
        }
        public static bool validBraces(String braces)
        {
            return braces.Count(x => x == '(') == braces.Count(x => x == ')') &&
                  braces.Count(x => x == '[') == braces.Count(x => x == ']') &&
                    braces.Count(x => x == '{') == braces.Count(x => x == '}');
        }
        public static string BreakCamelCase(string str)
        {
            return String.Join("", str.Select(x => Char.IsUpper(x) ? $" {x}" : $"{x}"));
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solution(10));
            Console.WriteLine(Maskify("Hola mUndo Como esta"));
            Console.WriteLine(SpinWords("Just gniddik ereht is llits one more"));
            string abc = "[(])";
            foreach (var item in abc)
            {
                Console.WriteLine((int)item);
            }
            Console.WriteLine(validBraces(abc));
            Console.WriteLine(BreakCamelCase("palabraClaveCazonsalud"));
        }
    }
}
