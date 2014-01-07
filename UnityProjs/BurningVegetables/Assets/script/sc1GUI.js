#pragma strict
var btnStartSkin:GUISkin;
var btnFriendsSkin:GUISkin;
var btnShuijingSkin:GUISkin;
function OnGUI () {
    	GUI.skin = btnStartSkin;
    	if(GUI.Button(Rect(Screen.width/2-70 ,Screen.height/2+30,140,120),"")){
            Application.LoadLevel("levelScene");
    	}
    	
    	GUI.skin = btnFriendsSkin;
    	if(GUI.Button(Rect(20 ,Screen.height-55,45,45),"")){
            //Application.LoadLevel("levelScene");
    	}
    	
    	GUI.skin = btnShuijingSkin;
    	if(GUI.Button(Rect(Screen.width-100 ,Screen.height-60,50,50),"")){
            //Application.LoadLevel("levelScene");
    	}
}
