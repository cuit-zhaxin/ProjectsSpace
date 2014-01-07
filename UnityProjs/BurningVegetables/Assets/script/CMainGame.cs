using UnityEngine;
using System;
using System.Collections;

public class CMainGame : MonoBehaviour {
	
	public GameObject heroPrefab;
	public GameObject enemyPrefab;
	GameObject dg;
	GameObject clone;
	GameObject clone_enemy;
	Array arrEnemy;
	float dis = 0f;
	Vector3 originPos;
	Vector3 pos;
	bool bShoot;
	Vector3 dir;
	bool bHeroStandBy;
	int currState;

	enum ENEMYSTATE{
		level0=0,
		level1=1,
		level2=2,
	}
	
	void Start () {
		bShoot = false;
		bHeroStandBy = false;
		arrEnemy = null;
		currState = 0;
		dg = GameObject.Find ("dg0");
		clone = Instantiate(heroPrefab,heroPrefab.transform.position,heroPrefab.transform.rotation)as GameObject;
		originPos = camera.ScreenToWorldPoint (new Vector3 (Screen.width/2,Screen.height/2,10));
		originPos = dg.transform.position;
		enemyState (currState);
		//enemyState (ENEMYSTATE.level2);
		Invoke ("autoChangeState", 6);
	}
	
	void Update () {
		if (!clone) {
			bHeroStandBy=false;
		}
		animWood ();
		//originPos = camera.ScreenToWorldPoint (clone.transform.position);
		if(Input.GetMouseButtonDown(0)){
			if(bShoot==false){
				pos = camera.WorldToScreenPoint (clone.transform.position);
				dis = pos.z;
				clone.transform.position = camera.ScreenToWorldPoint (new Vector3 (Input.mousePosition.x, Input.mousePosition.y, dis));
				dir = -(originPos - clone.transform.position);
			}
		}
		if(Input.GetMouseButtonDown(1)){
			bShoot=true;
			bHeroStandBy = true;
		}

		if(bHeroStandBy){
			UnityEngine.Debug.Log("shootHero"+dir);
			Vector3 pos1 = camera.WorldToScreenPoint (clone.transform.position);
			float dis1 = pos1.z;
			//clone.transform.position =
			//	camera.ScreenToWorldPoint (new Vector3(pos1.x+Time.deltaTime*200,pos1.y+200*Time.deltaTime, dis1));
			clone.transform.position =camera.ScreenToWorldPoint (new Vector3(pos1.x-1*Time.deltaTime*200*dir.x,pos1.y+200*Time.deltaTime*dir.y, dis1));
			//clone.rigidbody2D.AddForce(new Vector3(2*dir.x,2*dir.y,0));
			if(bShoot==true){
				shootHero();
			}
		}
	}

	void animWood(){
		for(int i=0;i<4;i++){
			GameObject wood = GameObject.Find ("protect"+i);
			Vector3 pos3 = camera.WorldToScreenPoint (wood.transform.position);
			float dis3 = pos3.z;
			wood.transform.position =camera.ScreenToWorldPoint(new Vector3(pos3.x+40.0f*Time.deltaTime,pos3.y,dis3));
			if(camera.WorldToScreenPoint (wood.transform.position).x >Screen.width+100){
				wood.transform.position=camera.ScreenToWorldPoint(new Vector3(-90,pos3.y,dis3));
			}
		}
	}

	void shootHero(){
		//clone.rigidbody2D.AddForce(new Vector3(200*dir.x,200*dir.y,0));
		bShoot = false;
	}

	void autoChangeState(){
		currState++;
		enemyState(currState);
	}

	void enemyState(int state){

		if((int)ENEMYSTATE.level0 == state){
			currState = state;
			for(int i=0;i<5;i++){
				clone_enemy = Instantiate(enemyPrefab,enemyPrefab.transform.position,enemyPrefab.transform.rotation)as GameObject;
				if(0 == i){
					clone_enemy.transform.position -= new Vector3(0,0.5f,0);
				}
				clone_enemy.name="level0"+i;
				//clone_enemy.rigidbody2D.AddForce(new Vector3(0,1,0));
				InvokeRepeating("moveEnemy",1,0.1f);
			}
		}

		if((int)ENEMYSTATE.level1 == state){
			for(int i=0;i<5;i++){
				clone_enemy = Instantiate(enemyPrefab,enemyPrefab.transform.position,enemyPrefab.transform.rotation)as GameObject;
				if(0 == i){
					clone_enemy.transform.position -= new Vector3(0.5f,0,0);
				}
				clone_enemy.name="level1"+i;
				InvokeRepeating("moveEnemy",1,0.1f);
			}
		}
	}

	void moveEnemy(){

		for(int i=0;i<5;i++){
			GameObject obj = GameObject.Find("level0"+i);
			if(obj){
				obj.transform.position += new Vector3 (0, -0.01f, 0);
			}
		    /*
			//checke out the result of the game 
			if(obj.transform.position.y<150){

				gameLoose(currState);
			}*/
		}
		for(int i=0;i<5;i++){
			GameObject obj = GameObject.Find("level1"+i);
			if(obj){
				obj.transform.position += new Vector3 (0, -0.01f, 0);
			}
			/*
			//checke out the result of the game 
			if(obj.transform.position.y<150){
				
				gameLoose(currState);
			}*/
		}
	}

	void gameWin(int nLevel){

		Debug.Log("Win the Game!");
		//Application.LoadLevel("WinGameLayer");
	}

	void gameLoose(int nLevel){

		Debug.Log("Loose the Game!");
		//Application.LoadLevel("LooseGameLayer");
	}
/*
	//draw the test line
	public Material material;
	void OnPostRender(){
		if(!material){        //需要在项目视图中添加material，给线条添加材质（颜色）	
			Debug.Log("请给材质资源赋值");
			return;
		}
		material.SetPass(0);
		GL.LoadOrtho();
		GL.Begin(GL.LINES);
		DrawLine(0,150,320,150);
		DrawLine(0,180,320,180);
		GL.End();
	}

	void DrawLine(float x1,float y1,float x2,float y2){
		GL.Vertex(new Vector3(x1/Screen.width,y1/Screen.height,0));
		GL.Vertex(new Vector3(x2/Screen.width,y2/Screen.height,0));
	}*/
}

/*
public class CMainGame : MonoBehaviour {

	GameObject heroObj;
	float dis = 0f;
	Vector3 originPos;
	Vector3 pos;
	bool bShoot;
	Vector3 dir;

	void Start () {
		bShoot=false;
		//heroObj = GameObject.Find("hero");
		heroObj = GameObject.FindGameObjectWithTag("Player");
	}

    void Update () {
		//originPos = heroObj.transform.position;
		originPos = new Vector3 (Screen.width/2,Screen.height/2,0);
		if(Input.GetMouseButtonDown(0)){
			if(bShoot==false){
				pos = camera.WorldToScreenPoint (heroObj.transform.position);
				dis = pos.z;
				heroObj.transform.position = camera.ScreenToWorldPoint (new Vector3 (Input.mousePosition.x, Input.mousePosition.y, dis));
				dir = originPos - heroObj.transform.position;
			}
		}
		if(Input.GetMouseButtonDown(1)){
			bShoot=true;
		}
		if(bShoot==true){
			shootHero();
		}
	}

	void shootHero(){
		//pos = camera.WorldToScreenPoint (heroObj.transform.position);
		//dis = pos.z;
		//heroObj.transform.position = camera.ScreenToWorldPoint (new Vector3(pos.x+Time.deltaTime*200*dir.x,pos.y+200*Time.deltaTime*dir.y, dis));
		heroObj.rigidbody2D.AddForce(new Vector3(20*dir.x,20*dir.y,0));
		//Destroy(heroObj,10);
	}

}
 */
