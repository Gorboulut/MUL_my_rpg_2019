/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg.h
*/

#ifndef RPG_H
#define RPG_H
#define UNUSED(x) (void)(x)

#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "text.h"
#include "menu.h"
#include "sprite.h"
#include "sound.h"
#include "tilemap.h"
#include "option.h"
#include "player.h"
#include "marvin.h"
#include "death.h"

typedef struct game_s {
    sprite_t sprite[NB_SPRITES];
    sprite_t menu_sp[NB_MENU];
    sprite_t inven_sp[NB_INV];
    text_t text[TXT];
    vol_t *volume;
    vol_t *text_speed;
    music_t *music;
    option_t *option;
    button_dead *death;
    tilemap_t *tile;
    inv_t *perso;
    sfView *camera;
    sfFloatRect view_rect;
    sfClock *cl;
    sfRenderWindow *window;
    sfEvent event;
    char **archi;
    char **first_rock;
    char **second_rock;
    char **third_rock;
    char **fourth_rock;
    char **fifth_rock;
    char **sixth_rock;
    char **mail;
    char **bridge;
    char **cave;
    char **cherry_tree;
    char **drunk;
    char **fountain;
    char **kid;
    char **mail_archi;
    sprite_t *endsc;
    char **mother;
    char **park;
    char **sign;
    char **tombe_man;
    char **trash;
    char **willy;
    char **pirate;
    char **grave;
    char **forger;
    char **drunkman;
    char **minerock;
    char **piratebridge;
    char **first_quest;
    char **second_quest;
    char **third_quest;
    char **fourth_quest;
    char **fifth_quest;
    char **johan;
    char **sixth_quest;
    char *current_quest;
    int menu;
    int inventory;
    int dialogue;
    int count;
    int load;
    int quest;
    int count_quest;
    int checking_quest;
    int obj;
    float clock;
    sfVector2f pos_camera;
    sfVector2u size;
    sfMusic *game_music;
    sfVector2f basic_pos;
    float tmp;
    int health;
    sfKeyEvent key;
    player_t *pl;
    sfTime sec;
    int secondes;
    int anim;
    float cl_sec;
    marv_t *marv;
    int marv_l;
    sound_t *s;
} game_t;

void reset_atk(game_t *game);
void show_attack(game_t *game);
void clock_management(game_t *game);
void create_game(game_t *game);
void create_my_music(game_t *game);
void game_initialisation(game_t *game);
void set_my_texture(game_t *game);
void game_events(game_t *game);
void game_update(game_t *game, float elapsed);
void game_render(game_t *game);
void destroy_game(game_t *game);
void in_play(game_t *game);
void in_lose(game_t *game);
void in_menu(game_t *game);
void in_option(game_t *game);
void in_pause(game_t *game);
void in_win(game_t *game);
void how_to_play(game_t *game);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
void create_vol(game_t *game);
void in_inventory(game_t *game);
void change_inventory(game_t *game, sfVector2i c);
char *new_strcat(char *dest, char c);
int my_strcmp(char const *s1, char const *s2);
char **parsing(char *path);
char **my_str_to_wordtab(char *str, char c);
void create_marvin_death(game_t *game);
void set_my_text(game_t *game);
void set_my_texture(game_t *game);
void create_my_sprite(sfIntRect pos, sfVector2f x, sprite_t *sp);
void create_my_text(char *font, char *text, sfVector2f x, text_t *tx);
void load_game(game_t *game);
int my_strlen(char const *src);
void create_my_save(game_t *game);
char *my_itoa(int array);
int my_getnbr(char *str);
void create_vertex_array(game_t *game, char *tileset);
void create_vertex(game_t *game, char ***map, sfVector2i tSize);
void *create_map(game_t *game, char ***map, sfVector2i tSize, char *tileset);
char ***get_map(game_t *game, char *tilemap);
void get_width_height(game_t *game, FILE *file, size_t hello);
char **str_to_word_tab(char *board, char a);
void click_pause(game_t *game, sfVector2i c);
void call_escape(game_t *game);
void setting_texture(char *path, sprite_t *sp);
void game_initialisation(game_t *game);
void control(game_t *game);
void create_my_texture(game_t *game);
void *my_realloc(void *src, size_t old_size, size_t size);
void create_speed_text(game_t *game);
void setting_value(game_t *game);
void creating_tiled_map(game_t *game);
void interaction_object(game_t *game, char **stk, int object);
void call_atk(game_t *game);
void start_sword_animation(game_t *game);
void check_create(game_t *game);
void call_shield(game_t *game);
void play_game(game_t *game);
void call_direction_tree(game_t *game);
void start_axe_animation(game_t *game);
char *collision(game_t *game, int y, int x);
void in_option2(game_t *game);
void init_option(game_t *game);
int button_is_clicked(game_t *game, sfVector2i c);
char *get_key(int i);
void in_change_key(game_t *game);
void change_up(game_t *game);
void change_down(game_t *game);
void change_left(game_t *game);
void change_right(game_t *game);
void change_inter(game_t *game);
void change_inv(game_t *game);
void change_pause(game_t *game);
void change_shield(game_t *game);
void change_attack(game_t *game);
void change_farm(game_t *game);
void init_button(game_t *game, void *func, sfIntRect rect, sfVector2f pos);
void set_my_texture_inventory(game_t *game);
void game_initialisation_two(game_t *game);
void set_nb_text(game_t *game);
void setting_value_two(game_t *game);
void in_game_events(game_t *game);
void change_hp(game_t *game, int hp);
void change_xp(game_t *game, int xp);
void lvl_up(game_t *game, int test);
void marvin_play(game_t *game);
void marvin_launch_attack(game_t *game);
void create_marv_attack(game_t *game);
void all_interaction_object(game_t *game);
void showing_quest(game_t *game, char **quest);
void set_value_in_string(game_t *game);
void quest_list(game_t *game, int inter, char **quest, int count);
int creating_text_from_file_three(game_t *game);
void set_object_in_inventory_two(game_t *game);
void add_fire(game_t *game);
void first_quest(game_t *game, int object);
void in_death(game_t *game);
int death_animation(game_t *game);
int button_is_clicked_death(game_t *game, sfVector2i c);
void create_my_texture_first(game_t *game);
void init_button_d(game_t *game, void *func, sfIntRect rect, sfVector2f pos);
void retry(game_t *game);
void exit_end(game_t *game);
void change_hp_marv(game_t *game, int hp);
void marvin_direction_second_attack(game_t *game);
void marvin_direction_first_attack(game_t *game);
void reset_atk(game_t *game);
void marvin_third_attack(game_t *game);
void all_interaction_object_two(game_t *game);
void check_hit_two(game_t *game);
void set_sound(game_t *game);
void marvin_death(game_t *game);
void reset_value(game_t *game);
int print_text(game_t *game, sfText *text, char *str);
void set_nb_text_two(game_t *game);

#endif /* !RPG_H */
