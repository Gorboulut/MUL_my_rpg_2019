/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** in_option2.c
*/

#include "my_rpg.h"

static char *key[sfKeyCount] = {
    [sfKeyA] = "A",
    [sfKeyB] = "B",
    [sfKeyC] = "C",
    [sfKeyD] = "D",
    [sfKeyE] = "E",
    [sfKeyF] = "F",
    [sfKeyG] = "G",
    [sfKeyH] = "H",
    [sfKeyI] = "I",
    [sfKeyJ] = "J",
    [sfKeyK] = "K",
    [sfKeyL] = "L",
    [sfKeyM] = "M",
    [sfKeyN] = "N",
    [sfKeyO] = "O",
    [sfKeyP] = "P",
    [sfKeyQ] = "Q",
    [sfKeyR] = "R",
    [sfKeyS] = "S",
    [sfKeyT] = "T",
    [sfKeyU] = "U",
    [sfKeyV] = "V",
    [sfKeyW] = "W",
    [sfKeyX] = "X",
    [sfKeyY] = "Y",
    [sfKeyZ] = "Z",
    [sfKeyNum0] = "0",
    [sfKeyNum1] = "1",
    [sfKeyNum2] = "2",
    [sfKeyNum3] = "3",
    [sfKeyNum4] = "4",
    [sfKeyNum5] = "5",
    [sfKeyNum6] = "6",
    [sfKeyNum7] = "7",
    [sfKeyNum8] = "8",
    [sfKeyNum9] = "9",
    [sfKeyEscape] = "Escape",
    [sfKeyLControl] = "Ctrl",
    [sfKeyLShift] = "Shift",
    [sfKeyLAlt] = "Alt",
    [sfKeyLSystem] = "System",
    [sfKeyRControl] = "RCtrl",
    [sfKeyRShift] = "RShift",
    [sfKeyRAlt] = "RAlt",
    [sfKeyRSystem] = "RSystem",
    [sfKeyMenu] = "Menu",
    [sfKeyLBracket] = "[",
    [sfKeyRBracket] = "]",
    [sfKeyComma] = ",",
    [sfKeyPeriod] = ".",
    [sfKeyQuote] = "'",
    [sfKeySlash] = "/",
    [sfKeyTilde] = "~",
    [sfKeyEqual] = "=",
    [sfKeySpace] = "Space",
    [sfKeyTab] = "Tab",
    [sfKeyPageUp] = "Page Up",
    [sfKeyPageDown] = "Page Down",
    [sfKeyEnd] = "End",
    [sfKeyHome] = "Home",
    [sfKeyInsert] = "Insert",
    [sfKeyDelete] = "Delete",
    [sfKeyAdd] = "+",
    [sfKeySubtract] = "-",
    [sfKeyMultiply] = "*",
    [sfKeyDivide] = "/",
    [sfKeyLeft] = "Left arrow",
    [sfKeyRight] = "Right arrow",
    [sfKeyUp] = "Up arrow",
    [sfKeyDown] = "Down arrow",
    [sfKeyNumpad0] = "NMPD 0",
    [sfKeyNumpad1] = "NMPD 1",
    [sfKeyNumpad2] = "NMPD 2",
    [sfKeyNumpad3] = "NMPD 3",
    [sfKeyNumpad4] = "NMPD 4",
    [sfKeyNumpad5] = "NMPD 5",
    [sfKeyNumpad6] = "NMPD 6",
    [sfKeyNumpad7] = "NMPD 7",
    [sfKeyNumpad8] = "NMPD 8",
    [sfKeyNumpad9] = "NMPD 9",
    [sfKeyF1] = "F1",
    [sfKeyF2] = "F2",
    [sfKeyF3] = "F3",
    [sfKeyF4] = "F4",
    [sfKeyF5] = "F5",
    [sfKeyF6] = "F6",
    [sfKeyF7] = "F7",
    [sfKeyF8] = "F8",
    [sfKeyF9] = "F9",
    [sfKeyF10] = "F10",
    [sfKeyF11] = "F11",
    [sfKeyF12] = "F12",
    [sfKeyF13] = "F13",
    [sfKeyF14] = "F14",
    [sfKeyF15] = "F15",
    [sfKeyPause] = "Pause"
};

char *get_key(int i)
{
    return (key[i]);
}

void init_button(game_t *game, void *func, sfIntRect rect, sfVector2f pos)
{
    static int i = 0;
    game->option->button[i].pos = pos;
    game->option->button[i].rect = rect;
    game->option->button[i].fct = func;
    i++;
}

void set_text_key(game_t *game)
{
    sfText_setString(game->text[TOP_TX].text, get_key(game->option->top));
    sfText_setString(game->text[BOT_TX].text, get_key(game->option->bot));
    sfText_setString(game->text[LEFT_TX].text, get_key(game->option->left));
    sfText_setString(game->text[RIGHT_TX].text, get_key(game->option->right));
    sfText_setString(game->text[INTERACT_TX].text,
        get_key(game->option->inter));
    sfText_setString(game->text[INV_TX].text, get_key(game->option->inv));
    sfText_setString(game->text[PAUSED_TX].text, get_key(game->option->pause));
    sfText_setString(game->text[SHIELD_TX].text, get_key(game->option->shield));
    sfText_setString(game->text[ATTACK_TX].text, get_key(game->option->attack));
    sfText_setString(game->text[FARM_TX].text, get_key(game->option->farm));
}

void in_change_key(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->menu_sp[SETTINGS2].sprite,
    NULL);
    sfVector2i c = sfMouse_getPositionRenderWindow(game->window);
    for (int i = 2; i < TXT; i++) {
        sfRenderWindow_drawText(game->window, game->text[i].text, NULL);
    }
    if (c.x > 230 && c.x < 290 && c.y < 900 && c.y > 868)
        sfRenderWindow_drawSprite(game->window, game->menu_sp[BACK_OP].sprite,
        NULL);
}

void in_option2(game_t *game)
{
    if (game->menu_sp[SETTINGS2].sprite == NULL)
        create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                (sfVector2f) {0, 0}, &game->menu_sp[SETTINGS2]);
    sfVector2i c = sfMouse_getPositionRenderWindow(game->window);
    sfRenderWindow_drawSprite(game->window, game->menu_sp[SETTINGS2].sprite,
    NULL);
    if (c.x > 230 && c.x < 290 && c.y < 900 && c.y > 868)
        sfRenderWindow_drawSprite(game->window, game->menu_sp[BACK_OP].sprite,
        NULL);
    for (int i = 2; i < TXT; i++) {
        sfRenderWindow_drawText(game->window, game->text[i].text, NULL);
    }
    set_text_key(game);
}