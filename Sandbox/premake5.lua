project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir("%{wks.location}/Binaries/" .. outputdir .. "%{prj.name}")
    objdir("%{wks.location}/Binaries/Object/" .. outputdir .. "%{prj.name}")

    files {
        "Include/**.h",
        "Source/**.cpp"
    }

    includedirs {
        "Include",
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