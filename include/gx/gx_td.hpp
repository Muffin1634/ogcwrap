#pragma once
#ifndef wrap_gx_td_h
#define wrap_gx_td_h

namespace ogcwrap
{
	namespace gx
	{
		// Vertex enums

		typedef enum gx_vertex_format_t
		{

		} VertexFormat;

		typedef enum gx_vertex_attribute_t
		{

		} VertexAttribute;

		typedef enum gx_vertex_component_type_t
		{

		} VertexComponentType;

		typedef enum gx_vertex_component_format_t
		{

		} VertexComponentFormat;

		typedef enum gx_vertex_descriptor_t
		{

		} VertexDescriptor;

		// Color enums

		typedef enum gx_color_channel_t
		{
			/* values */
		} ColorChannel;

		typedef enum gx_diffuse_mode_t
		{
			/* values */
		} DiffuseFunction;

		typedef enum gx_attenuation_mode_t
		{
			/* values */
		} AttenuationFunction;

		// Texture enums

		typedef enum gx_texture_coordinate_index_t
		{
			/* values */
		} TexcoordIndex;

		typedef enum gx_texture_coordinate_generation_type_t
		{
			/* values */
		} TexcoordGenType;

		typedef enum gx_texture_coordinate_source_t
		{
			/* values */
		} TexcoordSource;

		typedef enum gx_texture_matrix_index_t
		{
			/* values */
		} TextureMatrixIndex;

		typedef enum gx_post_transform_matrix_index_t
		{
			/* values */
		} PTTMatrixIndex;

		// TEV enums

		typedef enum gx_tev_stage_t
		{
			/* values */
		} TEVStage;

		typedef enum gx_tev_combiner_equation_t
		{
			/* values */
		} TEVCombinerOp;

		typedef enum gx_tev_register_t
		{
			/* values */
		} TEVRegister;

		typedef enum gx_tev_stage_t
		{
			/* values */
		} TEVStage;

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

		typedef enum gx_projection_type_t
		{
			Perspective,

			Orthographic,
			Frustum = Orthographic
		} ProjectionMatrixType;

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