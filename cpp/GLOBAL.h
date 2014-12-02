#ifndef DEF_GLOBAL
#define DEF_GLOBAL


//関数
#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include "../DxLib/DxLib.h"
#include "../cpp/calc.h"

#include "../cpp/player.h"

#include "hyouji.h"//表示
/////////////////////////////////////



//グローバル変数
extern int Key_Trg, Key_Info, Key_Old;   // キー情報r
extern int ChkKAny;                             // とにかくキーが押されたらtrue
extern int GLpCnt;                             // ゲームループカウンタ
extern int i, j, k,l;//ループ用
extern int title;//タイトル画像読み込み用
extern int bg; //ゲーム本編背景画像用
extern int GO;//ゲームオーバー画面読み取り用
extern int cl;//クリア画面用

extern int ten;//点数
extern int et,t_limit;//時間
 
extern int haji;//端フラグ
extern int tamahaba;//弾の幅

extern int FontHandle1;

extern int loop;//ループ用
extern int loop_s;//ループスピードカウンタ



extern int muki;//キャラの向き　8方向
extern int haba,tate;

extern int MHandle[4];  //大マップ用 

extern int white,green,red,blue,purple;


extern int key;//十字キー変数







#endif