#ifndef DEF_TEAM1//��dinclude�h�~
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



extern void map_set(int *GHandle);//�}�b�v�ǂݍ���

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

int loop;//���[�v�p
int loop_s;//���[�v�X�s�[�h�J�E���^

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



//�}�b�v//////////////////////////////////////////
void map_set(int *GHandle);//�v���g�^�C�v

//------ �}�b�v�\���p�A�萔�̐ݒ� ------//
#define CHIP_SIZE  32                           // �}�b�v�`�b�v�̑傫��
#define MAP_HEIGHT 480 / CHIP_SIZE              // �}�b�v�̍���
#define MAP_WIDTH  640 / CHIP_SIZE              // �}�b�v�̕�
/////////////////////////////////////////////////////////////////////////


 


//�\����
struct par{
	int x;//���@�̍��W
	int y;//
	int haji;//�[�t���O
	int gura[8];//�O���t�B�b�N�f�[�^
	int aruki[8][6];//����

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









#endif