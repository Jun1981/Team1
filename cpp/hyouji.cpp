#include "GLOBAL.h"
#include "../cpp/hyouji.h"

void hyouji(){
	DrawGraph(0, 0, MHandle[0], 1);


	if (key != -1){
		DrawGraph(jiki.x, jiki.y, jiki.aruki[key][loop], 1);
		loop_s--;
		if (loop_s <= 0){
			loop_s = 10;
			if (loop >= 5){
				loop = 0;
			}
			else{ loop++; }
		}
	}
	else{ DrawGraph(jiki.x, jiki.y, jiki.gura[jiki.muki], 1); }
	/*�@�O�F��
	�P�F����
	�Q�F��
	�R�F����
	�S�F��
	�T�F�E��
	�U�F�E
	�V�F�E��
	*/

	DrawFormatStringToHandle(510, 50, white, FontHandle1, "%d", Key_Info);
	DrawFormatStringToHandle(510, 70, white, FontHandle1, "�\���L�[%d", key);
	DrawFormatStringToHandle(510, 90, white, FontHandle1, "z�L�[%d", button.z);
	DrawFormatStringToHandle(510, 230, white, FontHandle1, "���x%d", jiki.spd);
	DrawFormatStringToHandle(510, 250, white, FontHandle1, "�ȂȂߑ��x%d", (int)(jiki.spd*cos(45 / 180.0*3.14159) + 0.5));

}