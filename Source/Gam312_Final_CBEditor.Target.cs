// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Gam312_Final_CBEditorTarget : TargetRules
{
	public Gam312_Final_CBEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Gam312_Final_CB" } );
	}
}
