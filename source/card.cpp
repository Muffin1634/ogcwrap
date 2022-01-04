/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "card/card_td.hpp"
#include "exi/exi_td.hpp"

using ogcwrap::exi::exi_channel_t;
using ogcwrap::card::card_return_value_t;
using ogcwrap::card::banner_format_t;
using ogcwrap::card::icon_format_t;
using ogcwrap::card::icon_speed_t;

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::card
{
	// subsystem management
	card_return_value_t init(const char *, const char *);

	// gethods
	card_return_value_t getStatus(exi_channel_t, s32, card_stat *);
	card_return_value_t getAttributes(exi_channel_t, s32, u8 *);
	card_return_value_t getErrorCode(exi_channel_t);
	card_return_value_t getFirstEntry(exi_channel_t, card_dir *, bool = false);
	card_return_value_t getNextEntry(card_dir *);
	card_return_value_t getDirectory(exi_channel_t, card_dir *, s32 *, bool = false);
	card_return_value_t getSectorSize(exi_channel_t, u32 *);
	card_return_value_t getBlockCount(exi_channel_t, u32 *);
	banner_format_t getBannerFormat(card_stat *);
	icon_format_t getIconFormat(card_stat *, u8);
	icon_speed_t getIconSpeed(card_stat *, u8);

	// sethods
	card_return_value_t setGameCode(const char *);
	card_return_value_t setCompanyCode(const char *);
	card_return_value_t setStatus(exi_channel_t, s32, card_stat *);
	card_return_value_t setAttributes(exi_channel_t, s32, u8);
	void setBannerFormat(card_stat *, banner_format_t);
	void setIconFormat(card_stat *, u8, icon_format_t);
	void setIconSpeed(card_stat *, u8, icon_speed_t);
	void setIconAddr(card_stat *, void *);
	void setCommentAddr(card_stat *, void *);

	card_return_value_t setStatusAsync(exi_channel_t, s32, card_stat *, cardcallback);
	card_return_value_t setAttributesAsync(exi_channel_t, s32, u8, cardcallback);

	// probing methods
	card_return_value_t probe(exi_channel_t);
	card_return_value_t probe(exi_channel_t, s32 *, s32 *);

	// mounting methods
	card_return_value_t mount(exi_channel_t, void *, cardcallback);
	card_return_value_t mountAsync(exi_channel_t, void *, cardcallback, cardcallback);
	card_return_value_t unmount(exi_channel_t);

	// formatting methods
	card_return_value_t format(exi_channel_t);
	card_return_value_t formatAsync(exi_channel_t, cardcallback);

	// sync file i/o methods
	card_return_value_t createFile(exi_channel_t, const char *, u32, card_file *);
	card_return_value_t createFile(exi_channel_t, card_dir *, card_file *);
	card_return_value_t deleteFile(exi_channel_t, const char *);
	card_return_value_t deleteFile(exi_channel_t, card_dir *);
	s32 open(exi_channel_t, const char *, card_file *);
	s32 open(exi_channel_t, card_dir *, card_file *);
	card_return_value_t close(card_file *);
	card_return_value_t read(card_file *, void *, u32, u32);
	card_return_value_t write(card_file *, void *, u32, u32);

	// async file i/o methods
	card_return_value_t createFileAsync(exi_channel_t, const char *, u32, card_file *, cardcallback);
	card_return_value_t createFileAsync(exi_channel_t, card_dir *, card_file *, cardcallback);
	card_return_value_t deleteFileAsync(exi_channel_t, const char *, cardcallback);
	card_return_value_t deleteFileAsync(exi_channel_t, card_dir *, cardcallback);
	card_return_value_t readAsync(card_file *, void *, u32, u32, cardcallback);
	card_return_value_t writeAsync(card_file *, void *, u32, u32, cardcallback);
}

/*******************************************************************************
 * functions
 */

card_return_value_t ogcwrap::card::init(const char * gameCode, const char * companyCode)
	{ return static_cast<card_return_value_t>(CARD_Init(gameCode, companyCode)); }

card_return_value_t ogcwrap::card::getStatus(exi_channel_t chan, s32 fileNo, card_stat * stat)
	{ return static_cast<card_return_value_t>(CARD_GetStatus(static_cast<s32>(chan), fileNo, stat)); }

card_return_value_t ogcwrap::card::getAttributes(exi_channel_t chan, s32 fileNo, u8 * attr)
	{ return static_cast<card_return_value_t>(CARD_GetAttributes(static_cast<s32>(chan), fileNo, attr)); }

card_return_value_t ogcwrap::card::getErrorCode(exi_channel_t chan)
	{ return static_cast<card_return_value_t>(CARD_GetErrorCode(static_cast<s32>(chan))); }

card_return_value_t ogcwrap::card::getFirstEntry(exi_channel_t chan, card_dir * dir, bool allFiles)
	{ return static_cast<card_return_value_t>(CARD_FindFirst(static_cast<s32>(chan), dir, allFiles)); }

card_return_value_t ogcwrap::card::getNextEntry(card_dir * dir)
	{ return static_cast<card_return_value_t>(CARD_FindNext(dir)); }

card_return_value_t ogcwrap::card::getDirectory(exi_channel_t chan, card_dir * dir, s32 * count, bool allFiles)
	{ return static_cast<card_return_value_t>(CARD_GetDirectory(static_cast<s32>(chan), dir, count, allFiles)); }

card_return_value_t ogcwrap::card::getSectorSize(exi_channel_t chan, u32 * sectorSize)
	{ return static_cast<card_return_value_t>(CARD_GetSectorSize(static_cast<s32>(chan), sectorSize)); }

card_return_value_t ogcwrap::card::getBlockCount(exi_channel_t chan, u32 * blockCount)
	{ return static_cast<card_return_value_t>(CARD_GetBlockCount(static_cast<s32>(chan), blockCount)); }

banner_format_t ogcwrap::card::getBannerFormat(card_stat * stat)
	{ return static_cast<banner_format_t>((stat->banner_fmt) & static_cast<u8>(banner_format_t::Mask)); }

icon_format_t ogcwrap::card::getIconFormat(card_stat * stat, u8 iconNo)
	{ return static_cast<icon_format_t>((stat->icon_fmt >> (2 * iconNo)) & static_cast<u16>(icon_format_t::Mask)); }

icon_speed_t ogcwrap::card::getIconSpeed(card_stat * stat, u8 iconNo)
	{ return static_cast<icon_speed_t>((stat->icon_speed >> (2 * iconNo)) & ~(static_cast<u16>(icon_speed_t::Mask))); }

card_return_value_t ogcwrap::card::setGameCode(const char * gameCode)
	{ return static_cast<card_return_value_t>(CARD_SetGamecode(gameCode)); }

card_return_value_t ogcwrap::card::setCompanyCode(const char * companyCode)
	{ return static_cast<card_return_value_t>(CARD_SetCompany(companyCode)); }

card_return_value_t ogcwrap::card::setStatus(exi_channel_t chan, s32 fileNo, card_stat * stat)
	{ return static_cast<card_return_value_t>(CARD_SetStatus(static_cast<s32>(chan), fileNo, stat)); }

card_return_value_t ogcwrap::card::setAttributes(exi_channel_t chan, s32 fileNo, u8 attr)
	{ return static_cast<card_return_value_t>(CARD_SetAttributes(static_cast<s32>(chan), fileNo, attr)); }

void ogcwrap::card::setBannerFormat(card_stat * stat, banner_format_t format)
	{ stat->banner_fmt = (stat->banner_fmt & ~(static_cast<u8>(banner_format_t::Mask))) | static_cast<u8>(format); }

void ogcwrap::card::setIconFormat(card_stat * stat, u8 iconNo, icon_format_t format)
	{ stat->icon_fmt = ((stat->icon_fmt & ~(static_cast<u16>(icon_format_t::Mask) << (2 * iconNo))) | (static_cast<u16>(format) << (2 * iconNo))); }

void ogcwrap::card::setIconSpeed(card_stat * stat, u8 iconNo, icon_speed_t speed)
	{ stat->icon_speed = ((stat->icon_speed & ~(static_cast<u16>(icon_speed_t::Mask) << (2 * iconNo))) | (static_cast<u16>(speed) << (2 * iconNo))); }

void ogcwrap::card::setIconAddr(card_stat * stat, void * addr)
	{ stat->icon_addr = static_cast<u32>(addr); }

void ogcwrap::card::setCommentAddr(card_stat * stat, void * addr)
	{ stat->comment_addr = static_cast<u32>(addr); }

card_return_value_t ogcwrap::card::setStatusAsync(exi_channel_t chan, s32 fileNo, card_stat * stat, cardcallback cb)
	{ return static_cast<card_return_value_t>(CARD_SetStatusAsync(static_cast<s32>(chan), fileNo, stat, cb)); }

card_return_value_t ogcwrap::card::setAttributesAsync(exi_channel_t chan, s32 fileNo, u8 attr, cardcallback cb)
	{ return static_cast<card_return_value_t>(CARD_SetAttributesAsync(static_cast<s32>(chan), fileNo, attr, cb)); }

card_return_value_t ogcwrap::card::probe(exi_channel_t chan)
	{ return static_cast<card_return_value_t>(CARD_Probe(static_cast<s32>(chan))); }

card_return_value_t ogcwrap::card::probe(exi_channel_t chan, s32 * memSize, s32 * sectSize)
	{ return static_cast<card_return_value_t>(CARD_ProbeEx(static_cast<s32>(chan), memSize, sectSize)); }

card_return_value_t ogcwrap::card::mount(exi_channel_t chan, void * workArea, cardcallback unmountCB)
	{ return static_cast<card_return_value_t>(CARD_Mount(static_cast<s32>(chan), workArea, unmountCB)); }

card_return_value_t ogcwrap::card::mountAsync(exi_channel_t chan, void * workArea, cardcallback unmountCB, cardcallback asyncCB)
	{ return static_cast<card_return_value_t>(CARD_MountAsync(static_cast<s32>(chan), workArea, unmountCB, asyncCB)); }

card_return_value_t ogcwrap::card::unmount(exi_channel_t chan)
	{ return static_cast<card_return_value_t>(CARD_Unmount(static_cast<s32>(chan))); }

card_return_value_t ogcwrap::card::format(exi_channel_t chan)
	{ return static_cast<card_return_value_t>(CARD_Format(static_cast<s32>(chan))); }

card_return_value_t ogcwrap::card::formatAsync(exi_channel_t chan, cardcallback cb)
	{ return static_cast<card_return_value_t>(CARD_FormatAsync(static_cast<s32>(chan), cb)); }

card_return_value_t ogcwrap::card::createFile(exi_channel_t chan, const char * fileName, u32 size, card_file * file)
	{ return static_cast<card_return_value_t>(CARD_Create(static_cast<s32>(chan), fileName, size, file)); }

card_return_value_t ogcwrap::card::createFile(exi_channel_t chan, card_dir * dirEntry, card_file * file)
	{ return static_cast<card_return_value_t>(CARD_CreateEntry(static_cast<s32>(chan), dirEntry, file)); }

card_return_value_t ogcwrap::card::deleteFile(exi_channel_t chan, const char * fileName)
	{ return static_cast<card_return_value_t>(CARD_Delete(static_cast<s32>(chan), fileName)); }

card_return_value_t ogcwrap::card::deleteFile(exi_channel_t chan, card_dir * dirEntry)
	{ return static_cast<card_return_value_t>(CARD_DeleteEntry(static_cast<s32>(chan), dirEntry)); }

s32 ogcwrap::card::open(exi_channel_t chan, const char * fileName, card_file * file)
	{ return CARD_Open(static_cast<s32>(chan), fileName, file); }

s32 ogcwrap::card::open(exi_channel_t chan, card_dir * dirEntry, card_file * file)
	{ return CARD_OpenEntry(static_cast<s32>(chan), dirEntry, file); }

card_return_value_t ogcwrap::card::close(card_file * file)
	{ return static_cast<card_return_value_t>(CARD_Close(file)); }

card_return_value_t ogcwrap::card::read(card_file * file, void * buf, u32 bufsize, u32 offset)
	{ return static_cast<card_return_value_t>(CARD_Read(file, buf, bufsize, offset)); }

card_return_value_t ogcwrap::card::write(card_file * file, void * buf, u32 bufsize, u32 offset)
	{ return static_cast<card_return_value_t>(CARD_Write(file, buf, bufsize, offset)); }

card_return_value_t ogcwrap::card::createFileAsync(exi_channel_t chan, const char * fileName, u32 size, card_file * file, cardcallback cb)
	{ return static_cast<card_return_value_t>(CARD_CreateAsync(static_cast<s32>(chan), fileName, size, file, cb)); }

card_return_value_t ogcwrap::card::createFileAsync(exi_channel_t chan, card_dir * dirEntry, card_file * file, cardcallback cb)
	{ return static_cast<card_return_value_t>(CARD_CreateEntryAsync(static_cast<s32>(chan), dirEntry, file, cb)); }

card_return_value_t ogcwrap::card::deleteFileAsync(exi_channel_t chan, const char * fileName, cardcallback cb)
	{ return static_cast<card_return_value_t>(CARD_DeleteAsync(static_cast<s32>(chan), fileName, cb)); }

card_return_value_t ogcwrap::card::deleteFileAsync(exi_channel_t chan, card_dir * dirEntry, cardcallback cb)
	{ return static_cast<card_return_value_t>(CARD_DeleteEntryAsync(static_cast<s32>(chan), dirEntry, cb)); }

card_return_value_t ogcwrap::card::readAsync(card_file * file, void * buf, u32 bufsize, u32 offset, cardcallback cb)
	{ return static_cast<card_return_value_t>(CARD_ReadAsync(file, buf, bufsize, offset, cb)); }

card_return_value_t ogcwrap::card::writeAsync(card_file * file, void * buf, u32 bufsize, u32 offset, cardcallback cb)
	{ return static_cast<card_return_value_t>(CARD_WriteAsync(file, buf, bufsize, offset, cb)); }