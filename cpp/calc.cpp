#include "../cpp/GLOBAL.h"
#include "../cpp/calc.h"
#include "../cpp/player.h"

void calc(void){

	//上下左右
	if(key==2){jiki.muki=2;
	if(jiki.x>=0){jiki.x-=jiki.spd;}
	}
	if(key==6){//右
		jiki.muki=6;
		//if( jiki.x+jiki.haba<=640){//右
		//	jiki.x+=jiki.spd;
		//}
		
		jiki.x+=jiki.spd;
		
		if( jiki.x+jiki.haba<=640){//右
		}

	}
	if(key==4){
		jiki.muki=4;
		if(   jiki.y>=0  ){//上
			jiki.y-=jiki.spd;
		}
	}
	if(key==0){//下
		jiki.muki=0;
		if(    jiki.y+jiki.tate<=480 ){//下
			jiki.y+=jiki.spd;
		}
	}

	//ななめ

	if(key==3){//左上
		if(jiki.x>0 && jiki.y>0){
			jiki.x-=jiki.spd_N;
			jiki.y-=jiki.spd_N;
			jiki.muki=3;
		}else if(jiki.x>0 && jiki.y<=0){//左上で上にぶつかった時左に
			jiki.x-=jiki.spd_N;		
			jiki.muki=2;
		}else if(jiki.x<=0 && jiki.y>0){//左上で左にぶつかった時上に
			jiki.y-=jiki.spd_N;	
			jiki.muki=4;
		}
	}


	if(key==5){
		if(jiki.x+jiki.haba<640 && jiki.y>=0){//右上
			jiki.x+=jiki.spd_N;
			jiki.y-=jiki.spd_N;
			jiki.muki=5;
		}else if(jiki.x+jiki.haba<640 && jiki.y<=0){//右上で上にぶつかった時右に
			jiki.x+=jiki.spd_N;		
			jiki.muki=6;
		}else if(jiki.x+jiki.haba>=640 && jiki.y>0){//右上で右にぶつかった時上に
			jiki.y-=jiki.spd_N;	
			jiki.muki=4;
		}
	}

	if(key==1){
		if(jiki.x>0 && jiki.y+jiki.tate<480){//左下
			jiki.x-=jiki.spd_N;
			jiki.y+=jiki.spd_N;
			jiki.muki=1;
		}else if( jiki.x>0 && jiki.y+jiki.tate>=480){//左下&下
			jiki.x-=jiki.spd_N;
			jiki.muki=2;
		}else if(jiki.x<=0 && jiki.y+jiki.tate<480){//左下＆左
			jiki.y+=jiki.spd_N;
			jiki.muki=0;
		}
	}

	if(key==7){
		if(    jiki.x+jiki.haba<640 && jiki.y+jiki.tate<480 ){//右下
			jiki.x+=jiki.spd_N;
			jiki.y+=jiki.spd_N;
			jiki.muki=7;
		}else if(jiki.x+jiki.haba<640 && jiki.y+jiki.tate>=480 ){//右下＆↓
			jiki.x+=jiki.spd_N;
			
			jiki.muki=6;
		}else if( jiki.x+jiki.haba>=640 && jiki.y+jiki.tate<480 ){//右下＆右
			jiki.y+=jiki.spd_N;
			jiki.muki=0;
		}
	}

	//移動モード切替
	if(button.z==1){
		jiki.spd=10;
		jiki.spd_N=jiki.spd*cos(45/180.0*M_PI)+0.5;
	}else{
		jiki.spd=4;
		jiki.spd_N=jiki.spd*cos(45/180.0*M_PI)+0.5;//自機スピードななめの初期化
	}

}


