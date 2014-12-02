
#include "../cpp/GLOBAL.h"
#include "../cpp/init.h"
#include"player.h"


void init(void){

	jiki.haba=48;jiki.tate=72;//自機の縦横サイズ
	jiki.M_Mode=0;//移動モード０（ふつう）

	

///画像読み込み


	// LoadDivGraph("../Img/MAP/test2.jpg", 4, 4, 1, 32, 32, GHandle);//テストマップ

	


    LoadDivGraph("../Img/MAP/town.jpg",4,2,2,640,480,MHandle,0);//大マップ
	 

	LoadDivGraph("../Img/miku/mikusan.png" ,8,8,1,48,64,jiki.gura,1);//自機画像（ミクさん）

	LoadDivGraph("../Img/miku/loop1000/loop0.png" ,6,6,1,48,64,jiki.aruki[0],1);//自機画像（ミクさん）下
	LoadDivGraph("../Img/miku/loop1001/loop1.png" ,6,6,1,48,64,jiki.aruki[1],1);//自機画像（ミクさん）左下
	LoadDivGraph("../Img/miku/loop1002/loop2.png" ,6,6,1,48,64,jiki.aruki[2],1);//自機画像（ミクさん）左
				  
	LoadDivGraph("../Img/miku/loop1003/loop3.png" ,6,6,1,48,64,jiki.aruki[3],1);//自機画像（ミクさん）左上
			
	LoadDivGraph("../Img/miku/loop1004/loop4.png" ,6,6,1,48,64,jiki.aruki[4],1);//自機画像（ミクさん）上
	LoadDivGraph("../Img/miku/loop1005/loop5.png" ,6,6,1,48,64,jiki.aruki[5],1);//自機画像（ミクさん）右上
				
	LoadDivGraph("../Img/miku/loop1006/loop6.png" ,6,6,1,48,64,jiki.aruki[6],1);//自機画像（ミクさん）右
	LoadDivGraph("../Img/miku/loop1007/loop7.png" ,6,6,1,48,64,jiki.aruki[7],1);//自機画像（ミクさん）右下
		
	loop_s=10;
	loop=0;


	white=GetColor(255,255,255);

	jiki.spd=4;//自機のスピード

	jiki.spd_N=jiki.spd*cos(45/180.0*M_PI)+0.5;//自機スピードななめの初期化
	//jiki.spd_N=4;//自機スピードななめ


	FontHandle1=CreateFontToHandle( "ＭＳ ゴシック", 20,  9, DX_FONTTYPE_NORMAL );
	//jiki.gura[0]=LoadGraph("../Img/tama.png");

	jiki.x=320,jiki.y=240;//自機座標初期化



	button.z=0;//zキー0

}

