/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "gx/gx_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::gx
{
	// library management
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
	void setTextureCopyDest(u16, u16, gx_texture_format_t bool); //m1
	void copyTexture(void *, bool);

	// frame management
	void abortFrame(void);
	void setDrawDone(void);
	void waitDrawDone(void);

	void syncPixelMode(void);
	void clearBoundingBox(void);

	// fog
	void setFog(gx_fog_equation_t, f32, f32, f32, f32, GXColor);
	void setFogColor(GXColor);
	void setFogRangeAdjustment(bool, u16, GXFogAdjTbl *); //m2??

	// vertex management
	void invalidateVertexCache(void);
	void clearVertexDescriptors(void);
//  void getVertexAttributeFormat();
//  void getVertexAttributeFormatList();
//  void getVertexDescriptor();
	void getVertexDescriptorList(GXVtxDesc *);
	void setVertexAttributeFormat(gx_vertex_format_t, gx_vertex_attribute_t, gx_vertex_component_type_t, gx_vertex_component_format_t, u8);
	void setVertexAttributeFormatList(gx_vertex_format_t, GXVtxAttrFmt *);
	void setVertexDescriptor(gx_vertex_attribute_t, gx_vertex_descriptor_t);
	void setVertexDescriptorList(GXVtxDesc *);
	void setArray(gx_vertex_attribute_t, void *, u8);

	// color management
	void setChannelCount(u8);
	void setColorChannelControl(gx_color_channel_t, bool, GXColor, GXColor, u8, gx_diffuse_function_t, gx_attenuation_function_t);
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

	void initTextureObject(GXTexObj *, void *, u16, u16, gx_texture_format_t, gx_clamp_mode_t, gx_clamp_mode_t, bool);
	void initTextureObjectColorIndex(GXTexObj *, void *, u16, u16, gx_texture_format_t, gx_clamp_mode_t, gx_clamp_mode_t, bool, gx_tlut_index_t);
	void initTLUTObj(GXTlutObj *, void *, gx_tlut_entry_format_t, u16);
	void initTLUTRegion(GXTlutRegion *, void *, u8);

	void preloadTexture(GXTexObj *, GXTexRegion *);
	void loadTextureObject(GXTexObj *, gx_texture_map_index_t);
	void loadTLUT(GXTlutObj *, gx_tlut_index_t);
	void loadPreloadedTextureObject(GXTexObj *, GXTexRegion *, gx_texture_map_index_t);

	void setTextureObjectData(GXTexObj *, void *);
	void setTextureObjectUserData(GXTexObj *, void *);
	void setTextureObjectTLUT(GXTexObj *, gx_tlut_index_t);
	void setTextureObjectWrap(GXTexObj *, gx_clamp_mode_t, gx_clamp_mode_t);
	void setTextureObjectLOD(GXTexObj *, gx_texture_filter_t, gx_texture_filter_t, f32, f32, f32, bool, bool, gx_max_anisotropic_filter_t);
	void setTextureObjectLODFilter(GXTexObj *, gx_texture_filter_t, gx_texture_filter_t);
	void setTextureObjectLODMin(GXTexObj *, f32);
	void setTextureObjectLODMax(GXTexObj *, f32);
	void setTextureObjectLODBias(GXTexObj *, f32);
	void setTextureObjectLODBiasClamp(GXTexObj *, bool);
	void setTextureObjectLODEdge(GXTexObj *, bool);
	void setTextureObjectLODMaxAniso(GXTexObj *, gx_max_anisotropic_filter_t);

	void getTextureObjectAll(GXTexObj *, void * *, u8 *, u8 *, u8 *, u8 *, u16 *, u16 *);
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
	void setTEVOrder(gx_tev_stage_t, gx_texture_coordinate_generation_type_t, gx_texture_map_index_t, gx_color_channel_t);
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
	void setTEVSwapMode(gx_tev_stage_t, gx_tev_swap_table_index_t);
	void setTEVSwapModeTable(gx_tev_swap_table_index_t, gx_tev_color_channel_t);

	void setTEVDirect(gx_tev_stage_t);
	void setTEVIndirect(gx_tev_stage_t, gx_indirect_texture_stage_t, gx_indirect_texture_format_t, gx_indirect_texture_bias_t, gx_indirect_texture_matrix_t, gx_indirect_texture_wrap_t, gx_indirect_texture_wrap_t, bool, bool, gx_indirect_texture_alpha_bump_t);
	void setTEVIndirectTile(gx_tev_stage_t, gx_indirect_texture_stage_t, u16, u16, u16, u16, gx_indirect_texture_format_t, gx_indirect_texture_matrix_t, gx_indirect_texture_bias_t, gx_indirect_texture_alpha_bump_t);
	void setTEVIndirectRepeat(gx_tev_stage_t);

	void setIndirectStageCount(u8);
	void setIndirectTextureOrder(gx_indirect_texture_stage_t, gx_texture_coordinate_index_t, gx_texture_map_index_t);
	void setIndirectTextureCoordScale(gx_indirect_texture_stage_t, gx_indirect_texture_scale_t, gx_indirect_texture_scale_t);
	void setIndirectTextureMatrix(gx_indirect_texture_matrix_t, Mtx23 *, s8);
	void setIndirectTextureBumpST(gx_tev_stage_t, gx_indirect_texture_stage_t, gx_indirect_texture_matrix_t);
	void setIndirectTextureBumpXYZ(gx_tev_stage_t, gx_indirect_texture_stage_t, gx_indirect_texture_matrix_t);

	// light management
	void loadLightObject(GXLightObj *, gx_light_index_t);
	void loadLightObjectIndex(u32, gx_light_index_t);

	void setLightShininess(GXLightObj *, f32);
	void setLightPosition(GXLightObj *, f32, f32, f32);
	void setLightPosition(GXLightObj *, guPos);
	void setLightDirection(GXLightObj *, f32, f32, f32);
	void setLightDirection(GXLightObj *, guVector);
	void setLightColor(GXLightObj *, GXColor);
	void setLightDistanceAttenuation(GXLightObj *, f32, f32, gx_attenuation_function_t);
	void setLightAttenuation(GXLightObj *, f32, f32, f32, f32, f32, f32);
	void setLightAttenuation(GXLightObj *, guVector, guVector);
	void setLightAttenuationAngle(GXLightObj *, f32, f32, f32);
	void setLightAttenuationAngle(GXLightObj *, guVector);
	void setLightAttenuationDistance(GXLightObj *, f32, f32, f32);
	void setLightAttenuationDistance(GXLightObj *, guVector);

	void setSpecularDirectionHalfAngle(GXLightObj *, f32, f32, f32, f32, f32, f32);
	void setSpecularDirectionHalfAngle(GXLightObj *, guVector, guVector);
	void setSpecularDirection(GXLightObj *, f32, f32, f32);
	void setSpecularDirection(GXLightObj *, guVector);

	void setLightSpot(GXLightObj *, f32, gx_spot_illumination_function_t);

	// matrices
	void matrixIndex(u8 index);
	void setCurrentMatrix(u32);

	void loadProjectionMatrix(Mtx44, gx_projection_type_t);
	void loadPosMtxImm(Mtx, u32 pnidx);
	void loadPosMtxIdx(u16 mtxidx, u32);
	void loadNrmMtxImm(Mtx, u32);
	void loadNrmMtxImm3x3(Mtx33, u32);
	void loadNrmMtxIdx3x3(u16, u32);
	void loadTexMtxImm(Mtx, u32, u8 type);
	void loadTexMtxIdx(u16, u32, u8);

	// breakpoint
	void enableBreakPoint(void *);
	void disableBreakPoint(void);

	// drawing settings
	void setLineWidth(u8, gx_texture_offset_value_t);
	void setPointSize(u8, gx_texture_offset_value_t);
	void setBlendMode(gx_blend_mode_t, gx_blend_control_t, gx_blend_control_t, gx_logic_operation_t);
	void setDitherMode(bool);
	void setCullingMode(gx_culling_mode_t);
	void setCoplanarMode(bool);
	void setClipMode(bool);

	// poke/peek
	void setPokeAlpha(bool);
	void setPokeColor(bool);
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
	void setMisc(u32, u32);

	u32 readClksPerVtx(void);
	u32 getOverflowCount(void);
	u32 resetOverflowCount(void);
	void readBoundingBox(u16 *, u16 *, u16 *, u16 *);

	lwp_t getCurrentThread(void);
	lwp_t setCurrentThread(void);
	volatile void * redirectWriteGatherPipe(void *);
	void restoreWriteGatherPipe(void);
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

u32 ogcwrap::gx::setDisplayCopyYScale(u16 efbHeight, xfbHeight)
	{ return GX_SetDispCopyYScale(GX_GetYScaleFactor(efbheight, xbheight)); }

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

void ogcwrap::gx::setCopyFilter(bool aa_status, u8 samplepattern[12][2], bool vf_status, u8 vfilter[7])
	{ GX_SetCopyFilter(aa_status, samplepattern, vf_status, vfilter); }

void ogcwrap::gx::setCopyClear(GXColor color, u32 z)
	{ GX_SetCopyClear(color, z); }

void ogcwrap::gx::copyDisplay(void * dest, bool clear)
	{ GX_CopyDisp(dest, clear); }

void ogcwrap::gx::setViewport(f32 left, f32 top, f32 width, f32 height, f32 near, f32 far)
	{ GX_SetViewport(left, top, width, height, near, far); }

void ogcwrap::gx::setViewportJitter(f32 left, f32 top, f32 width, f32 height, f32 near, f32 far, gx_next_field_t next)
	{ GX_SetViewportJitter(left, top, width, height, near, far, mcast(u32, next)); }

void ogcwrap::gx::adjustForOverscan(GXRModeObj * rm_in, GXRModeObj * rm_out, u16 htrim, u16 vtrim)
	{ GX_AdjustForOverscan(rm_in, rm_out, htim, vtrim); }

void ogcwrap::gx::setScissor(u16 top, u16 left, u16 width, u16 height)
	{ GX_SetScissor(top, left, width, height); }

void ogcwrap::gx::setScissorBoxOffset(s16 xOffset, s16 yOffset)
	{ GX_SetScissorBoxOffset(xOffset, yOffset); }

void ogcwrap::gx::setColorUpdate(bool enable)
	{ GX_SetColorUpdate(enable); }

void ogcwrap::gx::setColorUpdate(bool color_enable, bool alpha_enable)
{
	GX_SetColorUpdate(color_enable);
	GX_SetAlphaUpdate(alpha_enable);
}

void ogcwrap::gx::setAlphaUpdate(bool enable)
	{ GX_SetAlphaUpdate(enable); }

void ogcwrap::gx::setPixelFormat(gx_pixel_format_t pixelfmt, gx_z_format_t zfmt)
	{ GX_SetPixelFmt(mcast(u8, pixelfmt), mcast(u8, zfmt)); }

void ogcwrap::gx::setDestAlpha(bool enable, u8 alpha)
	{ GX_SetDstAlpha(enable, alpha); }

void ogcwrap::gx::setFieldMask(bool even, bool odd)
	{ GX_SetFieldMask(even, odd); }

void ogcwrap::gx::setFieldMode(bool field, bool half_aspect)
	{ GX_SetFieldMode(field, half_aspect); }

void ogcwrap::gx::setTextureCopySource(u16 left, u16 top, u16 width, u16 height)
	{ GX_SetTexCopySrc(left, top, width, height); }

void ogcwrap::gx::setTextureCopyDest(u16 width, u16 height, gx_texture_format_t format, bool mipmap)
	{ GX_SetTexCopyDst(width, height, mcast(u32, format), mipmap); }

void ogcwrap::gx::copyTexture(void * dest, bool clear)
	{ GX_CopyTex(dest, clear); }

void ogcwrap::gx::abortFrame(void)
	{ GX_AbortFrame(); }

u16 ogcwrap::gx::getDrawDone(void)
	{ return GX_GetDrawDone(); }

void ogcwrap::gx::setDrawDone(void)
	{ GX_SetDrawDone(); }

void ogcwrap::gx::waitDrawDone(void)
	{ GX_WaitDrawDone(); }

void ogcwrap::gx::syncPixelMode(void)
	{ GX_SyncPixelMode(); }

void ogcwrap::gx::clearBoundingBox(void)
	{ GX_ClearBoundingBox(); }

void ogcwrap::gx::setFog(gx_fog_equation_t equation, f32 start, f32 end, f32 near, f32 far, GXColor color)
	{ GX_SetFog(mcast(equation, start, end, near, far, color)); }

void ogcwrap::gx::setFogColor(GXColor color)
	{ GX_SetFogColor(color); }

void ogcwrap::gx::setFogRangeAdjustment(bool enable, u16 center, GXFogAdjTbl * table)
	{ GX_SetFogRangeAdj(enable, center, table); }

void ogcwrap::gx::invalidateVertexCache(void)
	{ GX_InvVtxCache(); }

void ogcwrap::gx::clearVertexDescriptors(void)
	{ GX_ClearVtxDesc(); }

void ogcwrap::gx::setVertexAttributeFormat(gx_vertex_format_t format, gx_vertex_attribute_t attr, gx_vertex_component_type_t comptype, gx_vertex_component_format_t compfmt, u8 fraction_bits)
	{ GX_SetVtxAttrFmt(mcast(u8, format), mcast(u32, attr), mcast(u32, comptype), mcast(u32, compfmt), fraction_bits); }

void ogcwrap::gx::setVertexAttributeFormatList(gx_vertex_format_t format, GXVtxAttrFmt * attrlist)
	{ GX_SetVtxAttrFmtv(mcast(u8, format), attrlist); }

void ogcwrap::gx::setVertexDescriptor(gx_vertex_attribute_t attr, gx_vertex_descriptor_t type)
	{ GX_SetVtxDesc(mcast(u8, attr), mcast(u8,type)); }

void ogcwrap::gx::setVertexDescriptorList(GXVtxDesc * desclist)
	{ GX_SetVtxDescv(desc_list); }

/*
void ogcwrap::gx::getVertexAttributeFormat()
	{}
*/

/*
void ogcwrap::gx::getVertexAttributeFormatList()
	{}
*/

/*
void ogcwrap::gx::getVertexDescriptor()
	{}
*/

void ogcwrap::gx::getVertexDescriptorList(GXVtxDesc * desclist)
	{ GX_GetVtxDescv(attrlist); }
void ogcwrap::gx::setArray(gx_vertex_attribute_t attr, void * array, u8 stride)
	{ GX_SetArray(mcast(u8, attr), array, stride); }

void ogcwrap::gx::setChannelCount(u8 count)
	{ GX_SetChanCount(count); }

void ogcwrap::gx::setColorChannelControl(gx_color_channel_t channel, bool light_enable, GXColor ambient, GXColor material, u8 lights, gx_diffuse_function_t diff, gx_attenuation_function_t attn)
	{ GX_SetChanCtrl(mcast(s32, channel), light_enable, ambient, material, lights, mcast(u8, diff), mcast(u8, attn)); }

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

void initTextureCacheRegion(GXTexRegion * region, bool is32bmip, void * texmemEven, gx_texture_cache_size_t sizeEven, void * texmemOdd, gx_texture_cache_size_t sizeOdd)
	{ GX_InitTexCacheRegion(region, is32bmip, mcast(u32, texmemEven), mcast(u8, sizeEven), mcast(u32, texmemOdd), mcast(u8, sizeOdd)); }

void initTexturePreloadRegion(GXTexRegion * region, void * texmemEven, u32 sizeEven, void * texmemOdd, u32 sizeOdd);
	{ GX_InitTexPreloadRegion(region, mcast(u32, texmemEven), sizeEven, mcast(u32, texmemOdd), sizeOdd); }

void ogcwrap::gx::initTextureObject(GXTexObj *			obj,
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
	{ GX_InitTlutRegion(region, addr, size); }

void ogcwrap::gx::preloadTexture(GXTexObj * obj, GXTexRegion * region)
	{ GX_PreloadEntireTexture(obj, region); }

void ogcwrap::gx::loadTextureObject(GXTexObj * obj, gx_texture_map_index_t index)
	{ GX_LoadTexObj(obj, mcast(u8, index)); }

void ogcwrap::gx::loadTLUT(GXTlutObj * tlut, gx_tlut_index_t index)
	{ GX_LoadTLUT(tlut, mcast(u8, index)); }

void ogcwrap::gx::loadPreloadedTextureObject(GXTexObj * obj, GXTexRegion * region, gx_texture_map_index_t index)
	{ GX_LoadTexObjPreloaded(obj, region, mcast(u8, index)); }

void ogcwrap::gx::setTextureObjectData(GXTexObj * obj, void * imagebuf)
	{ GX_InitTexObjData(obj, imagebuf); }

void ogcwrap::gx::setTextureObjectUserData(GXTexObj * obj, void * data)
	{ GX_InitTexObjUserData(obj, data); }

void ogcwrap::gx::setTextureObjectTLUT(GXTexObj * obj, gx_tlut_index_t tlut)
	{ GX_InitTexObjTlut(obj, tlut); }

void ogcwrap::gx::setTextureObjectWrap(GXTexObj * obj, gx_wrap_mode_t wrapS, gx_wrap_mode_t wrapT)
	{ GX_InitTexObjWrapMode(obj, mcast(u8, wrapS), mcast(u8, wrapT)); }

void ogcwrap::gx::setTextureObjectLOD(GXTexObj * obj, gx_texture_filter_t miniFilter, gx_texture_filter_t magniFilter, f32 minLOD, f32 maxLOD, f32 bias, bool clamp, bool edgeLOD, gx_max_anisotropic_filter_t maxaniso)
{
	GX_InitTexObjFilterMode(obj, mcast(u8, miniFilter), mcast(u8, magniFilter));
	GX_InitTexObjMinLOD(obj, minLOD);
	GX_InitTexObjMaxLOD(obj, maxLOD);
	GX_InitTexObjLODBias(obj, bias);
	GX_InitTexObjBiasClamp(obj, clamp);
	GX_InitTexObjLODEdge(obj, edgeLOD);
	GX_InitTexObjLODMaxAniso(obj, mcast(u8, maxaniso));
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
	{ GX_InitTexObjLODEdge(obj, edgeLOD); }

void ogcwrap::gx::setTextureObjectLODMaxAniso(GXTexObj * obj, gx_max_anisotropic_filter_t maxaniso)
	{ GX_InitTexObjLODMaxAniso(obj, mcast(u8, maxaniso)); }

void getTextureObjectAll(GXTexObj * obj, void * * imagebuf, u16 * width, u16 * height, u8 * format, u8 * wrapS, u8 * wrapT, u8 * mipmap)
	{ GX_GetTexObjAll(obj, imagebuf, width, height, format, wrapS, wrapT, mipmap); }

void * getTextureObjectData(GXTexObj * obj)
	{ return GX_GetTexObjData(obj); }

void * getTextureObjectUserData(GXTexObj * obj)
	{ return GX_GetTexObjUserData(obj); }

u16 getTextureObjectWidth(GXTexObj * obj)
	{ return GX_GetTexObjWidth(obj); }

u16 getTextureObjectHeight(GXTexObj * obj)
	{ return GX_GetTexObjHeight(obj); }

u32 getTextureObjectFormat(GXTexObj * obj)
	{ return GX_GetTexObjFormat(obj); }

u8 getTextureObjectWrapS(GXTexObj * obj)
	{ return GX_GetTexObjWrapS(obj); }

u8 getTextureObjectWrapT(GXTexObj * obj)
	{ return GX_GetTexObjWrapT(obj); }

u32 getTextureObjectMipmap(GXTexObj * obj)
	{ return GX_GetTexObjMipmap(obj); }

void ogcwrap::gx::invalidateTextureRegion(GXTexRegion * region)
	{ GX_InvalidateTexRegion(region); }

void ogcwrap::gx::invalidateAllTextures(void)
	{ GX_InvalidateTexAll(); }

void ogcwrap::gx::texModeSync(void)
	{ GX_TexModeSync(); }

void setTEVStageCount(u8);
void setTEVOrder(gx_tev_stage_t, gx_texture_coordinate_generation_type_t, gx_texture_map_index_t, gx_color_channel_t);
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
void setTEVSwapMode(gx_tev_stage_t, gx_tev_swap_table_index_t);
void setTEVSwapModeTable(gx_tev_swap_table_index_t, gx_tev_color_channel_t);

void setTEVDirect(gx_tev_stage_t);
void setTEVIndirect(gx_tev_stage_t, gx_indirect_texture_stage_t, gx_indirect_texture_format_t, gx_indirect_texture_bias_t, gx_indirect_texture_matrix_t, gx_indirect_texture_wrap_t, gx_indirect_texture_wrap_t, bool, bool, gx_indirect_texture_alpha_bump_t);
void setTEVIndirectTile(gx_tev_stage_t, gx_indirect_texture_stage_t, u16, u16, u16, u16, gx_indirect_texture_format_t, gx_indirect_texture_matrix_t, gx_indirect_texture_bias_t, gx_indirect_texture_alpha_bump_t);
void setTEVIndirectRepeat(gx_tev_stage_t);

void setIndirectStageCount(u8);
void setIndirectTextureOrder(gx_indirect_texture_stage_t, gx_texture_coordinate_index_t, gx_texture_map_index_t);
void setIndirectTextureCoordScale(gx_indirect_texture_stage_t, gx_indirect_texture_scale_t, gx_indirect_texture_scale_t);
void setIndirectTextureMatrix(gx_indirect_texture_matrix_t, Mtx23 *, s8);
void setIndirectTextureBumpST(gx_tev_stage_t, gx_indirect_texture_stage_t, gx_indirect_texture_matrix_t);
void setIndirectTextureBumpXYZ(gx_tev_stage_t, gx_indirect_texture_stage_t, gx_indirect_texture_matrix_t);

void loadLightObject(GXLightObj *, gx_light_index_t);
void loadLightObjectIndex(u32, gx_light_index_t);

void setLightShininess(GXLightObj *, f32);
void setLightPosition(GXLightObj *, f32, f32, f32);
void setLightPosition(GXLightObj *, guPos);
void setLightDirection(GXLightObj *, f32, f32, f32);
void setLightDirection(GXLightObj *, guVector);
void setLightColor(GXLightObj *, GXColor);
void setLightDistanceAttenuation(GXLightObj *, f32, f32, gx_attenuation_function_t);
void setLightAttenuation(GXLightObj *, f32, f32, f32, f32, f32, f32);
void setLightAttenuation(GXLightObj *, guVector, guVector);
void setLightAttenuationAngle(GXLightObj *, f32, f32, f32);
void setLightAttenuationAngle(GXLightObj *, guVector);
void setLightAttenuationDistance(GXLightObj *, f32, f32, f32);
void setLightAttenuationDistance(GXLightObj *, guVector);

void setSpecularDirectionHalfAngle(GXLightObj *, f32, f32, f32, f32, f32, f32);
void setSpecularDirectionHalfAngle(GXLightObj *, guVector, guVector);
void setSpecularDirection(GXLightObj *, f32, f32, f32);
void setSpecularDirection(GXLightObj *, guVector);

void ogcwrap::gx::setLightSpot(GXLightObj * lightobj, f32 angle, gx_spot_illumination_function_t spotfn)
	{ GX_InitLightSpot(lightobj, angle, mcast(u8, spotfn)); }

/*
void ogcwrap::gx::matrixIndex()
	{}
*/

void ogcwrap::gx::setCurrentMatrix(gx_position_normal_matrix_index_t index)
	{ GX_SetCurrentMatrix(mcast(u32, index)); }

void ogcwrap::gx::loadProjectionMatrix(Mtx44 mtx, gx_projection_type_t type)
	{ GX_LoadProjectionMtx(mtx, mcast(u8, type)); }

void ogcwrap::gx::loadPosMtxImm(Mtx mtx, gx_position_normal_matrix_index_t index)
	{ GX_LoadPosMtxImm(mtx, mcast(u32, index)); }

void ogcwrap::gx::loadPosMtxIdx(u16 mtxidx, gx_position_normal_matrix_index_t index)
	{ GX_LoadPosMtxIdx(mtxidx, mcast(u32, index)); }

void ogcwrap::gx::loadNrmMtxImm(Mtx mtx, gx_position_normal_matrix_index_t index)
	{ GX_LoadNrmMtxImm(mtx, mcast(u32, index)); }

/*
void ogcwrap::gx::loadNrmMtxIdx()
	{}
*/

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

void setLineWidth(u8, gx_texture_offset_value_t);
void setPointSize(u8, gx_texture_offset_value_t);
void setBlendMode(gx_blend_mode_t, gx_blend_control_t, gx_blend_control_t, gx_logic_operation_t);
void setDitherMode(bool);
void setCullingMode(gx_culling_mode_t);
void setCoplanarMode(bool);
void setClipMode(bool);

void setPokeAlpha(bool);
void setPokeColor(bool);
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

void ogcwrap::gx::setMisc(gx_misc_token_t token, u32 value)
	{ GX_SetMisc(mcast(u32, token), value); }

u32 readClksPerVtx(void);
u32 getOverflowCount(void);
u32 resetOverflowCount(void);
void readBoundingBox(u16 *, u16 *, u16 *, u16 *);

lwp_t getCurrentThread(void);
lwp_t setCurrentThread(void);
volatile void * redirectWriteGatherPipe(void *);
void restoreWriteGatherPipe(void);
void setGPMetric(gx_performance_counter_0_metric_t, gx_performance_counter_1_metric_t);
void readGPMetric(u32 *, u32 *);
void clearGPMetric(void);
void initXfRasMetric(void);
void readXfRasMetric(u32 *, u32 *, u32 *, u32 *);
void setVCacheMetric(gx_vertex_cache_metric_t);
void readVCacheMetric(u32 *, u32 *, u32 *);
void clearVCacheMetric(void);