// Copyright Epic Games, Inc. All Rights Reserved.

#include "MEDELTGameMode.h"
#include "MEDELTPlayerController.h"

AMEDELTGameMode::AMEDELTGameMode()
{
	// use our own player controller class
	PlayerControllerClass = AMEDELTPlayerController::StaticClass();
}
