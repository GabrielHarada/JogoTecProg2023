#pragma once
#include "Caixa.h"

Jogo::Entidade::Obstaculo::Caixa::Caixa(sf::Vector2f pos, sf::Vector2f tam) :
    Obstaculo(pos, tam, IDs::IDs::caixa), podeEmpurrar(false)
{

}

Jogo::Entidade::Obstaculo::Caixa::~Caixa() {

}

void Jogo::Entidade::Obstaculo::Caixa::colisao(Entidade* outraEntidade, sf::Vector2f ds) {

}