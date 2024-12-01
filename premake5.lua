workspace "Melancholy_Workspace"
    configurations { "Debug", "Release" }
    architecture "x64"

Includes = {}
Includes["Melancholy"] = "%{wks.location}/Melancholy/Source/"

include "Melancholy"
include "Sandbox"