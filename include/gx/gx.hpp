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
	void setDisplayCopyFrame2Field(gx_copy_mode_t mode);
	void setCopyClamp(gx_clamp_mode_t mode);
	void setCopyFilter(bool aaStatus, u8 samplePattern[12][2], bool vfStatus, u8 vfilter[7]);
	void setCopyClear(GXColor color, u32 z);
	void copyDisplay(void * dest, bool clear);

	void setViewport(f32 left, f32 top, f32 width, f32 height, f32 near, f32 far);
	void setViewportJitter(f32 left, f32 top, f32 width, f32 height, f32 near, f32 far, gx_next_field_t next);
	void adjustForOverscan(GXRModeObj * rmIn, GXRModeObj * rmOut, u16 hTrim, u16 vTrim);
	void setScissor(u16 top, u16 left, u16 width, u16 height);
	void setScissorBoxOffset(s16 xOffset, s16 yOffset);
	void setColorUpdate(bool enable);
	void setColorUpdate(bool colorEnable, bool alphaEnable);
	void setAlphaUpdate(bool enable);
	void setPixelFormat(gx_pixel_format_t pixelFmt, gx_z_format_t zFmt);
	void setDestAlpha(bool enable, u8 alpha);
	void setFieldMask(bool even, bool odd);
	void setFieldMode(bool field, bool halfAspect);

	void setTextureCopySource(u16 top, u16 left, u16 width, u16 height);
	void setTextureCopyDest(u16 width, u16 height, gx_texture_format_t format, bool mipmap);
	void copyTexture(void * dest, bool clear);

	// frame management
	void abortFrame(void);
	void setDrawDone(void);
	void waitDrawDone(void);

	void syncPixelMode(void);
	void readBoundingBox(u16 * top, u16 * bottom, u16 * left, u16 * right);
	void clearBoundingBox(void);

	// fog
	void setFog(gx_fog_equation_t equation, f32 startZ, f32 endZ, f32 nearZ, f32 farZ, GXColor color);
	void setFogColor(GXColor color);
	void setFogRangeAdjustment(bool enable, u16 center, GXFogAdjTbl * table);

	// vertex management
	void invalidateVertexCache(void);
	void clearVertexDescriptors(void);

//	void getVertexAttributeFormat(GXVtxAttrFmt * fmt);
//	void getVertexAttributeFormatList(GXVtxAttrFmt * fmtlist);
	void getVertexDescriptor(GXVtxDesc * desc);
	void getVertexDescriptorList(GXVtxDesc * desclist);

	void setVertexAttributeFormat(gx_vertex_format_t format, gx_vertex_attribute_t attr, gx_vertex_component_type_t comptype, gx_vertex_component_format_t compfmt, u8 fracbits);
	void setVertexAttributeFormatList(GXVtxAttrFmt * attrlist);
	void setVertexDescriptor(gx_vertex_attribute_t attr, gx_vertex_descriptor_t type);
	void setVertexDescriptorList(GXVtxDesc * desclist);

	void setArray(gx_vertex_attribute_t attr, void * array, u8 stride);

	// color management
	void setChannelCount(u8 count);
	void setColorChannelControl(gx_color_channel_t channel, bool lightEnable, u8 ambient, u8 material, u8 lights, gx_diffuse_function_t diff, gx_attenuation_function_t attn);
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
	void setTEVStageCount(u8 count);
	void setTEVOrder(gx_tev_stage_t stage, gx_texture_coordinate_generation_index_t texcoord, gx_texture_map_index_t texmap, gx_color_channel_t channel);
	void setTEVOp(gx_tev_stage_t stage, gx_tev_combiner_equation_t tevmode);
	void setTEVColor(gx_tev_register_t tevreg, GXColor color);		// cast to GXColor    to avoid ambiguity
	void setTEVColor(gx_tev_register_t tevreg, GXColorS10 color);	// cast to GXColorS10 to avoid ambiguity
	void setTEVColorIn(gx_tev_stage_t stage, gx_tev_register_input_t regA, gx_tev_register_input_t regB, gx_tev_register_input_t regC, gx_tev_register_input_t regD);
	void setTEVAlphaIn(gx_tev_stage_t stage, gx_tev_register_input_t regA, gx_tev_register_input_t regB, gx_tev_register_input_t regC, gx_tev_register_input_t regD);
	void setTEVColorOp(gx_tev_stage_t stage, gx_tev_combiner_operator_t tevop, gx_tev_bias_t bias, gx_tev_scale_t scale, bool clamp, gx_tev_register_t tevreg);
	void setTEVAlphaOp(gx_tev_stage_t stage, gx_tev_combiner_operator_t tevop, gx_tev_bias_t bias, gx_tev_scale_t scale, bool clamp, gx_tev_register_t tevreg);
	void setTEVAlphaCompare(gx_comparison_t lcomp, u8 lref, gx_alpha_operation_t alphaop, gx_comparison_t rcomp, u8 rref);
	void setTEVKColor(gx_tev_register_t tevreg, GXColor color);		// cast to GXColor    to avoid ambiguity
	void setTEVKColor(gx_tev_register_t tevreg, GXColorS10 color);	// cast to GXColorS10 to avoid ambiguity
	void selectTEVKColor(gx_tev_stage_t stage, gx_tev_constant_color_selection_t colorsel);
	void selectTEVKAlpha(gx_tev_stage_t stage, gx_tev_constant_alpha_selection_t alphasel);
	void setTEVSwapMode(gx_tev_stage_t stage, gx_tev_swap_table_index_t);
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

	void setLightPosition(GXLightObj * light, f32 posX, f32 posY, f32 posZ);
	void setLightPosition(GXLightObj * light, guVector position);
	void setLightDirection(GXLightObj * light, f32 nrmX, f32 nrmY, f32 nrmZ);
	void setLightDirection(GXLightObj * light, guVector normal);
	void setLightColor(GXLightObj * light, GXColor color);
	void setLightDistanceAttenuation(GXLightObj * light, f32 distance, f32 brightness, gx_attenuation_function_t distfn);
	void setLightAttenuation(GXLightObj * light, f32 ac1, f32 ac2, f32 ac3, f32 dc1, f32 dc2, f32 dc3);
	void setLightAttenuationAngle(GXLightObj * light, f32 ac1, f32 ac2, f32 ac3);
	void setLightAttenuationDistance(GXLightObj * light, f32 dc1, f32 dc2, f32 dc3);
	void setLightShininess(GXLightObj * light, f32 shininess);

	void setSpecularDirectionHalfAngle(GXLightObj * light, f32 nrmX, f32 nrmY, f32 nrmZ, f32 haX, f32 haY, f32 haZ);
	void setSpecularDirectionHalfAngle(GXLightObj * light, guVector normal, guVector halfangle);
	void setSpecularDirection(GXLightObj * light, f32 nrmX, f32 nrmY, f32 nrmZ);
	void setSpecularDirection(GXLightObj * light, guVector normal);

	void setLightSpot(GXLightObj * light, f32 angle, gx_spot_illumination_function_t spotfn);

	// matrices
	void matrixIndex(u8 index);
	void setCurrentMatrix(gx_position_normal_matrix_index_t index);

	void loadProjectionMatrix(Mtx44 mtx, gx_projection_type_t);
	void loadPosMtxImm(Mtx mtx, gx_position_normal_matrix_index_t index);
	void loadPosMtxIdx(u16 mtxidx, gx_position_normal_matrix_index_t index);
	void loadNrmMtxImm(Mtx mtx, gx_position_normal_matrix_index_t index);
	void loadNrmMtxIdx(u16 mtxidx, gx_position_normal_matrix_index_t index);
	void loadNrmMtxImm3x3(Mtx33 mtx, gx_position_normal_matrix_index_t index);
	void loadNrmMtxIdx3x3(u16 mtxidx, gx_position_normal_matrix_index_t index);
	void loadTexMtxImm(Mtx mtx, gx_texture_matrix_index_t index, gx_texture_matrix_type_t type);
	void loadTexMtxIdx(u16 mtxidx, gx_texture_matrix_index_t index, gx_texture_matrix_type_t type);

	// breakpoint
	void enableBreakPoint(void * addr);
	void disableBreakPoint(void);

	// drawing settings
	void setLineWidth(u8 width, gx_texture_offset_value_t texfmt);
	void setPointSize(u8 width, gx_texture_offset_value_t texfmt);
	void setBlendMode(gx_blend_mode_t type, gx_blend_control_t sourceFactor, gx_blend_control_t destFactor, gx_logic_operation_t op);
	void setCullingMode(gx_culling_mode_t mode);
	void setCoplanarMode(bool enable);
	void setClipMode(bool enable);
	void setDitherMode(bool enable);

	// poke/peek
	void setPokeColor(bool enable);
	void setPokeAlpha(bool enable);
	void setPokeDither(bool enable);

	void pokeAlphaMode(gx_comparison_t comp, u8 threshold);
	void pokeBlendMode(gx_blend_mode_t type, gx_blend_control_t sourceFactor, gx_blend_control_t destFactor, gx_logic_operation_t op);
	void pokeZMode(bool comp, gx_comparison_t compfn, bool update);

	void pokeAlphaRead(gx_alpha_read_mode_t mode);
	void pokeDestAlpha(bool enable, u8 constAlpha);

	void pokeRGBA(u16 x, u16 y, GXColor color);
	void pokeZ(u16 x, u16 y, u32 z);

	void peekRGBA(u16 x, u16 y, GXColor * color);
	void peekZ(u16 x, u16 y, u32 * z);

	// miscellaneous
	void setMisc(gx_misc_token_t token, u32 value);

	void getGPStatus(u8 * overHigh, u8 * underLow, u8 * readIdle, u8 * cmdIdle, u8 * breakpt);
	u32 readClksPerVtx(void);

	u32 getOverflowCount(void);
	u32 resetOverflowCount(void);

	lwp_t getCurrentThread(void);
	lwp_t setCurrentThread(void);

	volatile void * redirectWriteGatherPipe(void * tempPipe);
	void restoreWriteGatherPipe(void);

	void setGPMetric(gx_performance_counter_0_metric_t pc0metric, gx_performance_counter_1_metric_t pc0metric);
	void readGPMetric(u32 * pc0metric, u32 * pc0metric);
	void clearGPMetric(void);
	void initXfRasMetric(void);
	void readXfRasMetric(u32 * xfWaitIn, u32 * xfWaitOut, u32 * rasBusy, u32 * clocks);
	void setVCacheMetric(gx_vertex_cache_metric_t vtxMetric);
	void readVCacheMetric(u32 * check, u32 * miss, u32 * stall);
	void clearVCacheMetric(void);

	namespace draw
	{
		// management
		void begin(gx_primitive_t primitive, gx_vertex_format_t vtxfmt, u16 count);
		void end(void);

		u16 getDrawSync(void);
		void setDrawSync(u16 token);

		// display lists
		void beginDisplayList(void * buf, u32 bufsize);
		u32 endDisplayList(void);
		void callDisplayList(void * list, u32 listSize);

		// positions

		// index (cast to u8 or u16 specifically for these overloads)
		void indexedPosition(u8 index);
		void indexedPosition(u16 index);

		// 2 dimensions (implied z coordinate of 0)
		void position(u8 x, u8 y);
		void position(s8 x, s8 y);
		void position(u16 x, u16 y);
		void position(s16 x, s16 y);
		void position(f32 x, f32 y);

		// 3 dimensions
		void position(u8 x, u8 y, u8 z);
		void position(s8 x, s8 y, s8 z);
		void position(u16 x, u16 y, u16 z);
		void position(s16 x, s16 y, s16 z);
		void position(f32 x, f32 y, f32 z);

		// normals

		// index (cast to u8 or u16 specifically for these overloads)
		void indexedNormal(u8 index);
		void indexedNormal(u16 index);

		// 3 dimensions
		void normal(s8 nrmX, s8 nrmY, s8 nrmZ);
		void normal(s16 nrmX, s16 nrmY, s16 nrmZ);
		void normal(f32 nrmX, f32 nrmY, f32 nrmZ);

		// colors

		// index (cast to u8 or u16 specifically for these overloads)
		void indexedColor(u8 index);
		void indexedColor(u16 index);

		// 1 value (RGB)
		void color(u16 rgb565); // RGB565
		void color(u32 rgba8); // RGBA8

		// 3 values (R, G, B)
		void color(u8 r, u8 g, u8 b);
		void color(f32 r, f32 g, f32 b);

		// 4 values (R, G, B, A)
		void color(u8 r, u8 g, u8 b, u8 a);

		// textures

		// index (cast to u8 or u16 specifically for these overloads)
		void indexedTexcoord(u8 index);
		void indexedTexcoord(u16 index);

		// 1 dimension
		void texcoord(u8 s); // cast to u8 specifically for this overload
		void texcoord(s8 s); // cast to s8 specifically for this overload
		void texcoord(u16 s); // cast to u16 specifically for this overload
		void texcoord(s16 s); // cast to s16 specifically for this overload
		void texcoord(f32 s);

		// 2 dimensions
		void texcoord(u8 s, u8 t);
		void texcoord(s8 s, s8 t);
		void texcoord(u16 s, u16 t);
		void texcoord(s16 s, s16 t);
		void texcoord(f32 s, f32 t);
}

#endif // wrap_gx_h