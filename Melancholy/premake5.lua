project "Melancholy"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"

    targetdir("%{wks.location}/Binaries/" .. outputdir .. "%{prj.name}")
    objdir("%{wks.location}/Binaries/Object/" .. outputdir .. "%{prj.name}")

    files {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs {
        "Source"
    }

    defines {
        "ML_EXPORT"
    }

    filter "configurations:Debug"
        defines "ML_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ML_RELEASE"
        optimize "On"