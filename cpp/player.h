#ifndef DEF_PLAYER
#define DEF_PLAYER
//�\����
struct p{
	int x;//���@�̍��W
	int y;//
	int haji;//�[�t���O
	int gura[8];//�O���t�B�b�N�f�[�^
	int aruki[8][6];//����

	int cnt;//�����[�v���Ƃɓ�����

	int haba;//��
	int tate;//�c�T�C�Y

	int type;//�G�̃^�C�v

	int x1, y1;//�e�̍��W

	int muki;//����

	int sp_x, sp_y;//���������ɂ�����ړ����邩

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
typedef struct p P;




struct b{
	int z;//���L�[
};

typedef struct b B;

extern P jiki;
extern B button;


#endif
