#ifndef DEF_PLAYER
#define DEF_PLAYER
//構造体
struct p{
	int x;//自機の座標
	int y;//
	int haji;//端フラグ
	int gura[8];//グラフィックデータ
	int aruki[8][6];//歩き

	int cnt;//何ループごとに動くか

	int haba;//幅
	int tate;//縦サイズ

	int type;//敵のタイプ

	int x1, y1;//弾の座標

	int muki;//向き

	int sp_x, sp_y;//ｘｙ方向にいくら移動するか

	char num[3];//数字

	int ten;//点数

	int spd;//スピード
	int spd_N;//スピードななめ

	int M_Mode;//移動モード

	int color;//色

	//int tmf[j_tamakazu];//弾数

	//int tx[j_tamakazu],ty[j_tamakazu];//弾座標

	char tamagura[10];//弾の画像

	int tamahaba;//自機弾の幅

	int dead;//死亡フラグ
};
typedef struct p P;




struct b{
	int z;//ｚキー
};

typedef struct b B;

extern P jiki;
extern B button;


#endif
