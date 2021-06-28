// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#include "PsdPch.h"
#include "PsdSyncFileReader.h"

#include "PsdFile.h"


PSD_NAMESPACE_BEGIN

#ifdef _DEBUG
uint8_t DEBUG_BUFFER[2048]{};
#endif
// ---------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------
SyncFileReader::SyncFileReader(File* file)
	: m_file(file)
	, m_position(0ull)
{
}


// ---------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------
void SyncFileReader::Read(void* buffer, uint32_t count)
{
	// do an asynchronous read, wait until it's finished, and update the file position
	File::ReadOperation op = m_file->Read(buffer, count, m_position);
	m_file->WaitForRead(op);

	m_position += count;
#ifdef _DEBUG
	m_file->Read(DEBUG_BUFFER, 2048, m_position);
#endif
}


// ---------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------
void SyncFileReader::Skip(uint64_t count)
{
	m_position += count;
#ifdef _DEBUG
	m_file->Read(DEBUG_BUFFER, 2048, m_position);
#endif
}


// ---------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------
void SyncFileReader::SetPosition(uint64_t position)
{
	m_position = position;
#ifdef _DEBUG
	m_file->Read(DEBUG_BUFFER, 2048, m_position);
#endif
}


// ---------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------
uint64_t SyncFileReader::GetPosition(void) const
{
	return m_position;
}

PSD_NAMESPACE_END
