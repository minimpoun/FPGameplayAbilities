// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "AttributeSet.h"
#include "FPGAAttributeDisplay.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFPGAAttributeDisplayChanged, float, OldValue, float, NewValue);

struct FOnAttributeChangeData;
class UAbilitySystemComponent;

UCLASS()
class FPGAMEPLAYABILITIES_API UFPGAAttributeDisplay : public UTextBlock
{
	GENERATED_BODY()

public:
	FDelegateHandle DelegateHandle;

	UAbilitySystemComponent* AbilitySystemPtr;

	bool bNeedToUnbind = false;

	/** The attribute */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttribute Attribute;
	
	UPROPERTY(BlueprintAssignable)
	FOnFPGAAttributeDisplayChanged OnAttributeDisplayChanged;

	UFUNCTION(BlueprintCallable)
	void BindAttribute(UAbilitySystemComponent* AbilitySystem);

	UFUNCTION(BlueprintCallable)
	void BindAndSetAttribute(UAbilitySystemComponent* AbilitySystem, FGameplayAttribute NewAttribute);

	void UnbindAttribute();

	void OnAttributeChanged(const FOnAttributeChangeData& ChangeData);

	void BeginDestroy() override;

#if WITH_EDITOR
	const FText GetPaletteCategory() override;
#endif
};
