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
		void adjustForOverscan(GXRModeObj *, GXRModeObj *, u16, u16);

		// frame management
		void abortFrame(void);
		void drawDone(void);

		void setDrawDone(void);
		void waitDrawDone(void);

		// vertex management
		void invVtxCache(void);
		void clearVtxDesc(void);
		void setVtxAttrFormat(gx_vertex_format_t, gx_vertex_attribute_t, gx_vertex_component_type_t, gx_vertex_component_size_t, u8);
		void setVtxAttrFormatList(gx_vertex_format_t, GXVtxAttrFmt *);
		void setVtxDescriptor(gx_vertex_attribute_t, gx_vertex_descriptor_t);
		void setVtxDescriptorList(GXVtxDesc *);

		// color management
		void setColorChannelControl(gx_color_channel_t, bool, GXColor, GXColor, u8, gx_diffuse_mode_t, gx_attenuation_mode_t);
		void setColorChannelAmbient(gx_color_channel_t, GXColor);
		void setColorChannelMaterial(gx_color_channel_t, GXColor);

		// texture management
		void texModeSync(void);

		// matrices
		void loadProjectionMatrix(Mtx44, gx_perspective_type_t);
		void loadPositionMatrix(Mtx, u32);
		void loadPositionMatrix(gx_position_matrix_index_t, u32);
		void loadNormalMatrix(Mtx, u32)
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
			void position(u8);
			void position(u16);

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
			void normal(u8);
			void normal(u16);

			// 3 dimensions
			void normal(s8, s8, s8);
			void normal(s16, s16, s16);
			void normal(f32, f32, f32);

			// colors

			// index (cast to u8 or u16 specifically for these overloads)
			void color(u8);
			void color(u16);

			// 1 value (RGB)
		//	void color(u16); // RGB565; not supported because of ambiguity with 1x16 overload
			void color(u32);

			// 3 values (R, G, B)
			void color(u8, u8, u8);
			void color(f32, f32, f32);

			// 4 values (R, G, B, A)
			void color(u8, u8, u8, u8);

			// textures

			// index (cast to u8 or u16 specifically for these overloads)
			void texcoord(u8);
			void texcoord(u16);

			// 1 dimension
		//	void texcoord(u8); // not supported because of ambiguity with 1x8 overload
			void texcoord(s8); // cast to s8 specifically for this overload
		//	void texcoord(u16); // not supported because of ambiguity with 1x16 overload
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

		}
	}
}

/*******************************************************************************
 * functions
 */

