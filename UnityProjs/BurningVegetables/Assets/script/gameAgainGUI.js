#pragma strict
var btnAgainSkin:GUISkin;
var btnListSkin:GUISkin;
var btnNextSkin:GUISkin;

function Start () {

}

function OnGUI () {

	GUI.skin = btnAgainSkin;
    	if(GUI.Button(Rect(Screen.width/2-90 ,Screen.height/2+115,60,60),"")){
            Application.LoadLevel("GameScene");
    	}
    	
    	GUI.skin = btnListSkin;
    	if(GUI.Button(Rect(Screen.width/2-30 ,Screen.height/2+115,60,50),"")){
            Application.LoadLevel("levelChoose");
    	}
    	
    	GUI.skin = btnNextSkin;
    	if(GUI.Button(Rect(Screen.width/2+30 ,Screen.height/2+115,60,50),"")){
            Application.LoadLevel("GameScene2");
    	}
}