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

int muki;//キャラの向き　8方向
int haba,tate;



void jikidan_idou(void);//自機弾移動

void  atari_chk(void);//自機弾と敵の当たりチェック
/////////////////////////////////////////////////////////////////////////



//構造体
struct par{
	int x;//自機の座標
	int y;//
	int haji;//端フラグ
	int gura[8];//グラフィックデータ
	int cnt;//何ループごとに動くか

	int haba;//幅
	int tate;//縦サイズ

	int type;//敵のタイプ

	int x1,y1;//弾の座標

	int muki;//向き

	int sp_x,sp_y;//ｘｙ方向にいくら移動するか

	char num[3];//数字

	int ten;//点数

	int spd;//スピード
	int spd_N;//スピードななめ

	int M_Mode;//移動モード

	int color;//色

	//int tmf[j_tamakazu];//弾数

	//int tx[j_tamakazu],ty[j_tamakazu];//弾座標

	char tamagura[10];//弾の画像

	int tamahaba;//自機弾の幅

	int dead;//死亡フラグ


};

struct par jiki;


//
//typedef struct{
//
//	int hidari;
//	int migi;
//	int ue;
//	int shita;
//	int UL,UR,DL,DR;//左上、右上、左下、右下
//	//０はおしっぱ、１は連打
//
//}K;
//
//K key[2]={0};//構造体初期化


int key=0;//十字キー変数



//int button=0;//ボタン

typedef struct{

	int z;//ｚキー

}b;
b button;//宣言


/*　０：下
１：左下
２：左
３：左上
４：上
５：右上
６：右
７：右下


*/


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

	jiki.haba=48;jiki.tate=64;//自機の縦横サイズ
	jiki.M_Mode=0;//移動モード０（ふつう）


	LoadDivGraph("../Img/mikusan.png" ,8,8,1,48,64,jiki.gura,1);//自機画像（ミクさん）

	/*　０：下
	１：左下
	２：左
	３：左上
	４：上
	５：右上
	６：右
	７：右下


	*/

	white=GetColor(255,255,255);

	jiki.spd=4;//自機のスピード

	jiki.spd_N=jiki.spd*cos(45/180.0*M_PI)+0.5;//自機スピードななめの初期化
	//jiki.spd_N=4;//自機スピードななめ


	FontHandle1=CreateFontToHandle( "ＭＳ ゴシック", 20,  9, DX_FONTTYPE_NORMAL );
	//jiki.gura[0]=LoadGraph("../Img/tama.png");

	jiki.x=320,jiki.y=240;//自機座標初期化



	button.z=0;//zキー0

}


void game_main(void){


	idou();//移動関係
	hyouji();//表示関数


}

void hyouji(){

	//DrawGraph(jiki.x,jiki.y,jiki.gura,1);
	//DrawGraph(jiki.x,jiki.y,jiki.gura[0],1);

	switch(jiki.muki){
		case 0:
			DrawGraph(jiki.x,jiki.y,jiki.gura[0],1);
			break;
		case 1:
			DrawGraph(jiki.x,jiki.y,jiki.gura[1],1);
			break;
		case 2:
			DrawGraph(jiki.x,jiki.y,jiki.gura[2],1);
			break;
		case 3:
			DrawGraph(jiki.x,jiki.y,jiki.gura[3],1);
			break;
		case 4:
			DrawGraph(jiki.x,jiki.y,jiki.gura[4],1);
			break;
		case 5:
			DrawGraph(jiki.x,jiki.y,jiki.gura[5],1);
			break;
		case 6:
			DrawGraph(jiki.x,jiki.y,jiki.gura[6],1);
			break;

		case 7:
			DrawGraph(jiki.x,jiki.y,jiki.gura[7],1);
			break;

	}





	/*　０：下
	１：左下
	２：左
	３：左上
	４：上
	５：右上
	６：右
	７：右下


	*/


	DrawFormatStringToHandle(510,50,white,FontHandle1,"%d",Key_Info);
	DrawFormatStringToHandle(510,70,white,FontHandle1,"十字キー%d",key);
	DrawFormatStringToHandle(510,90,white,FontHandle1,"zキー%d",button.z);

	DrawFormatStringToHandle( 510,230,white,FontHandle1,"速度%d", jiki.spd);
	DrawFormatStringToHandle( 510,250,white,FontHandle1,"ななめ速度%d", (int)(jiki.spd*cos(45/180.0*3.14159)+0.5));



}

void idou(void){

	//上下左右
	if(key==2 && jiki.x>=0){//左
		jiki.x-=jiki.spd;
		jiki.muki=2;
	}
	if(key==6 && jiki.x+jiki.haba<=640){//右
		jiki.x+=jiki.spd;
		jiki.muki=6;
	}
	if(    key==4 && jiki.y>=0  ){//上
		jiki.y-=jiki.spd;
		jiki.muki=4;
	}
	if(    key==0 && jiki.y+jiki.tate<=480 ){//下
		jiki.y+=jiki.spd;
		jiki.muki=0;
	}

	//ななめ
	if(key==3 && jiki.x>=0 && jiki.y>=0){//左上
		jiki.x-=jiki.spd_N;
		jiki.y-=jiki.spd_N;
		jiki.muki=3;
	}
	if(key==5 && jiki.x+jiki.haba<=640 && jiki.y>=0){//右上
		jiki.x+=jiki.spd_N;
		jiki.y-=jiki.spd_N;
		jiki.muki=5;
	}
	if(    key==1 &&   jiki.x>=0 && jiki.y+jiki.tate<=480){//左下
		jiki.x-=jiki.spd_N;
		jiki.y+=jiki.spd_N;
		jiki.muki=1;
	}
	if(    key==7 && jiki.x+jiki.haba<=640 && jiki.y+jiki.tate<=480 ){//右下
		jiki.x+=jiki.spd_N;
		jiki.y+=jiki.spd_N;
		jiki.muki=7;
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

	if(ChkKAny==TRUE){

		if( (Key_Info&0x01)==0x01){key=2;}//左
		if( (Key_Info&0x02)==0x02){key=6;}//右
		if( (Key_Info&0x04)==0x04){key=4;}//上
		if( (Key_Info&0x08)==0x08){key=0;}//下



		if( (Key_Info&0x05)==0x05){key=3;}//左上

		if( (Key_Info&0x06)==0x06){key=5;}//右上

		if( (Key_Info&0x09)==0x09){key=1;	}//左下

		if( (Key_Info&0x0a)==0x0a){key=7;}//右下
		/////////////////////////////

		if( (Key_Info&0x20)==0x20){button.z=1;}else{button.z=0;}

	}else{key=-1;button.z=0;}//キー無効

}