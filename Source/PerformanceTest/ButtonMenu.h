// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "ButtonMenu.generated.h"

/**
 * 
 */
UCLASS()
class PERFORMANCETEST_API AButtonMenu : public AHUD
{
	GENERATED_BODY()

public:
	AButtonMenu(const FObjectInitializer& ObjectInitializer);

	// Unreal Font
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		UFont* unrealFont;

	// Font Scaling 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		float defaultFontScale;

	// Button 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		UTexture2D* buttonNormalTex;

	// Button Pressed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		UTexture2D* buttonPressedTex;

	// Draw Hud?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		bool dontDrawHUD;

	// Light Source Counter
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		int32 lightSourceCounter;

	// Triangle Counter
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		int32 triCounter;

	// Paticle Counter
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		int32 particleCounter;
	
	// Lights Visibility

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightProps")
		bool buttonSelectStationaryLightPressed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightProps")
		bool buttonSelectMoveableLightPressed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightProps")
		bool buttonSpawnLightSourcePressed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightProps")
		bool buttonSpawnPointLightPressed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightProps")
		bool buttonSpawnSkyLightPressed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightProps")
		bool buttonSpawnSpotLightPressed;

	// Objects Visibility
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObjProps")
		bool buttonSelectStaticObjectPressed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObjProps")
		bool buttonSelectMoveableObjectPressed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObjProps")
		bool buttonSpawn200TriObjectPressed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObjProps")
		bool buttonSpawn1kTriObjectPressed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObjProps")
		bool buttonSpawn5kTriObjectPressed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ObjProps")
		bool buttonSpawn25kTriObjectPressed;

	// Particle Visibility
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleProps")
		bool buttonSpawnParticlePressed;

	// Functions
	void DrawButton(FVector2D buttonScreenLocation, FString buttonText, FName hitboxName, UTexture2D* buttonTexture);

	void DrawLightButtons();

	void DrawObjectButtons();

	UFUNCTION(BlueprintCallable, Category = "ButtonDebugFunction")
	void DrawButtonTextFeedback(const FString buttonText, float visibleTime);

	void DrawHUD() override;

	UFUNCTION(BlueprintCallable, Category = "ButtonFunction")
	void SwitchButtonTexture(FName selectedBox);
};
