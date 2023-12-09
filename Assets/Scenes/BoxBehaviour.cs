using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class BoxBehaviour : MonoBehaviour
{

    [DllImport("boxcoll")]
    private static extern int SimpleReturnFunc();

    public Rigidbody rb;
    float distToGround = 0.0f;


    // Start is called before the first frame update
    void Start()
    {
        Debug.Log(SimpleReturnFunc());

        // get the distance to ground
        distToGround = GetComponent<Collider>().bounds.extents.y;
        rb = GetComponent<Rigidbody>();
    }

    /*
    // Update is called once per frame
    void Update()
    {
        
    }
    */

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool isJumping = false;

    void OnGUI()
    {
        Event e = Event.current;
        if (e.isKey)
        {
            Debug.Log("Detected key code: " + e.keyCode.ToString());
            //Input.GetKeyDown(KeyCode.Space);

            switch (e.keyCode.ToString())
            {
                case "W":
                    transform.Translate(0, 0, 0.03f);
                    break;
                case "A":
                    transform.Translate(-0.03f, 0, 0);
                    break;
                case "S":
                    transform.Translate(0, 0, -0.03f);
                    break;
                case "D":
                    transform.Translate(0.03f, 0, 0);
                    break;
                case "Space":
                    if(!isJumping)
                    {
                        //transform.Translate(0, 0.03f, 0);
                        rb.velocity = new Vector3(0, 10, 0);
                        Debug.Log("JUUUUUUUUUUUUMP! ");
                        isJumping = true;
                    }
                    break;
                default:
                    Debug.Log("Lala! ");
                    break;
            }
        }

        float tmpDist = GetComponent<Collider>().bounds.extents.y;

        if (!isJumping && (tmpDist - distToGround >=0))
        {
            Debug.Log("Landed! ");
            isJumping = false;
        }

            
        Debug.Log("Dist to ground: " + tmpDist);
    }

    void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag == "Enemy")
        {
            print("Enter");
        }
    }

    void OnTriggerStay(Collider other)
    {
        if (other.gameObject.tag == "Enemy")
        {
            print("Stay");
        }
    }

    void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == "Enemy")
        {
            print("Exit");
        }
    }
}
