#pragma once

#include "..\Obstaculo.h"
#include "..\..\Personagem\Personagem.h"

#define CAMINHO_TEXTURA_PLATAFORMA "image/Obstaculo/plataforma.png"
#define ESCALA_PLATAFORMA_X 1
#define ESCALA_PLATAFORMA_Y 1

namespace Fantasy {

    namespace Entidade {

        namespace Obstaculo {

            class Plataforma : public Obstaculo {
            private:
                int tipoPlataforma;
            public:
                Plataforma(sf::Vector2f pos, sf::Vector2f tam, int tipoPlataforma = 1);
                ~Plataforma();
                void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
            };

        }

    }

}