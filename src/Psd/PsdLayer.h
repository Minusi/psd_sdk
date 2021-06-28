// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#pragma once

#include <vector>
#include <map>
#include <memory>
#include "PsdFixedSizeString.h"
#include "PsdString.h"


PSD_NAMESPACE_BEGIN

struct Channel;
struct TransparencyMask;
struct LayerMask;
struct VectorMask;

struct Descriptor;
struct LinkedLayer;

struct Reference;


/// \ingroup Types
/// \class Layer
/// \brief A struct representing a layer as stored in the Layer Mask Info section.
/// \sa LayerMaskSection Channel LayerMask VectorMask
struct Layer
{
	Layer* parent;						///< The layer's parent layer, if any.
	util::FixedSizeString name;			///< The ASCII name of the layer. Truncated to 31 characters in PSD files.
	uint16_t* utf16Name;				///< The UTF16 name of the layer.

	int32_t top;						///< Top coordinate of the rectangle that encloses the layer.
	int32_t left;						///< Left coordinate of the rectangle that encloses the layer.
	int32_t bottom;						///< Bottom coordinate of the rectangle that encloses the layer.
	int32_t right;						///< Right coordinate of the rectangle that encloses the layer.

	Channel* channels;					///< An array of channels, having channelCount entries.
	unsigned int channelCount;			///< The number of channels stored in the array.

	LayerMask* layerMask;				///< The layer's user mask, if any.
	VectorMask* vectorMask;				///< The layer's vector mask, if any.

	uint32_t blendModeKey;				///< The key denoting the layer's blend mode. Can be any key described in \ref blendMode::Enum.
	uint8_t opacity;					///< The layer's opacity value, with the range [0, 255] mapped to [0%, 100%].
	uint8_t clipping;					///< The layer's clipping mode (not used yet).

	uint32_t type;						///< The layer's type. Can be any of \ref layerType::Enum.
	bool isVisible;						///< The layer's visibility.
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Additional Layer 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct AdditionalLayer
{
public:
	std::vector<std::unique_ptr<LinkedLayer>> linkLayers{};
};

struct LinkedLayer
{
public:
	enum class LinkType
	{
		NONE,	// no initialized yet
		liFD,	// which means 'linked file data'
		liFE,	// which means 'linked file external'
		liFA,	// which means 'linked file alias'
	};

public:
	LinkType type{};

	std::unique_ptr<Descriptor> fileDescriptor{};
	std::wstring fileName{};
	std::string fileExtension{};
	std::string fileCreator{};
	uint64_t fileLength{};

	// only use when type is liFE
	std::unique_ptr<Descriptor> extFileDescriptor{};
	std::wstring extFilePath{};

	UnicodeString childDocumentID{};
	uint16_t assetLockState{};
	
	// TODO implement when you need
	// double assetModTime{};
};


struct Descriptor
{
	UnicodeString className;
	uint32_t classIDLength{};
	std::string classID{};
	uint32_t numItems{};
	
	// TODO : implement all items hidden by comment
	std::map<std::string, std::shared_ptr<Reference>> references;
	std::map<std::string, std::shared_ptr<Descriptor>> descriptors;
	//std::map<std::string, std::list<>> lists;
	std::map<std::string, double> doubles;
	//std::map<std::string, float> floats;
	std::map<std::string, UnicodeString> texts;
	//std::map<std::string, enum> enums;
	std::map<std::string, uint32_t> integers;
	std::map<std::string, uint64_t> largeIntegers;
	std::map<std::string, bool> bools;
	//std::map<std::string, std::shared_ptr<Descriptor>> globalObjects;
	//std::map<std::string, type> types;
	//std::map<std::string, GlobalClass> globalClasses;
	//std::map<std::string, Alias> aliases;
	//std::map<std::string, RawData> rawDatas;
};

struct Reference
{
	uint32_t numItems{};
	// TODO : impelemnt all items
};

PSD_NAMESPACE_END
