/* DeepinBlurEffect.c generated by valac 0.30.1, the Vala compiler
 * generated from DeepinBlurEffect.vala, do not modify */

/**/
/*  Copyright (C) 2015 Deepin Technology Co., Ltd.*/
/**/
/*  This program is free software: you can redistribute it and/or modify*/
/*  it under the terms of the GNU General Public License as published by*/
/*  the Free Software Foundation, either version 3 of the License, or*/
/*  (at your option) any later version.*/
/**/
/*  This program is distributed in the hope that it will be useful,*/
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of*/
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the*/
/*  GNU General Public License for more details.*/
/**/
/*  You should have received a copy of the GNU General Public License*/
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
/**/

#include <glib.h>
#include <glib-object.h>
#include <clutter/clutter.h>
#include <float.h>
#include <math.h>
#include <cogl/cogl.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_DEEPIN_BLUR_EFFECT (deepin_blur_effect_get_type ())
#define DEEPIN_BLUR_EFFECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DEEPIN_BLUR_EFFECT, DeepinBlurEffect))
#define DEEPIN_BLUR_EFFECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DEEPIN_BLUR_EFFECT, DeepinBlurEffectClass))
#define IS_DEEPIN_BLUR_EFFECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DEEPIN_BLUR_EFFECT))
#define IS_DEEPIN_BLUR_EFFECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DEEPIN_BLUR_EFFECT))
#define DEEPIN_BLUR_EFFECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DEEPIN_BLUR_EFFECT, DeepinBlurEffectClass))

typedef struct _DeepinBlurEffect DeepinBlurEffect;
typedef struct _DeepinBlurEffectClass DeepinBlurEffectClass;
typedef struct _DeepinBlurEffectPrivate DeepinBlurEffectPrivate;
#define _cogl_program_unref0(var) ((var == NULL) ? NULL : (var = (cogl_program_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _cogl_material_unref0(var) ((var == NULL) ? NULL : (var = (cogl_material_unref (var), NULL)))
#define _cogl_shader_unref0(var) ((var == NULL) ? NULL : (var = (cogl_shader_unref (var), NULL)))

struct _DeepinBlurEffect {
	ClutterOffscreenEffect parent_instance;
	DeepinBlurEffectPrivate * priv;
};

struct _DeepinBlurEffectClass {
	ClutterOffscreenEffectClass parent_class;
};

struct _DeepinBlurEffectPrivate {
	gboolean _horizontal;
	gint _width;
	gint _height;
	gfloat _radius;
	gfloat _bloom;
	CoglHandle* program;
};


static gpointer deepin_blur_effect_parent_class = NULL;

GType deepin_blur_effect_get_type (void) G_GNUC_CONST;
#define DEEPIN_BLUR_EFFECT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_DEEPIN_BLUR_EFFECT, DeepinBlurEffectPrivate))
enum  {
	DEEPIN_BLUR_EFFECT_DUMMY_PROPERTY,
	DEEPIN_BLUR_EFFECT_HORIZONTAL,
	DEEPIN_BLUR_EFFECT_WIDTH,
	DEEPIN_BLUR_EFFECT_HEIGHT,
	DEEPIN_BLUR_EFFECT_RADIUS,
	DEEPIN_BLUR_EFFECT_BLOOM
};
#define DEEPIN_BLUR_EFFECT_BLUR_SHADER_FRAG_H_CODE "\n" \
"\t// Fragment Shader horizontal\n" \
"\t\tuniform sampler2D texture;\n" \
"\t\tuniform int width;\n" \
"\t\tuniform float radius;\n" \
"\t\tuniform float bloom;\n" \
"\n" \
"\t\tvoid main()\n" \
"\t\t{\n" \
"\t\t\tfloat v;\n" \
"\t\t\tfloat pi = 3.141592653589793;\n" \
"\t\t\tfloat e_step = 1.0 / width;\n" \
"\t\t\tfloat rel_radius = radius;\n" \
"\t\t\tif (rel_radius < 0) rel_radius = 0;\n" \
"\t\t\tint steps = int(min(rel_radius * 0.7, sqrt(rel_radius) * pi));\n" \
"\t\t\tfloat r = rel_radius / steps;\n" \
"\t\t\tfloat t = bloom / (steps * 2 + 1);\n" \
"\t\t\tfloat x = cogl_tex_coord_in[0].x;\n" \
"\t\t\tfloat y = cogl_tex_coord_in[0].y;\n" \
"\t\t\tvec4 sum = texture2D(texture, vec2(x, y)) * t;\n" \
"\t\t\tint i;\n" \
"\t\t\tfor(i = 1; i <= steps; i++){\n" \
"\t\t\t\tv = (cos(i / (steps + 1) / pi) + 1) * 0.5;\n" \
"\t\t\t\tsum += texture2D(texture, vec2(x + i * e_step * r, y)) * v * t" \
";\n" \
"\t\t\t\tsum += texture2D(texture, vec2(x - i * e_step * r, y)) * v * t" \
";\n" \
"\t\t\t}\n" \
"\n" \
"\t\t    cogl_color_out = sum;\n" \
"\t\t}\n" \
"\t"
#define DEEPIN_BLUR_EFFECT_BLUR_SHADER_FRAG_V_CODE "\n" \
"\t// Fragment Shader vertical\n" \
"\t\tuniform sampler2D texture;\n" \
"\t\tuniform int height;\n" \
"\t\tuniform float radius;\n" \
"\t\tuniform float bloom;\n" \
"\n" \
"\t\tvoid main()\n" \
"\t\t{\n" \
"\t\t\tfloat v;\n" \
"\t\t\tfloat pi = 3.141592653589793;\n" \
"\t\t\tfloat e_step = 1.0 / height;\n" \
"\t\t\tfloat rel_radius = radius;\n" \
"\t\t\tif (rel_radius < 0) rel_radius = 0;\n" \
"\t\t\tint steps = int(min(rel_radius * 0.7, sqrt(rel_radius) * pi));\n" \
"\t\t\tfloat r = rel_radius / steps;\n" \
"\t\t\tfloat t = bloom / (steps * 2 + 1);\n" \
"\t\t\tfloat x = cogl_tex_coord_in[0].x;\n" \
"\t\t\tfloat y = cogl_tex_coord_in[0].y;\n" \
"\t\t\tvec4 sum = texture2D(texture, vec2(x, y)) * t;\n" \
"\t\t\tint i;\n" \
"\t\t\tfor(i = 1; i <= steps; i++){\n" \
"\t\t\t\tv = (cos(i / (steps + 1) / pi) + 1) * 0.5;\n" \
"\t\t\t\tsum += texture2D(texture, vec2(x, y + i * e_step * r)) * v * t" \
";\n" \
"\t\t\t\tsum += texture2D(texture, vec2(x, y - i * e_step * r)) * v * t" \
";\n" \
"\t\t\t}\n" \
"\n" \
"\t\t    cogl_color_out = sum;\n" \
"\t\t}\n" \
"\t"
DeepinBlurEffect* deepin_blur_effect_new (gboolean horizontal, gint width, gint height, gfloat radius, gfloat bloom);
DeepinBlurEffect* deepin_blur_effect_construct (GType object_type, gboolean horizontal, gint width, gint height, gfloat radius, gfloat bloom);
void deepin_blur_effect_setup (ClutterActor* actor, gint width, gint height, gfloat radius, gint repeat);
void deepin_blur_effect_update_size (DeepinBlurEffect* self, gint new_width, gint new_height);
static void deepin_blur_effect_real_paint_target (ClutterOffscreenEffect* base);
gboolean deepin_blur_effect_get_horizontal (DeepinBlurEffect* self);
static void deepin_blur_effect_set_horizontal (DeepinBlurEffect* self, gboolean value);
gint deepin_blur_effect_get_width (DeepinBlurEffect* self);
static void deepin_blur_effect_set_width (DeepinBlurEffect* self, gint value);
gint deepin_blur_effect_get_height (DeepinBlurEffect* self);
static void deepin_blur_effect_set_height (DeepinBlurEffect* self, gint value);
gfloat deepin_blur_effect_get_radius (DeepinBlurEffect* self);
static void deepin_blur_effect_set_radius (DeepinBlurEffect* self, gfloat value);
gfloat deepin_blur_effect_get_bloom (DeepinBlurEffect* self);
static void deepin_blur_effect_set_bloom (DeepinBlurEffect* self, gfloat value);
static GObject * deepin_blur_effect_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void deepin_blur_effect_finalize (GObject* obj);
static void _vala_deepin_blur_effect_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_deepin_blur_effect_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


DeepinBlurEffect* deepin_blur_effect_construct (GType object_type, gboolean horizontal, gint width, gint height, gfloat radius, gfloat bloom) {
	DeepinBlurEffect * self = NULL;
	gboolean _tmp0_ = FALSE;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	gfloat _tmp3_ = 0.0F;
	gfloat _tmp4_ = 0.0F;
	_tmp0_ = horizontal;
	_tmp1_ = width;
	_tmp2_ = height;
	_tmp3_ = radius;
	_tmp4_ = bloom;
	self = (DeepinBlurEffect*) g_object_new (object_type, "horizontal", _tmp0_, "width", _tmp1_, "height", _tmp2_, "radius", _tmp3_, "bloom", _tmp4_, NULL);
	return self;
}


DeepinBlurEffect* deepin_blur_effect_new (gboolean horizontal, gint width, gint height, gfloat radius, gfloat bloom) {
	return deepin_blur_effect_construct (TYPE_DEEPIN_BLUR_EFFECT, horizontal, width, height, radius, bloom);
}


void deepin_blur_effect_setup (ClutterActor* actor, gint width, gint height, gfloat radius, gint repeat) {
	g_return_if_fail (actor != NULL);
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				gint _tmp2_ = 0;
				gint _tmp3_ = 0;
				ClutterActor* _tmp4_ = NULL;
				gint _tmp5_ = 0;
				gint _tmp6_ = 0;
				gfloat _tmp7_ = 0.0F;
				DeepinBlurEffect* _tmp8_ = NULL;
				DeepinBlurEffect* _tmp9_ = NULL;
				ClutterActor* _tmp10_ = NULL;
				gint _tmp11_ = 0;
				gint _tmp12_ = 0;
				gfloat _tmp13_ = 0.0F;
				DeepinBlurEffect* _tmp14_ = NULL;
				DeepinBlurEffect* _tmp15_ = NULL;
				if (!_tmp0_) {
					gint _tmp1_ = 0;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = repeat;
				if (!(_tmp2_ < _tmp3_)) {
					break;
				}
				_tmp4_ = actor;
				_tmp5_ = width;
				_tmp6_ = height;
				_tmp7_ = radius;
				_tmp8_ = deepin_blur_effect_new (TRUE, _tmp5_, _tmp6_, _tmp7_, 1.0f);
				g_object_ref_sink (_tmp8_);
				_tmp9_ = _tmp8_;
				clutter_actor_add_effect (_tmp4_, (ClutterEffect*) _tmp9_);
				_g_object_unref0 (_tmp9_);
				_tmp10_ = actor;
				_tmp11_ = width;
				_tmp12_ = height;
				_tmp13_ = radius;
				_tmp14_ = deepin_blur_effect_new (FALSE, _tmp11_, _tmp12_, _tmp13_, 1.0f);
				g_object_ref_sink (_tmp14_);
				_tmp15_ = _tmp14_;
				clutter_actor_add_effect (_tmp10_, (ClutterEffect*) _tmp15_);
				_g_object_unref0 (_tmp15_);
			}
		}
	}
}


void deepin_blur_effect_update_size (DeepinBlurEffect* self, gint new_width, gint new_height) {
	gint uniform_no = 0;
	CoglHandle* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	CoglHandle* _tmp2_ = NULL;
	gint _tmp3_ = 0;
	gint _tmp4_ = 0;
	CoglHandle* _tmp5_ = NULL;
	gint _tmp6_ = 0;
	CoglHandle* _tmp7_ = NULL;
	gint _tmp8_ = 0;
	gint _tmp9_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->program;
	_tmp1_ = cogl_program_get_uniform_location (_tmp0_, "width");
	uniform_no = _tmp1_;
	_tmp2_ = self->priv->program;
	_tmp3_ = uniform_no;
	_tmp4_ = new_width;
	cogl_program_set_uniform_1i (_tmp2_, _tmp3_, _tmp4_);
	_tmp5_ = self->priv->program;
	_tmp6_ = cogl_program_get_uniform_location (_tmp5_, "height");
	uniform_no = _tmp6_;
	_tmp7_ = self->priv->program;
	_tmp8_ = uniform_no;
	_tmp9_ = new_height;
	cogl_program_set_uniform_1i (_tmp7_, _tmp8_, _tmp9_);
}


static gpointer _cogl_material_ref0 (gpointer self) {
	return self ? cogl_material_ref (self) : NULL;
}


static void deepin_blur_effect_real_paint_target (ClutterOffscreenEffect* base) {
	DeepinBlurEffect * self;
	CoglHandle* material = NULL;
	CoglHandle* _tmp0_ = NULL;
	CoglHandle* _tmp1_ = NULL;
	CoglHandle* _tmp2_ = NULL;
	self = (DeepinBlurEffect*) base;
	_tmp0_ = clutter_offscreen_effect_get_target ((ClutterOffscreenEffect*) self);
	_tmp1_ = _cogl_material_ref0 (_tmp0_);
	material = _tmp1_;
	_tmp2_ = self->priv->program;
	cogl_material_set_user_program (material, _tmp2_);
	CLUTTER_OFFSCREEN_EFFECT_CLASS (deepin_blur_effect_parent_class)->paint_target (G_TYPE_CHECK_INSTANCE_CAST (self, clutter_offscreen_effect_get_type (), ClutterOffscreenEffect));
	_cogl_material_unref0 (material);
}


gboolean deepin_blur_effect_get_horizontal (DeepinBlurEffect* self) {
	gboolean result;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_horizontal;
	result = _tmp0_;
	return result;
}


static void deepin_blur_effect_set_horizontal (DeepinBlurEffect* self, gboolean value) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_horizontal = _tmp0_;
	g_object_notify ((GObject *) self, "horizontal");
}


gint deepin_blur_effect_get_width (DeepinBlurEffect* self) {
	gint result;
	gint _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_width;
	result = _tmp0_;
	return result;
}


static void deepin_blur_effect_set_width (DeepinBlurEffect* self, gint value) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_width = _tmp0_;
	g_object_notify ((GObject *) self, "width");
}


gint deepin_blur_effect_get_height (DeepinBlurEffect* self) {
	gint result;
	gint _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_height;
	result = _tmp0_;
	return result;
}


static void deepin_blur_effect_set_height (DeepinBlurEffect* self, gint value) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_height = _tmp0_;
	g_object_notify ((GObject *) self, "height");
}


gfloat deepin_blur_effect_get_radius (DeepinBlurEffect* self) {
	gfloat result;
	gfloat _tmp0_ = 0.0F;
	g_return_val_if_fail (self != NULL, 0.0F);
	_tmp0_ = self->priv->_radius;
	result = _tmp0_;
	return result;
}


static void deepin_blur_effect_set_radius (DeepinBlurEffect* self, gfloat value) {
	gfloat _tmp0_ = 0.0F;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_radius = _tmp0_;
	g_object_notify ((GObject *) self, "radius");
}


gfloat deepin_blur_effect_get_bloom (DeepinBlurEffect* self) {
	gfloat result;
	gfloat _tmp0_ = 0.0F;
	g_return_val_if_fail (self != NULL, 0.0F);
	_tmp0_ = self->priv->_bloom;
	result = _tmp0_;
	return result;
}


static void deepin_blur_effect_set_bloom (DeepinBlurEffect* self, gfloat value) {
	gfloat _tmp0_ = 0.0F;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_bloom = _tmp0_;
	g_object_notify ((GObject *) self, "bloom");
}


static GObject * deepin_blur_effect_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	DeepinBlurEffect * self;
	CoglHandle* _tmp0_ = NULL;
	CoglHandle* shader = NULL;
	CoglHandle* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	CoglHandle* _tmp5_ = NULL;
	CoglHandle* _tmp6_ = NULL;
	CoglHandle* _tmp7_ = NULL;
	CoglHandle* _tmp8_ = NULL;
	gint uniform_no = 0;
	CoglHandle* _tmp9_ = NULL;
	gint _tmp10_ = 0;
	CoglHandle* _tmp11_ = NULL;
	gint _tmp12_ = 0;
	CoglHandle* _tmp13_ = NULL;
	gint _tmp14_ = 0;
	CoglHandle* _tmp15_ = NULL;
	gint _tmp16_ = 0;
	gint _tmp17_ = 0;
	CoglHandle* _tmp18_ = NULL;
	gint _tmp19_ = 0;
	CoglHandle* _tmp20_ = NULL;
	gint _tmp21_ = 0;
	gint _tmp22_ = 0;
	CoglHandle* _tmp23_ = NULL;
	gint _tmp24_ = 0;
	CoglHandle* _tmp25_ = NULL;
	gint _tmp26_ = 0;
	gfloat _tmp27_ = 0.0F;
	CoglHandle* _tmp28_ = NULL;
	gint _tmp29_ = 0;
	CoglHandle* _tmp30_ = NULL;
	gint _tmp31_ = 0;
	gfloat _tmp32_ = 0.0F;
	parent_class = G_OBJECT_CLASS (deepin_blur_effect_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_DEEPIN_BLUR_EFFECT, DeepinBlurEffect);
	_tmp0_ = (CoglHandle*) cogl_create_program ();
	_cogl_program_unref0 (self->priv->program);
	self->priv->program = _tmp0_;
	_tmp1_ = (CoglHandle*) cogl_create_shader (COGL_SHADER_TYPE_FRAGMENT);
	shader = _tmp1_;
	_tmp2_ = self->priv->_horizontal;
	if (_tmp2_) {
		CoglHandle* _tmp3_ = NULL;
		_tmp3_ = shader;
		cogl_shader_source (_tmp3_, DEEPIN_BLUR_EFFECT_BLUR_SHADER_FRAG_H_CODE);
	} else {
		CoglHandle* _tmp4_ = NULL;
		_tmp4_ = shader;
		cogl_shader_source (_tmp4_, DEEPIN_BLUR_EFFECT_BLUR_SHADER_FRAG_V_CODE);
	}
	_tmp5_ = shader;
	cogl_shader_compile (_tmp5_);
	_tmp6_ = self->priv->program;
	_tmp7_ = shader;
	cogl_program_attach_shader (_tmp6_, _tmp7_);
	_tmp8_ = self->priv->program;
	cogl_program_link (_tmp8_);
	_tmp9_ = self->priv->program;
	_tmp10_ = cogl_program_get_uniform_location (_tmp9_, "texture");
	uniform_no = _tmp10_;
	_tmp11_ = self->priv->program;
	_tmp12_ = uniform_no;
	cogl_program_set_uniform_1i (_tmp11_, _tmp12_, 0);
	_tmp13_ = self->priv->program;
	_tmp14_ = cogl_program_get_uniform_location (_tmp13_, "width");
	uniform_no = _tmp14_;
	_tmp15_ = self->priv->program;
	_tmp16_ = uniform_no;
	_tmp17_ = self->priv->_width;
	cogl_program_set_uniform_1i (_tmp15_, _tmp16_, _tmp17_);
	_tmp18_ = self->priv->program;
	_tmp19_ = cogl_program_get_uniform_location (_tmp18_, "height");
	uniform_no = _tmp19_;
	_tmp20_ = self->priv->program;
	_tmp21_ = uniform_no;
	_tmp22_ = self->priv->_height;
	cogl_program_set_uniform_1i (_tmp20_, _tmp21_, _tmp22_);
	_tmp23_ = self->priv->program;
	_tmp24_ = cogl_program_get_uniform_location (_tmp23_, "radius");
	uniform_no = _tmp24_;
	_tmp25_ = self->priv->program;
	_tmp26_ = uniform_no;
	_tmp27_ = self->priv->_radius;
	cogl_program_set_uniform_1f (_tmp25_, _tmp26_, _tmp27_);
	_tmp28_ = self->priv->program;
	_tmp29_ = cogl_program_get_uniform_location (_tmp28_, "bloom");
	uniform_no = _tmp29_;
	_tmp30_ = self->priv->program;
	_tmp31_ = uniform_no;
	_tmp32_ = self->priv->_bloom;
	cogl_program_set_uniform_1f (_tmp30_, _tmp31_, _tmp32_);
	_cogl_shader_unref0 (shader);
	return obj;
}


static void deepin_blur_effect_class_init (DeepinBlurEffectClass * klass) {
	deepin_blur_effect_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (DeepinBlurEffectPrivate));
	((ClutterOffscreenEffectClass *) klass)->paint_target = deepin_blur_effect_real_paint_target;
	G_OBJECT_CLASS (klass)->get_property = _vala_deepin_blur_effect_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_deepin_blur_effect_set_property;
	G_OBJECT_CLASS (klass)->constructor = deepin_blur_effect_constructor;
	G_OBJECT_CLASS (klass)->finalize = deepin_blur_effect_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), DEEPIN_BLUR_EFFECT_HORIZONTAL, g_param_spec_boolean ("horizontal", "horizontal", "horizontal", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), DEEPIN_BLUR_EFFECT_WIDTH, g_param_spec_int ("width", "width", "width", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), DEEPIN_BLUR_EFFECT_HEIGHT, g_param_spec_int ("height", "height", "height", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), DEEPIN_BLUR_EFFECT_RADIUS, g_param_spec_float ("radius", "radius", "radius", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), DEEPIN_BLUR_EFFECT_BLOOM, g_param_spec_float ("bloom", "bloom", "bloom", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void deepin_blur_effect_instance_init (DeepinBlurEffect * self) {
	self->priv = DEEPIN_BLUR_EFFECT_GET_PRIVATE (self);
}


static void deepin_blur_effect_finalize (GObject* obj) {
	DeepinBlurEffect * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_DEEPIN_BLUR_EFFECT, DeepinBlurEffect);
	_cogl_program_unref0 (self->priv->program);
	G_OBJECT_CLASS (deepin_blur_effect_parent_class)->finalize (obj);
}


GType deepin_blur_effect_get_type (void) {
	static volatile gsize deepin_blur_effect_type_id__volatile = 0;
	if (g_once_init_enter (&deepin_blur_effect_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DeepinBlurEffectClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) deepin_blur_effect_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DeepinBlurEffect), 0, (GInstanceInitFunc) deepin_blur_effect_instance_init, NULL };
		GType deepin_blur_effect_type_id;
		deepin_blur_effect_type_id = g_type_register_static (clutter_offscreen_effect_get_type (), "DeepinBlurEffect", &g_define_type_info, 0);
		g_once_init_leave (&deepin_blur_effect_type_id__volatile, deepin_blur_effect_type_id);
	}
	return deepin_blur_effect_type_id__volatile;
}


static void _vala_deepin_blur_effect_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	DeepinBlurEffect * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_DEEPIN_BLUR_EFFECT, DeepinBlurEffect);
	switch (property_id) {
		case DEEPIN_BLUR_EFFECT_HORIZONTAL:
		g_value_set_boolean (value, deepin_blur_effect_get_horizontal (self));
		break;
		case DEEPIN_BLUR_EFFECT_WIDTH:
		g_value_set_int (value, deepin_blur_effect_get_width (self));
		break;
		case DEEPIN_BLUR_EFFECT_HEIGHT:
		g_value_set_int (value, deepin_blur_effect_get_height (self));
		break;
		case DEEPIN_BLUR_EFFECT_RADIUS:
		g_value_set_float (value, deepin_blur_effect_get_radius (self));
		break;
		case DEEPIN_BLUR_EFFECT_BLOOM:
		g_value_set_float (value, deepin_blur_effect_get_bloom (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_deepin_blur_effect_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	DeepinBlurEffect * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_DEEPIN_BLUR_EFFECT, DeepinBlurEffect);
	switch (property_id) {
		case DEEPIN_BLUR_EFFECT_HORIZONTAL:
		deepin_blur_effect_set_horizontal (self, g_value_get_boolean (value));
		break;
		case DEEPIN_BLUR_EFFECT_WIDTH:
		deepin_blur_effect_set_width (self, g_value_get_int (value));
		break;
		case DEEPIN_BLUR_EFFECT_HEIGHT:
		deepin_blur_effect_set_height (self, g_value_get_int (value));
		break;
		case DEEPIN_BLUR_EFFECT_RADIUS:
		deepin_blur_effect_set_radius (self, g_value_get_float (value));
		break;
		case DEEPIN_BLUR_EFFECT_BLOOM:
		deepin_blur_effect_set_bloom (self, g_value_get_float (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



