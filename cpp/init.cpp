
#include "../cpp/GLOBAL.h"
#include "../cpp/init.h"
#include"player.h"


void init(void){

	jiki.haba=48;jiki.tate=72;//���@�̏c���T�C�Y
	jiki.M_Mode=0;//�ړ����[�h�O�i�ӂ��j

	

///�摜�ǂݍ���


	// LoadDivGraph("../Img/MAP/test2.jpg", 4, 4, 1, 32, 32, GHandle);//�e�X�g�}�b�v

	


    LoadDivGraph("../Img/MAP/town.jpg",4,2,2,640,480,MHandle,0);//��}�b�v
	 

	LoadDivGraph("../Img/miku/mikusan.png" ,8,8,1,48,64,jiki.gura,1);//���@�摜�i�~�N����j

	LoadDivGraph("../Img/miku/loop1000/loop0.png" ,6,6,1,48,64,jiki.aruki[0],1);//���@�摜�i�~�N����j��
	LoadDivGraph("../Img/miku/loop1001/loop1.png" ,6,6,1,48,64,jiki.aruki[1],1);//���@�摜�i�~�N����j����
	LoadDivGraph("../Img/miku/loop1002/loop2.png" ,6,6,1,48,64,jiki.aruki[2],1);//���@�摜�i�~�N����j��
				  
	LoadDivGraph("../Img/miku/loop1003/loop3.png" ,6,6,1,48,64,jiki.aruki[3],1);//���@�摜�i�~�N����j����
			
	LoadDivGraph("../Img/miku/loop1004/loop4.png" ,6,6,1,48,64,jiki.aruki[4],1);//���@�摜�i�~�N����j��
	LoadDivGraph("../Img/miku/loop1005/loop5.png" ,6,6,1,48,64,jiki.aruki[5],1);//���@�摜�i�~�N����j�E��
				
	LoadDivGraph("../Img/miku/loop1006/loop6.png" ,6,6,1,48,64,jiki.aruki[6],1);//���@�摜�i�~�N����j�E
	LoadDivGraph("../Img/miku/loop1007/loop7.png" ,6,6,1,48,64,jiki.aruki[7],1);//���@�摜�i�~�N����j�E��
		
	loop_s=10;
	loop=0;


	white=GetColor(255,255,255);

	jiki.spd=4;//���@�̃X�s�[�h

	jiki.spd_N=jiki.spd*cos(45/180.0*M_PI)+0.5;//���@�X�s�[�h�ȂȂ߂̏�����
	//jiki.spd_N=4;//���@�X�s�[�h�ȂȂ�


	FontHandle1=CreateFontToHandle( "�l�r �S�V�b�N", 20,  9, DX_FONTTYPE_NORMAL );
	//jiki.gura[0]=LoadGraph("../Img/tama.png");

	jiki.x=320,jiki.y=240;//���@���W������



	button.z=0;//z�L�[0

}

