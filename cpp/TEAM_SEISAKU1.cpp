#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>

#define _USE_MATH_DEFINES
#include<math.h>


#include "../DxLib/DxLib.h"

#pragma warning(disable:4996)

//グローバル変数
int Key_Trg, Key_Info, Key_Old;   // キー情報r
int ChkKAny;                             // とにかくキーが押されたらtrue
int GLpCnt;                             // ゲームループカウンタ
int i, j, k,l;//ループ用
int title;//タイトル画像読み込み用
int bg; //ゲーム本編背景画像用
int GO;//ゲームオーバー画面読み取り用
int cl;//クリア画面用

int ten;//点数
int et,t_limit;//時間

int haji=0;//端フラグ
int tamahaba=0;//弾の幅

int FontHandle1;

//色
int white,green,red,blue,purple;
//////////////////////////////////////////////////変数宣言終わり



//プロトタイプ関数/////////////////////////////////////////////////////////s
void init(void);//初期化
void key_chk(void);//キーチェック
void key_henkan(void);//キー変換

void hyouji(void);//表示

int haji_chk(void);//端チェック
void game_main(void);//メイン

void idou(void);//敵移動関数

void jiki_shot(void);//自機の弾うち関数



void jikidan_idou(void);//自機弾移動

void  atari_chk(void);//自機弾と敵の当たりチェック
/////////////////////////////////////////////////////////////////////////



//構造体
struct par{
	int x;//自機の座標
	int y;//
	int haji;//端フラグ
	int gura;//グラフィックデータ

	int cnt;//何ループごとに動くか

	int haba;//幅

	int type;//敵のタイプ

	int x1,y1;//弾の座標

	int muki;//向き

	int sp_x,sp_y;//ｘｙ方向にいくら移動するか

	char num[3];//数字

	int ten;//点数

	int spd;//スピード

	int color;//色

	//int tmf[j_tamakazu];//弾数

	//int tx[j_tamakazu],ty[j_tamakazu];//弾座標

	char tamagura[10];//弾の画像

	int tamahaba;//自機弾の幅

	int dead;//死亡フラグ


};

struct par jiki;



typedef struct{

	int hidari;
	int migi;
	int ue;
	int shita;
	int UL,UR,DL,DR;//左上、右上、左下、右下
	//０はおしっぱ、１は連打

}K;

K key[2]={0};//構造体初期化








/////////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	//
	ChangeWindowMode(TRUE);                     // ウインドウモードに変更(ただし、２５６色)

	if (DxLib_Init() == -1) {                    // ＤＸライブラリ初期化処理
		return -1;                              // エラーが起きたら直ちに終了
	}

	//


	init();//初期化

	SetDrawScreen(DX_SCREEN_BACK);              // 描画先を裏画面へ




	// ゲームシステム初期化
	//------ ゲームループ ------//
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Escキーが押されるまでループ
		ClsDrawScreen();                        // 裏画面クリア


		// ゲームコントロールメイン
		key_chk();//キーチェック
		key_henkan();//キー変換（おしっぱor連打）

		game_main();



		ScreenFlip();                           // 裏画面を表画面へ
		if (ProcessMessage() == -1) {            // メッセージ処理
			break;                              // エラーが起きたらループから抜ける
		}
	}
	DxLib_End();// ＤＸライブラリ使用の終了処理
	return 0;// アプリケーションの終了

}



void init(void){

	white=GetColor(255,255,255);

	jiki.spd=10;//自機のスピード



	FontHandle1=CreateFontToHandle( "ＭＳ ゴシック", 20,  9, DX_FONTTYPE_NORMAL );
	jiki.gura=LoadGraph("../Img/tama.png");

	jiki.x=320,jiki.y=240;//自機座標初期化

}


void game_main(void){


	idou();//移動関係
	hyouji();//表示関数


}

void hyouji(){

	DrawGraph(jiki.x,jiki.y,jiki.gura,1);


	DrawFormatStringToHandle(510,50,white,FontHandle1,"%d",Key_Info);
	DrawFormatStringToHandle(510,70,white,FontHandle1,"上%d",key[0].ue);
	DrawFormatStringToHandle(510,90,white,FontHandle1,"下%d",key[0].shita);
	DrawFormatStringToHandle(510,110,white,FontHandle1,"左%d",key[0].hidari);
	DrawFormatStringToHandle(510,130,white,FontHandle1,"右%d",key[0].migi);
	DrawFormatStringToHandle(510,150,white,FontHandle1,"左上%d",key[0].UL);
	DrawFormatStringToHandle(510,170,white,FontHandle1,"右上%d",key[0].UR);
	DrawFormatStringToHandle(510,190,white,FontHandle1,"左下%d",key[0].DL);
	DrawFormatStringToHandle(510,210,white,FontHandle1,"右下%d",key[0].DR);
	DrawFormatStringToHandle( 510,230,white,FontHandle1,"%d", jiki.spd);
	DrawFormatStringToHandle( 510,250,white,FontHandle1,"%lf", cos(30/180*3.14159));



}

void idou(void){

	//上下左右
	if(key[0].hidari==1 /*&& key[0].DL==0 && key[0].UL==0*/){//左
		jiki.x-=jiki.spd;
	}
	if(key[0].migi==1 /*&& key[0].UR==0 && key[0].DR==0*/){//右
		jiki.x+=jiki.spd;
	}
	if(    key[0].ue==1 /*&& key[0].UL==0 && key[0].UR==0 */  ){//上
		jiki.y-=jiki.spd;
	}
	if(    key[0].shita==1 /*&& key[0].DL==0 && key[0].DR==0 */ ){//下
		jiki.y+=jiki.spd;
	}

	//ななめ
	if(key[0].UL==1){//左上S
		jiki.x-=jiki.spd*cos(45/180*M_PI);

		jiki.y-=jiki.spd*cos(45/180*M_PI);
	}
	if(key[0].UR==1){//右上
		jiki.x+=jiki.spd*cos(45/180*M_PI);
		jiki.y-=jiki.spd*cos(45/180*M_PI);
	}
	if(    key[0].DL==1    ){//左下
		jiki.x-=jiki.spd*cos(45/180*M_PI);
		jiki.y+=jiki.spd*cos(45/180*M_PI);
	}
	if(    key[0].DR==1  ){//右下
		jiki.x+=jiki.spd*cos(45/180*M_PI);
		jiki.y+=jiki.spd*cos(45/180*M_PI);
	}


}




void key_chk(){

	/*---------------------
	*    キー情報取得    *
	*---------------------
	*
	*    LEFT  = 0000 0001
	*    RIGHT = 0000 0010
	*    UP    = 0000 0100
	*    DOWN  = 0000 1000
	*    key_trgは押した瞬間の情報
	*    key_infoは今の状態
	*
	*/
	Key_Trg = Key_Info = 0;                                 // キー情報クリア
	ChkKAny = false;
	if (CheckHitKey(KEY_INPUT_LEFT))   { Key_Info |= 0x01; }
	if (CheckHitKey(KEY_INPUT_RIGHT))  { Key_Info |= 0x02; }
	if (CheckHitKey(KEY_INPUT_UP))     { Key_Info |= 0x04; }
	if (CheckHitKey(KEY_INPUT_DOWN))   { Key_Info |= 0x08; }
	if (CheckHitKey(KEY_INPUT_SPACE))  { Key_Info |= 0x10; }
	if (CheckHitKey(KEY_INPUT_Z))      { Key_Info |= 0x20; }
	if (CheckHitKey(KEY_INPUT_ESCAPE)) { Key_Info |= 0x40; }
	if (CheckHitKeyAll()) { ChkKAny = true; }                    // あにー

	Key_Trg = (Key_Info ^ Key_Old) & Key_Info;          // キートリガー情報セット
	Key_Old = Key_Info;                                     // キー情報セーブ
}
void key_henkan(void){


	//上下左右おしっぱ
	if( (Key_Info&0x01)==0x01){//左
		key[0].hidari=1;
	}else {
		key[0].hidari=0;
	}
	if( (Key_Info&0x02)==0x02){//右
		key[0].migi=1;
	}else{
		key[0].migi=0;
	}



	if( (Key_Info&0x04)==0x04){//上
		key[0].ue=1;
	}else{
		key[0].ue=0;

	}


	if( (Key_Info&0x08)==0x08){//下
		key[0].shita=1;
	}else {
		key[0].shita=0;
	}



	if( (Key_Info&0x05)==0x05){//左上
		key[0].hidari=key[0].ue=0;
		key[0].UL=1;
		key[0].hidari=key[0].ue=0;
	}else {
		key[0].UL=0;
	}

	if( (Key_Info&0x06)==0x06){//右上

		key[0].migi=key[0].ue=0;//右と上を０

		key[0].UR=1;
		key[0].ue=key[0].migi=0;
	}else {
		key[0].UR=0;
	}

	if( (Key_Info&0x09)==0x09){//左下

		key[0].hidari=key[0].shita=0;

		key[0].DL=1;
		key[0].hidari=key[0].shita=0;
	}else {
		key[0].DL=0;
	}

	if( (Key_Info&10)==10){//右下

		key[0].migi=key[0].shita=0;

		key[0].DR=1;
		key[0].migi=key[0].shita=0;
	}else {
		key[0].DR=0;
	}
	/////////////////////////////

}

