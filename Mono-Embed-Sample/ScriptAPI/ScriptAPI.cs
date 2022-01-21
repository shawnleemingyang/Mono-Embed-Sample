using System;
using System.Runtime.CompilerServices;

namespace ScriptAPI
{
    public class Vector3
    {
        public float xData;
        public float yData;
        public float zData;

        //public Vector3(float _x, float _y, float _z)
        //{
        //    x = _x;
        //    y = _y;
        //    z = _z;
        //}
    }

    public class ScriptAPIClass
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void TestPrint();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Vector3 ReturnVec3();

        
    }
}
