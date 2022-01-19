using System;
using System.Runtime.CompilerServices;

namespace ScriptAPI
{
    public class Vector3
    {
        float x, y, z;

        public Vector3(float _x, float _y, float _z)
        {
            x = _x;
            y = _y;
            z = _z;
        }
    }

    public class ScriptAPIClass
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void TestPrint();

        public static Vector3 ReturnVec3() { Vector3 retval = new Vector3(1.0f, 2.0f, 3.0f); return retval; }
    }
}
