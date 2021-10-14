#pragma once
#ifndef wrap_gx_h
#define wrap_gx_h

#include <gctypes.h>
#include <ogc/gx.h>
#include <ogc/gx_struct.h>

#include "gx/gx_td.hpp"

namespace ogcwrap::gx
{
	// library management
	GXFifoObj * init(void * base_addr, u32 size);

	// callbacks
	GXDrawSyncCallback setDrawSyncCallback(GXDrawSyncCallback cb);
	GXDrawDoneCallback setDrawDoneCallback(GXDrawDoneCallback cb);
	GXBreakPtCallback setBreakPtCallback(GXBreakPtCallback cb);
	GXTexRegionCallback setTexRegionCallback(GXTexRegionCallback cb);
	GXTlutRegionCallback setTLUTRegionCallback(GXTlutRegionCallback cb);

	// fifo
	void setFifoBase(GXFifoObj * fifo, void * base_addr, u32 size);
	void setFifoLimits(GXFifoObj * fifo, u32 high, u32 low);
	void setFifoPtrs(GXFifoObj * fifo, void * readptr, void * writeptr);
	void setCPUFifo(GXFifoObj * fifo);
	void setGPUFifo(GXFifoObj * fifo);

	void * getFifoBase(GXFifoObj * fifo);
	u32 getFifoCacheLineCount(GXFifoObj * fifo);
	u32 getFifoSize(GXFifoObj * fifo);
	u8 getFifoWrap(GXFifoObj * fifo);
	void getFifoPtrs(GXFifoObj * fifo, void * * readptr, void * * writeptr);
	void getCPUFifo(GXFifoObj * fifo);
	void getGPUFifo(GXFifoObj * fifo);

	void flushCPUFifo(void);

	// framebuffer management
	f32 getYScaleFactor(u16 efbHeight, u16 xfbHeight);
	u32 setDisplayCopyYScale(f32 scale);
	u32 setDisplayCopyYScale(u16 efbHeight, u16 xfbHeight);
	void setDisplayCopySource(u16 left, u16 top, u16 width, u16 height);
	void setDisplayCopyDest(u16 width, u16 height);
	void setDisplayCopyGamma(gx_gamma_t gamma);
	void setDisplayCopyFrame2Field(gx_copy_mode_t copymode);
	void setCopyClamp(gx_clamp_mode_t clampmode);
	void setCopyFilter(bool antialias, u8 samplepattern[12][2], bool vf, u8 vfilter[7]);
	void setCopyClear(GXColor color, u32 z);
	void copyDisplay(void * dest, bool clear);

	void setViewport(f32 left, f32 top, f32 width, f32 height, f32 near, f32 far);
	void setViewportJitter(f32 left, f32 top, f32 width, f32 height, f32 near, f32 far, gx_next_field_t next);
	void adjustForOverscan(GXRModeObj * rm_in, GXRModeObj * rm_out, u16 htrim, u16 vtrim);
	void setScissor(u16 top, u16 left, u16 width, u16 height);
	void setScissorBoxOffset(s16 xOffset, s16 yOffset);
	void setColorUpdate(bool enable);
	void setColorUpdate(bool color_enable, bool alpha_enable);
	void setAlphaUpdate(bool enable);
	void setPixelFormat(gx_pixel_format_t pixelfmt, gx_z_format_t zfmt);
	void setDestAlpha(bool enable, u8 alpha);
	void setFieldMask(bool even, bool odd);
	void setFieldMode(bool field, bool half_aspect);

	void setTextureCopySource(u16 top, u16 left, u16 width, u16 height);
	void setTextureCopyDest(u16 width, u16 height, gx_texture_format_t format, bool mipmap);
	void copyTexture(void * dest, bool clear);

	// frame management
	void abortFrame(void);
	void setDrawDone(void);
	void waitDrawDone(void);

	void syncPixelMode(void);
	void clearBoundingBox(void);

	// fog
	void setFog(gx_fog_equation_t equation, f32 startZ, f32 endZ, f32 nearZ, f32 farZ, GXColor color);
	void setFogColor(GXColor color);
	void setFogRangeAdjustment(bool enable, u16 center, GXFogAdjTbl * table);

	// vertex management
	void invalidateVertexCache(void);
	void clearVertexDescriptors(void);

	void setVertexAttributeFormat(gx_vertex_format_t format, gx_vertex_attribute_t attr, gx_vertex_component_type_t comptype, gx_vertex_component_format_t compfmt, u8 fracbits);
	void setVertexAttributeFormatList(gx_vertex_format_t format, GXVtxAttrFmt * attrlist);
	void setVertexDescriptor(gx_vertex_attribute_t attr, gx_vertex_descriptor_t type);
	void setVertexDescriptorList(GXVtxDesc * desc);

//  void getVertexAttributeFormat();
//  void getVertexAttributeFormatList();
//  void getVertexDescriptor();
	void getVertexDescriptorList(GXVtxDesc * desclist);

	void setArray(gx_vertex_attribute_t attr, void * array, u8 stride);

	// color management
	void setChannelCount(u8 count);
	void setColorChannelControl(gx_color_channel_t channel, bool light_enable, GXColor ambient, GXColor material, u8 lights, gx_diffuse_function_t diff, gx_attenuation_function_t attn);
	void setColorChannelAmbient(gx_color_channel_t channel, GXColor color);
	void setColorChannelMaterial(gx_color_channel_t channel, GXColor color);

	// texture management
	void setTexGenCount(u8 count);
	void setTexCoordGen(gx_texture_coordinate_index_t coordindex, gx_texture_coordinate_generation_type_t type, gx_texture_coordinate_source_t source, gx_texture_matrix_index_t index, bool normalize = false, gx_post_transform_matrix_index_t ptfindex = mcast(gx_post_transform_matrix_index_t, 0));
	void setTexCoordScale(gx_texture_coordinate_index_t coordindex, bool autoscale, u16 scaleS = 1, u16 scaleT = 1);
	void setTexCoordBias(gx_texture_coordinate_index_t coordindex, bool biasS, bool biasT);
	void setTexCoordCylWrap(u8 texcoord, bool s_enable, bool t_enable);
	void setTextureOffsetStatus(gx_texture_coordinate_index_t coordindex, bool lineStatus, bool pointStatus);

	u32 getTextureBufferSize(u16 width, u16 height, gx_texture_format_t format, bool mipmapStatus, u8 maxLOD);

	void setZMode(bool comparisonEnable, gx_comparison_t comparison, bool bufferUpdate);
	void setZTexture(gx_z_texture_operator_t op, gx_z_texture_format_t format, u32 bias);
	void setZCompLoc(gx_z_buffer_time_t time);

	void initTextureCacheRegion(GXTexRegion * region, bool is32bitmip, void * texmemEven, gx_texture_cache_size_t sizeEven, void * texmemOdd, gx_texture_cache_size_t sizeOdd);
	void initTexturePreloadRegion(GXTexRegion * region, void * texmemEven, u32 sizeEven, void * texmemOdd, u32 sizeOdd);

	void initTextureObject(GXTexObj * obj, void * imagebuf, u16 width, u16 height, gx_texture_format_t format, gx_wrap_mode_t wrapS, gx_wrap_mode_t wrapT, bool trilinear);
	void initTextureObjectColorIndex(GXTexObj * obj, void * imagebuf, u16 width, u16 height, gx_texture_format_t format, gx_wrap_mode_t wrapS, gx_wrap_mode_t wrapT, bool mipmap, gx_tlut_index_t tlut);
	void initTLUTObj(GXTlutObj * obj, void * LUTaddr, gx_tlut_entry_format_t format, u16 entries);
	void initTLUTRegion(GXTlutRegion * region, void * addr, u8 size);

	void preloadTexture(GXTexObj * obj, GXTexRegion * region);
	void loadTextureObject(GXTexObj * obj, gx_texture_map_index_t index);
	void loadTLUT(GXTlutObj * tlut, gx_tlut_index_t index);
	void loadPreloadedTextureObject(GXTexObj * obj, GXTexRegion * region, gx_texture_map_index_t index);

	void setTextureObjectData(GXTexObj * obj, void * imagebuf);
	void setTextureObjectUserData(GXTexObj * obj, void * data);
	void setTextureObjectTLUT(GXTexObj * obj, gx_tlut_index_t tlut);
	void setTextureObjectWrap(GXTexObj * obj, gx_wrap_mode_t, gx_wrap_mode_t);
	void setTextureObjectLOD(GXTexObj * obj, gx_texture_filter_t miniFilter, gx_texture_filter_t magniFilter, f32 minLOD, f32 maxLOD, f32 bias, bool clamp, bool edgeLOD, gx_max_anisotropic_filter_t maxaniso);
	void setTextureObjectLODFilter(GXTexObj * obj, gx_texture_filter_t miniFilter, gx_texture_filter_t magniFilter);
	void setTextureObjectLODMin(GXTexObj * obj, f32 minLOD);
	void setTextureObjectLODMax(GXTexObj * obj, f32 maxLOD);
	void setTextureObjectLODBias(GXTexObj * obj, f32 bias);
	void setTextureObjectLODBiasClamp(GXTexObj * obj, bool clamp);
	void setTextureObjectLODEdge(GXTexObj * obj, bool edgeLOD);
	void setTextureObjectLODMaxAniso(GXTexObj * obj, gx_max_anisotropic_filter_t maxaniso);

	void getTextureObjectAll(GXTexObj * obj, void * * imagebuf, u16 * width, u16 * height, u8 * format, u8 * wrapS, u8 * wrapT, u8 * mipmap);
	void * getTextureObjectData(GXTexObj * obj);
	void * getTextureObjectUserData(GXTexObj * obj);
	u16 getTextureObjectWidth(GXTexObj * obj);
	u16 getTextureObjectHeight(GXTexObj * obj);
	u32 getTextureObjectFormat(GXTexObj * obj);
	u8 getTextureObjectWrapS(GXTexObj * obj);
	u8 getTextureObjectWrapT(GXTexObj * obj);
	u32 getTextureObjectMipmap(GXTexObj * obj);

	void invalidateTextureRegion(GXTexRegion * region);
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

	void setTEVDirect(gx_tev_stage_t stage);
	void setTEVIndirect(gx_tev_stage_t stage, gx_indirect_texture_stage_t indstage, gx_indirect_texture_format_t format, gx_indirect_texture_bias_t bias, gx_indirect_texture_matrix_t mtx, gx_indirect_texture_wrap_t wrapS, gx_indirect_texture_wrap_t wrapT, bool addprev, bool modtc_mipmap, gx_indirect_texture_alpha_bump_t bump);
	void setTEVIndirectTile(gx_tev_stage_t stage, gx_indirect_texture_stage_t indstage, u16 width, u16 height, u16 repeatX, u16 repeatY, gx_indirect_texture_format_t format, gx_indirect_texture_matrix_t mtx, gx_indirect_texture_bias_t bias, gx_indirect_texture_alpha_bump_t bump);
	void setTEVIndirectRepeat(gx_tev_stage_t stage);

	void setIndirectStageCount(u8 count);
	void setIndirectTextureOrder(gx_indirect_texture_stage_t indstage, gx_texture_coordinate_index_t coordindex, gx_texture_map_index_t mapindex);
	void setIndirectTextureCoordScale(gx_indirect_texture_stage_t indstage, gx_indirect_texture_scale_t indscaleS, gx_indirect_texture_scale_t indscaleT);
	void setIndirectTextureMatrix(gx_indirect_texture_matrix_t indmtx, Mtx23 * offset, s8 scaleExp);
	void setIndirectTextureBumpST(gx_tev_stage_t stage, gx_indirect_texture_stage_t indstage, gx_indirect_texture_matrix_t indmtx);
	void setIndirectTextureBumpXYZ(gx_tev_stage_t stage, gx_indirect_texture_stage_t indstage, gx_indirect_texture_matrix_t indmtx);

	// light management
	void loadLightObject(GXLightObj * light, gx_light_index_t index);
	void loadLightObjectIndex(u32 lightelement, gx_light_index_t index);

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

#endif // wrap_gx_h