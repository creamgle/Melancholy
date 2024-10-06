workspace "Melancholy_Workspace"
    configurations { "Debug", "Release" }
    architecture "x86_64"

outputdir = ""

Includes = {}
Includes["Melancholy"] = "%{wks.location}/Melancholy/Source"

include "Melancholy"
include "Sandbox"