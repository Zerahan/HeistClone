// Fill out your copyright notice in the Description page of Project Settings.

#include "HeistGameCloneEditor.h"
#include "UnrealEd.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_GAME_MODULE( FDefaultGameModuleImpl, HeistGameCloneEditor );

void FHeistGameCloneEditorModule::StartupModule()
{
	if (GUnrealEd)
	{
	}
}

void FHeistGameCloneEditorModule::ShutdownModule()
{
	if (GUnrealEd)
	{
	}
}
