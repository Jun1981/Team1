#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>

#define _USE_MATH_DEFINES
#include<math.h>


#include "../DxLib/DxLib.h"

#pragma warning(disable:4996)

//�O���[�o���ϐ�
int Key_Trg, Key_Info, Key_Old;   // �L�[���r
int ChkKAny;                             // �Ƃɂ����L�[�������ꂽ��true
int GLpCnt;                             // �Q�[�����[�v�J�E���^
int i, j, k,l;//���[�v�p
int title;//�^�C�g���摜�ǂݍ��ݗp
int bg; //�Q�[���{�Ҕw�i�摜�p
int GO;//�Q�[���I�[�o�[��ʓǂݎ��p
int cl;//�N���A��ʗp

int ten;//�_��
int et,t_limit;//����

int haji=0;//�[�t���O
int tamahaba=0;//�e�̕�

int FontHandle1;

//�F
int white,green,red,blue,purple;
//////////////////////////////////////////////////�ϐ��錾�I���



//�v���g�^�C�v�֐�/////////////////////////////////////////////////////////s
void init(void);//������
void key_chk(void);//�L�[�`�F�b�N
void key_henkan(void);//�L�[�ϊ�

void hyouji(void);//�\��

int haji_chk(void);//�[�`�F�b�N
void game_main(void);//���C��

void idou(void);//�G�ړ��֐�

void jiki_shot(void);//���@�̒e�����֐�



void jikidan_idou(void);//���@�e�ړ�

void  atari_chk(void);//���@�e�ƓG�̓�����`�F�b�N
/////////////////////////////////////////////////////////////////////////



//�\����
struct par{
	int x;//���@�̍��W
	int y;//
	int haji;//�[�t���O
	int gura;//�O���t�B�b�N�f�[�^

	int cnt;//�����[�v���Ƃɓ�����

	int haba;//��

	int type;//�G�̃^�C�v

	int x1,y1;//�e�̍��W

	int muki;//����

	int sp_x,sp_y;//���������ɂ�����ړ����邩

	char num[3];//����

	int ten;//�_��

	int spd;//�X�s�[�h

	int color;//�F

	//int tmf[j_tamakazu];//�e��

	//int tx[j_tamakazu],ty[j_tamakazu];//�e���W

	char tamagura[10];//�e�̉摜

	int tamahaba;//���@�e�̕�

	int dead;//���S�t���O


};

struct par jiki;



typedef struct{

	int hidari;
	int migi;
	int ue;
	int shita;
	int UL,UR,DL,DR;//����A�E��A�����A�E��
	//�O�͂������ρA�P�͘A��

}K;

K key[2]={0};//�\���̏�����








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



void init(void){

	white=GetColor(255,255,255);

	jiki.spd=10;//���@�̃X�s�[�h



	FontHandle1=CreateFontToHandle( "�l�r �S�V�b�N", 20,  9, DX_FONTTYPE_NORMAL );
	jiki.gura=LoadGraph("../Img/tama.png");

	jiki.x=320,jiki.y=240;//���@���W������

}


void game_main(void){


	idou();//�ړ��֌W
	hyouji();//�\���֐�


}

void hyouji(){

	DrawGraph(jiki.x,jiki.y,jiki.gura,1);


	DrawFormatStringToHandle(510,50,white,FontHandle1,"%d",Key_Info);
	DrawFormatStringToHandle(510,70,white,FontHandle1,"��%d",key[0].ue);
	DrawFormatStringToHandle(510,90,white,FontHandle1,"��%d",key[0].shita);
	DrawFormatStringToHandle(510,110,white,FontHandle1,"��%d",key[0].hidari);
	DrawFormatStringToHandle(510,130,white,FontHandle1,"�E%d",key[0].migi);
	DrawFormatStringToHandle(510,150,white,FontHandle1,"����%d",key[0].UL);
	DrawFormatStringToHandle(510,170,white,FontHandle1,"�E��%d",key[0].UR);
	DrawFormatStringToHandle(510,190,white,FontHandle1,"����%d",key[0].DL);
	DrawFormatStringToHandle(510,210,white,FontHandle1,"�E��%d",key[0].DR);
	DrawFormatStringToHandle( 510,230,white,FontHandle1,"%d", jiki.spd);
	DrawFormatStringToHandle( 510,250,white,FontHandle1,"%lf", cos(30/180*3.14159));



}

void idou(void){

	//�㉺���E
	if(key[0].hidari==1 /*&& key[0].DL==0 && key[0].UL==0*/){//��
		jiki.x-=jiki.spd;
	}
	if(key[0].migi==1 /*&& key[0].UR==0 && key[0].DR==0*/){//�E
		jiki.x+=jiki.spd;
	}
	if(    key[0].ue==1 /*&& key[0].UL==0 && key[0].UR==0 */  ){//��
		jiki.y-=jiki.spd;
	}
	if(    key[0].shita==1 /*&& key[0].DL==0 && key[0].DR==0 */ ){//��
		jiki.y+=jiki.spd;
	}

	//�ȂȂ�
	if(key[0].UL==1){//����S
		jiki.x-=jiki.spd*cos(45/180*M_PI);

		jiki.y-=jiki.spd*cos(45/180*M_PI);
	}
	if(key[0].UR==1){//�E��
		jiki.x+=jiki.spd*cos(45/180*M_PI);
		jiki.y-=jiki.spd*cos(45/180*M_PI);
	}
	if(    key[0].DL==1    ){//����
		jiki.x-=jiki.spd*cos(45/180*M_PI);
		jiki.y+=jiki.spd*cos(45/180*M_PI);
	}
	if(    key[0].DR==1  ){//�E��
		jiki.x+=jiki.spd*cos(45/180*M_PI);
		jiki.y+=jiki.spd*cos(45/180*M_PI);
	}


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
	if( (Key_Info&0x01)==0x01){//��
		key[0].hidari=1;
	}else {
		key[0].hidari=0;
	}
	if( (Key_Info&0x02)==0x02){//�E
		key[0].migi=1;
	}else{
		key[0].migi=0;
	}



	if( (Key_Info&0x04)==0x04){//��
		key[0].ue=1;
	}else{
		key[0].ue=0;

	}


	if( (Key_Info&0x08)==0x08){//��
		key[0].shita=1;
	}else {
		key[0].shita=0;
	}



	if( (Key_Info&0x05)==0x05){//����
		key[0].hidari=key[0].ue=0;
		key[0].UL=1;
		key[0].hidari=key[0].ue=0;
	}else {
		key[0].UL=0;
	}

	if( (Key_Info&0x06)==0x06){//�E��

		key[0].migi=key[0].ue=0;//�E�Ə���O

		key[0].UR=1;
		key[0].ue=key[0].migi=0;
	}else {
		key[0].UR=0;
	}

	if( (Key_Info&0x09)==0x09){//����

		key[0].hidari=key[0].shita=0;

		key[0].DL=1;
		key[0].hidari=key[0].shita=0;
	}else {
		key[0].DL=0;
	}

	if( (Key_Info&10)==10){//�E��

		key[0].migi=key[0].shita=0;

		key[0].DR=1;
		key[0].migi=key[0].shita=0;
	}else {
		key[0].DR=0;
	}
	/////////////////////////////

}

