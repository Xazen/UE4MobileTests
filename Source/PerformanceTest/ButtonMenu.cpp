// Fill out your copyright notice in the Description page of Project Settings.

#include "PerformanceTest.h"
#include "ButtonMenu.h"

AButtonMenu::AButtonMenu(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	defaultFontScale = 1.0f;

	dontDrawHUD = false;

	// Counter
	lightSourceCounter = 0;
	triCounter = 0;
	particleCounter = 0;

	// Select Light Mobility
	buttonSelectStationaryLightPressed = false;
	buttonSelectMoveableLightPressed = false;

	// Select Object Mobility 
	buttonSelectStaticObjectPressed = false; 
	buttonSelectMoveableObjectPressed = false;

	// Every LightSource Button
	buttonSpawnLightSourcePressed = false;
	buttonSpawnPointLightPressed = false;
	buttonSpawnSkyLightPressed = false;
	buttonSpawnSpotLightPressed = false;

	// Every Object Button
	buttonSpawn200TriObjectPressed = false;
	buttonSpawn1kTriObjectPressed = false;
	buttonSpawn5kTriObjectPressed = false;
	buttonSpawn25kTriObjectPressed = false;

	// Particle Button
	buttonSpawnParticlePressed = false;

}

void AButtonMenu::DrawButton(FVector2D buttonScreenLocation, FString buttonText, FName hitboxName, UTexture2D* buttonTexture)
{
	float posX = 0.0f;
	float posY = 0.0f;
	posX = buttonScreenLocation.X - 128.0f;
	posY = buttonScreenLocation.Y - 64.0f;
	DrawTextureSimple(buttonTexture, posX, posY, 0.6f, false);

	float texOutWidth = 0.0f;
	float texOutHeight = 0.0f;
	GetTextSize(buttonText, texOutWidth, texOutHeight, this->unrealFont, 1.0f);
	texOutWidth = texOutWidth	/ 2;
	texOutWidth = texOutHeight	/ 2;

	DrawText(buttonText, WhiteColor, (buttonScreenLocation.X - 105.0f), (buttonScreenLocation.Y - 40.0f), this->unrealFont, 0.8f, false);

	AddHitBox(FVector2D(posX, posY), FVector2D(150.0f, 70.0f), hitboxName, false, 0);
}

void AButtonMenu::DrawButtonTextFeedback(const FString buttonText, float visibleTime)
{
	GEngine->AddOnScreenDebugMessage(-1, visibleTime, FColor::White, buttonText);
}

void AButtonMenu::DrawHUD()
{
	// Draw HUD?
	if (dontDrawHUD) return;

	// Super
	Super::DrawHUD();

	// No Canvas?
	if (!Canvas) return;
	
	// FVector2D(Canvas->SizeX / 2, Canvas->SizeY / 2) = Center of Screen

	// Counter
	float textLightOutWidth = 0.0f;
	float textLightOutHeight = 0.0f;
	FString lightCounterText = "Light Sources: " + FString::FromInt(lightSourceCounter);
	GetTextSize(lightCounterText, textLightOutWidth, textLightOutHeight, this->unrealFont, 1.0f);
	textLightOutWidth = textLightOutWidth / 2;
	textLightOutHeight = textLightOutHeight / 2;

	float textTriOutWidth = 0.0f;
	float textTriOutHeight = 0.0f;
	FString triCounterText = "Triangles: " + FString::FromInt(triCounter);
	GetTextSize(triCounterText, textTriOutWidth, textTriOutHeight, this->unrealFont, 1.0f);
	textTriOutWidth = textTriOutWidth / 2;
	textTriOutHeight = textTriOutHeight / 2;

	float textParticleOutWidth = 0.0f;
	float textParticleOutHeight = 0.0f;
	FString particleCounterText = "Particles: " + FString::FromInt(particleCounter);
	GetTextSize(particleCounterText, textParticleOutWidth, textParticleOutHeight, this->unrealFont, 1.0f);
	textParticleOutWidth = textParticleOutWidth / 2;
	textParticleOutHeight = textParticleOutHeight / 2;

	DrawText(lightCounterText, WhiteColor, 20.0f, 50.0f, this->unrealFont, 0.8f, false);
	DrawText(triCounterText, WhiteColor, 180.0f, 50.0f, this->unrealFont, 0.8f, false);
	DrawText(particleCounterText, WhiteColor, 400.0f, 50.0f, this->unrealFont, 0.8f, false);

/*
	// Lights
	if (!buttonSelectStationaryLightPressed)
	{
		DrawButton(FVector2D(130, 140), "+Stationaries", "Stationaries", this->buttonNormalTex);
	}
	else
	{
		if (!buttonSelectMoveableLightPressed)
		{
			DrawButton(FVector2D(130, 140), "-Stationaries", "Stationaries", this->buttonNormalTex);
		
			// StationaryLights
			DrawLightButtons();
		}
		else
		{
			DrawButton(FVector2D(130, 140), "-Stationaries", "Stationaries", this->buttonNormalTex);
		}
	}

	if (!buttonSelectMoveableLightPressed)
	{
		DrawButton(FVector2D(280, 140), "+Moveable", "MoveableLight", this->buttonNormalTex);
	}
	else
	{
		if (!buttonSelectStationaryLightPressed)
		{
			DrawButton(FVector2D(280, 140), "-Moveable", "MoveableLight", this->buttonNormalTex);
		
			// Moveable Lights
			DrawLightButtons();
		}
		else
		{
			DrawButton(FVector2D(280, 140), "-Moveable", "MoveableLight", this->buttonNormalTex);
		}
	}
	
	// Objects

	if (!buttonSelectStaticObjectPressed)
	{
		DrawButton(FVector2D(700, 140), "+Static", "Static", this->buttonNormalTex);
	}
	else
	{ 
		if (!buttonSelectMoveableObjectPressed)
		{ 
			DrawButton(FVector2D(700, 140), "-Static", "Static", this->buttonNormalTex);

			// StationaryLights
			DrawObjectButtons();
		}
		else
		{
			DrawButton(FVector2D(700, 140), "-Static", "Static", this->buttonNormalTex);
		}
	}

	if (!buttonSelectMoveableObjectPressed)
	{
		DrawButton(FVector2D(840, 140), "+Moveable", "MoveableObj", this->buttonNormalTex);
	}
	else
	{
		if (!buttonSelectStaticObjectPressed)
		{
			DrawButton(FVector2D(840, 140), "-Moveable", "MoveableObj", this->buttonNormalTex);

			// Moveable Lights
			DrawObjectButtons();
		}
		else
		{
			DrawButton(FVector2D(840, 140), "-Moveable", "MoveableObj", this->buttonNormalTex);
		}
	}
*/

	// Objects
	if (!buttonSelectStaticObjectPressed)
	{
		DrawButton(FVector2D(130, 140), "+Static", "Static", this->buttonNormalTex);
	}
	else
	{
		if (!buttonSelectMoveableObjectPressed)
		{
			DrawButton(FVector2D(130, 140), "-Static", "Static", this->buttonNormalTex);

			// StationaryLights
			DrawObjectButtons();
		}
		else
		{
			DrawButton(FVector2D(130, 140), "-Static", "Static", this->buttonNormalTex);
		}
	}

	if (!buttonSelectMoveableObjectPressed)
	{
		DrawButton(FVector2D(280, 140), "+Moveable", "MoveableObj", this->buttonNormalTex);
	}
	else
	{
		if (!buttonSelectStaticObjectPressed)
		{
			DrawButton(FVector2D(280, 140), "-Moveable", "MoveableObj", this->buttonNormalTex);

			// Moveable Lights
			DrawObjectButtons();
		}
		else
		{
			DrawButton(FVector2D(280, 140), "-Moveable", "MoveableObj", this->buttonNormalTex);
		}
	}

	// Particle
	if (!buttonSpawnParticlePressed)
	{
		DrawButton(FVector2D(500, 140), "+Particle", "Particle", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(500, 140), "-Particle", "Particle", this->buttonNormalTex);
	}

}

void AButtonMenu::DrawLightButtons()
{
	/*
	// Light Buttons
	if (!buttonSpawnLightSourcePressed)
	{
		DrawButton(FVector2D(200, 200), "+LightSource", "LightSource", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(200, 200), "-LightSource", "LightSource", this->buttonNormalTex);
	}

	if (!buttonSpawnPointLightPressed)
	{
		DrawButton(FVector2D(200, 270), "+PointLight", "PointLight", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(200, 270), "-PointLight", "PointLight", this->buttonNormalTex);
	}

	if (!buttonSpawnSkyLightPressed)
	{
		DrawButton(FVector2D(200, 340), "+SkyLight", "SkyLight", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(200, 340), "-SkyLight", "SkyLight", this->buttonNormalTex);
	}

	if (!buttonSpawnSpotLightPressed)
	{
		DrawButton(FVector2D(200, 410), "+SpotLight", "SpotLight", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(200, 410), "-SpotLight", "SpotLight", this->buttonNormalTex);
	}
	*/
}

void AButtonMenu::DrawObjectButtons()
{
	// Object Buttons
	if (!buttonSpawn200TriObjectPressed)
	{
		DrawButton(FVector2D(200, 200), "+200TriObj", "200TriObj", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(200, 200), "-200TriObj", "200TriObj", this->buttonNormalTex);
	}

	if (!buttonSpawn1kTriObjectPressed)
	{
		DrawButton(FVector2D(200, 270), "+1kTriObj", "1kTriObj", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(200, 270), "-1kTriObj", "1kTriObj", this->buttonNormalTex);
	}

	if (!buttonSpawn5kTriObjectPressed)
	{
		DrawButton(FVector2D(200, 340), "+5kTriObj", "5kTriObj", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(200, 340), "-5kTriObj", "5kTriObj", this->buttonNormalTex);
	}

	if (!buttonSpawn25kTriObjectPressed)
	{
		DrawButton(FVector2D(200, 410), "+25kTriObj", "25kTriObj", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(200, 410), "-25kTriObj", "25kTriObj", this->buttonNormalTex);
	}
	/*
	// Object Buttons
	if (!buttonSpawn200TriObjectPressed)
	{
		DrawButton(FVector2D(770, 200), "+200TriObj", "200TriObj", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(770, 200), "-200TriObj", "200TriObj", this->buttonNormalTex);
	}

	if (!buttonSpawn1kTriObjectPressed)
	{
		DrawButton(FVector2D(770, 270), "+1kTriObj", "1kTriObj", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(770, 270), "-1kTriObj", "1kTriObj", this->buttonNormalTex);
	}

	if (!buttonSpawn5kTriObjectPressed)
	{
		DrawButton(FVector2D(770, 340), "+5kTriObj", "5kTriObj", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(770, 340), "-5kTriObj", "5kTriObj", this->buttonNormalTex);
	}

	if (!buttonSpawn25kTriObjectPressed)
	{
		DrawButton(FVector2D(770, 410), "+25kTriObj", "25kTriObj", this->buttonNormalTex);
	}
	else
	{
		DrawButton(FVector2D(770, 410), "-25kTriObj", "25kTriObj", this->buttonNormalTex);
	}
	*/
}

void AButtonMenu::SwitchButtonTexture(FName selectedBox)
{	
	/*
	if (selectedBox == "Stationaries")
	{
		buttonSelectStationaryLightPressed = !buttonSelectStationaryLightPressed;
	}

	if (selectedBox == "MoveableLight")
	{
		buttonSelectMoveableLightPressed = !buttonSelectMoveableLightPressed;
	}

	//
	if (selectedBox == "LightSource")
	{
		buttonSpawnLightSourcePressed = !buttonSpawnLightSourcePressed;
	}

	if (selectedBox == "PointLight")
	{
		buttonSpawnPointLightPressed = !buttonSpawnPointLightPressed;
	}

	if (selectedBox == "SkyLight")
	{
		buttonSpawnSkyLightPressed = !buttonSpawnSkyLightPressed;
	}

	if (selectedBox == "SpotLight")
	{
		buttonSpawnSpotLightPressed = !buttonSpawnSpotLightPressed;
	}
	*/
	// Objects

	if (selectedBox == "Static")
	{
		buttonSelectStaticObjectPressed = !buttonSelectStaticObjectPressed;
	}

	if (selectedBox == "MoveableObj")
	{
		buttonSelectMoveableObjectPressed = !buttonSelectMoveableObjectPressed;
	}

	//
	if (selectedBox == "200TriObj")
	{
		buttonSpawn200TriObjectPressed = !buttonSpawn200TriObjectPressed;
	}

	if (selectedBox == "1kTriObj")
	{
		buttonSpawn1kTriObjectPressed = !buttonSpawn1kTriObjectPressed;
	}

	if (selectedBox == "5kTriObj")
	{
		buttonSpawn5kTriObjectPressed = !buttonSpawn5kTriObjectPressed;
	}

	if (selectedBox == "25kTriObj")
	{
		buttonSpawn25kTriObjectPressed = !buttonSpawn25kTriObjectPressed;
	}


	// Particle
	if (selectedBox == "Particle")
	{
		buttonSpawnParticlePressed = !buttonSpawnParticlePressed;
	}
	
}
//