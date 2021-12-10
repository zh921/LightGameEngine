- [MiniGameEngine](#minigameengine)
	- [Hazel](#hazel)
	- [Visual Studio Confuguration](#visual-studio-confuguration)
	- [Entry Point](#entry-point)
	- [Loging system](#loging-system)


# MiniGameEngine

learn how to develop a game engine.


- [GitHub - Hazel](GitHub https://github.com/TheCherno/Hazel)
- [GitHub - Cherno](https://github.com/TheCherno/Cherno)
- [GitHub - ludumdare](https://github.com/ludumdare)

## Hazel

Entry point

Application Layer

Window Layer

	Input
	Events

Renderer

	Reder API abstraction

Debugging support

	logging system
	performance

Scripting Language

Memory Systems

Entity Component System (ECS)

Physics

File I/O, VFS

Build System

## Visual Studio Confuguration

MiniGameEngine Property Pages > Configuration Properties > General > Output Directory > $(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\
MiniGameEngine Property Pages > Configuration Properties > General > Intermediate Directory > $(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\
MiniGameEngine Property Pages > Configuration Properties > General > Configuration Type > Dynamic Library(.dll)
MiniGameEngine Property Pages > Configuration Properties > General > Windows SDK Version > 10.0.19041.0
MiniGameEngine Property Pages > Configuration Properties > General > Platform Toolset > Visual Studio 2019(v142)
MiniGameEngine Property Pages > Configuration Properties > C/C++ > General > Additional Include Directories > $(SolutionDir)MiniGameEngine\vendor\spdlog\include;
MiniGameEngine Property Pages > Configuration Properties > C/C++ > Preprocessor > MGE_PLATFORM_WINDOWS;MGE_BUILD_DLL;

Sandbox Property Pages > Configuration Properties > General > Output Directory > $(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\
Sandbox Property Pages > Configuration Properties > General > Intermediate Directory > $(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\
Sandbox Property Pages > Configuration Properties > General > Configuration Type > Application(.exe)
Sandbox Property Pages > Configuration Properties > General > Windows SDK Version > 10.0.19041.0
Sandbox Property Pages > Configuration Properties > General > Platform Toolset > Visual Studio 2019(v142)
Sandbox Property Pages > Configuration Properties > C/C++ > General > Additional Include Directories > $(SolutionDir)MiniGameEngine\src;$(SolutionDir)MiniGameEngine\vendor\spdlog\include;
Sandbox Property Pages > Configuration Properties > C/C++ > Preprocessor > MGE_PLATFORM_WINDOWS;


## Entry Point

```cpp
__declspec(dllexport) // 导出符号，也就是定义需要导出函数的dll中给导出函数的函数声明前面加上导出符号，表示该方法可以导出给其他DLL或者exe使用。
__declspec(dllimport) // 导入符号，也就是在使用该函数的DLL或者exe中需要在该函数的函数声明前面加上该符号，表示该函数方法是从其他库导入的。

// 为了方便使用和维护同一分头文件，所以在导出函数的头文件中加上这段代码:

#ifdef MGE_BUILD_DLL
	#define MGE_API __declspec(dllexport)
#else
	#define MGE_API __declspec(dllimport)
#endif

// 我们在该导出DLL的编译选项定义中定义宏 #define MGE_BUILD_DLL，而在调用该导出函数DLL的其他DLL或者exe的编译选项中不定义宏 MGE_BUILD_DLL。
// 那么导出头文件和导入头文件就可以只维持一份头文件了，有利于维护。

```

## Loging system

git submodule add https://github.com/gabime/spdlog MiniGameEngine/vendor/spdlog

