project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir("%{wks.location}/Build/")
    objdir("%{wks.location}/Build/Object")

    files {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs {
        "Source/",
        "%{Includes.Melancholy}"
    }

    links {
        "Melancholy"
    }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"