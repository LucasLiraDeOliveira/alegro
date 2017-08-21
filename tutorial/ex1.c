// Cabeçalho com a inclusão das bibliotecas
// necessárias para esse programa
#include <stdlib.h>
#include <allegro.h>

void main(void)
{
    int x, y, radius;
    int red, green, blue, color;

    // Inicializa a Allegro
    allegro_init();

    install_timer();
    srand(time(NULL));

    // Inicializa o teclado
    install_keyboard();

    // Inicializa o modo do video para 640x480
    int ret = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640,
            480, 0, 0);
    if(ret != 0)
    {
        allegro_message(allegro_error);
        return;
    }
    // Mostra a resolução da tela
    textprintf(screen, font, 0, 0, 15,
            "Circles Program - %dx%d - Pressione ESC para
            sair",
            SCREEN_W, SCREEN_H);

    // Aguarda o pressionamento da tecla ESC
    while(!key[KEY_ESC])
    {
        // Configura uma localização aleatória
        x = 30 + rand() % (SCREEN_W - 60);
        y = 30 + rand() % (SCREEN_H - 60);
        radius = rand() % 30;

        // Configura uma cor aleatória
        red = rand() % 255;
        green = rand() % 255;
        blue = rand() % 255;
        color = makecol(red, green, blue);

        // Desenha o circulo
        circle(screen, x, y, radius, color);
        rest(25);
    }
    // finaliza o programa
    allegro_exit();
}
END_OF_MAIN();
