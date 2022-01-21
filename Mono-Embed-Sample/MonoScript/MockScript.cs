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
            Vector3 myVec = ScriptAPIClass.ReturnVec3();
            Console.WriteLine($"X: {myVec.xData}, Y: {myVec.yData}, Z: {myVec.zData}\n");
        }

    }
}
