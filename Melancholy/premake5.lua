project "Melancholy"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"

    targetdir("%{wks.location}/Build/")
    objdir("%{wks.location}/Build/Object")

    files {
        "Source/**.h",
        "Source/**.cpp",
    }

    includedirs {
        "Source/"
    }

    defines {
        "M_EXPORT"
    }

    filter "configurations:Debug"
        defines "M_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "M_RELEASE"
        optimize "On"