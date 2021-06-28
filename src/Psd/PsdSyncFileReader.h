// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#pragma once

#include <cstring>

PSD_NAMESPACE_BEGIN

class File;


/// \ingroup Files
/// \brief Synchronous file wrapper using an arbitrary \ref File implementation for sequential reads.
/// \details In certain situations, working with synchronous read operations is much easier than having to deal with a number
/// of asynchronous reads, keeping track of individual read operations. This is especially true when parsing a file sequentially,
/// where different read operations depend on previous ones.
/// \sa File
class SyncFileReader
{
public:

	/// Constructor initializing the internal read position to zero.
	/// \remark The given \a file must already be open.
	explicit SyncFileReader(File* file);

	/// Reads \a count bytes into \a buffer synchronously, incrementing the internal read position.
	void Read(void* buffer, uint32_t count);

	/// Read \a count bytes into \a buffer synchronously, storing with little endian each T bytes and incrementing the internal read position.
	template <size_t T>
	void ReadLE(void* buffer, uint32_t count)
	{
		if (count % T != 0)
		{
			return;
		}

		{
			auto number = T;
			while (number % 2 == 0)
			{
				number /= 2;
			}

			if (number != 1)
			{
				return;
			}
		}

		Read(buffer, count);

		if (T == 1u)
		{
			return;
		}

		for (size_t offset = 0; offset <= count; offset += T)
		{
			uint8_t unit[T]{};
			uint8_t convert[T]{};

			std::memcpy(unit, static_cast<uint8_t*>(buffer) + offset, T);
			for (size_t index = 0; index < T; ++index)
			{
				convert[index] = unit[T - index - 1];
			}
			std::memcpy(static_cast<uint8_t*>(buffer) + offset, convert, T);
		}
	}

	/// Skips \a count bytes.
	void Skip(uint64_t count);

	/// Sets the internal read position for the next call to Read().
	void SetPosition(uint64_t position);

	/// Returns the internal read position.
	uint64_t GetPosition(void) const;

private:
	File* m_file;
	uint64_t m_position;
};

#ifdef _DEBUG
extern uint8_t DEBUG_BUFFER[2048];
#endif
PSD_NAMESPACE_END