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

int muki;//�L�����̌����@8����
int haba,tate;



void jikidan_idou(void);//���@�e�ړ�

void  atari_chk(void);//���@�e�ƓG�̓�����`�F�b�N
/////////////////////////////////////////////////////////////////////////



//�\����
struct par{
	int x;//���@�̍��W
	int y;//
	int haji;//�[�t���O
	int gura[8];//�O���t�B�b�N�f�[�^
	int cnt;//�����[�v���Ƃɓ�����

	int haba;//��
	int tate;//�c�T�C�Y

	int type;//�G�̃^�C�v

	int x1,y1;//�e�̍��W

	int muki;//����

	int sp_x,sp_y;//���������ɂ�����ړ����邩

	char num[3];//����

	int ten;//�_��

	int spd;//�X�s�[�h
	int spd_N;//�X�s�[�h�ȂȂ�

	int M_Mode;//�ړ����[�h

	int color;//�F

	//int tmf[j_tamakazu];//�e��

	//int tx[j_tamakazu],ty[j_tamakazu];//�e���W

	char tamagura[10];//�e�̉摜

	int tamahaba;//���@�e�̕�

	int dead;//���S�t���O


};

struct par jiki;


//
//typedef struct{
//
//	int hidari;
//	int migi;
//	int ue;
//	int shita;
//	int UL,UR,DL,DR;//����A�E��A�����A�E��
//	//�O�͂������ρA�P�͘A��
//
//}K;
//
//K key[2]={0};//�\���̏�����


int key=0;//�\���L�[�ϐ�



//int button=0;//�{�^��

typedef struct{

	int z;//���L�[

}b;
b button;//�錾


/*�@�O�F��
�P�F����
�Q�F��
�R�F����
�S�F��
�T�F�E��
�U�F�E
�V�F�E��


*/


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

	jiki.haba=48;jiki.tate=64;//���@�̏c���T�C�Y
	jiki.M_Mode=0;//�ړ����[�h�O�i�ӂ��j


	LoadDivGraph("../Img/mikusan.png" ,8,8,1,48,64,jiki.gura,1);//���@�摜�i�~�N����j

	/*�@�O�F��
	�P�F����
	�Q�F��
	�R�F����
	�S�F��
	�T�F�E��
	�U�F�E
	�V�F�E��


	*/

	white=GetColor(255,255,255);

	jiki.spd=4;//���@�̃X�s�[�h

	jiki.spd_N=jiki.spd*cos(45/180.0*M_PI)+0.5;//���@�X�s�[�h�ȂȂ߂̏�����
	//jiki.spd_N=4;//���@�X�s�[�h�ȂȂ�


	FontHandle1=CreateFontToHandle( "�l�r �S�V�b�N", 20,  9, DX_FONTTYPE_NORMAL );
	//jiki.gura[0]=LoadGraph("../Img/tama.png");

	jiki.x=320,jiki.y=240;//���@���W������



	button.z=0;//z�L�[0

}


void game_main(void){


	idou();//�ړ��֌W
	hyouji();//�\���֐�


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





	/*�@�O�F��
	�P�F����
	�Q�F��
	�R�F����
	�S�F��
	�T�F�E��
	�U�F�E
	�V�F�E��


	*/


	DrawFormatStringToHandle(510,50,white,FontHandle1,"%d",Key_Info);
	DrawFormatStringToHandle(510,70,white,FontHandle1,"�\���L�[%d",key);
	DrawFormatStringToHandle(510,90,white,FontHandle1,"z�L�[%d",button.z);

	DrawFormatStringToHandle( 510,230,white,FontHandle1,"���x%d", jiki.spd);
	DrawFormatStringToHandle( 510,250,white,FontHandle1,"�ȂȂߑ��x%d", (int)(jiki.spd*cos(45/180.0*3.14159)+0.5));



}

void idou(void){

	//�㉺���E
	if(key==2 && jiki.x>=0){//��
		jiki.x-=jiki.spd;
		jiki.muki=2;
	}
	if(key==6 && jiki.x+jiki.haba<=640){//�E
		jiki.x+=jiki.spd;
		jiki.muki=6;
	}
	if(    key==4 && jiki.y>=0  ){//��
		jiki.y-=jiki.spd;
		jiki.muki=4;
	}
	if(    key==0 && jiki.y+jiki.tate<=480 ){//��
		jiki.y+=jiki.spd;
		jiki.muki=0;
	}

	//�ȂȂ�
	if(key==3 && jiki.x>=0 && jiki.y>=0){//����
		jiki.x-=jiki.spd_N;
		jiki.y-=jiki.spd_N;
		jiki.muki=3;
	}
	if(key==5 && jiki.x+jiki.haba<=640 && jiki.y>=0){//�E��
		jiki.x+=jiki.spd_N;
		jiki.y-=jiki.spd_N;
		jiki.muki=5;
	}
	if(    key==1 &&   jiki.x>=0 && jiki.y+jiki.tate<=480){//����
		jiki.x-=jiki.spd_N;
		jiki.y+=jiki.spd_N;
		jiki.muki=1;
	}
	if(    key==7 && jiki.x+jiki.haba<=640 && jiki.y+jiki.tate<=480 ){//�E��
		jiki.x+=jiki.spd_N;
		jiki.y+=jiki.spd_N;
		jiki.muki=7;
	}

	//�ړ����[�h�ؑ�
	if(button.z==1){
		jiki.spd=10;
		jiki.spd_N=jiki.spd*cos(45/180.0*M_PI)+0.5;
	}else{
		jiki.spd=4;
		jiki.spd_N=jiki.spd*cos(45/180.0*M_PI)+0.5;//���@�X�s�[�h�ȂȂ߂̏�����
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

		if( (Key_Info&0x20)==0x20){button.z=1;}else{button.z=0;}

	}else{key=-1;button.z=0;}//�L�[����

}