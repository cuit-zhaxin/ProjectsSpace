#pragma strict
var btnLevel1Skin:GUISkin;
var btnBacktSkin:GUISkin;
function OnGUI () {
    	GUI.skin = btnLevel1Skin;
    	if(GUI.Button(Rect(25 ,110,80,80),"")){
           Application.LoadLevel("GameScene");
    	}
    	
    	GUI.skin = btnBacktSkin;
    	if(GUI.Button(Rect(10 ,Screen.height-70,55,50),"")){
            Application.LoadLevel("levelScene");
    	}
}