workspace "MiniGameEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MiniGameEngine"
    location "MiniGameEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.19041.0"

        defines
        {
            "MGE_PLATFORM_WINDOWS",
            "MGE_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "MGE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "MGE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "MGE_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "MiniGameEngine/vendor/spdlog/include",
        "MiniGameEngine/src"
    }

    links
    {
        "MiniGameEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.19041.0"

        defines
        {
            "MGE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "MGE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "MGE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "MGE_DIST"
        optimize "On"
