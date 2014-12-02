#include "../cpp/GLOBAL.h"

#pragma warning(disable:4996)
extern void map_init();

void init(void);//������
void key_chk(void);//�L�[�`�F�b�N
void key_henkan(void);//�L�[�ϊ�


int haji_chk(void);//�[�`�F�b�N
void game_main(void);//���C��
 // �X�N���[�����W







/////////////////////////////////////////////////////////////////////////



//�}�b�v//////////////////////////////////////////
//void map_set(int *MHandle);//�v���g�^�C�v

//------ �}�b�v�\���p�A�萔�̐ݒ� ------//


#define CHIP_SIZE  32                           // �}�b�v�`�b�v�̑傫��
#define MAP_HEIGHT 480 / CHIP_SIZE              // �}�b�v�̍���
#define MAP_WIDTH  640 / CHIP_SIZE              // �}�b�v�̕�


/////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
		
	
	//
	ChangeWindowMode(TRUE);                     // �E�C���h�E���[�h�ɕύX(�������A�Q�T�U�F)

	if (DxLib_Init() == -1) {                    // �c�w���C�u��������������
		return -1;                              // �G���[���N�����璼���ɏI��
	}

	//


	init();//������

	SetDrawScreen(DX_SCREEN_BACK);              // �`���𗠉�ʂ�
		

	// �Q�[���V�X�e��������
	//------ �Q�[�����[�v ------//
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Esc�L�[���������܂Ń��[�v
		ClsDrawScreen();                        // ����ʃN���A


		// �Q�[���R���g���[�����C��
		key_chk();//�L�[�`�F�b�N
		key_henkan();//�L�[�ϊ��i��������or�A�Łj

		game_main();



		ScreenFlip();                           // ����ʂ�\��ʂ�
		if (ProcessMessage() == -1) {            // ���b�Z�[�W����
			break;                              // �G���[���N�����烋�[�v���甲����
		}
	}
	DxLib_End();// �c�w���C�u�����g�p�̏I������
	return 0;// �A�v���P�[�V�����̏I��

}






void game_main(void){

	//map_set(GHandle);
	calc();//�v�Z�֌W
	hyouji();//�\���֐�
			

}


void key_chk(){

	/*---------------------
	*    �L�[���擾    *
	*---------------------
	*
	*    LEFT  = 0000 0001
	*    RIGHT = 0000 0010
	*    UP    = 0000 0100
	*    DOWN  = 0000 1000
	*    key_trg�͉������u�Ԃ̏��
	*    key_info�͍��̏��
	*
	*/
	Key_Trg = Key_Info = 0;                                 // �L�[���N���A
	ChkKAny = false;
	if (CheckHitKey(KEY_INPUT_LEFT))   { Key_Info |= 0x01; }
	if (CheckHitKey(KEY_INPUT_RIGHT))  { Key_Info |= 0x02; }
	if (CheckHitKey(KEY_INPUT_UP))     { Key_Info |= 0x04; }
	if (CheckHitKey(KEY_INPUT_DOWN))   { Key_Info |= 0x08; }
	if (CheckHitKey(KEY_INPUT_SPACE))  { Key_Info |= 0x10; }
	if (CheckHitKey(KEY_INPUT_Z))      { Key_Info |= 0x20; }
	if (CheckHitKey(KEY_INPUT_ESCAPE)) { Key_Info |= 0x40; }
	if (CheckHitKeyAll()) { ChkKAny = true; }                    // ���Ɂ[

	Key_Trg = (Key_Info ^ Key_Old) & Key_Info;          // �L�[�g���K�[���Z�b�g
	Key_Old = Key_Info;                                     // �L�[���Z�[�u
}


void key_henkan(void){


	//�㉺���E��������

	if(ChkKAny==TRUE){

		if( (Key_Info&0x01)==0x01){key=2;}//��
		if( (Key_Info&0x02)==0x02){key=6;}//�E
		if( (Key_Info&0x04)==0x04){key=4;}//��
		if( (Key_Info&0x08)==0x08){key=0;}//��



		if( (Key_Info&0x05)==0x05){key=3;}//����

		if( (Key_Info&0x06)==0x06){key=5;}//�E��

		if( (Key_Info&0x09)==0x09){key=1;	}//����

		if( (Key_Info&0x0a)==0x0a){key=7;}//�E��
		/////////////////////////////

		if( (Key_Info&0x01)!=0x01
		  && (Key_Info&0x02)!=0x02
		  && (Key_Info&0x04)!=0x04
		  && (Key_Info&0x08)!=0x08
		  && (Key_Info&0x05)!=0x05
		  && (Key_Info&0x06)!=0x06
		  && (Key_Info&0x09)!=0x09){
			  key=-1;//�\���L�[����
		}




		if( (Key_Info&0x20)==0x20){button.z=1;}else{button.z=0;}

	}else{key=-1;button.z=0;}//�L�[����

}




