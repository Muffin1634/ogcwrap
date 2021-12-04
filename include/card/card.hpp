#pragma once
#ifndef wrap_card_h
#define wrap_card_h

#include <gctypes.h>
#include <ogc/card.h>

#include "card/card_td.hpp"
#include "exi/exi_td.hpp"

namespace ogcwrap::card
{
	// subsystem management
	CardReturnValue init(const char * gameCode, const char * companyCode);

	// gethods
	CardReturnValue getStatus(EXIChannel chan, s32 fileNo, card_stat * stat);
	CardReturnValue getAttributes(EXIChannel chan, s32 fileNo, u8 * attr);
	CardReturnValue getErrorCode(EXIChannel chan);
	CardReturnValue getFirstEntry(EXIChannel chan, card_dir * dir, bool allFiles = false);
	CardReturnValue getNextEntry(card_dir * dir);
	CardReturnValue getDirectory(EXIChannel chan, card_dir * dir, s32 * count, bool allFiles = false);
	CardReturnValue getSectorSize(EXIChannel chan, u32 * sectorSize);
	CardReturnValue getBlockCount(EXIChannel chan, u32 * blockCount);
	BannerFormat getBannerFormat(card_stat * stat);
	IconFormat getIconFormat(card_stat * stat, u8 iconNo);
	IconSpeed getIconSpeed(card_stat * stat, u8 iconNo);

	// sethods
	CardReturnValue setGameCode(const char * gameCode);
	CardReturnValue setCompanyCode(const char * conpanyCode);
	CardReturnValue setStatus(EXIChannel chan, s32 fileNo, card_stat * stat);
	CardReturnValue setAttributes(EXIChannel chan, s32 fileNo, u8 attr);
	void setBannerFormat(card_stat * stat, BannerFormat format);
	void setIconFormat(card_stat * stat, u8 iconNo, IconFormat format);
	void setIconSpeed(card_stat * stat, u8 iconNo, IconSpeed speed);
	void setIconAddr(card_stat * stat, void * addr);
	void setCommentAddr(card_stat * stat, void * addr);

	CardReturnValue setStatusAsync(EXIChannel chan, s32 fileNo, card_stat * stat, cardcallback cb);
	CardReturnValue setAttributesAsync(EXIChannel chan, s32 fileNo, u8 attr, cardcallback cb);

	// probing methods
	CardReturnValue probe(EXIChannel chan);
	CardReturnValue probeExtended(EXIChannel chan, s32 * memSize = NULL, s32 * sectSize = NULL);

	// mounting methods
	CardReturnValue mount(EXIChannel chan, void * workArea, cardcallback unmountCB);
	CardReturnValue mountAsync(EXIChannel chan, void * workArea, cardcallback unmountCB, cardcallback asyncCB);
	CardReturnValue unmount(EXIChannel chan);

	// formatting methods
	CardReturnValue format(EXIChannel chan);
	CardReturnValue formatAsync(EXIChannel chan, cardcallback cb);

	// sync file i/o methods
	CardReturnValue createFile(EXIChannel chan, const char * fileName, u32 size, card_file * file);
	CardReturnValue createFile(EXIChannel chan, card_dir * dirEntry, card_file * file);
	CardReturnValue deleteFile(EXIChannel chan, const char * fileName);
	CardReturnValue deleteFile(EXIChannel chan, card_dir * dirEntry);
	s32 open(EXIChannel chan, const char * fileName, card_file * file);
	s32 open(EXIChannel chan, card_dir * dirEntry, card_file * file);
	CardReturnValue close(card_file * file);
	CardReturnValue read(card_file * file, void * buf, u32 bufsize, u32 offset);
	CardReturnValue write(card_file * file, void * buf, u32 bufsize, u32 offset);

	// async file i/o methods
	CardReturnValue createFileAsync(EXIChannel chan, const char * fileName, u32 size, card_file * file, cardcallback cb);
	CardReturnValue createFileAsync(EXIChannel chan, card_dir * dirEntry, card_file * file, cardcallback cb);
	CardReturnValue deleteFileAsync(EXIChannel chan, const char * fileName, cardcallback cb);
	CardReturnValue deleteFileAsync(EXIChannel chan, card_dir * dirEntry, cardcallback cb);
	CardReturnValue readAsync(card_file * file, void * buf, u32 bufsize, u32 offset, cardcallback cb);
	CardReturnValue writeAsync(card_file * file, void * buf, u32 bufsize, u32 offset, cardcallback cb);
}

#endif // wrap_card_h