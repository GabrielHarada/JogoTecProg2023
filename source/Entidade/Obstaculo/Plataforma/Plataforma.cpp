#pragma once
#include "..\..\header\Entidade\Obstaculo\Plataforma\Plataforma.h"

Fantasy::Entidade::Obstaculo::Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam) :
    Obstaculo(pos, tam, IDs::IDs::plataforma, CAMINHO_TEXTURA_PLATAFORMA)
{
    //textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_PLATAFORMA);
    //corpo.setTexture(&textura);
    //corpo.setFillColor(sf::Color::Cyan);
}

Fantasy::Entidade::Obstaculo::Plataforma::~Plataforma() {

}

void Fantasy::Entidade::Obstaculo::Plataforma::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
    sf::Vector2f posOutro = outraEntidade->getPos();
    sf::Vector2f tamOutro = outraEntidade->getTam();

    if (outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::inimigo) {
        colisaoObstaculo(ds, static_cast<Personagem::Personagem*>(outraEntidade));
    }
}

void Fantasy::Entidade::Obstaculo::Plataforma::colisaoObstaculo(sf::Vector2f ds, Personagem::Personagem* pPersonagem) {
    sf::Vector2f posOutro = pPersonagem->getPos();
    sf::Vector2f tamOutro = pPersonagem->getTam();
    sf::Vector2f velFinal = pPersonagem->getVelFinal();
    if (ds.x < 0.0f && ds.y < 0.0f) { //houve colisao
        if (ds.x > ds.y) {
            if (posOutro.x < pos.x) { //colis�o em x
                posOutro.x += ds.x;
            }
            else {
                posOutro.x -= ds.x;
            }
            velFinal.x = 0.0f;
        }
        else {
            if (posOutro.y < pos.y) { //colis�o em y
                posOutro.y += ds.y;
                if (pPersonagem->getID() == IDs::IDs::jogador) {
                    Personagem::Jogador::Jogador* pJogador = static_cast<Personagem::Jogador::Jogador*>(pPersonagem);
                    pJogador->podePular();
                }
            }
            else {
                posOutro.y -= ds.y;
            }
            velFinal.y = 0.0f;
        }
    }
    pPersonagem->setPos(posOutro);
    pPersonagem->setVelFinal(velFinal);
}