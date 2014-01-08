#pragma strict
var btnStartSkin:GUISkin;
var btnFriendsSkin:GUISkin;
var btnShuijingSkin:GUISkin;
//var btnAudioClip:AudioClip;
//private var btnAudioEffect:AudioSource;

function OnStart(){
	//btnAudioEffect = gameObject.AddComponent<AudioSource>();
	//btnAudioEffect.clip = btnAudioClip;
}

function OnGUI () {
    	GUI.skin = btnStartSkin;
    	if(GUI.Button(Rect(Screen.width/2-70 ,Screen.height/2+30,140,120),"")){
    		//btnAudioEffect.Play();
            Application.LoadLevel("levelScene");
    	}
    	
    	GUI.skin = btnFriendsSkin;
    	if(GUI.Button(Rect(20 ,Screen.height-55,45,45),"")){
    		//btnAudioEffect.Play();
            //Application.LoadLevel("levelScene");
    	}
    	
    	GUI.skin = btnShuijingSkin;
    	if(GUI.Button(Rect(Screen.width-100 ,Screen.height-60,50,50),"")){
    		//btnAudioEffect.Play();
            //Application.LoadLevel("levelScene");
    	}
}
