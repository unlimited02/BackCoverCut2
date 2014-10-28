#ifndef BackCoverCut_Macros_h
#define BackCoverCut_Macros_h

// 画面サイズ取得
#define WINSIZE Director::getInstance()->getWinSize()

// データベース名
#define dbName "Text"

// 刃の初期位置
#define DEFAULT_BLADE_POS_X 550
#define DEFAULT_BLADE_POS_Y 500

// 刃の移動量（Y方向）
#define DROP_Y 360

// ベーススコア設定
#define BASESCORE_1 20000
#define BASESCORE_2 15000
#define BASESCORE_3 5000
#define BASESCORE_4 2000
#define BASESCORE_5 0

// ベーススコア選択用の境界値
#define DISTANCEBORDER_1 0.5
#define DISTANCEBORDER_2 2
#define DISTANCEBORDER_3 6
#define DISTANCEBORDER_4 10
#define DISTANCEBORDER_5 20

// スコア比較境界値
#define SCOREBORDER_1 score<3000
#define SCOREBORDER_2 score<6000
#define SCOREBORDER_3 score<14000
#define SCOREBORDER_4 score<19000

// ラジアン変換
#define RADIAN      angle * 3.14159265 / 180

// 角度変換
#define ANGLE       radian * 180 / 3.14159165

// 刃の角度取得
#define GETANGLE   getChildByTag(T_Blade)->getRotation()-90

#endif
