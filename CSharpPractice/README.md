# CSharp Practice

You need to install dotnet cli w/ .NET SDKs

## General
- dotnet new gitignore
- dotnet new xunit

NOTE: "dotnet new sln" is only used if used with Visual Studio or if a group of *.csproj are intended to be grouped into a single unit.

NOTE: "dotnet new sln -o '_Name_of_Solution_'"
NOTE: "dotnet new classlib -o '_Name_of_Class_Library_'"
NOTE: "dotnet sln add $'./_Name_of_Other_Solution_/____.csproj'"
## Personal.CSharp.UnitTest Setup
- dotnet restore
- dotnet test

NOTE: [Fact] is a test method attribute that denotes a parameterless test
NOTE: [Theory] is a test method attribute that denotes a parameterized test that is true for a subset of data, where multiple parameters is a list deliminated with a comma