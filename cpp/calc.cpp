#include "../cpp/GLOBAL.h"
#include "../cpp/calc.h"
#include "../cpp/player.h"

void calc(void){

	//�㉺���E
	if(key==2){jiki.muki=2;
	if(jiki.x>=0){jiki.x-=jiki.spd;}
	}
	if(key==6){//�E
		jiki.muki=6;
		//if( jiki.x+jiki.haba<=640){//�E
		//	jiki.x+=jiki.spd;
		//}
		
		jiki.x+=jiki.spd;
		
		if( jiki.x+jiki.haba<=640){//�E
		}

	}
	if(key==4){
		jiki.muki=4;
		if(   jiki.y>=0  ){//��
			jiki.y-=jiki.spd;
		}
	}
	if(key==0){//��
		jiki.muki=0;
		if(    jiki.y+jiki.tate<=480 ){//��
			jiki.y+=jiki.spd;
		}
	}

	//�ȂȂ�

	if(key==3){//����
		if(jiki.x>0 && jiki.y>0){
			jiki.x-=jiki.spd_N;
			jiki.y-=jiki.spd_N;
			jiki.muki=3;
		}else if(jiki.x>0 && jiki.y<=0){//����ŏ�ɂԂ�����������
			jiki.x-=jiki.spd_N;		
			jiki.muki=2;
		}else if(jiki.x<=0 && jiki.y>0){//����ō��ɂԂ����������
			jiki.y-=jiki.spd_N;	
			jiki.muki=4;
		}
	}


	if(key==5){
		if(jiki.x+jiki.haba<640 && jiki.y>=0){//�E��
			jiki.x+=jiki.spd_N;
			jiki.y-=jiki.spd_N;
			jiki.muki=5;
		}else if(jiki.x+jiki.haba<640 && jiki.y<=0){//�E��ŏ�ɂԂ��������E��
			jiki.x+=jiki.spd_N;		
			jiki.muki=6;
		}else if(jiki.x+jiki.haba>=640 && jiki.y>0){//�E��ŉE�ɂԂ����������
			jiki.y-=jiki.spd_N;	
			jiki.muki=4;
		}
	}

	if(key==1){
		if(jiki.x>0 && jiki.y+jiki.tate<480){//����
			jiki.x-=jiki.spd_N;
			jiki.y+=jiki.spd_N;
			jiki.muki=1;
		}else if( jiki.x>0 && jiki.y+jiki.tate>=480){//����&��
			jiki.x-=jiki.spd_N;
			jiki.muki=2;
		}else if(jiki.x<=0 && jiki.y+jiki.tate<480){//��������
			jiki.y+=jiki.spd_N;
			jiki.muki=0;
		}
	}

	if(key==7){
		if(    jiki.x+jiki.haba<640 && jiki.y+jiki.tate<480 ){//�E��
			jiki.x+=jiki.spd_N;
			jiki.y+=jiki.spd_N;
			jiki.muki=7;
		}else if(jiki.x+jiki.haba<640 && jiki.y+jiki.tate>=480 ){//�E������
			jiki.x+=jiki.spd_N;
			
			jiki.muki=6;
		}else if( jiki.x+jiki.haba>=640 && jiki.y+jiki.tate<480 ){//�E�����E
			jiki.y+=jiki.spd_N;
			jiki.muki=0;
		}
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


