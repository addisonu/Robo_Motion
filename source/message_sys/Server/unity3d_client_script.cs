// AUTHOR: AU
// DATE: 02/15/17
// DESC: C# script to start unity3d client
// FILE: unity3d_client_script.cs

using UnityEngine;
using System.Runtime.InteropServices;

class ClientConnectionScript : MonoBehavior {

    #if UNITY_IPHONE
        [DllImport ("__Internal")]

    #else
        [(DllImport ("Server")]

    #endif

    private static extern MessageClient();
    private static extern bool openConnection(string &msg);
    private static extern bool bindSocket(string &msg);
    private static extern bool listenClient(string &msg);
    private static extern void doConnection();
    private static extern bool closeConnection(string &msg);

    void runConnection(){
        MessageClient() client;
        client.openConnection("Connection not opened");
        client.listenClient("Connecting to server");
        client.closeConnection("Connection terminated");
    }
}
