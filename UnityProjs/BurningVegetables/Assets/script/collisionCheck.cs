using UnityEngine;
using System.Collections;

public class collisionCheck : MonoBehaviour {

	bool bCollision;
	
	void Start () {
		bCollision = false;
	}
	
	void Update () {
		if(bCollision){
			UnityEngine.Debug.Log("collision");
		}
	}
	
	void OnCollisionEnter2D(Collision2D col){
		//UnityEngine.Debug.Log("collision");
		if(col.gameObject.tag!="protect"){

			Destroy(col.gameObject);
			bCollision = true;
		}
	}	
} 

/*
public class collisionCheck : MonoBehaviour {

	public GameObject heroPrefab;
	GameObject clone;
	float dis = 0f;
	Vector3 originPos;
	Vector3 pos;
	bool bShoot;
	bool bCollision;
	Vector3 dir;
	
	void Start () {
		bShoot = false;
		bCollision = false;
		clone = Instantiate(heroPrefab,heroPrefab.transform.position,heroPrefab.transform.rotation)as GameObject;
	}
	
	void Update () {
		//originPos = clone.transform.position;
		originPos = camera.ScreenToWorldPoint (new Vector3 (Screen.width/2,Screen.height/2,0));
		if(Input.GetMouseButtonDown(0)){
			if(bShoot==false){
				pos = camera.WorldToScreenPoint (clone.transform.position);
				dis = pos.z;
				clone.transform.position = camera.ScreenToWorldPoint (new Vector3 (Input.mousePosition.x, Input.mousePosition.y, dis));
				dir = originPos - heroPrefab.transform.position;
			}
		}
		if(Input.GetMouseButtonDown(1)){
			bShoot=true;
		}
		if(bShoot==true){
			shootHero();
		}
		if(bCollision){
			
			//UnityEngine.Debug.Log("Copy the object");
			clone = Instantiate(heroPrefab,heroPrefab.transform.position,heroPrefab.transform.rotation)as GameObject;
			bCollision = false;
		}
	}
	
	void shootHero(){
		UnityEngine.Debug.Log("shootHero"+dir);
		clone.rigidbody2D.AddForce(new Vector3(200*dir.x,200*dir.y,0));
		bShoot = false;
	}

	void OnCollisionEnter2D(Collision2D col){
		UnityEngine.Debug.Log("collision");
		Destroy(col.gameObject);
		Destroy(clone);
		bCollision = true;
	}	
}*/

/*
public class collisionCheck : MonoBehaviour {

	public GameObject heroPrefab;
	Object clone;
	Vector3 pos;
	bool bCollision;

	void Start () {
		//Instantiate(heroPrefab,Vector3(100,100,0),Quaternion.identity);
		//pos = heroPrefab.transform.localPosition;
		clone = Object.Instantiate(heroPrefab,heroPrefab.transform.position,heroPrefab.transform.rotation);
		bCollision = false;
	}
	
	void Update () {

		UnityEngine.Debug.Log("collision"+heroPrefab.tag);
		if(bCollision){

			//UnityEngine.Debug.Log("Copy the object");
			clone = Object.Instantiate(heroPrefab,heroPrefab.transform.position,heroPrefab.transform.rotation);
			bCollision = false;
		}
	}
	
	void OnCollisionEnter2D(Collision2D col){
		UnityEngine.Debug.Log("collision");
		Destroy(col.gameObject);
		Destroy(clone);
		//transform.position = new Vector3(0,-2,-10);
		bCollision = true;
	}
}*/

/*
public class collisionCheck : MonoBehaviour {

	Vector3 pos;

	void Start () {
		pos = transform.localPosition;
	}

	void Update () {
		
	}

	void OnCollisionEnter2D(Collision2D col){
		UnityEngine.Debug.Log("collision");
		Destroy(col.gameObject);
		//transform.position = new Vector3(0,-2,-10);
	}
}
*/