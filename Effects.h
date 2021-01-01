//
// Created by anarg on 1/1/2021.
//

#ifndef UNTITLED1_EFFECTS_H
#define UNTITLED1_EFFECTS_H

enum EffectType {STRENGTH=1,DEXTERITY=2,AGILITY=3};

class Effects {
private:
    EffectType type;
    int duration;
    int power;
public:
    Effects(EffectType effect_type,int power,int duration);
    ~Effects();
    EffectType getType(){return type;}
    int getDuration(){return duration;}
    int getPower(){return power;}
    void setDuration(int Duration){duration=Duration;}
};


#endif //UNTITLED1_EFFECTS_H
