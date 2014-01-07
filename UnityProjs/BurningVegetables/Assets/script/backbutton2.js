#pragma strict
//按钮贴图
public var buttonTexture:Texture2D;


function Start () {
	
}

function Update () {
	
}

function OnGUI () {

	//GUISkin = guiSkin;
    if(GUI.Button(Rect(10,Screen.height-30,buttonTexture.width/3,buttonTexture.height/3),buttonTexture)){
    //if(GUI.Button(Rect(),"","button1")){
        Application.LoadLevel("welcomeScene");
    }
}