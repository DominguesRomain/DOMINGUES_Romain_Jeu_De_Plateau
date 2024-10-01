// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class DOMINGUES_ColorBoardTarget : TargetRules
{
	public DOMINGUES_ColorBoardTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "DOMINGUES_ColorBoard" } );
	}
}
