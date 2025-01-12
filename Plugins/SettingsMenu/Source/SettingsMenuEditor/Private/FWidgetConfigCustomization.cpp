// Fill out your copyright notice in the Description page of Project Settings.


#include "FWidgetConfigCustomization.h"

#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "WidgetConfigDataAsset.h"


TSharedRef<IPropertyTypeCustomization> FWidgetConfigCustomization::MakeInstance()
{
	return MakeShareable(new FWidgetConfigCustomization());
}



void FWidgetConfigCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle,
	FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	HeaderRow
		.NameContent()
		[
			PropertyHandle->CreatePropertyNameWidget()
		]
		.ValueContent()
		[
			PropertyHandle->CreatePropertyValueWidget()
		];
}

void FWidgetConfigCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle,
	IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	const TSharedPtr<IPropertyHandle> WidgetTypeHandle = PropertyHandle->GetChildHandle("WidgetType");
	const TSharedPtr<IPropertyHandle> LabelTextHandle = PropertyHandle->GetChildHandle("LabelText");
	const TSharedPtr<IPropertyHandle> OptionsHandle = PropertyHandle->GetChildHandle("Options");
	const TSharedPtr<IPropertyHandle> DefaultValueHandle = PropertyHandle->GetChildHandle("DefaultValue");
	const TSharedPtr<IPropertyHandle> IsCheckedHandle = PropertyHandle->GetChildHandle("bIsChecked");

	if (WidgetTypeHandle.IsValid())
	{
		ChildBuilder.AddProperty(WidgetTypeHandle.ToSharedRef());
	}

	if (LabelTextHandle.IsValid())
	{
		ChildBuilder.AddProperty(LabelTextHandle.ToSharedRef());
	}

	if (OptionsHandle.IsValid())
	{
		ChildBuilder.AddProperty(OptionsHandle.ToSharedRef())
			.Visibility(TAttribute<EVisibility>::CreateLambda([WidgetTypeHandle]()
			{
				uint8 WidgetType;
				WidgetTypeHandle->GetValue(WidgetType);
				return static_cast<EWidgetType>(WidgetType) == EWidgetType::Selector ? EVisibility::Visible : EVisibility::Collapsed;
			}));
	}



	if (DefaultValueHandle.IsValid())
	{
		ChildBuilder.AddProperty(DefaultValueHandle.ToSharedRef())
			.Visibility(TAttribute<EVisibility>::CreateLambda([WidgetTypeHandle]()
			{
				uint8 WidgetType;
				WidgetTypeHandle->GetValue(WidgetType);
				return static_cast<EWidgetType>(WidgetType) == EWidgetType::Slider ? EVisibility::Visible : EVisibility::Collapsed;
			}));
	}

	if (IsCheckedHandle.IsValid())
	{
		ChildBuilder.AddProperty(IsCheckedHandle.ToSharedRef())
			.Visibility(TAttribute<EVisibility>::CreateLambda([WidgetTypeHandle]()
			{
				uint8 WidgetType;
				WidgetTypeHandle->GetValue(WidgetType);
				return static_cast<EWidgetType>(WidgetType) == EWidgetType::Toggle ? EVisibility::Visible : EVisibility::Collapsed;
			}));
	}
}




