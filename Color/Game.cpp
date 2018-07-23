#include "Game.h"
#include "GameProcessor.h"
#include "GameViewer.h"

Game::Game( ) {
	_process = GameProcessorPtr( new GameProcessor( ) );
	_viewer = GameViewerPtr( new GameViewer( _process ) );
}

Game::~Game( ) {
}

void Game::update( ) {
	_process->update( );
	_viewer->update( );
}