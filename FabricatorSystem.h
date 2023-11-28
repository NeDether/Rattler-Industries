#pragma once

#include <Spore\BasicIncludes.h>
#include "stdafx.h"
#include "Spore/Simulator/SubSystem/SpaceTrading.h"
#include <Spore\BasicIncludes.h>
#include <Spore/CommonIDs.h>
#include "xFabClose.h"
#include <Spore/Simulator/cSpaceToolData.h>
#include <exception>
#include <stdexcept>
#include <Spore\App\cJob.h>
#include <Spore\App\JobManager.h>
#include <Spore\UI\ScrollFrameVertical.h>
#include <set>

#define FabricatorSystemPtr intrusive_ptr<FabricatorSystem>
#define FabricatorSystemA (FabricatorSystem::Get())[0]
///
/// In your dllmain Initialize method, add the system like this:
/// ModAPI::AddSimulatorStrategy(new FabricatorSystem(), FabricatorSystem::NOUN_ID);
///

struct Recipe
{
public:
	Recipe(uint32_t propID);
	Recipe();
	//Recipe(PropertyListPtr propList, uint32_t toolID, vector<uint32_t> Blueprint, vector<uint32_t> Ingredients , uint32_t CraftingID);

	const bool operator==(const Recipe other);
	const bool operator!=(const Recipe other);
	explicit operator bool() const;


	PropertyListPtr mpPropList;
	uint32_t mToolID;
	vector<uint32_t> Blueprint;
	vector<uint32_t> Ingredients;
	uint32_t CraftingID;
	LocalizedString CName;
	LocalizedString CDesc;
};
///kamacite - ni - [0]
///sulphide - s - [1]
///ice - h - [2]
///silica - si - [3]
///carbon - c - [4]
///copper - cu - [5]
///titanium - ti - [6]
///gold - au - [7]
///latticine - lt - [8]
/// 
class FabricatorSystem
	: public Simulator::cStrategy
{
public:
	static const uint32_t TYPE = id("RattlerSpore::FabricatorSystem");
	static const uint32_t NOUN_ID = TYPE;
	UTFWin::UILayout layout;
	int AddRef() override;
	int Release() override;
	void Initialize() override;
	void Dispose() override;
	const char* GetName() const override;
	bool Write(Simulator::ISerializerStream* stream) override;
	bool Read(Simulator::ISerializerStream* stream) override;
	void Update(int deltaTime, int deltaGameTime) override;
	bool WriteToXML(Simulator::XmlSerializer* writexml) override;

	//
	// You can add more methods here
	//

	static Simulator::Attribute ATTRIBUTES[];
	static FabricatorSystem* Get();

	bool OpenFab(bool sex);
	bool CloseFab(bool sex);

private:
	//
	// You can add members here
	//

	static FabricatorSystem* sInstance;
	UTFWin::UILayout* mpUIlayout;
	float mWindowOffset;
};