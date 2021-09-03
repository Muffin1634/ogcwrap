#pragma once
#ifndef wrap_gx_td_h
#define wrap_gx_td_h

namespace ogcwrap
{
	namespace gx
	{
		// Framebuffer enums

		typedef enum gx_gamma_t
		{
			g10,
			g17,
			g22
		} GammaValue;

		typedef enum gx_copy_mode_t
		{
			Progressive,

			InterlacedEven = 2,
			InterlacedOdd
		} EFBCopyMode;

		typedef enum gx_clamp_mode_t
		{
			None,
			Top,
			Bottom
		} ClampMode;

		typedef enum gx_next_field_t
		{
			InterlacedEven,
			InterlacedOdd
		} NextField;

		typedef enum gx_pixel_format_t
		{
			rgb8z24,
			rgba6z24,

			rgb565z16
		} PixelFormat;

		typedef enum gx_z_format_t
		{
			Linear,
			Near,
			Mid,
			Far
		} CompressedZFormat;

		// Vertex enums

		typedef enum gx_vertex_format_t
		{
			Format0,
			Format1,
			Format2,
			Format3,
			Format4,
			Format5,
			Format6,
			Format7,

			MaxVF
		} VertexFormat;

		typedef enum gx_vertex_attribute_t
		{
			Position,
			Normal,
			Color,
			TexCoord
		} VertexAttribute;

		typedef enum gx_vertex_component_type_t
		{
			posXY,
			posXYZ,

			nrmXYZ = 0,
			nrmNBT,
			nrmNBT3,

			clrRGB = 0,
			clrRGBA,

			texS = 0,
			texST
		} VertexComponentType;

		typedef enum gx_vertex_component_format_t
		{
			u8,
			s8,
			u16,
			s16,
			f32,

			rgb565 = 0,
			rgb8,
			rgbx8,
			rgba4,
			rgba6,
			rgba8
		} VertexComponentFormat;

		typedef enum gx_vertex_descriptor_t
		{
			None,
			Direct,
			Index8,
			Index16
		} VertexDescriptor;

		// Color enums

		typedef enum gx_color_channel_t
		{
			Color0,
			Color1,

			Alpha0,
			Alpha1,

			C0A0,
			C1A1,

			Czero, // not Color0
			Abump,
			AbumpN,
			Cnull = 255
		} ColorChannel;

		typedef enum gx_diffuse_function_t
		{
			None,
			Signed,
			Clamp
		} DiffuseFunction;

		typedef enum gx_attenuation_function_t
		{
			Specular,
			Spot,
			None
		} AttenuationFunction;

		// Texture enums

		typedef enum gx_texture_coordinate_index_t
		{
			TexCoord0,
			TexCoord1,
			TexCoord2,
			TexCoord3,
			TexCoord4,
			TexCoord5,
			TexCoord6,
			TexCoord7,

			MaxTexCoord,
			TexCoordNull = 255
		} TexcoordIndex;

		typedef enum gx_texture_coordinate_generation_type_t
		{
			Mtx2x4,
			Mtx3x4,

			Bump0,
			Bump1,
			Bump2,
			Bump3,
			Bump4,
			Bump5,
			Bump6,
			Bump7,

			SRTG
		} TexcoordGenType;

		typedef enum gx_texture_coordinate_source_t
		{
			Texture0,
			Texture1,
			Texture2,
			Texture3,
			Texture4,
			Texture5,
			Texture6,
			Texture7,

			TexCoord0
		} TexcoordSource;

		typedef enum gx_texture_matrix_index_t
		{
			/* values */
		} TextureMatrixIndex;

		typedef enum gx_post_transform_matrix_index_t
		{
			/* values */
		} PTFMatrixIndex;

		typedef enum gx_texture_format_t
		{
			/* values */
		} TextureFormat;

		typedef enum gx_comparison_t
		{
			/* values */
		} ComparisonType;

		typedef enum gx_z_texture_operator_t
		{
			Disable,
			Add,
			Replace,

			MaxZTOp
		} ZTextureOperator;

		typedef enum gx_z_texture_format_t
		{
			/* values */
		} ZTextureFormat;

		typedef enum gx_z_buffer_time_t
		{
			/* values */
		} ZBufferTime;

		typedef enum gx_texture_cache_size_t
		{
			/* values */
		} TextureCacheSize;

		typedef enum gx_texture_size_t
		{
			/* values */
		} TextureSize;

		typedef enum gx_tlut_index_t
		{
			/* values */
		} TLUTIndex;

		typedef enum gx_tlut_entry_format_t
		{
			/* values */
		} TLUTEntryFormat;

		typedef enum gx_texture_map_index_t
		{
			/* values */
		} TextureMapIndex;

		typedef enum gx_texture_filter_t
		{
			/* values */
		} TextureFilter;

		typedef enum gx_max_anisotropic_filter_t
		{
			/* values */
		} MaxAnisoFilter;

		// TEV enums

		typedef enum gx_tev_stage_t
		{
			Stage0,
			Stage1,
			Stage2,
			Stage3,
			Stage4,
			Stage5,
			Stage6,
			Stage7,
			Stage8,
			Stage9,
			Stage10,
			Stage11,
			Stage12,
			Stage13,
			Stage14,
			Stage15,
			MaxStages
		} TEVStage;

		typedef enum gx_tev_combiner_equation_t
		{
			/* values */
		} TEVCombinerOp;

		typedef enum gx_tev_register_t
		{
			/* values */
		} TEVRegister;

		typedef enum gx_tev_register_input_t
		{
			/* values */
		} TEVRegisterInput;

		typedef enum gx_tev_operation_t
		{
			/* values */
		} TEVOperation;

		typedef enum gx_tev_bias_t
		{
			/* values */
		} TEVBias;

		typedef enum gx_tev_scale_t
		{
			/* values */
		} TEVScale;

		typedef enum gx_alpha_operation_t
		{
			/* values */
		} AlphaOperation;

		typedef enum gx_tev_constant_register_t
		{
			/* values */
		} TEVKonstRegister;

		typedef enum gx_tev_swap_table_index_t
		{
			/* values */
		} TEVSwapTableIndex;

		// indirect textures, as a subset

		typedef enum gx_indirect_texture_stage_t
		{
			/* values */
		} IndirectTextureStage;

		typedef enum gx_indirect_texture_format_t
		{
			/* values */
		} IndirectTextureFormat;

		typedef enum gx_indirect_texture_bias_t
		{
			/* values */
		} IndirectTextureBias;

		typedef enum gx_indirect_texture_matrix_t
		{
			/* values */
		} IndirectTextureMatrix;

		typedef enum gx_indirect_texture_wrap_t
		{
			/* values */
		} IndirectTextureWrap;

		typedef enum gx_indirect_texture_alpha_bump_t
		{
			/* values */
		} IndirectTextureAlphaBump;

		typedef enum gx_indirect_texture_scale_t
		{
			/* values */
		} IndirectTextureScale;

		// lights

		typedef enum gx_light_index_t
		{
			/* values */
		} LightIndex;

		typedef enum gx_light_object_index_t
		{
			/* values */
		} LightObjectIndex;

		typedef enum gx_spot_illumination_function_t
		{
			/* values */
		} SpotIlluminationFunction;

		// matrix enums

		typedef enum gx_projection_type_t
		{
			Perspective,

			Orthographic,
			Frustum = Orthographic
		} ProjectionMatrixType;

		// other

		typedef enum gx_texture_offset_value_t
		{
			/* values */
		} TextureOffsetValue;

		typedef enum gx_blend_mode_t
		{
			/* values */
		} BlendMode;

		typedef enum gx_blend_control_t
		{
			/* values */
		} BlendControl;

		typedef enum gx_logic_operation_t
		{
			/* values */
		} LogicalOperation;

		typedef enum gx_culling_mode_t
		{
			/* values */
		} CullingMode;

		typedef enum gx_alpha_read_mode_t
		{
			/* values */
		} AlphaReadMode;

		// metrics

		typedef enum gx_performance_counter_0_metric_t
		{
			/* values */
		} PerfCounter0Metric;

		typedef enum gx_performance_counter_1_metric_t
		{
			/* values */
		} PerfCounter1Metric;

		typedef enum gx_vertex_cache_metric_t
		{
			/* values */
		} VertexCacheMetric;

		// drawing

		typedef enum gx_primitive_t
		{
			Points = 184,

			Lines = 168,
			LineStrip = 176,

			Triangles = 144,
			TriangleStrip = 152,
			TriangleFan = 160,

			Quads = 128
		} GXPrimitive;
	}
}

#endif // wrap_gx_td_h