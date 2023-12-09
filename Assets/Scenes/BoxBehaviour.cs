using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class BoxBehaviour : MonoBehaviour
{

    [DllImport("boxcoll")]

    private static extern int SimpleReturnFunc();

    
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log(SimpleReturnFunc());
    }

    /*
    // Update is called once per frame
    void Update()
    {
        
    }
    */
}
