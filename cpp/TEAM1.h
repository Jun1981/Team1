#ifndef DEF_TEAM1//二重include防止
#define DEF_TEAM1





#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>

#define _USE_MATH_DEFINES
#include<math.h>
#include "../DxLib/DxLib.h"

#pragma warning(disable:4996)



extern void map_set(int *GHandle);//マップ読み込み

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

int loop;//ループ用
int loop_s;//ループスピードカウンタ

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



//マップ//////////////////////////////////////////
void map_set(int *GHandle);//プロトタイプ

//------ マップ表示用、定数の設定 ------//
#define CHIP_SIZE  32                           // マップチップの大きさ
#define MAP_HEIGHT 480 / CHIP_SIZE              // マップの高さ
#define MAP_WIDTH  640 / CHIP_SIZE              // マップの幅
/////////////////////////////////////////////////////////////////////////


 


//構造体
struct par{
	int x;//自機の座標
	int y;//
	int haji;//端フラグ
	int gura[8];//グラフィックデータ
	int aruki[8][6];//歩き

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









#endif