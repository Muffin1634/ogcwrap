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

		// screen
		void setViewport(f32, f32, f32, f32, f32, f32);
		void setViewportJitter(f32, f32, f32, f32, f32, f32, gx_next_field_t);
		void setLineWidth(u8, gx_texture_offset_value_t);
		void setPointSize(u8, gx_texture_offset_value_t);
		void adjustForOverscan(GXRModeObj *, GXRModeObj *, u16, u16);

		// frame management
		void abortFrame(void);
		void setDrawDone(void);
		void waitDrawDone(void);

		// vertex management
		void invVtxCache(void);
		void clearVtxDesc(void);
		void setVtxAttrFormat(gx_vertex_format_t, gx_vertex_attribute_t, gx_vertex_component_type_t, gx_vertex_component_format_t, u8);
		void setVtxAttrFormatList(gx_vertex_format_t, GXVtxAttrFmt *);
		void setVtxDescriptor(gx_vertex_attribute_t, gx_vertex_descriptor_t);
		void setVtxDescriptorList(GXVtxDesc *);

		// color management
		void setColorChannelControl(gx_color_channel_t, bool, GXColor, GXColor, u8, gx_diffuse_mode_t, gx_attenuation_mode_t);
		void setColorChannelAmbient(gx_color_channel_t, GXColor);
		void setColorChannelMaterial(gx_color_channel_t, GXColor);

		// texture management
		void setNumTexGens(gx_texture_coordinate_index_t);
		void setTexCoordGen(gx_texture_coordinate_index_t, gx_texture_coordinate_generation_type_t, gx_texture_coordinate_source, gx_texture_matrix_index_t, bool = false, gx_post_transform_matrix_index_t = (gx_post_transform_matrix_index_t)0);

		void setZMode(bool, gx_comparison_t, bool);
		void setZTexture(gx_z_texture_operator_t, gx_z_texture_format_t, u32);
		void setZCompLoc(gx_z_buffer_time_t);
		void texModeSync(void);

		// texture environment management
		void setTevOp(gx_tev_stage_t, gx_tev_combiner_operation_t);
		void setTevColor(gx_tev_register_t, GXColor);		// cast to GXColor    to avoid ambiguity
		void setTevColor(gx_tev_register_t, GXColorS10);	// cast to GXColorS10 to avoid ambiguity
		void setTevColorIn(gx_tev_stage_t, gx_tev_register_input_t, gx_tev_register_input_t, gx_tev_register_input_t, gx_tev_register_input_t);
		void setTevAlphaIn(gx_tev_stage_t, gx_tev_register_input_t, gx_tev_register_input_t, gx_tev_register_input_t, gx_tev_register_input_t);
		void setTevColorOp(gx_tev_stage_t, gx_tev_operation_t, gx_tev_bias_t, gx_tev_scale_t, bool, gx_tev_register_t);
		void setTevAlphaOp(gx_tev_stage_t, gx_tev_operation_t, gx_tev_bias_t, gx_tev_scale_t, bool, gx_tev_register_t);

		// matrices
		void setCurrentMatrix(u32);
		void loadProjectionMatrix(Mtx44, gx_projection_type_t);
		void matrixIndex(u8);

		// arrays
		void setArray(gx_vertex_attribute_t, void *, u8);

		// breakpoint
		void enableBreakPoint(void *);
		void disableBreakPoint(void);

		// other
		u16 getDrawSync();

		void setDrawSync(u16);

		// miscellaneous
		void setMisc(u32, u32);

		namespace draw
		{
			// management
			void begin(gx_primitive_t, gx_vertex_format_t, u16);
			void end(void);

			// display lists
			void beginDisplayList(void *, u32);
			u32 endDisplayList();
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
			// encode (f<-b)
			encode(gx_primitive_t);

			// decode (f->b)
			decode(gx_primitive_t);
		}
	}
}

/*******************************************************************************
 * functions
 */

using ogcwrap::gx::gx_primitive_t;

// ogcwrap::gx::detail::encode

gx_primitive_t ogcwrap::gx::detail::encode(u8 prim)
{
	switch (prim)
	{
		case 184:
			return gx_primitive_t::Points;
		case 168:
			return gx_primitive_t::Lines;
		case 176:
			return gx_primitive_t::LineStrip;
		case 144:
			return gx_primitive_t::Triangles;
		case 152:
			return gx_primitive_t::TriangleStrip;
		case 160:
			return gx_primitive_t::TriangleFan;
		case 128:
			return gx_primitive_t::Quads;

		default: // never used in practice
			return gx_primitive_t::Points;
	}
}

// ogcwrap::gx::detail::decode

u8 ogcwrap::gx::detail::decode(gx_primitive_t prim)
{
	switch (prim)
	{
		case gx_primitive_t::Points:
			return 184;
		case gx_primitive_t::Lines:
			return 168;
		case gx_primitive_t::LineStrip:
			return 176;
		case gx_primitive_t::Triangles:
			return 144;
		case gx_primitive_t::TriangleStrip:
			return 152;
		case gx_primitive_t::TriangleFan:
			return 160;
		case gx_primitive_t::Quads:
			return 128;

		default:
			return -1;
	}
}