#include "../cpp/GLOBAL.h"

#pragma warning(disable:4996)
extern void map_init();

void init(void);//初期化
void key_chk(void);//キーチェック
void key_henkan(void);//キー変換


int haji_chk(void);//端チェック
void game_main(void);//メイン
 // スクロール座標







/////////////////////////////////////////////////////////////////////////



//マップ//////////////////////////////////////////
//void map_set(int *MHandle);//プロトタイプ

//------ マップ表示用、定数の設定 ------//


#define CHIP_SIZE  32                           // マップチップの大きさ
#define MAP_HEIGHT 480 / CHIP_SIZE              // マップの高さ
#define MAP_WIDTH  640 / CHIP_SIZE              // マップの幅


/////////////////////////////////////////////////////////////////////////



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






void game_main(void){

	//map_set(GHandle);
	calc();//計算関係
	hyouji();//表示関数
			

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

		if( (Key_Info&0x01)!=0x01
		  && (Key_Info&0x02)!=0x02
		  && (Key_Info&0x04)!=0x04
		  && (Key_Info&0x08)!=0x08
		  && (Key_Info&0x05)!=0x05
		  && (Key_Info&0x06)!=0x06
		  && (Key_Info&0x09)!=0x09){
			  key=-1;//十字キー無効
		}




		if( (Key_Info&0x20)==0x20){button.z=1;}else{button.z=0;}

	}else{key=-1;button.z=0;}//キー無効

}




