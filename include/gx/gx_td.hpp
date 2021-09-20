#pragma once
#ifndef wrap_gx_td_h
#define wrap_gx_td_h

namespace ogcwrap::gx
{
	// Framebuffer enum structs

	typedef enum struct gx_gamma_t
	{
		g10,
		g17,
		g22
	} GammaValue;

	typedef enum struct gx_copy_mode_t
	{
		Progressive,

		InterlacedEven = 2,
		InterlacedOdd
	} EFBCopyMode;

	typedef enum struct gx_clamp_mode_t
	{
		None,
		Top,
		Bottom
	} ClampMode;

	typedef enum struct gx_next_field_t
	{
		InterlacedEven,
		InterlacedOdd
	} NextField;

	typedef enum struct gx_pixel_format_t
	{
		rgb8z24,
		rgba6z24,

		rgb565z16
	} PixelFormat;

	typedef enum struct gx_z_format_t
	{
		Linear,
		Near,
		Mid,
		Far
	} CompressedZFormat;

	// Fog enum struct

	typedef enum struct gx_fog_equation_t
	{
		None,

		PerspectiveLinear = 2,
		PerspectiveExponential = 4,
		PerspectiveExpSquared,
		PerspectiveReverseExp,
		PerspectiveReverseExpSquared,

		OrthographicLinear = 10,
		OrthographicExponential = 12,
		OrthographicExpSquared,
		OrthographicReverseExp,
		OrthographicReverseExpSquared,

		Linear = PerspectiveLinear,
		Exponential = PerspectiveExponential,
		ExpSquared = PerspectiveExpSquared,
		ReverseExp = PerspectiveReverseExp,
		ReverseExpSquared = PerspectiveReverseExpSquared
	} FogEquation;

	// Vertex enum structs

	typedef enum struct gx_vertex_format_t
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

	typedef enum struct gx_vertex_attribute_t
	{
		Position,
		Normal,
		Color,
		TexCoord
	} VertexAttribute;

	typedef enum struct gx_vertex_component_type_t
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

	typedef enum struct gx_vertex_component_format_t
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

	typedef enum struct gx_vertex_descriptor_t
	{
		None,
		Direct,
		Index8,
		Index16
	} VertexDescriptor;

	// Color enum structs

	typedef enum struct gx_color_channel_t
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

	typedef enum struct gx_diffuse_function_t
	{
		None,
		Signed,
		Clamp
	} DiffuseFunction;

	typedef enum struct gx_attenuation_function_t
	{
		None = 2,
		Specular = 0,
		Spot
	} AttenuationFunction;

	// Texture enum structs

	typedef enum struct gx_texture_coordinate_index_t
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

	typedef enum struct gx_texture_coordinate_generation_type_t
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

	typedef enum struct gx_texture_coordinate_source_t
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

	typedef enum struct gx_texture_matrix_index_t
	{
		TexMtxIdentity = 60,

		TexMtx0 = 30,
		TexMtx1 = 33,
		TexMtx2 = 36,
		TexMtx3 = 39,
		TexMtx4 = 42,
		TexMtx5 = 45,
		TexMtx6 = 48,
		TexMtx7 = 51,
		TexMtx8 = 54,
		TexMtx9 = 57
	} TextureMatrixIndex;

	typedef enum struct gx_post_transform_matrix_index_t
	{
		STCG1, // used in ::setCoordTexGen()

		PTFMtxIdentity = 125,

		PTFMtx0 = 64,
		PTFMtx1 = 67,
		PTFMtx2 = 70,
		PTFMtx3 = 73,
		PTFMtx4 = 76,
		PTFMtx5 = 79,
		PTFMtx6 = 82,
		PTFMtx7 = 85,
		PTFMtx8 = 88,
		PTFMtx9 = 91,
		PTFMtx10 = 94,
		PTFMtx11 = 97,
		PTFMtx12 = 100,
		PTFMtx13 = 103,
		PTFMtx14 = 106,
		PTFMtx15 = 109,
		PTFMtx16 = 112,
		PTFMtx17 = 115,
		PTFMtx18 = 118,
		PTFMtx19 = 121
	} PTFMatrixIndex;

	typedef enum struct gx_texture_format_t
	{
		i4, // intensity
		i8,
		ia4, // intensity alpha
		ia8,
		rgb565,
		rgb5a3,
		rgba8,

		Palette4 = 8,
		Palette8,
		Palette14,

		Compressed = 14
	} TextureFormat;

	typedef enum struct gx_comparison_t
	{
		Never,
		Less,
		LEqual = 3,
		NEqual = 5,
		Equal = 2,
		GEqual = 6,
		Greater = 4,
		Always = 7
	} ComparisonType;

	typedef enum struct gx_z_texture_operator_t
	{
		Disable,
		Add,
		Replace,

		MaxZTOp
	} ZTextureOperator;

	typedef enum struct gx_z_texture_format_t
	{
		z8 = 17,
		z16 = 19,
		z24x8 = 22
	} ZTextureFormat;

	typedef enum struct gx_z_buffer_time_t
	{
		BeforeTexturing = 1,
		AfterTexturing = 0
	} ZBufferTime;

	typedef enum struct gx_texture_cache_size_t
	{
		NoCache = 3,

		Cache32K = 0,
		Cache128K,
		Cache512K
	} TextureCacheSize;

	typedef enum struct gx_wrap_mode_t
	{
		Clamp,
		Repeat,
		Mirror
	} WrapMode;

	typedef enum struct gx_tlut_index_t
	{
		TLUT0,
		TLUT1,
		TLUT2,
		TLUT3,
		TLUT4,
		TLUT5,
		TLUT6,
		TLUT7,
		TLUT8,
		TLUT9,
		TLUT10,
		TLUT11,
		TLUT12,
		TLUT13,
		TLUT14,
		TLUT15,

		BigTLUT0,
		BigTLUT1,
		BigTLUT2,
		BigTLUT3
	} TLUTIndex;

	typedef enum struct gx_tlut_entry_format_t
	{
		ia8, // intensity alpha
		rgb565,
		rgb5a3

	} TLUTEntryFormat;

	typedef enum struct gx_texture_map_index_t
	{
		TexMap0,
		TexMap1,
		TexMap2,
		TexMap3,
		TexMap4,
		TexMap5,
		TexMap6,
		TexMap7,

		MaxTexMap,
		TexMapNull = 255,
		TexMapDisable,
	} TextureMapIndex;

	typedef enum struct gx_texture_filter_t
	{
		Near,
		Linear,

		NearMipNear,
		NearMipLinear,
		LinearMipNear,
		LinearMipLinear
	} TextureFilter;

	typedef enum struct gx_max_anisotropic_filter_t
	{
		Aniso1,
		Aniso2,
		Aniso4,

		MaxAniso
	} MaxAnisoFilter;

	// TEV enum structs

	typedef enum struct gx_tev_stage_t
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

	typedef enum struct gx_tev_combiner_equation_t
	{
		Modulate,
		Decal,
		Blend,
		Replace,
		PassClear
	} TEVCombinerEquation;

	typedef enum struct gx_tev_register_t
	{
		RegPrev,
		Reg0,
		Reg1,
		Reg2,

		MaxTEVReg
	} TEVRegister;

	typedef enum struct gx_tev_register_input_t
	{
		ColorPrev,
		ColorTex = 8,
		ColorRaster = 10,
		Color0 = 2,
		Color1 = 4,
		Color2 = 6,

		AlphaPrev = 1,
		AlphaTex = 9,
		AlphaRaster = 11,
		Alpha0 = 3,
		Alpha1 = 5,
		Alpha2 = 7,

		Constant = 14,

		Zero = 15,
		Half = 13,
		One = 12
	} TEVRegisterInput;

	typedef enum struct gx_tev_combiner_operator_t
	{
		Add,
		Sub,

		CompareR8Equal = 9,
		CompareR8Greater = 8,
		CompareGR16Equal = 11,
		CompareGR16Greater = 10,
		CompareBGR24Equal = 13,
		CompareBGR24Greater = 12,
		CompareRGB8Equal = 15,
		CompareRGB8Greater = 14,
		CompareA8Equal = CompareRGB8Equal,
		CompareA8Greater = CompareRGB8Greater
	} TEVCombinerOperator;

	typedef enum struct gx_tev_bias_t
	{
		MinusHalfBias = 2,
		ZeroBias = 0
		PlusHalfBias,

		MaxTEVBias = 3
	} TEVBias;

	typedef enum struct gx_tev_scale_t
	{
		ScaleHalf = 3,
		Scale1 = 0,
		Scale2,
		Scale4,

		MaxTEVScale = 4
	} TEVScale;

	typedef enum struct gx_alpha_operation_t
	{
		AlphaAnd,
		AlphaOr,
		AlphaXOr,
		AlphaXNor,

		MaxAlphaOp
	} AlphaOperation;

	typedef enum struct gx_tev_constant_color_selection_t
	{
		ConstEighth = 7,
		ConstQuarter = 6,
		ConstThreeEighths = 5,
		ConstHalf = 4,
		ConstFiveEighths = 3,
		ConstThreeQuarters = 2,
		ConstSevenEighths = 1,
		ConstOne = 0,

		Reg0 = 12,
		Reg0R = 16,
		Reg0G = 20,
		Reg0B = 24,
		Reg0A = 28,

		Reg1 = 13,
		Reg1R = 17,
		Reg1G = 21,
		Reg1B = 25,
		Reg1A = 29,

		Reg2 = 14,
		Reg2R = 18,
		Reg2G = 22,
		Reg2B = 26,
		Reg2A = 30,

		Reg3 = 15,
		Reg3R = 19,
		Reg3G = 23,
		Reg3B = 25,
		Reg3A = 31
	} TEVKonstColorSelection;

	typedef enum struct gx_tev_constant_alpha_selection_t
	{
		ConstEighth = 7,
		ConstQuarter = 6,
		ConstThreeEighths = 5,
		ConstHalf = 4,
		ConstFiveEighths = 3,
		ConstThreeQuarters = 2,
		ConstSevenEighths = 1,
		ConstOne = 0,

		Reg0R = 16,
		Reg0G = 20,
		Reg0B = 24,
		Reg0A = 28,

		Reg1R = 17,
		Reg1G = 21,
		Reg1B = 25,
		Reg1A = 29,

		Reg2R = 18,
		Reg2G = 22,
		Reg2B = 26,
		Reg2A = 30,

		Reg3R = 19,
		Reg3G = 23,
		Reg3B = 25,
		Reg3A = 31
	} TEVKonstAlphaSelection;

	typedef enum struct gx_tev_swap_table_index_t
	{
		SwapTable0,
		SwapTable1,
		SwapTable2,
		SwapTable3,

		MaxSwapTable
	} TEVSwapTableIndex;

	// indirect textures, as a subset

	typedef enum struct gx_indirect_texture_stage_t
	{
		IndirectStage0,
		IndirectStage1,
		IndirectStage2,
		IndirectStage3,

		MaxIndirectStage
	} IndirectTextureStage;

	typedef enum struct gx_indirect_texture_format_t
	{
		Off3Bump5 = 3, // is this how this shit works?
		Off4Bump4 = 2,
		Off5Bump5 = 1,
		Off8Bump8 = 0, // definitely how this works

		MaxIndirectFormat = 4
	} IndirectTextureFormat;

	typedef enum struct gx_indirect_texture_bias_t
	{
		BiasNone,

		BiasS,
		BiasT,
		BiasU = 4,

		BiasST = 3,
		BiasSU = 5,
		BiasTU,

		BiasSTU,

		MaxIndirectBias
	} IndirectTextureBias;

	typedef enum struct gx_indirect_texture_matrix_t
	{
		MatrixNone,

		Matrix0,
		Matrix1,
		Matrix2,

		SMatrix0 = 5,
		SMatrix1,
		SMatrix2,

		TMatrix0 = 9,
		TMatrix1,
		TMatrix2
	} IndirectTextureMatrix;

	typedef enum struct gx_indirect_texture_wrap_t
	{
		WrapNone,

		Wrap256,
		Wrap128,
		Wrap64,
		Wrap32,
		Wrap16,
		Wrap0,

		MaxIndirectWrap
	} IndirectTextureWrap;

	typedef enum struct gx_indirect_texture_alpha_bump_t
	{
		BumpOff,

		BumpS,
		BumpT,
		BumpU,

		MaxIndirectBump
	} IndirectTextureAlphaBump;

	typedef enum struct gx_indirect_texture_scale_t
	{
		Scale1,
		Scale2,
		Scale4,
		Scale8,
		Scale16,
		Scale32,
		Scale64,
		Scale128,
		Scale256,

		MaxIndirectScale
	} IndirectTextureScale;

	// lights

	typedef enum struct gx_light_index_t
	{
		LightNone,

		Light0,
		Light1,
		Light2,
		Light3,
		Light4,
		Light5,
		Light6,
		Light7,

		MaxLight = 256
	} LightIndex;

	typedef enum struct gx_spot_illumination_function_t
	{
		Off,
		Flat,
		Cosine,
		CosSquared,
		Sharp,
		Ring1,
		Ring2
	} SpotIlluminationFunction;

	// matrix enum structs

	typedef enum struct gx_position_normal_matrix_index_t
	{
		PNMatrix0,
		PNMatrix1 = 3,
		PNMatrix2 = 6,
		PNMatrix3 = 9,
		PNMatrix4 = 12,
		PNMatrix5 = 15,
		PNMatrix6 = 18,
		PNMatrix7 = 21,
		PNMatrix8 = 24,
		PNMatrix9 = 27
	} PNMtxIndex;

	typedef enum struct gx_projection_type_t
	{
		Perspective,

		Orthographic,
		Frustum = Orthographic
	} ProjectionMatrixType;

	typedef enum struct gx_texture_matrix_type_t
	{
		Mtx3x4,
		Mtx2x4
	} TextureMatrixType;

	// other

	typedef enum struct gx_texture_offset_value_t
	{
		Zero,
		Sixteenth,
		Eighth,
		Fourth,
		Half,
		One,

		MaxOffset
	} TextureOffsetValue;

	typedef enum struct gx_blend_mode_t
	{
		None,
		Equation,
		Logic,
		Subtract,

		MaxBlend
	} BlendMode;

	typedef enum struct gx_blend_control_t
	{
		Zero,
		One,
		SourceColor,
		InverseSourceColor,
		SourceAlpha,
		InverseSourceAlpha,
		DestColor = SourceColor,
		InverseDestColor = InverseSourceColor,
		DestAlpha = 6,
		InverseDestAlpha
	} BlendControl;

	typedef enum struct gx_logic_operation_t
	{
		Clear,
		Set = 15,

		Source = 3,
		InvertSource = 12,
		Dest = 5,
		InvertDest = 10,

		Or = 7,
		InverseOr = 13,
		ReverseOr = 11,
		NOr = 8,

		XOr = 6,
		XNor = 9,

		And = 1,
		InverseAnd = 4,
		ReverseAnd = 2,
		NAnd = 14,
	} LogicalOperation;

	typedef enum struct gx_misc_token_t
	{
		XfFlush = 1,
		DLSaveCTX
	} MiscToken;

	typedef enum struct gx_culling_mode_t
	{
		CullNone,
		CullFront,
		CullBack,
		CullBoth
	} CullingMode;

	typedef enum struct gx_alpha_read_mode_t
	{
		Read00,
		ReadFF,
		ReadRealValue
	} AlphaReadMode;

	// metrics

	typedef enum struct gx_performance_counter_0_metric_t
	{
		Vertices,
		ClipVertex,
		ClipClocks,
		XFWaitIn,
		XFWaitOut,
		XFTransformClocks,
		XFLightClocks,
		XFBottomClocks,
		XFRegisterLoadClocks,
		XFRegisterReadClocks,
		ClipRatio,
		Triangles,
		TrianglesCulled,
		TrianglesPassed,
		TrianglesScissored,
		Triangles0Tex,
		Triangles1Tex,
		Triangles2Tex,
		Triangles3Tex,
		Triangles4Tex,
		Triangles5Tex,
		Triangles6Tex,
		Triangles7Tex,
		Triangles0Clr,
		Triangles1Clr,
		Triangles2Clr,
		Quad0Coverage,
		QuadNon0Coverage,
		Quad1Coverage,
		Quad2Coverage,
		Quad3Coverage,
		Quad4Coverage,
		AverageQuadCount,
		Clocks,

		NoMetric // can also be used to reset
	} PerfCounter0Metric;

	typedef enum struct gx_performance_counter_1_metric_t
	{
		Texels,
		TXIdle,
		TXRegisterClocks,
		TXMemStall,
		TCCheck1_2,
		TCCheck3_4,
		TCCheck5_6,
		TCCheck7_8,
		TCMiss,
		VCElemQFull,
		VCMissQFull,
		VCMEMREQFull,
		VCStatus7,
		VCMissRepFull,
		VCStreamBufferLow,
		VCAllStalls,
		Vertices,
		FifoReq,
		CallReq,
		VCMissReq,
		CPAllReq,
		Clocks,

		NoMetric // can also be used to reset
	} PerfCounter1Metric;

	typedef enum struct gx_vertex_cache_metric_t
	{
		Positions,
		Normals,
		Color0,
		Color1,
		Texture0,
		Texture1,
		Texture2,
		Texture3,
		Texture4,
		Texture5,
		Texture6,
		Texture7,

		All = 15
	} VertexCacheMetric;

	// drawing

	typedef enum struct gx_primitive_t
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

#endif // wrap_gx_td_h