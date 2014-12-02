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
	/*　０：下
	１：左下
	２：左
	３：左上
	４：上
	５：右上
	６：右
	７：右下
	*/

	DrawFormatStringToHandle(510, 50, white, FontHandle1, "%d", Key_Info);
	DrawFormatStringToHandle(510, 70, white, FontHandle1, "十字キー%d", key);
	DrawFormatStringToHandle(510, 90, white, FontHandle1, "zキー%d", button.z);
	DrawFormatStringToHandle(510, 230, white, FontHandle1, "速度%d", jiki.spd);
	DrawFormatStringToHandle(510, 250, white, FontHandle1, "ななめ速度%d", (int)(jiki.spd*cos(45 / 180.0*3.14159) + 0.5));

}