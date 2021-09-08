/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::gx
{
	// Framebuffer enum structs

	enum struct gx_gamma_t
	{
		g10,
		g17,
		g22
	};

	enum struct gx_copy_mode_t
	{
		Progressive,

		InterlacedEven = 2,
		InterlacedOdd
	};

	enum struct gx_clamp_mode_t
	{
		None,
		Top,
		Bottom
	};

	enum struct gx_next_field_t
	{
		InterlacedEven,
		InterlacedOdd
	};

	enum struct gx_pixel_format_t
	{
		rgb8z24,
		rgba6z24,

		rgb565z16
	};

	enum struct gx_z_format_t
	{
		Linear,
		Near,
		Mid,
		Far
	};

	// Fog enum struct

	enum struct gx_fog_equation_t
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
	};

	// Vertex enum structs

	enum struct gx_vertex_format_t
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
	};

	enum struct gx_vertex_attribute_t
	{
		Position,
		Normal,
		Color,
		TexCoord
	};

	enum struct gx_vertex_component_type_t
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
	};

	enum struct gx_vertex_component_format_t
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
	};

	enum struct gx_vertex_descriptor_t
	{
		None,
		Direct,
		Index8,
		Index16
	};

	// Color enum structs

	enum struct gx_color_channel_t
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
	};

	enum struct gx_diffuse_function_t
	{
		None,
		Signed,
		Clamp
	};

	enum struct gx_attenuation_function_t
	{
		None = 2,
		Specular = 0,
		Spot
	};

	// Texture enum structs

	enum struct gx_texture_coordinate_index_t
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
	};

	enum struct gx_texture_coordinate_generation_type_t
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
	};

	enum struct gx_texture_coordinate_source_t
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
	};

	enum struct gx_texture_matrix_index_t
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
	};

	enum struct gx_post_transform_matrix_index_t
	{
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
	};

	enum struct gx_texture_format_t
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
	};

	enum struct gx_comparison_t
	{
		Never,
		Less,
		LEqual = 3,
		NEqual = 5,
		Equal = 2,
		GEqual = 6,
		Greater = 4,
		Always = 7
	};

	enum struct gx_z_texture_operator_t
	{
		Disable,
		Add,
		Replace,

		MaxZTOp
	};

	enum struct gx_z_texture_format_t
	{
		z8 = 17,
		z16 = 19,
		z24x8 = 22
	};

	enum struct gx_z_buffer_time_t
	{
		BeforeTexturing = 1,
		AfterTexturing = 0
	};

	enum struct gx_texture_cache_size_t
	{
		NoCache = 3,

		Cache32K = 0,
		Cache128K,
		Cache512K
	};

	enum struct gx_tlut_index_t
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
	};

	enum struct gx_tlut_entry_format_t
	{
		ia8, // intensity alpha
		rgb565,
		rgb5a3

	};

	enum struct gx_texture_map_index_t
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
	};

	enum struct gx_texture_filter_t
	{
		Near,
		Linear,

		NearMipNear,
		NearMipLinear,
		LinearMipNear,
		LinearMipLinear
	};

	enum struct gx_max_anisotropic_filter_t
	{
		Aniso1,
		Aniso2,
		Aniso4,

		MaxAniso
	};

	// TEV enum structs

	enum struct gx_tev_stage_t
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
	};

	enum struct gx_tev_combiner_equation_t
	{
		Modulate,
		Decal,
		Blend,
		Replace,
		PassClear
	};

	enum struct gx_tev_register_t
	{
		RegPrev,
		Reg0,
		Reg1,
		Reg2,

		MaxTEVReg
	};

	enum struct gx_tev_register_input_t
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
	};

	enum struct gx_tev_combiner_operator_t
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
	};

	enum struct gx_tev_bias_t
	{
		MinusHalfBias = 2,
		ZeroBias = 0
		PlusHalfBias,

		MaxTEVBias = 3
	};

	enum struct gx_tev_scale_t
	{
		ScaleHalf = 3,
		Scale1 = 0,
		Scale2,
		Scale4,

		MaxTEVScale = 4
	};

	enum struct gx_alpha_operation_t
	{
		AlphaAnd,
		AlphaOr,
		AlphaXOr,
		AlphaXNor,

		MaxAlphaOp
	};

	enum struct gx_tev_constant_color_selection_t
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
	};

	enum struct gx_tev_constant_alpha_selection_t
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
	};

	enum struct gx_tev_swap_table_index_t
	{
		SwapTable0,
		SwapTable1,
		SwapTable2,
		SwapTable3,

		MaxSwapTable
	};

	// indirect textures, as a subset

	enum struct gx_indirect_texture_stage_t
	{
		IndirectStage0,
		IndirectStage1,
		IndirectStage2,
		IndirectStage3,

		MaxIndirectStage
	};

	enum struct gx_indirect_texture_format_t
	{
		Off3Bump5 = 3, // is this how this shit works?
		Off4Bump4 = 2,
		Off5Bump5 = 1,
		Off8Bump8 = 0, // definitely how this works

		MaxIndirectFormat = 4
	};

	enum struct gx_indirect_texture_bias_t
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
	};

	enum struct gx_indirect_texture_matrix_t
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
	};

	enum struct gx_indirect_texture_wrap_t
	{
		WrapNone,

		Wrap256,
		Wrap128,
		Wrap64,
		Wrap32,
		Wrap16,
		Wrap0,

		MaxIndirectWrap
	};

	enum struct gx_indirect_texture_alpha_bump_t
	{
		BumpOff,

		BumpS,
		BumpT,
		BumpU,

		MaxIndirectBump
	};

	enum struct gx_indirect_texture_scale_t
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
	};

	// lights

	enum struct gx_light_index_t
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
	};

	enum struct gx_spot_illumination_function_t
	{
		Off,
		Flat,
		Cosine,
		CosSquared,
		Sharp,
		Ring1,
		Ring2
	};

	// matrix enum structs

	enum struct gx_projection_type_t
	{
		Perspective,

		Orthographic,
		Frustum = Orthographic
	};

	// other

	enum struct gx_texture_offset_value_t
	{
		Zero,
		Sixteenth,
		Eighth,
		Fourth,
		Half,
		One,

		MaxOffset
	};

	enum struct gx_blend_mode_t
	{
		None,
		Equation,
		Logic,
		Subtract,

		MaxBlend
	};

	enum struct gx_blend_control_t
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
	};

	enum struct gx_logic_operation_t
	{
		Clear,
		Set = 15,

		Source = 3,
		InvertSource = 12
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
	};

	enum struct gx_culling_mode_t
	{
		CullNone,
		CullFront,
		CullBack,
		CullBoth
	};

	enum struct gx_alpha_read_mode_t
	{
		Read00,
		ReadFF,
		ReadRealValue
	};

	// metrics

	enum struct gx_performance_counter_0_metric_t
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
	};

	enum struct gx_performance_counter_1_metric_t
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
	};

	enum struct gx_vertex_cache_metric_t
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
	};

	// drawing

	enum struct gx_primitive_t
	{
		Points = 184,

		Lines = 168,
		LineStrip = 176,

		Triangles = 144,
		TriangleStrip = 152,
		TriangleFan = 160,

		Quads = 128
	};

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