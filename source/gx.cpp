/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "gx/gx_td.hpp"

// doesn't work
// #define GX_DETAIL_IMPLEMENT

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::gx
{
	// subsystem management
	GXFifoObj * init(void *, u32);

	// callbacks
	GXDrawSyncCallback setDrawSyncCallback(GXDrawSyncCallback);
	GXDrawDoneCallback setDrawDoneCallback(GXDrawDoneCallback);
	GXBreakPtCallback setBreakPtCallback(GXBreakPtCallback);
	GXTexRegionCallback setTexRegionCallback(GXTexRegionCallback);
	GXTlutRegionCallback setTLUTRegionCallback(GXTlutRegionCallback);

	// fifo
	void setFifoBase(GXFifoObj *, void *, u32);
	void setFifoLimits(GXFifoObj *, u32, u32);
	void setFifoPtrs(GXFifoObj *, void *, void *);
	void setCPUFifo(GXFifoObj *);
	void setGPUFifo(GXFifoObj *);

	void * getFifoBase(GXFifoObj *);
	u32 getFifoCacheLineCount(GXFifoObj *);
	u32 getFifoSize(GXFifoObj *);
	u8 getFifoWrap(GXFifoObj *);
	void getFifoPtrs(GXFifoObj *, void * *, void * *);
	void getCPUFifo(GXFifoObj *);
	void getGPUFifo(GXFifoObj *);

	void flushCPUFifo(void);

	// framebuffer management
	f32 getYScaleFactor(u16, u16);
	u32 setDisplayCopyYScale(f32);
	u32 setDisplayCopyYScale(u16, u16);
	void setDisplayCopySource(u16, u16, u16, u16);
	void setDisplayCopyDest(u16, u16);
	void setDisplayCopyGamma(gx_gamma_t);
	void setDisplayCopyFrame2Field(gx_copy_mode_t);
	void setCopyClamp(gx_clamp_mode_t);
	void setCopyFilter(bool, u8[12][2], bool, u8[7]);
	void setCopyClear(GXColor, u32);
	void copyDisplay(void *, bool);

	void setViewport(f32, f32, f32, f32, f32, f32);
	void setViewportJitter(f32, f32, f32, f32, f32, f32, gx_next_field_t);
	void adjustForOverscan(GXRModeObj *, GXRModeObj *, u16, u16);
	void setScissor(u16, u16, u16, u16);
	void setScissorBoxOffset(s16, s16);
	void setColorUpdate(bool);
	void setColorUpdate(bool, bool);
	void setAlphaUpdate(bool);
	void setPixelFormat(gx_pixel_format_t, gx_z_format_t);
	void setDestAlpha(bool, u8);
	void setFieldMask(bool, bool);
	void setFieldMode(bool, bool);

	void setTextureCopySource(u16, u16, u16, u16);
	void setTextureCopyDest(u16, u16, gx_texture_format_t, bool); //m1
	void copyTexture(void *, bool);

	// frame management
	void abortFrame(void);
	void setDrawDone(void);
	void waitDrawDone(void);

	void syncPixelMode(void);
	void readBoundingBox(u16 *, u16 *, u16 *, u16 *);
	void clearBoundingBox(void);

	// fog
	void setFog(gx_fog_equation_t, f32, f32, f32, f32, GXColor);
	void setFogColor(GXColor);
	void setFogRangeAdjustment(bool, u16, GXFogAdjTbl *); //m2??

	// vertex management
	void invalidateVertexCache(void);
	void clearVertexDescriptors(void);

//	void getVertexAttributeFormat(GXVtxAttrFmt *);
//	void getVertexAttributeFormatList(GXVtxAttrFmt *);
	void getVertexDescriptor(GXVtxDesc *);
	void getVertexDescriptorList(GXVtxDesc *);

	void setVertexAttributeFormat(gx_vertex_format_t, gx_vertex_attribute_t, gx_vertex_component_type_t, gx_vertex_component_format_t, u8);
	void setVertexAttributeFormatList(gx_vertex_format_t, GXVtxAttrFmt *);
	void setVertexDescriptor(gx_vertex_attribute_t, gx_vertex_descriptor_t);
	void setVertexDescriptorList(GXVtxDesc *);

	void setArray(gx_vertex_attribute_t, void *, u8);

	// color management
	void setChannelCount(u8);
	void setColorChannelControl(gx_color_channel_t, bool, u8, u8, u8, gx_diffuse_function_t, gx_attenuation_function_t);
	void setColorChannelAmbient(gx_color_channel_t, GXColor);
	void setColorChannelMaterial(gx_color_channel_t, GXColor);

	// texture management
	void setTexGenCount(u8);
	void setTexCoordGen(gx_texture_coordinate_index_t, gx_texture_coordinate_generation_type_t, gx_texture_coordinate_source_t, gx_texture_matrix_index_t, bool = false, gx_post_transform_matrix_index_t = (gx_post_transform_matrix_index_t)0);
	void setTexCoordScale(gx_texture_coordinate_index_t, bool, u16 = 1, u16 = 1);
	void setTexCoordBias(gx_texture_coordinate_index_t, bool, bool);
	void setTexCoordCylWrap(u8, bool, bool);
	void setTextureOffsetStatus(gx_texture_coordinate_index_t, bool, bool);

	u32 getTextureBufferSize(u16, u16, gx_texture_format_t, bool, u8);

	void setZMode(bool, gx_comparison_t, bool);
	void setZTexture(gx_z_texture_operator_t, gx_z_texture_format_t, u32);
	void setZCompLoc(gx_z_buffer_time_t);

	void initTextureCacheRegion(GXTexRegion *, bool, void *, gx_texture_cache_size_t, void *, gx_texture_cache_size_t);
	void initTexturePreloadRegion(GXTexRegion *, void *, u32, void *, u32);

	void initTextureObject(GXTexObj *, void *, u16, u16, gx_texture_format_t, gx_wrap_mode_t, gx_wrap_mode_t, bool);
	void initTextureObjectColorIndex(GXTexObj *, void *, u16, u16, gx_texture_format_t, gx_wrap_mode_t, gx_wrap_mode_t, bool, gx_tlut_index_t);
	void initTLUTObj(GXTlutObj *, void *, gx_tlut_entry_format_t, u16);
	void initTLUTRegion(GXTlutRegion *, void *, u8);

	void preloadTexture(GXTexObj *, GXTexRegion *);
	void loadTextureObject(GXTexObj *, gx_texture_map_index_t);
	void loadTLUT(GXTlutObj *, gx_tlut_index_t);
	void loadPreloadedTextureObject(GXTexObj *, GXTexRegion *, gx_texture_map_index_t);

	void setTextureObjectData(GXTexObj *, void *);
	void setTextureObjectUserData(GXTexObj *, void *);
	void setTextureObjectTLUT(GXTexObj *, gx_tlut_index_t);
	void setTextureObjectWrap(GXTexObj *, gx_wrap_mode_t, gx_wrap_mode_t);
	void setTextureObjectLOD(GXTexObj *, gx_texture_filter_t, gx_texture_filter_t, f32, f32, f32, bool, bool, gx_max_anisotropic_filter_t);
	void setTextureObjectLODFilter(GXTexObj *, gx_texture_filter_t, gx_texture_filter_t);
	void setTextureObjectLODMin(GXTexObj *, f32);
	void setTextureObjectLODMax(GXTexObj *, f32);
	void setTextureObjectLODBias(GXTexObj *, f32);
	void setTextureObjectLODBiasClamp(GXTexObj *, bool);
	void setTextureObjectLODEdge(GXTexObj *, bool);
	void setTextureObjectLODMaxAniso(GXTexObj *, gx_max_anisotropic_filter_t);

	void getTextureObjectAll(GXTexObj *, void * *, u16 *, u16 *,u8 *, u8 *, u8 *, u8 *);
	void * getTextureObjectUserData(GXTexObj *);
	void * getTextureObjectData(GXTexObj *);
	u32 getTextureObjectFormat(GXTexObj *);
	u32 getTextureObjectMipmap(GXTexObj *);
	u8 getTextureObjectWrapS(GXTexObj *);
	u8 getTextureObjectWrapT(GXTexObj *);
	u16 getTextureObjectHeight(GXTexObj *);
	u16 getTextureObjectWidth(GXTexObj *);

	void invalidateTextureRegion(GXTexRegion *);
	void invalidateAllTextures(void);
	void texModeSync(void);

	// texture environment management
	void setTEVStageCount(u8);
	void setTEVOrder(gx_tev_stage_t, gx_texture_coordinate_index_t, gx_texture_map_index_t, gx_color_channel_t); //m5
	void setTEVOp(gx_tev_stage_t, gx_tev_combiner_equation_t);
	void setTEVColor(gx_tev_register_t, GXColor);		// cast to GXColor    to avoid ambiguity
	void setTEVColor(gx_tev_register_t, GXColorS10);	// cast to GXColorS10 to avoid ambiguity
	void setTEVColorIn(gx_tev_stage_t, gx_tev_register_input_t, gx_tev_register_input_t, gx_tev_register_input_t, gx_tev_register_input_t);
	void setTEVAlphaIn(gx_tev_stage_t, gx_tev_register_input_t, gx_tev_register_input_t, gx_tev_register_input_t, gx_tev_register_input_t);
	void setTEVColorOp(gx_tev_stage_t, gx_tev_combiner_operator_t, gx_tev_bias_t, gx_tev_scale_t, bool, gx_tev_register_t);
	void setTEVAlphaOp(gx_tev_stage_t, gx_tev_combiner_operator_t, gx_tev_bias_t, gx_tev_scale_t, bool, gx_tev_register_t);
	void setTEVAlphaCompare(gx_comparison_t, u8, gx_alpha_operation_t, gx_comparison_t, u8);
	void setTEVKColor(gx_tev_register_t, GXColor);		// cast to GXColor    to avoid ambiguity
	void setTEVKColor(gx_tev_register_t, GXColorS10);	// cast to GXColorS10 to avoid ambiguity
	void selectTEVKColor(gx_tev_stage_t, gx_tev_constant_color_selection_t);
	void selectTEVKAlpha(gx_tev_stage_t, gx_tev_constant_alpha_selection_t);
	void setTEVSwapMode(gx_tev_stage_t, gx_tev_swap_table_index_t, gx_tev_swap_table_index_t); //m3
	void setTEVSwapModeTable(gx_tev_swap_table_index_t, gx_tev_color_channel_t, gx_tev_color_channel_t, gx_tev_color_channel_t, gx_tev_color_channel_t); //m4

	void setTEVDirect(gx_tev_stage_t);
	void setTEVIndirect(gx_tev_stage_t, gx_indirect_texture_stage_t, gx_indirect_texture_format_t, gx_indirect_texture_bias_t, gx_indirect_texture_matrix_t, gx_indirect_texture_wrap_t, gx_indirect_texture_wrap_t, bool, bool, gx_indirect_texture_alpha_bump_t);
	void setTEVIndirectTile(gx_tev_stage_t, gx_indirect_texture_stage_t, u16, u16, u16, u16, gx_indirect_texture_format_t, gx_indirect_texture_matrix_t, gx_indirect_texture_bias_t, gx_indirect_texture_alpha_bump_t);
	void setTEVIndirectRepeat(gx_tev_stage_t);

	void setIndirectStageCount(u8);
	void setIndirectTextureOrder(gx_indirect_texture_stage_t, gx_texture_coordinate_index_t, gx_texture_map_index_t);
	void setIndirectTextureCoordScale(gx_indirect_texture_stage_t, gx_indirect_texture_scale_t, gx_indirect_texture_scale_t);
	void setIndirectTextureMatrix(gx_indirect_texture_matrix_t, f32[2][3], s8);
	void setIndirectTextureBumpST(gx_tev_stage_t, gx_indirect_texture_stage_t, gx_indirect_texture_matrix_t);
	void setIndirectTextureBumpXYZ(gx_tev_stage_t, gx_indirect_texture_stage_t, gx_indirect_texture_matrix_t);

	// light management
	void loadLightObject(GXLightObj *, gx_light_index_t);
	void loadLightObjectIndex(u32, gx_light_index_t);

	void setLightPosition(GXLightObj *, f32, f32, f32);
	void setLightPosition(GXLightObj *, guVector);
	void setLightDirection(GXLightObj *, f32, f32, f32);
	void setLightDirection(GXLightObj *, guVector);
	void setLightColor(GXLightObj *, GXColor);
	void setLightDistanceAttenuation(GXLightObj *, f32, f32, gx_attenuation_function_t);
	void setLightAttenuation(GXLightObj *, f32, f32, f32, f32, f32, f32);
	void setLightAttenuationAngle(GXLightObj *, f32, f32, f32);
	void setLightAttenuationDistance(GXLightObj *, f32, f32, f32);
	void setLightShininess(GXLightObj *, f32);

	void setSpecularDirectionHalfAngle(GXLightObj *, f32, f32, f32, f32, f32, f32);
	void setSpecularDirectionHalfAngle(GXLightObj *, guVector, guVector);
	void setSpecularDirection(GXLightObj *, f32, f32, f32);
	void setSpecularDirection(GXLightObj *, guVector);

	void setLightSpot(GXLightObj *, f32, gx_spot_illumination_function_t);

	// matrices
	void matrixIndex(u8);
	void setCurrentMatrix(gx_position_normal_matrix_index_t);

	void loadProjectionMatrix(Mtx44, gx_projection_type_t);
	void loadPosMtxImm(Mtx, gx_position_normal_matrix_index_t);
	void loadPosMtxIdx(u16, gx_position_normal_matrix_index_t);
	void loadNrmMtxImm(Mtx, gx_position_normal_matrix_index_t);
	void loadNrmMtxIdx(u16, gx_position_normal_matrix_index_t);
	void loadNrmMtxImm3x3(Mtx33, gx_position_normal_matrix_index_t);
	void loadNrmMtxIdx3x3(u16, gx_position_normal_matrix_index_t);
	void loadTexMtxImm(Mtx, gx_texture_matrix_index_t, gx_texture_matrix_type_t);
	void loadTexMtxIdx(u16, gx_texture_matrix_index_t, gx_texture_matrix_type_t);

	// breakpoint
	void enableBreakPoint(void *);
	void disableBreakPoint(void);

	// drawing settings
	void setLineWidth(u8, gx_texture_offset_value_t);
	void setPointSize(u8, gx_texture_offset_value_t);
	void setBlendMode(gx_blend_mode_t, gx_blend_control_t, gx_blend_control_t, gx_logic_operation_t);
	void setCullingMode(gx_culling_mode_t);
	void setCoplanarMode(bool);
	void setClipMode(bool);
	void setDitherMode(bool);

	// poke/peek
	void setPokeColor(bool);
	void setPokeAlpha(bool);
	void setPokeDither(bool);

	void pokeAlphaMode(gx_comparison_t, u8);
	void pokeBlendMode(gx_blend_mode_t, gx_blend_control_t, gx_blend_control_t, gx_logic_operation_t);
	void pokeZMode(bool, gx_comparison_t, bool);

	void pokeAlphaRead(gx_alpha_read_mode_t);
	void pokeDestAlpha(bool, u8);

	void pokeRGBA(u16, u16, GXColor);
	void pokeZ(u16, u16, u32);

	void peekRGBA(u16, u16, GXColor *);
	void peekZ(u16, u16, u32 *);

	// miscellaneous
	void setMisc(gx_misc_token_t, u32);

	void getGPStatus(u8 *, u8 *, u8 *, u8 *, u8 *);
	u32 readClksPerVtx(void);

	u32 getOverflowCount(void);
	u32 resetOverflowCount(void);

	lwp_t getCurrentThread(void);
	lwp_t setCurrentThread(void);

	volatile void * redirectWriteGatherPipe(void *);
	void restoreWriteGatherPipe(void);

	// metrics
	void setGPMetric(gx_performance_counter_0_metric_t, gx_performance_counter_1_metric_t);
	void readGPMetric(u32 *, u32 *);
	void clearGPMetric(void);
	void initXfRasMetric(void);
	void readXfRasMetric(u32 *, u32 *, u32 *, u32 *);
	void setVCacheMetric(gx_vertex_cache_metric_t);
	void readVCacheMetric(u32 *, u32 *, u32 *);
	void clearVCacheMetric(void);

	namespace draw
	{
		// management
		void begin(gx_primitive_t, gx_vertex_format_t, u16);
		void end(void);

		u16 getDrawSync(void);
		void setDrawSync(u16);

		// display lists
		void beginDisplayList(void *, u32);
		u32 endDisplayList(void);
		void callDisplayList(void *, u32);

		// positions

		// index (cast to u8 or u16 specifically for these overloads)
		void indexedPosition(u8);
		void indexedPosition(u16);

		// 2 dimensions (implied z coordinate of 0)
		void position(u8, u8);
		void position(s8, s8);
		void position(u16, u16);
		void position(s16, s16);
		void position(f32, f32);

		// 3 dimensions
		void position(u8, u8, u8);
		void position(s8, s8, s8);
		void position(u16, u16, u16);
		void position(s16, s16, s16);
		void position(f32, f32, f32);

		// normals

		// index (cast to u8 or u16 specifically for these overloads)
		void indexedNormal(u8);
		void indexedNormal(u16);

		// 3 dimensions
		void normal(s8, s8, s8);
		void normal(s16, s16, s16);
		void normal(f32, f32, f32);

		// colors

		// index (cast to u8 or u16 specifically for these overloads)
		void indexedColor(u8);
		void indexedColor(u16);

		// 1 value (RGB)
		void color(u16); // RGB565
		void color(u32); // RGBX8

		// 3 values (R, G, B)
		void color(u8, u8, u8);
		void color(f32, f32, f32);

		// 4 values (R, G, B, A)
		void color(u8, u8, u8, u8);

		// textures

		// index (cast to u8 or u16 specifically for these overloads)
		void indexedTexcoord(u8);
		void indexedTexcoord(u16);

		// 1 dimension
		void texcoord(u8); // cast to u8 specifically for this overload
		void texcoord(s8); // cast to s8 specifically for this overload
		void texcoord(u16); // cast to u16 specifically for this overload
		void texcoord(s16); // cast to s16 specifically for this overload
		void texcoord(f32);

		// 2 dimensions
		void texcoord(u8, u8);
		void texcoord(s8, s8);
		void texcoord(u16, u16);
		void texcoord(s16, s16);
		void texcoord(f32, f32);
	}

	namespace detail
	{
		void GetVtxAttrFmt(GXVtxAttrFmt *);
//		void GetVtxAttrFmtv(GXVtxAttrFmt *);

		void GetVtxDesc(GXVtxDesc *);

		void LoadNrmMtxIdx(u16, u32);
	}
}

/*******************************************************************************
 * functions
 */

GXFifoObj * ogcwrap::gx::init(void * base_addr, u32 size)
	{ return GX_Init(base_addr, size); }

GXDrawSyncCallback ogcwrap::gx::setDrawSyncCallback(GXDrawSyncCallback cb)
	{ return GX_SetDrawSyncCallback(cb); }

GXDrawDoneCallback ogcwrap::gx::setDrawDoneCallback(GXDrawDoneCallback cb)
	{ return GX_SetDrawDoneCallback(cb); }

GXBreakPtCallback ogcwrap::gx::setBreakPtCallback(GXBreakPtCallback cb)
	{ return GX_SetBreakPtCallback(cb); }

GXTexRegionCallback ogcwrap::gx::setTexRegionCallback(GXTexRegionCallback cb)
	{ return GX_SetTexRegionCallback(cb); }

GXTlutRegionCallback ogcwrap::gx::setTLUTRegionCallback(GXTlutRegionCallback cb)
	{ return GX_SetTlutRegionCallback(cb); }

void ogcwrap::gx::setFifoBase(GXFifoObj * fifo, void * base_addr, u32 size)
	{ GX_InitFifoBase(fifo, base_addr, size); }

void ogcwrap::gx::setFifoLimits(GXFifoObj * fifo, u32 high, u32 low)
	{ GX_InitFifoLimits(fifo, high, low); }

void ogcwrap::gx::setFifoPtrs(GXFifoObj * fifo, void * readptr, void * writeptr)
	{ GX_InitFifoPtrs(fifo, readptr, writeptr); }

void ogcwrap::gx::setCPUFifo(GXFifoObj * fifo)
	{ GX_SetCPUFifo(fifo); }

void ogcwrap::gx::setGPUFifo(GXFifoObj * fifo)
	{ GX_SetGPFifo(fifo); }

void * ogcwrap::gx::getFifoBase(GXFifoObj * fifo)
	{ return GX_GetFifoBase(fifo); }

u32 ogcwrap::gx::getFifoCacheLineCount(GXFifoObj * fifo)
	{ return GX_GetFifoCount(fifo); }

u32 ogcwrap::gx::getFifoSize(GXFifoObj * fifo)
	{ return GX_GetFifoSize(fifo); }

u8 ogcwrap::gx::getFifoWrap(GXFifoObj * fifo)
	{ return GX_GetFifoWrap(fifo); }

void ogcwrap::gx::getFifoPtrs(GXFifoObj * fifo, void * * readptr, void * * writeptr)
	{ GX_GetFifoPtrs(fifo, readptr, writeptr); }

void ogcwrap::gx::getCPUFifo(GXFifoObj * fifo)
	{ GX_GetCPUFifo(fifo); }

void ogcwrap::gx::getGPUFifo(GXFifoObj * fifo)
	{ GX_GetGPFifo(fifo); }

void ogcwrap::gx::flushCPUFifo(void)
	{ GX_Flush(); }

f32 ogcwrap::gx::getYScaleFactor(u16 efbHeight, u16 xfbHeight)
	{ return GX_GetYScaleFactor(efbHeight, xfbHeight); }

u32 ogcwrap::gx::setDisplayCopyYScale(f32 scale)
	{ return GX_SetDispCopyYScale(scale); }

u32 ogcwrap::gx::setDisplayCopyYScale(u16 efbHeight, u16 xfbHeight)
	{ return GX_SetDispCopyYScale(GX_GetYScaleFactor(efbHeight, xfbHeight)); }

void ogcwrap::gx::setDisplayCopySource(u16 left, u16 top, u16 width, u16 height)
	{ GX_SetDispCopySrc(left, top, width, height); }

void ogcwrap::gx::setDisplayCopyDest(u16 width, u16 height)
	{ GX_SetDispCopyDst(width, height); }

void ogcwrap::gx::setDisplayCopyGamma(gx_gamma_t gamma)
	{ GX_SetDispCopyGamma(mcast(u8, gamma)); }

void ogcwrap::gx::setDisplayCopyFrame2Field(gx_copy_mode_t mode)
	{ GX_SetDispCopyFrame2Field(mcast(u8, mode)); }

void ogcwrap::gx::setCopyClamp(gx_clamp_mode_t mode)
	{ GX_SetCopyClamp(mcast(u8, mode)); }

void ogcwrap::gx::setCopyFilter(bool aaStatus, u8 samplePattern[12][2], bool vfStatus, u8 vfilter[7])
	{ GX_SetCopyFilter(aaStatus, samplePattern, vfStatus, vfilter); }

void ogcwrap::gx::setCopyClear(GXColor color, u32 z)
	{ GX_SetCopyClear(color, z); }

void ogcwrap::gx::copyDisplay(void * dest, bool clear)
	{ GX_CopyDisp(dest, clear); }

void ogcwrap::gx::setViewport(f32 left, f32 top, f32 width, f32 height, f32 near, f32 far)
	{ GX_SetViewport(left, top, width, height, near, far); }

void ogcwrap::gx::setViewportJitter(f32 left, f32 top, f32 width, f32 height, f32 near, f32 far, gx_next_field_t next)
	{ GX_SetViewportJitter(left, top, width, height, near, far, mcast(u32, next)); }

void ogcwrap::gx::adjustForOverscan(GXRModeObj * rmIn, GXRModeObj * rmOut, u16 hTrim, u16 vTrim)
	{ GX_AdjustForOverscan(rmIn, rmOut, hTrim, vTrim); }

void ogcwrap::gx::setScissor(u16 top, u16 left, u16 width, u16 height)
	{ GX_SetScissor(top, left, width, height); }

void ogcwrap::gx::setScissorBoxOffset(s16 xOffset, s16 yOffset)
	{ GX_SetScissorBoxOffset(xOffset, yOffset); }

void ogcwrap::gx::setColorUpdate(bool enable)
	{ GX_SetColorUpdate(enable); }

void ogcwrap::gx::setColorUpdate(bool colorEnable, bool alphaEnable)
{
	GX_SetColorUpdate(colorEnable);
	GX_SetAlphaUpdate(alphaEnable);
}

void ogcwrap::gx::setAlphaUpdate(bool enable)
	{ GX_SetAlphaUpdate(enable); }

void ogcwrap::gx::setPixelFormat(gx_pixel_format_t pixelFmt, gx_z_format_t zFmt)
	{ GX_SetPixelFmt(mcast(u8, pixelFmt), mcast(u8, zFmt)); }

void ogcwrap::gx::setDestAlpha(bool enable, u8 alpha)
	{ GX_SetDstAlpha(enable, alpha); }

void ogcwrap::gx::setFieldMask(bool even, bool odd)
	{ GX_SetFieldMask(even, odd); }

void ogcwrap::gx::setFieldMode(bool field, bool halfAspect)
	{ GX_SetFieldMode(field, halfAspect); }

void ogcwrap::gx::setTextureCopySource(u16 left, u16 top, u16 width, u16 height)
	{ GX_SetTexCopySrc(left, top, width, height); }

void ogcwrap::gx::setTextureCopyDest(u16 width, u16 height, gx_texture_format_t format, bool mipmap)
	{ GX_SetTexCopyDst(width, height, mcast(u32, format), mipmap); }

void ogcwrap::gx::copyTexture(void * dest, bool clear)
	{ GX_CopyTex(dest, clear); }

void ogcwrap::gx::abortFrame(void)
	{ GX_AbortFrame(); }

void ogcwrap::gx::setDrawDone(void)
	{ GX_SetDrawDone(); }

void ogcwrap::gx::waitDrawDone(void)
	{ GX_WaitDrawDone(); }

void ogcwrap::gx::syncPixelMode(void)
	{ GX_PixModeSync(); }

void ogcwrap::gx::readBoundingBox(u16 * top, u16 * bottom, u16 * left, u16 * right)
	{ GX_ReadBoundingBox(top, bottom, left, right); }

void ogcwrap::gx::clearBoundingBox(void)
	{ GX_ClearBoundingBox(); }

void ogcwrap::gx::setFog(gx_fog_equation_t equation, f32 startZ, f32 endZ, f32 nearZ, f32 farZ, GXColor color)
	{ GX_SetFog(mcast(u8, equation), startZ, endZ, nearZ, farZ, color); }

void ogcwrap::gx::setFogColor(GXColor color)
	{ GX_SetFogColor(color); }

void ogcwrap::gx::setFogRangeAdjustment(bool enable, u16 center, GXFogAdjTbl * table)
	{ GX_SetFogRangeAdj(enable, center, table); }

void ogcwrap::gx::invalidateVertexCache(void)
	{ GX_InvVtxCache(); }

void ogcwrap::gx::clearVertexDescriptors(void)
	{ GX_ClearVtxDesc(); }

/*
void ogcwrap::gx::getVertexAttributeFormat(GXVtxAttrFmt * fmt)
	{ ogcwrap::gx::detail::GetVtxAttrFmt(fmt); }
*/

/*
void ogcwrap::gx::getVertexAttributeFormatList(GXVtxAttrFmt * fmtlist)
	{ ogcwrap::gx::detail::GetVtxAttrFmtv(fmtlist); }
*/

void ogcwrap::gx::getVertexDescriptor(GXVtxDesc * desc)
	{ ogcwrap::gx::detail::GetVtxDesc(desc); }

void ogcwrap::gx::getVertexDescriptorList(GXVtxDesc * desclist)
	{ GX_GetVtxDescv(desclist); }

void ogcwrap::gx::setVertexAttributeFormat(gx_vertex_format_t format, gx_vertex_attribute_t attr, gx_vertex_component_type_t comptype, gx_vertex_component_format_t compfmt, u8 fraction_bits)
	{ GX_SetVtxAttrFmt(mcast(u8, format), mcast(u32, attr), mcast(u32, comptype), mcast(u32, compfmt), fraction_bits); }

void ogcwrap::gx::setVertexAttributeFormatList(gx_vertex_format_t format, GXVtxAttrFmt * attrlist)
	{ GX_SetVtxAttrFmtv(mcast(u8, format), attrlist); }

void ogcwrap::gx::setVertexDescriptor(gx_vertex_attribute_t attr, gx_vertex_descriptor_t type)
	{ GX_SetVtxDesc(mcast(u8, attr), mcast(u8,type)); }

void ogcwrap::gx::setVertexDescriptorList(GXVtxDesc * desclist)
	{ GX_SetVtxDescv(desclist); }

void ogcwrap::gx::setArray(gx_vertex_attribute_t attr, void * array, u8 stride)
	{ GX_SetArray(mcast(u8, attr), array, stride); }

void ogcwrap::gx::setChannelCount(u8 count)
	{ GX_SetNumChans(count); }

void ogcwrap::gx::setColorChannelControl(gx_color_channel_t channel, bool lightEnable, u8 ambient, u8 material, u8 lights, gx_diffuse_function_t diff, gx_attenuation_function_t attn)
	{ GX_SetChanCtrl(mcast(s32, channel), lightEnable, ambient, material, lights, mcast(u8, diff), mcast(u8, attn)); }

void ogcwrap::gx::setColorChannelAmbient(gx_color_channel_t channel, GXColor color)
	{ GX_SetChanAmbColor(mcast(s32, channel), color); }

void ogcwrap::gx::setColorChannelMaterial(gx_color_channel_t channel, GXColor color)
	{ GX_SetChanMatColor(mcast(s32, channel), color); }

void ogcwrap::gx::setTexGenCount(u8 count)
	{ GX_SetNumTexGens(count); }

void ogcwrap::gx::setTexCoordGen(gx_texture_coordinate_index_t coordindex, gx_texture_coordinate_generation_type_t type, gx_texture_coordinate_source_t source, gx_texture_matrix_index_t index, bool normalize, gx_post_transform_matrix_index_t ptfindex)
{
	if (ptfindex == gx_post_transform_matrix_index_t::STCG1)
		GX_SetTexCoordGen(mcast(u16, coordindex), mcast(u32, type), mcast(u32, source), mcast(u32, index));
	else
		GX_SetTexCoordGen2(mcast(u16, coordindex), mcast(u32, type), mcast(u32, source), mcast(u32, index), normalize, mcast(u32, ptfindex));
}
void ogcwrap::gx::setTexCoordScale(gx_texture_coordinate_index_t coordindex, bool autoscale, u16 scaleS, u16 scaleT)
	{ GX_SetTexCoordScaleManually(mcast(u8, coordindex), autoscale, scaleS, scaleT); }

void ogcwrap::gx::setTexCoordBias(gx_texture_coordinate_index_t coordindex, bool biasS, bool biasT)
	{ GX_SetTexCoordBias(mcast(u8, coordindex), biasS, biasT); }

void ogcwrap::gx::setTexCoordCylWrap(u8 texcoord, bool s_enable, bool t_enable)
	{ GX_SetTexCoordCylWrap(texcoord, s_enable, t_enable); }

void ogcwrap::gx::setTextureOffsetStatus(gx_texture_coordinate_index_t coordindex, bool lineStatus, bool pointStatus)
	{ GX_EnableTexOffsets(mcast(u8, coordindex), lineStatus, pointStatus); }

u32 ogcwrap::gx::getTextureBufferSize(u16 width, u16 height, gx_texture_format_t format, bool mipmapStatus, u8 maxLOD)
	{ return GX_GetTexBufferSize(width, height, mcast(u32, format), mipmapStatus, maxLOD); }

void ogcwrap::gx::setZMode(bool comparisonEnable, gx_comparison_t comparison, bool bufferUpdate)
	{ GX_SetZMode(comparisonEnable, mcast(u8, comparison), bufferUpdate); }

void ogcwrap::gx::setZTexture(gx_z_texture_operator_t op, gx_z_texture_format_t format, u32 bias)
	{ GX_SetZTexture(mcast(u8, op), mcast(u8, format), bias); }

void ogcwrap::gx::setZCompLoc(gx_z_buffer_time_t time)
	{ GX_SetZCompLoc(mcast(u8, time)); }

void ogcwrap::gx::initTextureCacheRegion(GXTexRegion * region, bool is32bmip, void * texmemEven, gx_texture_cache_size_t sizeEven, void * texmemOdd, gx_texture_cache_size_t sizeOdd)
	{ GX_InitTexCacheRegion(region, is32bmip, mcast(u32, texmemEven), mcast(u8, sizeEven), mcast(u32, texmemOdd), mcast(u8, sizeOdd)); }

void ogcwrap::gx::initTexturePreloadRegion(GXTexRegion * region, void * texmemEven, u32 sizeEven, void * texmemOdd, u32 sizeOdd)
	{ GX_InitTexPreloadRegion(region, mcast(u32, texmemEven), sizeEven, mcast(u32, texmemOdd), sizeOdd); }

void ogcwrap::gx::initTextureObject(
	GXTexObj *			obj,
	void *				imagebuf,
	u16					width,
	u16					height,
	gx_texture_format_t	format,
	gx_wrap_mode_t		wrapS,
	gx_wrap_mode_t		wrapT,
	bool				trilinear)
{
	GX_InitTexObj(obj,
				  imagebuf,
				  width,
				  height,
				  mcast(u8, format),
				  mcast(u8, wrapS),
				  mcast(u8, wrapT),
				  trilinear);
}

void ogcwrap::gx::initTextureObjectColorIndex(
	GXTexObj *			obj,
	void *				imagebuf,
	u16					width,
	u16					height,
	gx_texture_format_t	format,
	gx_wrap_mode_t		wrapS,
	gx_wrap_mode_t		wrapT,
	bool				mipmap,
	gx_tlut_index_t		tlut)
{
	GX_InitTexObjCI(obj,
					imagebuf,
					width,
					height,
					mcast(u8, format),
					mcast(u8, wrapS),
					mcast(u8, wrapT),
					mipmap,
					mcast(u32, tlut));
}

void ogcwrap::gx::initTLUTObj(GXTlutObj * tlut, void * addr, gx_tlut_entry_format_t format, u16 entries)
	{ GX_InitTlutObj(tlut, addr, mcast(u8, format), entries); }

void ogcwrap::gx::initTLUTRegion(GXTlutRegion * region, void * addr, u8 size)
	{ GX_InitTlutRegion(region, mcast(u32, addr), size); }

void ogcwrap::gx::preloadTexture(GXTexObj * obj, GXTexRegion * region)
	{ GX_PreloadEntireTexture(obj, region); }

void ogcwrap::gx::loadTextureObject(GXTexObj * obj, gx_texture_map_index_t index)
	{ GX_LoadTexObj(obj, mcast(u8, index)); }

void ogcwrap::gx::loadTLUT(GXTlutObj * tlut, gx_tlut_index_t index)
	{ GX_LoadTlut(tlut, mcast(u8, index)); }

void ogcwrap::gx::loadPreloadedTextureObject(GXTexObj * obj, GXTexRegion * region, gx_texture_map_index_t index)
	{ GX_LoadTexObjPreloaded(obj, region, mcast(u8, index)); }

void ogcwrap::gx::setTextureObjectData(GXTexObj * obj, void * imagebuf)
	{ GX_InitTexObjData(obj, imagebuf); }

void ogcwrap::gx::setTextureObjectUserData(GXTexObj * obj, void * data)
	{ GX_InitTexObjUserData(obj, data); }

void ogcwrap::gx::setTextureObjectTLUT(GXTexObj * obj, gx_tlut_index_t tlut)
	{ GX_InitTexObjTlut(obj, mcast(u8, tlut)); }

void ogcwrap::gx::setTextureObjectWrap(GXTexObj * obj, gx_wrap_mode_t wrapS, gx_wrap_mode_t wrapT)
	{ GX_InitTexObjWrapMode(obj, mcast(u8, wrapS), mcast(u8, wrapT)); }

void ogcwrap::gx::setTextureObjectLOD(GXTexObj * obj, gx_texture_filter_t miniFilter, gx_texture_filter_t magniFilter, f32 minLOD, f32 maxLOD, f32 bias, bool clamp, bool edgeLOD, gx_max_anisotropic_filter_t maxaniso)
{
	GX_InitTexObjFilterMode(obj, mcast(u8, miniFilter), mcast(u8, magniFilter));
	GX_InitTexObjMinLOD(obj, minLOD);
	GX_InitTexObjMaxLOD(obj, maxLOD);
	GX_InitTexObjLODBias(obj, bias);
	GX_InitTexObjBiasClamp(obj, clamp);
	GX_InitTexObjEdgeLOD(obj, edgeLOD);
	GX_InitTexObjMaxAniso(obj, mcast(u8, maxaniso));
}

void ogcwrap::gx::setTextureObjectLODFilter(GXTexObj * obj, gx_texture_filter_t miniFilter, gx_texture_filter_t magniFilter)
	{ GX_InitTexObjFilterMode(obj, mcast(u8, miniFilter), mcast(u8, magniFilter)); }

void ogcwrap::gx::setTextureObjectLODMin(GXTexObj * obj, f32 minLOD)
	{ GX_InitTexObjMinLOD(obj, minLOD); }

void ogcwrap::gx::setTextureObjectLODMax(GXTexObj * obj, f32 maxLOD)
	{ GX_InitTexObjMaxLOD(obj, maxLOD); }

void ogcwrap::gx::setTextureObjectLODBias(GXTexObj * obj, f32 bias)
	{ GX_InitTexObjLODBias(obj, bias); }

void ogcwrap::gx::setTextureObjectLODBiasClamp(GXTexObj * obj, bool clamp)
	{ GX_InitTexObjBiasClamp(obj, clamp); }

void ogcwrap::gx::setTextureObjectLODEdge(GXTexObj * obj, bool edgeLOD)
	{ GX_InitTexObjEdgeLOD(obj, edgeLOD); }

void ogcwrap::gx::setTextureObjectLODMaxAniso(GXTexObj * obj, gx_max_anisotropic_filter_t maxAniso)
	{ GX_InitTexObjMaxAniso(obj, mcast(u8, maxAniso)); }

void ogcwrap::gx::getTextureObjectAll(GXTexObj * obj,
									  void * * imagebuf,
									  u16 * width,
									  u16 * height,
									  u8 * format,
									  u8 * wrapS,
									  u8 * wrapT,
									  u8 * mipmap)
{
	GX_GetTexObjAll(obj,
					imagebuf,
					width,
					height,
					format,
					wrapS,
					wrapT,
					mipmap);
}

void * ogcwrap::gx::getTextureObjectData(GXTexObj * obj)
	{ return GX_GetTexObjData(obj); }

void * ogcwrap::gx::getTextureObjectUserData(GXTexObj * obj)
	{ return GX_GetTexObjUserData(obj); }

u16 ogcwrap::gx::getTextureObjectWidth(GXTexObj * obj)
	{ return GX_GetTexObjWidth(obj); }

u16 ogcwrap::gx::getTextureObjectHeight(GXTexObj * obj)
	{ return GX_GetTexObjHeight(obj); }

u32 ogcwrap::gx::getTextureObjectFormat(GXTexObj * obj)
	{ return GX_GetTexObjFmt(obj); }

u8 ogcwrap::gx::getTextureObjectWrapS(GXTexObj * obj)
	{ return GX_GetTexObjWrapS(obj); }

u8 ogcwrap::gx::getTextureObjectWrapT(GXTexObj * obj)
	{ return GX_GetTexObjWrapT(obj); }

u32 ogcwrap::gx::getTextureObjectMipmap(GXTexObj * obj)
	{ return GX_GetTexObjMipMap(obj); }

void ogcwrap::gx::invalidateTextureRegion(GXTexRegion * region)
	{ GX_InvalidateTexRegion(region); }

void ogcwrap::gx::invalidateAllTextures(void)
	{ GX_InvalidateTexAll(); }

void ogcwrap::gx::texModeSync(void)
	{ GX_TexModeSync(); }

void ogcwrap::gx::setTEVStageCount(u8 count)
	{ GX_SetNumTevStages(count); }

void ogcwrap::gx::setTEVOrder(gx_tev_stage_t stage, gx_texture_coordinate_index_t texcoord, gx_texture_map_index_t texmap, gx_color_channel_t channel)
	{ GX_SetTevOrder(mcast(u8, stage), mcast(u8, texcoord), mcast(u8, texmap), mcast(u8, channel)); }

void ogcwrap::gx::setTEVOp(gx_tev_stage_t stage, gx_tev_combiner_equation_t tevmode)
	{ GX_SetTevOp(mcast(u8, stage), mcast(u8, tevmode)); }

void ogcwrap::gx::setTEVColor(gx_tev_register_t tevreg, GXColor color)
	{ GX_SetTevColor(mcast(u8, tevreg), color); }

void ogcwrap::gx::setTEVColor(gx_tev_register_t tevreg, GXColorS10 color)
	{ GX_SetTevColorS10(mcast(u8, tevreg), color); }

void ogcwrap::gx::setTEVColorIn(gx_tev_stage_t stage, gx_tev_register_input_t regA, gx_tev_register_input_t regB, gx_tev_register_input_t regC, gx_tev_register_input_t regD)
	{ GX_SetTevColorIn(mcast(u8, stage), mcast(u8, regA), mcast(u8, regB), mcast(u8, regC), mcast(u8, regD)); }

void ogcwrap::gx::setTEVAlphaIn(gx_tev_stage_t stage, gx_tev_register_input_t regA, gx_tev_register_input_t regB, gx_tev_register_input_t regC, gx_tev_register_input_t regD)
	{ GX_SetTevAlphaIn(mcast(u8, stage), mcast(u8, regA), mcast(u8, regB), mcast(u8, regC), mcast(u8, regD)); }

void ogcwrap::gx::setTEVColorOp(gx_tev_stage_t stage, gx_tev_combiner_operator_t tevop, gx_tev_bias_t bias, gx_tev_scale_t scale, bool clamp, gx_tev_register_t tevreg)
	{ GX_SetTevColorOp(mcast(u8, stage), mcast(u8, tevop), mcast(u8, bias), mcast(u8, scale), clamp, mcast(u8, tevreg)); }

void ogcwrap::gx::setTEVAlphaOp(gx_tev_stage_t stage, gx_tev_combiner_operator_t tevop, gx_tev_bias_t bias, gx_tev_scale_t scale, bool clamp, gx_tev_register_t tevreg)
	{ GX_SetTevAlphaOp(mcast(u8, stage), mcast(u8, tevop), mcast(u8, bias), mcast(u8, scale), clamp, mcast(u8, tevreg)); }

void ogcwrap::gx::setTEVAlphaCompare(gx_comparison_t lcomp, u8 lref, gx_alpha_operation_t alphaop, gx_comparison_t rcomp, u8 rref)
	{ GX_SetAlphaCompare(mcast(u8, lcomp), lref, mcast(u8, alphaop), mcast(u8, rcomp), rref); }

void ogcwrap::gx::setTEVKColor(gx_tev_register_t tevreg, GXColor color)
	{ GX_SetTevKColor(mcast(u8, tevreg), color); }

void ogcwrap::gx::setTEVKColor(gx_tev_register_t tevreg, GXColorS10 color)
	{ GX_SetTevKColorS10(mcast(u8, tevreg), color); }

void ogcwrap::gx::selectTEVKColor(gx_tev_stage_t stage, gx_tev_constant_color_selection_t colorsel)
	{ GX_SetTevKColorSel(mcast(u8, stage), mcast(u8, colorsel)); }

void ogcwrap::gx::selectTEVKAlpha(gx_tev_stage_t stage, gx_tev_constant_alpha_selection_t alphasel)
	{ GX_SetTevKAlphaSel(mcast(u8, stage), mcast(u8, alphasel)); }

void ogcwrap::gx::setTEVSwapMode(gx_tev_stage_t stage, gx_tev_swap_table_index_t raster, gx_tev_swap_table_index_t texture)
	{ GX_SetTevSwapMode(mcast(u8, stage), mcast(u8, raster), mcast(u8, texture)); }

void ogcwrap::gx::setTEVSwapModeTable(gx_tev_swap_table_index_t table, gx_tev_color_channel_t red, gx_tev_color_channel_t green, gx_tev_color_channel_t blue, gx_tev_color_channel_t alpha)
	{ GX_SetTevSwapModeTable(mcast(u8, table), mcast(u8, red), mcast(u8, green), mcast(u8, blue), mcast(u8, alpha)); }

void ogcwrap::gx::setTEVDirect(gx_tev_stage_t stage)
	{ GX_SetTevDirect(mcast(u8, stage)); }

void ogcwrap::gx::setTEVIndirect(gx_tev_stage_t						stage,
								 gx_indirect_texture_stage_t		indstage,
								 gx_indirect_texture_format_t		format,
								 gx_indirect_texture_bias_t			bias,
								 gx_indirect_texture_matrix_t		mtx,
								 gx_indirect_texture_wrap_t			wrapS,
								 gx_indirect_texture_wrap_t			wrapT,
								 bool								addprev,
								 bool								modtc_mipmap,
								 gx_indirect_texture_alpha_bump_t	bump)
{
	GX_SetTevIndirect(mcast(u8, stage),
					  mcast(u8, indstage),
					  mcast(u8, format),
					  mcast(u8, bias),
					  mcast(u8, mtx),
					  mcast(u8, wrapS),
					  mcast(u8, wrapT),
					  addprev,
					  modtc_mipmap,
					  mcast(u8, bump));
}

void ogcwrap::gx::setTEVIndirectTile(gx_tev_stage_t						stage,
									 gx_indirect_texture_stage_t		indstage,
									 u16								width,
									 u16								height,
									 u16								repeatX,
									 u16								repeatY,
									 gx_indirect_texture_format_t		format,
									 gx_indirect_texture_matrix_t		mtx,
									 gx_indirect_texture_bias_t			bias,
									 gx_indirect_texture_alpha_bump_t	bump)
{
	GX_SetTevIndTile(mcast(u8, stage),
					 mcast(u8, indstage),
					 width,
					 height,
					 repeatX,
					 repeatY,
					 mcast(u8, format),
					 mcast(u8, mtx),
					 mcast(u8, bias),
					 mcast(u8, bump));
}

void ogcwrap::gx::setTEVIndirectRepeat(gx_tev_stage_t stage)
	{ GX_SetTevIndRepeat(mcast(u8, stage)); }

void ogcwrap::gx::setIndirectStageCount(u8 count)
	{ GX_SetNumIndStages(count); }

void ogcwrap::gx::setIndirectTextureOrder(gx_indirect_texture_stage_t indstage, gx_texture_coordinate_index_t coordindex, gx_texture_map_index_t mapindex)
	{ GX_SetIndTexOrder(mcast(u8, indstage), mcast(u8, coordindex), mcast(u8, mapindex)); }

void ogcwrap::gx::setIndirectTextureCoordScale(gx_indirect_texture_stage_t indstage, gx_indirect_texture_scale_t indscaleS, gx_indirect_texture_scale_t indscaleT)
	{ GX_SetIndTexCoordScale(mcast(u8, indstage), mcast(u8, indscaleS), mcast(u8, indscaleT)); }

void ogcwrap::gx::setIndirectTextureMatrix(gx_indirect_texture_matrix_t indmtx, f32 offset[2][3], s8 scaleExp)
	{ GX_SetIndTexMatrix(mcast(u8, indmtx), offset, scaleExp); }

void ogcwrap::gx::setIndirectTextureBumpST(gx_tev_stage_t stage, gx_indirect_texture_stage_t indstage, gx_indirect_texture_matrix_t indmtx)
	{ GX_SetTevIndBumpST(mcast(u8, stage), mcast(u8, indstage), mcast(u8, indmtx)); }

void ogcwrap::gx::setIndirectTextureBumpXYZ(gx_tev_stage_t stage, gx_indirect_texture_stage_t indstage, gx_indirect_texture_matrix_t indmtx)
	{ GX_SetTevIndBumpXYZ(mcast(u8, stage), mcast(u8, indstage), mcast(u8, indmtx)); }

void ogcwrap::gx::loadLightObject(GXLightObj * light, gx_light_index_t index)
	{ GX_LoadLightObj(light, mcast(u8, index)); }

void ogcwrap::gx::loadLightObjectIndex(u32 lightelement, gx_light_index_t index)
	{ GX_LoadLightObjIdx(lightelement, mcast(u8, index)); }

void ogcwrap::gx::setLightPosition(GXLightObj * light, f32 posX, f32 posY, f32 posZ)
	{ GX_InitLightPos(light, posX, posY, posZ); }

void ogcwrap::gx::setLightPosition(GXLightObj * light, guVector position)
	{ GX_InitLightPos(light, position.x, position.y, position.z); }

void ogcwrap::gx::setLightDirection(GXLightObj * light, f32 nrmX, f32 nrmY, f32 nrmZ)
	{ GX_InitLightDir(light, nrmX, nrmY, nrmZ); }

void ogcwrap::gx::setLightDirection(GXLightObj * light, guVector normal)
	{ GX_InitLightDir(light, normal.x, normal.y, normal.z); }

void ogcwrap::gx::setLightColor(GXLightObj * light, GXColor color)
	{ GX_InitLightColor(light, color); }

void ogcwrap::gx::setLightDistanceAttenuation(GXLightObj * light, f32 distance, f32 brightness, gx_attenuation_function_t distfn)
	{ GX_InitLightDistAttn(light, distance, brightness, mcast(u8, distfn)); }

void ogcwrap::gx::setLightAttenuation(GXLightObj * light, f32 ac1, f32 ac2, f32 ac3, f32 dc1, f32 dc2, f32 dc3)
	{ GX_InitLightAttn(light, ac1, ac2, ac3, dc1, dc2, dc3); }

void ogcwrap::gx::setLightAttenuationAngle(GXLightObj * light, f32 ac1, f32 ac2, f32 ac3)
	{ GX_InitLightAttnA(light, ac1, ac2, ac3); }

void ogcwrap::gx::setLightAttenuationDistance(GXLightObj * light, f32 dc1, f32 dc2, f32 dc3)
	{ GX_InitLightAttnK(light, dc1, dc2, dc3); }

void ogcwrap::gx::setLightShininess(GXLightObj * light, f32 shininess)
	{ GX_InitLightAttn(light, 0.0f, 0.0f, 0.0f, shininess/2.0f, 0.0f, 1.0f - shininess/2.0f); }

void ogcwrap::gx::setSpecularDirectionHalfAngle(GXLightObj * light, f32 nrmX, f32 nrmY, f32 nrmZ, f32 haX, f32 haY, f32 haZ)
	{ GX_InitSpecularDirHA(light, nrmX, nrmY, nrmZ, haX, haY, haZ); }

void ogcwrap::gx::setSpecularDirectionHalfAngle(GXLightObj * light, guVector normal, guVector halfangle)
	{ GX_InitSpecularDirHA(light, normal.x, normal.y, normal.z, halfangle.x, halfangle.y, halfangle.z); }

void ogcwrap::gx::setSpecularDirection(GXLightObj * light, f32 nrmX, f32 nrmY, f32 nrmZ)
	{ GX_InitSpecularDir(light, nrmX, nrmY, nrmZ); }

void ogcwrap::gx::setSpecularDirection(GXLightObj * light, guVector normal)
	{ GX_InitSpecularDir(light, normal.x, normal.y, normal.z); }

void ogcwrap::gx::setLightSpot(GXLightObj * light, f32 angle, gx_spot_illumination_function_t spotfn)
	{ GX_InitLightSpot(light, angle, mcast(u8, spotfn)); }

void ogcwrap::gx::matrixIndex(u8 index)
	{ GX_MatrixIndex1x8(index); }

void ogcwrap::gx::setCurrentMatrix(gx_position_normal_matrix_index_t index)
	{ GX_SetCurrentMtx(mcast(u32, index)); }

void ogcwrap::gx::loadProjectionMatrix(Mtx44 mtx, gx_projection_type_t type)
	{ GX_LoadProjectionMtx(mtx, mcast(u8, type)); }

void ogcwrap::gx::loadPosMtxImm(Mtx mtx, gx_position_normal_matrix_index_t index)
	{ GX_LoadPosMtxImm(mtx, mcast(u32, index)); }

void ogcwrap::gx::loadPosMtxIdx(u16 mtxidx, gx_position_normal_matrix_index_t index)
	{ GX_LoadPosMtxIdx(mtxidx, mcast(u32, index)); }

void ogcwrap::gx::loadNrmMtxImm(Mtx mtx, gx_position_normal_matrix_index_t index)
	{ GX_LoadNrmMtxImm(mtx, mcast(u32, index)); }

void ogcwrap::gx::loadNrmMtxIdx(u16 mtxidx, gx_position_normal_matrix_index_t index)
	{ ogcwrap::gx::detail::LoadNrmMtxIdx(mtxidx, mcast(u32, index)); }

void ogcwrap::gx::loadNrmMtxImm3x3(Mtx33 mtx, gx_position_normal_matrix_index_t index)
	{ GX_LoadNrmMtxImm3x3(mtx, mcast(u32, index)); }

void ogcwrap::gx::loadNrmMtxIdx3x3(u16 mtxidx, gx_position_normal_matrix_index_t index)
	{ GX_LoadNrmMtxIdx3x3(mtxidx, mcast(u32, index)); }

void ogcwrap::gx::loadTexMtxImm(Mtx mtx, gx_texture_matrix_index_t index, gx_texture_matrix_type_t type)
	{ GX_LoadTexMtxImm(mtx, mcast(u32, index), mcast(u8, type)); }

void ogcwrap::gx::loadTexMtxIdx(u16 mtxidx, gx_texture_matrix_index_t index, gx_texture_matrix_type_t type)
	{ GX_LoadTexMtxIdx(mtxidx, mcast(u32, index), mcast(u8, type)); }

void ogcwrap::gx::enableBreakPoint(void * addr)
	{ GX_EnableBreakPt(addr); }

void ogcwrap::gx::disableBreakPoint(void)
	{ GX_DisableBreakPt(); }

void ogcwrap::gx::setLineWidth(u8 width, gx_texture_offset_value_t texfmt)
	{ GX_SetLineWidth(width, mcast(u8, texfmt)); }

void ogcwrap::gx::setPointSize(u8 width, gx_texture_offset_value_t texfmt)
	{ GX_SetPointSize(width, mcast(u8, texfmt)); }

void ogcwrap::gx::setBlendMode(gx_blend_mode_t type, gx_blend_control_t sourceFactor, gx_blend_control_t destFactor, gx_logic_operation_t op)
	{ GX_SetBlendMode(mcast(u8, type), mcast(u8, sourceFactor), mcast(u8, destFactor), mcast(u8, op)); }

void ogcwrap::gx::setCullingMode(gx_culling_mode_t mode)
	{ GX_SetCullMode(mcast(u8, mode)); }

void ogcwrap::gx::setCoplanarMode(bool enable)
	{ GX_SetCoPlanar(enable); }

void ogcwrap::gx::setClipMode(bool enable)
	{ GX_SetClipMode(enable); }

void ogcwrap::gx::setDitherMode(bool enable)
	{ GX_SetDither(enable); }

void ogcwrap::gx::setPokeColor(bool enable)
	{ GX_PokeColorUpdate(enable); }

void ogcwrap::gx::setPokeAlpha(bool enable)
	{ GX_PokeAlphaUpdate(enable); }

void ogcwrap::gx::setPokeDither(bool enable)
	{ GX_PokeDither(enable); }

void ogcwrap::gx::pokeAlphaMode(gx_comparison_t comp, u8 threshold)
	{ GX_PokeAlphaMode(mcast(u8, comp), threshold); }

void ogcwrap::gx::pokeBlendMode(gx_blend_mode_t type, gx_blend_control_t sourceFactor, gx_blend_control_t destFactor, gx_logic_operation_t op)
	{ GX_PokeBlendMode(mcast(u8, type), mcast(u8, sourceFactor), mcast(u8, destFactor), mcast(u8, op)); }

void ogcwrap::gx::pokeZMode(bool comp, gx_comparison_t compfn, bool update)
	{ GX_PokeZMode(comp, mcast(u8, compfn), update); }

void ogcwrap::gx::pokeAlphaRead(gx_alpha_read_mode_t mode)
	{ GX_PokeAlphaRead(mcast(u8, mode)); }

void ogcwrap::gx::pokeDestAlpha(bool enable, u8 constAlpha)
	{ GX_PokeDstAlpha(enable, constAlpha); }

void ogcwrap::gx::pokeRGBA(u16 x, u16 y, GXColor color)
	{ GX_PokeARGB(x, y, color); }

void ogcwrap::gx::pokeZ(u16 x, u16 y, u32 z)
	{ GX_PokeZ(x, y, z); }

void ogcwrap::gx::peekRGBA(u16 x, u16 y, GXColor * color)
	{ GX_PeekARGB(x, y, color); }

void ogcwrap::gx::peekZ(u16 x, u16 y, u32 * z)
	{ GX_PeekZ(x, y, z); }

void ogcwrap::gx::setMisc(gx_misc_token_t token, u32 value)
	{ GX_SetMisc(mcast(u32, token), value); }

void ogcwrap::gx::getGPStatus(u8 * overHigh, u8 * underLow, u8 * readIdle, u8 * cmdIdle, u8 * breakpt)
	{ GX_GetGPStatus(overHigh, underLow, readIdle, cmdIdle, breakpt); }

u32 ogcwrap::gx::readClksPerVtx(void)
	{ return GX_ReadClksPerVtx(); }

u32 ogcwrap::gx::getOverflowCount(void)
	{ return GX_GetOverflowCount(); }

u32 ogcwrap::gx::resetOverflowCount(void)
	{ return GX_ResetOverflowCount(); }

lwp_t ogcwrap::gx::getCurrentThread(void)
	{ return GX_GetCurrentGXThread(); }

lwp_t ogcwrap::gx::setCurrentThread(void)
	{ return GX_SetCurrentGXThread(); }

volatile void * ogcwrap::gx::redirectWriteGatherPipe(void * tempPipe)
	{ return GX_RedirectWriteGatherPipe(tempPipe); }

void ogcwrap::gx::restoreWriteGatherPipe(void)
	{ GX_RestoreWriteGatherPipe(); }

void ogcwrap::gx::setGPMetric(gx_performance_counter_0_metric_t pc0metric, gx_performance_counter_1_metric_t pc1metric)
	{ GX_SetGPMetric(mcast(u32, pc0metric), mcast(u32, pc1metric)); }

void ogcwrap::gx::readGPMetric(u32 * pc0metric, u32 * pc1metric)
	{ GX_ReadGPMetric(pc0metric, pc1metric); }

void ogcwrap::gx::clearGPMetric(void)
	{ GX_ClearGPMetric(); }

void ogcwrap::gx::initXfRasMetric(void)
	{ GX_InitXfRasMetric(); }

void ogcwrap::gx::readXfRasMetric(u32 * xfWaitIn, u32 * xfWaitOut, u32 * rasBusy, u32 * clocks)
	{ GX_ReadXfRasMetric(xfWaitIn, xfWaitOut, rasBusy, clocks); }

void ogcwrap::gx::setVCacheMetric(gx_vertex_cache_metric_t vtxMetric)
	{ GX_SetVCacheMetric(mcast(u32, vtxMetric)); }

void ogcwrap::gx::readVCacheMetric(u32 * check, u32 * miss, u32 * stall)
	{ GX_ReadVCacheMetric(check, miss, stall); }

void ogcwrap::gx::clearVCacheMetric(void)
	{ GX_ClearVCacheMetric(); }

// namespace ogcwrap::gx::draw

void ogcwrap::gx::draw::begin(gx_primitive_t primitive, gx_vertex_format_t vtxfmt, u16 count)
	{ GX_Begin(mcast(u8, primitive), mcast(u8, vtxfmt), count); }

void ogcwrap::gx::draw::end()
	{ GX_End(); }

u16 ogcwrap::gx::draw::getDrawSync(void)
	{ return GX_GetDrawSync(); }

void ogcwrap::gx::draw::setDrawSync(u16 token)
	{ GX_SetDrawSync(token); }

void ogcwrap::gx::draw::beginDisplayList(void * buf, u32 bufsize)
	{ GX_BeginDispList(buf, bufsize); }

[[nodiscard("return value used as input in callDisplayList")]]
u32 ogcwrap::gx::draw::endDisplayList(void)
	{ return GX_EndDispList(); }

void ogcwrap::gx::draw::callDisplayList(void * list, u32 listSize)
	{ GX_CallDispList(list, listSize); }

void ogcwrap::gx::draw::indexedPosition(u8 index)
	{ GX_Position1x8(index); }

void ogcwrap::gx::draw::indexedPosition(u16 index)
	{ GX_Position1x16(index); }

void ogcwrap::gx::draw::position(u8 x, u8 y)
	{ GX_Position2u8(x, y); }

void ogcwrap::gx::draw::position(s8 x, s8 y)
	{ GX_Position2s8(x, y); }

void ogcwrap::gx::draw::position(u16 x, u16 y)
	{ GX_Position2u16(x, y); }

void ogcwrap::gx::draw::position(s16 x, s16 y)
	{ GX_Position2s16(x, y); }

void ogcwrap::gx::draw::position(f32 x, f32 y)
	{ GX_Position2f32(x, y); }

void ogcwrap::gx::draw::position(u8 x, u8 y, u8 z)
	{ GX_Position3u8(x, y, z); }

void ogcwrap::gx::draw::position(s8 x, s8 y, s8 z)
	{ GX_Position3s8(x, y, z); }

void ogcwrap::gx::draw::position(u16 x, u16 y, u16 z)
	{ GX_Position3u16(x, y, z); }

void ogcwrap::gx::draw::position(s16 x, s16 y, s16 z)
	{ GX_Position3s16(x, y, z); }

void ogcwrap::gx::draw::position(f32 x, f32 y, f32 z)
	{ GX_Position3f32(x, y, z); }

void ogcwrap::gx::draw::indexedNormal(u8 index)
	{ GX_Normal1x8(index); }

void ogcwrap::gx::draw::indexedNormal(u16 index)
	{ GX_Normal1x16(index); }

void ogcwrap::gx::draw::normal(s8 nx, s8 ny, s8 nz)
	{ GX_Normal3s8(nx, ny, nz); }

void ogcwrap::gx::draw::normal(s16 nx, s16 ny, s16 nz)
	{ GX_Normal3s16(nx, ny, nz); }

void ogcwrap::gx::draw::normal(f32 nx, f32 ny, f32 nz)
	{ GX_Normal3f32(nx, ny, nz); }

void ogcwrap::gx::draw::indexedColor(u8 index)
	{ GX_Color1x8(index); }

void ogcwrap::gx::draw::indexedColor(u16 index)
	{ GX_Color1x16(index); }

void ogcwrap::gx::draw::color(u16 rgb565)
	{ GX_Color1u16(rgb565); }

void ogcwrap::gx::draw::color(u32 rgba8)
	{ GX_Color1u32(rgba8); }

void ogcwrap::gx::draw::color(u8 r, u8 g, u8 b)
	{ GX_Color3u8(r, g, b); }

void ogcwrap::gx::draw::color(f32 r, f32 g, f32 b)
	{ GX_Color3f32(r, g, b); }

void ogcwrap::gx::draw::color(u8 r, u8 g, u8 b, u8 a)
	{ GX_Color4u8(r, g, b, a); }

void ogcwrap::gx::draw::indexedTexcoord(u8 index)
	{ GX_TexCoord1x8(index); }

void ogcwrap::gx::draw::indexedTexcoord(u16 index)
	{ GX_TexCoord1x16(index); }

void ogcwrap::gx::draw::texcoord(u8 s)
	{ GX_TexCoord1u8(s); }

void ogcwrap::gx::draw::texcoord(s8 s)
	{ GX_TexCoord1s8(s); }

void ogcwrap::gx::draw::texcoord(u16 s)
	{ GX_TexCoord1u16(s); }

void ogcwrap::gx::draw::texcoord(s16 s)
	{ GX_TexCoord1s16(s); }

void ogcwrap::gx::draw::texcoord(f32 s)
	{ GX_TexCoord1f32(s); }

void ogcwrap::gx::draw::texcoord(u8 s, u8 t)
	{ GX_TexCoord2u8(s, t); }

void ogcwrap::gx::draw::texcoord(s8 s, s8 t)
	{ GX_TexCoord2s8(s, t); }

void ogcwrap::gx::draw::texcoord(u16 s, u16 t)
	{ GX_TexCoord2u16(s, t); }

void ogcwrap::gx::draw::texcoord(s16 s, s16 t)
	{ GX_TexCoord2s16(s, t); }

void ogcwrap::gx::draw::texcoord(f32 s, f32 t)
	{ GX_TexCoord2f32(s, t); }

// namespace ogcwrap::gx::detail

#ifdef GX_DETAIL_IMPLEMENT

void ogcwrap::gx::detail::GetVtxAttrFmt(u8 slot, GXVtxAttrFmt * fmt)
{
	extern __gx_regdef * __gx;
	u8 vat = (slot & 0b0111);

	u32 gxvals[3] = {__gx->VAT0reg[vat], __gx->VAT1reg[vat], __gx->VAT2reg[vat]};

	fmt->comptype = ( gxvals[0]        & 0x01) |
					( gxvals[0] >> 9         ) |
					((gxvals[0] >> 13) & 0x01) |
					((gxvals[0] >> 17) & 0x01) |
					((gxvals[0] >> 21) & 0x01) |
					( gxvals[1]        & 0x01) |
					((gxvals[1] >> 9 ) & 0x01) |
					((gxvals[1] >> 18) & 0x01) |
					((gxvals[1] >> 27) & 0x01) |
					((gxvals[2] >> 5 ) & 0x01) |
					((gxvals[2] >> 14) & 0x01) |
					((gxvals[2] >> 23) & 0x01);

	fmt->comptype = ((gxvals[0] >> 1 ) & 0x07) |
					((gxvals[0] >> 10) & 0x07) |
					((gxvals[0] >> 14) & 0x07) |
					((gxvals[0] >> 18) & 0x07) |
					((gxvals[0] >> 22) & 0x07) |
					((gxvals[1] >> 1 ) & 0x07) |
					((gxvals[1] >> 10) & 0x07) |
					((gxvals[1] >> 19) & 0x07) |
					((gxvals[1] >> 28) & 0x07) |
					((gxvals[2] >> 6 ) & 0x07) |
					((gxvals[0] >> 15) & 0x07) |
					((gxvals[0] >> 24) & 0x07);

	if (gxvals[0] & (1 << 62))
	{
		fmt->frac = ((gxvals[0] >> 4 ) & 0x1f) | // 31, mask out all but first 5 bits
					((gxvals[0] >> 25) & 0x1f) |
					((gxvals[1] >> 4 ) & 0x1f) |
					((gxvals[1] >> 13) & 0x1f) |
					((gxvals[1] >> 22) & 0x1f) |
					( gxvals[2]        & 0x1f) |
					((gxvals[2] >> 9 ) & 0x1f) |
					((gxvals[2] >> 18) & 0x1f) |
					((gxvals[2] >> 27) & 0x1f);
	}
	else
		{ fmt->frac = 0; }
	}
}

/*
void ogcwrap::gx::detail::GetVtxAttrFmtv(GXVtxAttrFmt * fmtlist)
{
	extern __gx_regdef * __gx;
}
*/

void ogcwrap::gx::detail::GetVtxDesc(u8 attr, GXVtxDesc * desc)
{
	// damn near verbatim from libogc
	extern __gx_regdef * __gx;

	switch (__gx->vcdLo)
	{
		// position matrix index
		case (1 << 0):
			desc->attr = GX_VA_PTNMTXIDX;
			desc->type = (1 << 0);
			break;

		// texture matrix indices
		case (1 << 1):
			desc->attr = GX_VA_TEX0MTXIDX;
			desc->type = (1 << 1);
			break;
		case (1 << 2):
			desc->attr = GX_VA_TEX1MTXIDX;
			desc->type = (1 << 2);
			break;
		case (1 << 3):
			desc->attr = GX_VA_TEX2MTXIDX;
			desc->type = (1 << 3);
			break;
		case (1 << 4):
			desc->attr = GX_VA_TEX3MTXIDX;
			desc->type = (1 << 4);
			break;
		case (1 << 5):
			desc->attr = GX_VA_TEX4MTXIDX;
			desc->type = (1 << 5);
			break;
		case (1 << 6):
			desc->attr = GX_VA_TEX5MTXIDX;
			desc->type = (1 << 6);
			break;
		case (1 << 7):
			desc->attr = GX_VA_TEX6MTXIDX;
			desc->type = (1 << 7);
			break;
		case (1 << 8):
			desc->attr = GX_VA_TEX7MTXIDX;
			desc->type = (1 << 8);
			break;

		// position
		case (1 << 9):
		case (1 << 10): [[fallthrough]];
			desc->attr = GX_VA_POS;
			desc->type = ((__gx->vcdLo >> 9) & 0b11);
			break;

		// normals
		case (1 << 11):
		case (1 << 12): [[fallthrough]];
			desc->attr = __gx->vcdNrms == 1 ? GX_VA_NRM : GX_VA_NBT;
			desc->type = ((__gx->vcdLo >> 11) & 0b11);
			break;

		// colors
		case (1 << 13):
		case (1 << 14): [[fallthrough]];
			desc->attr = GX_VA_CLR0;
			desc->type = ((__gx->vcdLo >> 13) & 0b11);
			break;
		case (1 << 15):
		case (1 << 16): [[fallthrough]];
			desc->attr = GX_VA_CLR1;
			desc->type = ((__gx->vcdLo >> 15) & 0b11);
		default: [[fallthrough]];
			break;
	}

	switch (__gx->vcdHi)
	{
		// textures
		case (1 << 0):
		case (1 << 1): [[fallthrough]];
			desc->attr = GX_VA_TEX0;
			desc->type = (__gx->vcdHi & 0b11);
			break;
		case (1 << 2):
		case (1 << 3): [[fallthrough]];
			desc->attr = GX_VA_TEX1;
			desc->type = ((__gx->vcdHi >> 2) & 0b11);
			break;
		case (1 << 4):
		case (1 << 5): [[fallthrough]];
			desc->attr = GX_VA_TEX2;
			desc->type = ((__gx->vcdHi >> 4) & 0b11);
			break;
		case (1 << 6):
		case (1 << 7): [[fallthrough]];
			desc->attr = GX_VA_TEX3;
			desc->type = ((__gx->vcdHi >> 6) & 0b11);
			break;
		case (1 << 8):
		case (1 << 9): [[fallthrough]];
			desc->attr = GX_VA_TEX4;
			desc->type = ((__gx->vcdHi >> 8) & 0b11);
			break;
		case (1 << 10):
		case (1 << 11): [[fallthrough]];
			desc->attr = GX_VA_TEX5;
			desc->type = ((__gx->vcdHi >> 10) & 0b11);
			break;
		case (1 << 12):
		case (1 << 13): [[fallthrough]];
			desc->attr = GX_VA_TEX6;
			desc->type = ((__gx->vcdHi >> 12) & 0b11);
			break;
		case (1 << 14):
		case (1 << 15): [[fallthrough]];
			desc->attr = GX_VA_TEX5;
			desc->type = ((__gx->vcdHi >> 14) & 0b11);
		default: [[fallthrough]];
			break;
	}
}

void ogcwrap::gx::detail::LoadNrmMtxIdx(u16 mtxidx, u32 pnidx)
{
	extern union _wgpipe * const wgPipe;

	wgPipe->U8 = 0x28; // is this correct?
	wgPipe->U32 = (mtxidx << 16) | (1 << 15) | ((1 << 10) | pnidx * 3);
}

#endif // GX_DETAIL_IMPLEMENT