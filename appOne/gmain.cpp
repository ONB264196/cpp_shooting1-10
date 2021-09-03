#include"libOne.h"
#define _78910

#ifdef _123
/*基底クラス*/
class CHARACTER {
protected:
    int Img = 0;
    float Px = 0, Py = 0, Angle = 0;
    float Vx = 0, Vy = 0, AngSpeed = 0;

public:
    void setImg(int img) {
        Img = img;
    }
    void init() {
        Px = width / 2;
        Py = height / 2;
        Angle = 0;
        Vx = 1;
        Vy = 1;
        AngSpeed = 0.01f;
    }
    /*継承した関数の基底クラス側には"virtual"を付けておく*/
    virtual void move() {
        Angle += AngSpeed;
    }
    void draw() {
        rectMode(CENTER);
        image(Img, Px, Py, Angle);
    }
};
/*派生クラス*/
class PLAYER : public CHARACTER {
public:
    void move() {
        Px += Vx;
    }
};
class ENEMY : public CHARACTER {
public:
    void move() {
        Py += Vy;
    }
};
class ENEMY_BULLET : public CHARACTER {};
void gmain(){
    window(1920, 1080, full);
    int playerImg = loadImage("assets\\player.png");
    int enemyImg = loadImage("assets\\enemy.png");
    int enemyBulletImg = loadImage("assets\\eBullet.png");


    PLAYER player;
    ENEMY enemy;
    ENEMY_BULLET eBullet;

    player.setImg(playerImg);
    enemy.setImg(enemyImg);
    eBullet.setImg(enemyBulletImg);

    const int num = 3;
    CHARACTER* chara[num];
    chara[0] = &player;
    chara[1] = &enemy;
    chara[2] = &eBullet;

    for (int i = 0; i < num; i++) {
    chara[i]->init();
    }
    while(notQuit) {
        for (int i = 0; i < num; i++) {
            chara[i]->move();
        }
        clear(); 
        for (int i = 0; i < num; i++) {
            chara[i]->draw();
        }
    }
}
#endif 



#ifdef _4
class ENEMY {
private:
    int Img;
    float Px, Py, Vx;
public:
    void setImage(int img) {
        Img = img;
    }
    void init() {
        Px = random() % (int)width;
        Py = random() % (int)height;
        Vx = random() % 5 + 1.0f;
    }
    void move() {
        Px += Vx;
    }
    void draw() {
        image(Img, Px, Py);
    }
};

void gmain() {
    window(1920, 1080, 1);
    hideCursor();
    int enemyImg = loadImage("assets\\enemy.png");
    int num = 50;
    ENEMY* enemy = new ENEMY[num];
    for (int i = 0; i < num; i++) {
        enemy[i].setImage(enemyImg);
        enemy[i].init();
    }
    while (notQuit) {
        clear();
        for (int i = 0; i < num; i++) {
            enemy[i].move();
            enemy[i].draw();
        }
    }
    delete[] enemy;
}
#endif



#ifdef _5
class RENGE {
public:
    RENGE() {
        textSize(200);
        fill(5, 220, 227);
        text("にゃんぱすー", 300, height / 2);
    }
    ~RENGE() {
        textSize(200);
        fill(5, 220, 227);
        text("にゃんぱすぱすーん", 100, height / 2 + 300);
    }
};
void func() {
    RENGE renge;
}
void gmain() {
    window(1920, 1080, 1);
    RENGE* renge = new RENGE;
    delete renge;
    while (notQuit) {

    }
}
#endif



#ifdef _6
#include"TAKO.h"
void gmain() {
    window(1920, 1080, 1);
    int takoImg = loadImage("assets\\enemy.png");
    int num = 30;
    TAKO* takos = new TAKO[num];
    for (int i = 0; i < num; i++) {
        takos[i].setImage(takoImg);
        takos[i].init();
    }
    while (notQuit) {
        for (int i = 0; i < num; i++) {
            takos[i].move();
            takos[i].draw();
        }
    }
    delete[] takos;
}
#endif




#ifdef _78910
class FLOAT2 {
public:
    float x = 0, y = 0;
    FLOAT2() {}
    FLOAT2(float x, float y) {
        this->x = x;
        this->y = y;
    }
    FLOAT2 operator+(FLOAT2& f2) {
        return FLOAT2(x + f2.x, y + f2.y);
    }
    FLOAT2 operator-(FLOAT2& f2) {
        return FLOAT2(x - f2.x, y - f2.y);
    }
    FLOAT2 operator*(float f) {
        return FLOAT2(x * f, y * f);
    }
    void operator+=(const FLOAT2& f2) {
        x += f2.x;
        y += f2.y;
    }
    void normalize() {
        float mag = sqrt(x * x + y * y);
        x /= mag;
        y /= mag;
    }
};

void gmain() {
    window(1000, 1000, 1);
    
    FLOAT2 pos(100, 10);
    FLOAT2 vec(200, 20);
    vec.normalize();
    pos += vec * 5.0f;

    printSize(200);
    print(pos.x);
    print(pos.y);

    while (notQuit) {

    }
}
#endif



