#pragma strict
var btnBacktSkin:GUISkin;
var btnChooseLevelSkin:GUISkin;
function OnGUI () {
    	GUI.skin = btnChooseLevelSkin;
    	if(GUI.Button(Rect(Screen.width/2-70 ,Screen.height/2-70,140,120),"")){
           Application.LoadLevel("levelChoose");
    	}
    	
    	GUI.skin = btnBacktSkin;
    	if(GUI.Button(Rect(20 ,Screen.height-55,45,45),"")){
            Application.LoadLevel("welcomeScene");
    	}
}
