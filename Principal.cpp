#pragma once
#include "Principal.h"

Jogo::Principal::Principal() :
	listaPersonagem(), listaObstaculo(), pGrafico(pGrafico->getGerenciadorGrafico()),
	pEvento(pEvento->getGerenciadorEvento()),
	colisor(&listaPersonagem, &listaObstaculo)
{
	if (pGrafico == nullptr) {
		std::cout << "ERROR::Jogo::Principal nao foi possivel criar o GerenciadorGrafico" << std::endl;
		exit(1);
	}
	if (pEvento== nullptr) {
		std::cout << "ERROR::Jogo::Principal nao foi possivel criar o GerenciadorEvento" << std::endl;
		exit(1);
	}

	instanciaEntidades();

	executar();
}

Jogo::Principal::~Principal() {
	listaObstaculo.limparLista();
	listaPersonagem.limparLista();
}

void Jogo::Principal::instanciaEntidades() {

	//cria personagens e obstaculos
	Entidade::Personagem::Jogador::Jogador* jogador = new Entidade::Personagem::Jogador::Jogador(sf::Vector2f(500.0f, 100.0f), sf::Vector2f(50.0f, 50.0f));
	Entidade::Personagem::Inimigo::Inimigo* i1 = new Entidade::Personagem::Inimigo::Inimigo(sf::Vector2f(500.0f, 100.0f), sf::Vector2f(50.0f, 50.0f), jogador);
	Entidade::Obstaculo::Plataforma* p1 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(300.0f, 150.0f), sf::Vector2f(400.0f, 40.0f));
	Entidade::Obstaculo::Plataforma* p2 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(0.0f, 400.0f), sf::Vector2f(400.0f, 40.0f));
	Entidade::Obstaculo::Plataforma* p3 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(350.0f, 300.0f), sf::Vector2f(400.0f, 40.0f));
	Entidade::Obstaculo::Plataforma* p4 = new Entidade::Obstaculo::Plataforma(sf::Vector2f(250.0f, 550.0f), sf::Vector2f(400.0f, 40.0f));

	//transforma eles em entidades
	Entidade::Entidade* e1 = static_cast<Entidade::Entidade*>(jogador);
	Entidade::Entidade* e2 = static_cast<Entidade::Entidade*>(p1);
	Entidade::Entidade* e3 = static_cast<Entidade::Entidade*>(p2);
	Entidade::Entidade* e4 = static_cast<Entidade::Entidade*>(p3);
	Entidade::Entidade* e5 = static_cast<Entidade::Entidade*>(p4);

	Entidade::Entidade* e6 = static_cast<Entidade::Entidade*>(i1);

	//adiciona na lista de entidades
	listaPersonagem.addEntidade(e1);
	listaPersonagem.addEntidade(e6);

	listaObstaculo.addEntidade(e2);
	listaObstaculo.addEntidade(e3);
	listaObstaculo.addEntidade(e4);
	listaObstaculo.addEntidade(e5);

	pEvento->setJogador(jogador);
}

void Jogo::Principal::executar() {
	while (pGrafico->verificaJanelaAberta()) {
		pEvento->executar();
		pGrafico->limpaJanela();
		//pinta entidades
		listaPersonagem.executar(pGrafico->getWindow());
		listaObstaculo.executar(pGrafico->getWindow());

		colisor.executar();

		pGrafico->mostraElementos();
	}
}