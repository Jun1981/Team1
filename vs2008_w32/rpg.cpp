/**********************
 *                    *
 *    �Q�[�����[�v    *
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
    ChangeWindowMode(TRUE);                     // �E�C���h�E���[�h�ɕύX(�������A�Q�T�U�F)

    if(DxLib_Init() == -1) {                    // �c�w���C�u��������������
         return -1;                             // �G���[���N�����璼���ɏI��
    }
    SetDrawScreen(DX_SCREEN_BACK);              // �`���𗠉�ʂ�
	
	PY py;
	py.x = 200;
	py.y = 200;
	py.muki = 0;
	int map = LoadGraph("maptest.png");
    //------ �Q�[�����[�v ------//
    while(CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Esc�L�[���������܂Ń��[�v
        ClsDrawScreen();                        // ����ʃN���A 
		

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
			DrawString(580,20,"��",GetColor(255,255,255));
			break;

		case 2:
			DrawString(580,20,"��",GetColor(255,255,255));
			break;

		case 4:
			DrawString(580,20,"��",GetColor(255,255,255));
			break;

		case 6:
			DrawString(580,20,"�E",GetColor(255,255,255));
			break;
		}
		
		DrawGraph(0,0,map,TRUE);

        ScreenFlip();                           // ����ʂ�\��ʂ�
        if(ProcessMessage() == -1) {            // ���b�Z�[�W����
            break;                              // �G���[���N�����烋�[�v���甲����
        }
    }
    DxLib_End();                                // �c�w���C�u�����g�p�̏I������
    return 0;                                   // �\�t�g�̏I��
}
//void key(PY py){
//	
//}