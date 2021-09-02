/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap
{
	namespace gx
	{
		// library management
		GXFifoObj * init(void *, u32);

		// callbacks
		GXDrawSyncCallback setDrawSyncCallback(GXDrawSyncCallback);
		GXDrawDoneCallback setDrawDoneCallback(GXDrawDoneCallback);
		GXBreakPtCallback setBreakPtCallback(GXBreakPtCallback);

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

		void flush(void);

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
		void setTextureCopyDest(u16, u16, gx_texture_format_t);
		void copyTexture(void *, bool);

		// frame management
		void abortFrame(void);
		void setDrawDone(void);
		void waitDrawDone(void);

		void syncPixelMode(void);
		void clearBoundingBox(void);

		// fog
		void setFog(gx_fog_type_t, f32, f32, f32, f32, GXColor);
		void setFogRangeAdjustment(GXFogAdjTbl *, u16, Mtx44 *);

		// vertex management
		void invVtxCache(void);
		void clearVtxDesc(void);
		void setVtxAttrFormat(gx_vertex_format_t, gx_vertex_attribute_t, gx_vertex_component_type_t, gx_vertex_component_format_t, u8);
		void setVtxAttrFormatList(gx_vertex_format_t, GXVtxAttrFmt *);
		void setVtxDescriptor(gx_vertex_attribute_t, gx_vertex_descriptor_t);
		void setVtxDescriptorList(GXVtxDesc *);

		// color management
		void setChannelCount(u8);
		void setColorChannelControl(gx_color_channel_t, bool, GXColor, GXColor, u8, gx_diffuse_mode_t, gx_attenuation_mode_t);
		void setColorChannelAmbient(gx_color_channel_t, GXColor);
		void setColorChannelMaterial(gx_color_channel_t, GXColor);

		// texture management
		void setNumTexGens(gx_texture_coordinate_index_t);
		void setTexCoordGen(gx_texture_coordinate_index_t, gx_texture_coordinate_generation_type_t, gx_texture_coordinate_source_t, gx_texture_matrix_index_t, bool = false, gx_post_transform_matrix_index_t = (gx_post_transform_matrix_index_t)0);
		void setTexCoordScale(gx_texture_coordinate_index_t, bool, u16 = 1, u16 = 1);
		void setTexCoordCylWrap(u8, bool, bool);
		void setTextureOffsetStatus(gx_texture_coordinate_index_t, bool, bool);

		u32 getTextureBufferSize(u16, u16, gx_texture_format_t, bool, u8);

		void setZMode(bool, gx_comparison_t, bool);
		void setZTexture(gx_z_texture_operator_t, gx_z_texture_format_t, u32);
		void setZCompLoc(gx_z_buffer_time_t);

		void initTextureCacheRegion(GXTexRegion *, bool, void *, gx_texture_cache_size_t, void *, gx_texture_size_t);
		void initTexturePreloadRegion(GXTexRegion *, u8, gx_texture_cache_size_t, u8, gx_texture_size_t);

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
		void setTevStageCount(u8);
		void setTevOrder(gx_tev_stage_t, gx_texture_coordinate_generation_type_t, gx_texture_map_index_t, gx_color_channel_t);
		void setTevOp(gx_tev_stage_t, gx_tev_combiner_operation_t);
		void setTevColor(gx_tev_register_t, GXColor);			// cast to GXColor    to avoid ambiguity
		void setTevColor(gx_tev_register_t, GXColorS10);		// cast to GXColorS10 to avoid ambiguity
		void setTevColorIn(gx_tev_stage_t, gx_tev_register_input_t, gx_tev_register_input_t, gx_tev_register_input_t, gx_tev_register_input_t);
		void setTevAlphaIn(gx_tev_stage_t, gx_tev_register_input_t, gx_tev_register_input_t, gx_tev_register_input_t, gx_tev_register_input_t);
		void setTevColorOp(gx_tev_stage_t, gx_tev_operation_t, gx_tev_bias_t, gx_tev_scale_t, bool, gx_tev_register_t);
		void setTevAlphaOp(gx_tev_stage_t, gx_tev_operation_t, gx_tev_bias_t, gx_tev_scale_t, bool, gx_tev_register_t);
		void setTevAlphaCompare(gx_comparison_t, u8, gx_alpha_operation_t, gx_comparison_t, u8);
		void setTevKColor(gx_tev_constant_register_t, GXColor);		// cast to GXColor    to avoid ambiguity
		void setTevKColor(gx_tev_constant_register_t, GXColorS10);	// cast to GXColorS10 to avoid ambiguity
		void selectTevKColor(gx_tev_stage_t, gx_tev_constant_register_t);
		void selectTevKAlpha(gx_tev_stage_t, gx_tev_constant_register_t);
		void setTevSwapMode(gx_tev_stage_t, gx_tev_swap_table_index_t);
		void setTevSwapModeTable(gx_tev_swap_table_index_t, gx_tev_color_channel_t);

		// indirect textures, as a subset

		void setTevDirect(void);
		void setTevIndirect(gx_tev_stage_t, gx_indirect_texture_stage_t, gx_indirect_texture_format_t, gx_indirect_texture_bias_t, gx_indirect_texture_matrix_t, gx_indirect_texture_wrap_t, gx_indirect_texture_wrap_t, bool, bool, gx_indirect_texture_alpha_bump_t);
		void setTevIndirectTile(gx_tev_stage_t, gx_indirect_texture_stage_t, u16, u16, u16, u16, gx_indirect_texture_format_t, gx_indirect_texture_matrix_t, gx_indirect_texture_bias_t, gx_indirect_texture_alpha_bump_t);
		void setTevIndirectRepeat(gx_tev_stage_t);

		void setIndirectStageCount(u8);
		void setIndirectTextureOrder(gx_indirect_texture_stage_t, gx_texture_coordinate_index_t, gx_texture_map_index_t);
		void setIndirectTextureCoordScale(gx_indirect_texture_stage_t, gx_indirect_texture_scale_t, gx_indirect_texture_scale_t);
		void setIndirectTextureMatrix(gx_indirect_texture_matrix_t, Mtx23 *, s8);
		void setIndirectTextureBumpST(gx_tev_stage_t, gx_indirect_texture_stage_t, gx_indirect_texture_matrix_t);
		void setIndirectTextureBumpXYZ(gx_tev_stage_t, gx_indirect_texture_stage_t, gx_indirect_texture_matrix_t);

		// matrices
		void setCurrentMatrix(u32);
		void loadProjectionMatrix(Mtx44, gx_projection_type_t);
		void matrixIndex(u8);

		// arrays
		void setArray(gx_vertex_attribute_t, void *, u8);

		// breakpoint
		void enableBreakPoint(void *);
		void disableBreakPoint(void);

		// drawing stuff?
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
}

/*******************************************************************************
 * functions
 */

using ogcwrap::gx::gx_primitive_t;
