using System;
using System.Runtime.CompilerServices;

namespace MonoScript
{
    public class ScriptAPI
    {

        [MethodImpl(MethodImplOptions.InternalCall)]
        extern static void PrintData();
        [MethodImpl(MethodImplOptions.InternalCall)]
        extern static void AddData(string _data);

        static void TestPrint()
        {
            Console.WriteLine("[C#] Executing TestPrint() from C# side...\n");
            Console.WriteLine("[C#] Printing ECS data...: ");
            PrintData();
            Console.WriteLine("[C#] Printing complete.\n");
            Console.WriteLine("[C#] Adding data via internal call...\n");
            AddData("Data 1: Added from Script");
            Console.WriteLine("[C#] Printing ECS data...: ");
            PrintData();
            Console.WriteLine("[C#] Printing complete.\n\n");
            Console.WriteLine("[C#] Completed TestPrint()\n");
        }
    }
}
