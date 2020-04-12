using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Test();
            Console.ReadKey();
        }

        static void Test()
        {
            var e = new TestLibNet.Entry();
            e.Add("nihao");
            e.Add("tahao");
            var content = e.GetJson();
            Console.WriteLine($"Document: {content}");
            Console.WriteLine("Entries: ");
            var list = e.GetAssets();
            foreach (var s in list)
            {
                Console.WriteLine(s);
            }
        }
    }
}
