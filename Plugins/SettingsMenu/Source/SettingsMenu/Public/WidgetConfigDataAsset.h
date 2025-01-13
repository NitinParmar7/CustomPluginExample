// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WidgetConfigDataAsset.generated.h"

/**
 * Enum to identify widget type
 */
UENUM(BlueprintType)
enum class EWidgetType : uint8
{
	Selector UMETA(DisplayName = "Selector"),
	Slider UMETA(DisplayName = "Slider"),
	Toggle UMETA(DisplayName = "Toggle"),
};


/**
 * a Widget configuration widget, which allows us to specify what kind of widget it is
 * and it's data
 */
USTRUCT(BlueprintType)
struct SETTINGSMENU_API FWidgetConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetConfig")
	EWidgetType WidgetType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetConfig")
	FText LabelText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetConfig")
	TArray<FString> Options;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetConfig")
	float DefaultValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetConfig")
	bool bIsChecked;
};

/**
 * a Primary Data Asset which holds the information regarding widgets
 * Which can be used to async load and generate widgets at runtime
 */
UCLASS(Blueprintable, BlueprintType)
class SETTINGSMENU_API UWidgetConfigDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TArray<FWidgetConfig> Widgets;
};
