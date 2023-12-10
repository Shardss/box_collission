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
        //Debug.Log(SimpleReturnFunc());

        // get the distance to ground
        distToGround = GetComponent<Collider>().bounds.extents.y;
        rb = GetComponent<Rigidbody>();
    }

    
    // Update is called once per frame
    void Update()
    {
       /* Vector3 totalMovement = Vector3.zero;

        if (Input.GetKey(KeyCode.W))
        {
            totalMovement += transform.forward;
        }
        if (Input.GetKey(KeyCode.A))
        {
            totalMovement -= transform.right;
        }
        if (Input.GetKey(KeyCode.S))
        {
            totalMovement -= transform.forward;
        }
        if (Input.GetKey(KeyCode.D))
        {
            totalMovement += transform.right;
        }
        if (Input.GetKey(KeyCode.Space))
        {
            totalMovement += transform.forward;
        }*/

        //Store user input as a movement vector
        Vector3 m_Input = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical"));

        //Apply the movement vector to the current position, which is
        //multiplied by deltaTime and speed for a smooth MovePosition
        rb.MovePosition(transform.position + m_Input * Time.deltaTime * 5f);

        // ===============
        /*
        Event e = Event.current;
        if (e.isKey)
        {
            Debug.Log("Detected key code: " + e.keyCode.ToString());
            //Input.GetKeyDown(KeyCode.Space);

            switch (e.keyCode.ToString())
            {
                case "W":
                    //rb.AddForce(new Vector3(0, 0.1f, 0.5f), ForceMode.Acceleration);
                    rb.velocity = new Vector3(0, 0, 3);
                    //transform.Translate(0, 0, 0.03f);
                    break;
                case "A":
                    rb.velocity = new Vector3(-3, 0, 0);
                    //transform.Translate(-0.03f, 0, 0);
                    break;
                case "S":
                    rb.velocity = new Vector3(0, 0, -3);
                    //transform.Translate(0, 0, -0.03f);
                    break;
                case "D":
                    rb.velocity = new Vector3(3, 0, 0);
                    //transform.Translate(0.03f, 0, 0);
                    break;
                case "Space":
                    if (!isJumping)
                    {
                        //transform.Translate(0, 0.03f, 0);
                        rb.velocity = new Vector3(0, 5, 0);
                        Debug.Log("JUUUUUUUUUUUUMP! ");
                        isJumping = true;
                    }
                    break;
                default:
                    //Debug.Log("Lala! ");
                    break;
            }
        }

        float tmpDist = GetComponent<Collider>().bounds.extents.y;

        if (isJumping && (tmpDist - distToGround >= 0))
        {
            Debug.Log("Landed! ");
            isJumping = false;
        }
*/

        //Debug.Log("Dist to ground: " + tmpDist);
    }


    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool isJumping = false;

    void OnGUI()
    {
        
    }

    void OnCollisionEnter(Collision other)
    {
        if(other.gameObject.tag == "Enemy")
        {
            var enemyRenderer = other.gameObject.GetComponent<Renderer>();
            enemyRenderer.material.color = Color.red;
            print("Enter");
        }
    }

/*
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
*/

}
