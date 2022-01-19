using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using ScriptAPI;

namespace MonoScript
{
    class MockScript : MonoScript
    {
        public void OnAwake()
        {
            Console.WriteLine("Calling OnAwake()\n");
            ScriptAPIClass.TestPrint();
        }

        public Vector3 RetVec3()
        {
            Console.WriteLine("Calling RetVec3!\n");
            return ScriptAPIClass.ReturnVec3();
        }

    }
}
