#ifndef buzzer_included
#define buzzer_included

extern int ruidosLocos[];
extern int ruidosLocos2[];
extern int ruidosLocos3[];
extern int ruidosLocos4[];
extern int *arreglo;
extern int i;

void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_play_sound();

#endif // included
