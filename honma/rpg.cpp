/**********************
 *                    *
 *    ゲームループ    *
 *                    *
 **********************
 */

#include "../DxLib/DxLib.h"
#define P_SPD 4

typedef struct{
	int x;
	int y;
	int muki;
}PY;
int jiki[9];
	
/*---------------------
 *    Main program    *
 *---------------------
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);                     // ウインドウモードに変更(ただし、２５６色)

    if(DxLib_Init() == -1) {                    // ＤＸライブラリ初期化処理
         return -1;                             // エラーが起きたら直ちに終了
    }
    SetDrawScreen(DX_SCREEN_BACK);              // 描画先を裏画面へ
	
	PY py;
	py.x = 200;
	py.y = 200;
	py.muki = 0;
	int map = LoadGraph("maptest.png");
    //------ ゲームループ ------//
    while(CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Escキーが押されるまでループ
        ClsDrawScreen();                        // 裏画面クリア 
		

		if(CheckHitKey(KEY_INPUT_RIGHT) == 1){
			py.x += P_SPD;
			py.muki = 6;
		}
		if(CheckHitKey(KEY_INPUT_LEFT) == 1){
			py.x -= P_SPD;
			py.muki = 2;
		}
		if(CheckHitKey(KEY_INPUT_UP) == 1){
			py.y -= P_SPD;
			py.muki = 4;
		}
		if(CheckHitKey(KEY_INPUT_DOWN) == 1){
			py.y += P_SPD;
			py.muki = 0;
		}
		if(CheckHitKey(KEY_INPUT_LEFT) == 1 && CheckHitKey(KEY_INPUT_DOWN) == 1){
			py.muki = 1;
		}
		if(CheckHitKey(KEY_INPUT_LEFT) == 1 && CheckHitKey(KEY_INPUT_UP) == 1){
			py.muki = 3;
		}
		if(CheckHitKey(KEY_INPUT_RIGHT) == 1 && CheckHitKey(KEY_INPUT_UP) == 1){
			py.muki = 5;
		}
		if(CheckHitKey(KEY_INPUT_RIGHT) == 1 && CheckHitKey(KEY_INPUT_DOWN) == 1){
			py.muki = 7;
		}
		DrawGraph(py.x,py.y,jiki[py.muki],TRUE);
		switch(py.muki){
		case 0:
			DrawString(580,20,"下",GetColor(255,255,255));
			break;

		case 2:
			DrawString(580,20,"左",GetColor(255,255,255));
			break;

		case 4:
			DrawString(580,20,"上",GetColor(255,255,255));
			break;

		case 6:
			DrawString(580,20,"右",GetColor(255,255,255));
			break;
		}
		
		DrawGraph(0,0,map,TRUE);

        ScreenFlip();                           // 裏画面を表画面へ
        if(ProcessMessage() == -1) {            // メッセージ処理
            break;                              // エラーが起きたらループから抜ける
        }
    }
    DxLib_End();                                // ＤＸライブラリ使用の終了処理
    return 0;                                   // ソフトの終了
}
//void key(PY py){
//	
//}