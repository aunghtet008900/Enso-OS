/* LightDMGateway.c generated by valac 0.30.1, the Vala compiler
 * generated from LightDMGateway.vala, do not modify */

/*
* Copyright (c) 2011-2017 elementary LLC (http://launchpad.net/pantheon-greeter)
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation; either
* version 2 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc., 59 Temple Place - Suite 330,
* Boston, MA 02111-1307, USA.
*
*/

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <lightdm.h>
#include <glib/gi18n-lib.h>
#include <gtk/gtk.h>


#define TYPE_LOGIN_GATEWAY (login_gateway_get_type ())
#define LOGIN_GATEWAY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_LOGIN_GATEWAY, LoginGateway))
#define IS_LOGIN_GATEWAY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_LOGIN_GATEWAY))
#define LOGIN_GATEWAY_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TYPE_LOGIN_GATEWAY, LoginGatewayIface))

typedef struct _LoginGateway LoginGateway;
typedef struct _LoginGatewayIface LoginGatewayIface;

#define TYPE_LOGIN_MASK (login_mask_get_type ())
#define LOGIN_MASK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_LOGIN_MASK, LoginMask))
#define IS_LOGIN_MASK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_LOGIN_MASK))
#define LOGIN_MASK_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TYPE_LOGIN_MASK, LoginMaskIface))

typedef struct _LoginMask LoginMask;
typedef struct _LoginMaskIface LoginMaskIface;

#define TYPE_PROMPT_TYPE (prompt_type_get_type ())

#define TYPE_PROMPT_TEXT (prompt_text_get_type ())

#define TYPE_MESSAGE_TEXT (message_text_get_type ())

#define TYPE_LIGHT_DM_GATEWAY (light_dm_gateway_get_type ())
#define LIGHT_DM_GATEWAY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_LIGHT_DM_GATEWAY, LightDMGateway))
#define LIGHT_DM_GATEWAY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_LIGHT_DM_GATEWAY, LightDMGatewayClass))
#define IS_LIGHT_DM_GATEWAY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_LIGHT_DM_GATEWAY))
#define IS_LIGHT_DM_GATEWAY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_LIGHT_DM_GATEWAY))
#define LIGHT_DM_GATEWAY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_LIGHT_DM_GATEWAY, LightDMGatewayClass))

typedef struct _LightDMGateway LightDMGateway;
typedef struct _LightDMGatewayClass LightDMGatewayClass;
typedef struct _LightDMGatewayPrivate LightDMGatewayPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define TYPE_PANTHEON_GREETER (pantheon_greeter_get_type ())
#define PANTHEON_GREETER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PANTHEON_GREETER, PantheonGreeter))
#define PANTHEON_GREETER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PANTHEON_GREETER, PantheonGreeterClass))
#define IS_PANTHEON_GREETER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PANTHEON_GREETER))
#define IS_PANTHEON_GREETER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PANTHEON_GREETER))
#define PANTHEON_GREETER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PANTHEON_GREETER, PantheonGreeterClass))

typedef struct _PantheonGreeter PantheonGreeter;
typedef struct _PantheonGreeterClass PantheonGreeterClass;

typedef enum  {
	PROMPT_TYPE_SECRET,
	PROMPT_TYPE_QUESTION,
	PROMPT_TYPE_CONFIRM_LOGIN,
	PROMPT_TYPE_FPRINT
} PromptType;

typedef enum  {
	PROMPT_TEXT_USERNAME,
	PROMPT_TEXT_PASSWORD,
	PROMPT_TEXT_OTHER
} PromptText;

typedef enum  {
	MESSAGE_TEXT_FPRINT_SWIPE,
	MESSAGE_TEXT_FPRINT_SWIPE_AGAIN,
	MESSAGE_TEXT_FPRINT_SWIPE_TOO_SHORT,
	MESSAGE_TEXT_FPRINT_NOT_CENTERED,
	MESSAGE_TEXT_FPRINT_REMOVE,
	MESSAGE_TEXT_FPRINT_PLACE,
	MESSAGE_TEXT_FPRINT_PLACE_AGAIN,
	MESSAGE_TEXT_FPRINT_NO_MATCH,
	MESSAGE_TEXT_FPRINT_TIMEOUT,
	MESSAGE_TEXT_FPRINT_ERROR,
	MESSAGE_TEXT_FAILED,
	MESSAGE_TEXT_OTHER
} MessageText;

struct _LoginMaskIface {
	GTypeInterface parent_iface;
	void (*show_prompt) (LoginMask* self, PromptType type, PromptText prompttext, const gchar* text);
	void (*show_message) (LoginMask* self, LightDMMessageType type, MessageText messagetext, const gchar* text);
	void (*not_authenticated) (LoginMask* self);
	void (*login_aborted) (LoginMask* self);
	const gchar* (*get_login_name) (LoginMask* self);
	const gchar* (*get_login_session) (LoginMask* self);
};

struct _LoginGatewayIface {
	GTypeInterface parent_iface;
	void (*login_with_mask) (LoginGateway* self, LoginMask* mask, gboolean guest);
	void (*respond) (LoginGateway* self, const gchar* message);
	void (*start_session) (LoginGateway* self);
	gboolean (*get_hide_users) (LoginGateway* self);
	gboolean (*get_has_guest_account) (LoginGateway* self);
	gboolean (*get_show_manual_login) (LoginGateway* self);
	gboolean (*get_lock) (LoginGateway* self);
	const gchar* (*get_default_session) (LoginGateway* self);
	const gchar* (*get_select_user) (LoginGateway* self);
};

struct _LightDMGateway {
	GObject parent_instance;
	LightDMGatewayPrivate * priv;
};

struct _LightDMGatewayClass {
	GObjectClass parent_class;
};

struct _LightDMGatewayPrivate {
	LoginMask* _current_login;
	gboolean had_prompt;
	gboolean awaiting_confirmation;
	gboolean awaiting_start_session;
	LightDMGreeter* lightdm;
};


static gpointer light_dm_gateway_parent_class = NULL;
static LoginGatewayIface* light_dm_gateway_login_gateway_parent_iface = NULL;

GType prompt_type_get_type (void) G_GNUC_CONST;
GType prompt_text_get_type (void) G_GNUC_CONST;
GType message_text_get_type (void) G_GNUC_CONST;
GType login_mask_get_type (void) G_GNUC_CONST;
GType login_gateway_get_type (void) G_GNUC_CONST;
GType light_dm_gateway_get_type (void) G_GNUC_CONST;
#define LIGHT_DM_GATEWAY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_LIGHT_DM_GATEWAY, LightDMGatewayPrivate))
enum  {
	LIGHT_DM_GATEWAY_DUMMY_PROPERTY,
	LIGHT_DM_GATEWAY_HIDE_USERS,
	LIGHT_DM_GATEWAY_HAS_GUEST_ACCOUNT,
	LIGHT_DM_GATEWAY_SHOW_MANUAL_LOGIN,
	LIGHT_DM_GATEWAY_LOCK,
	LIGHT_DM_GATEWAY_DEFAULT_SESSION,
	LIGHT_DM_GATEWAY_SELECT_USER
};
LightDMGateway* light_dm_gateway_new (void);
LightDMGateway* light_dm_gateway_construct (GType object_type);
static void light_dm_gateway_show_message (LightDMGateway* self, const gchar* text, LightDMMessageType type);
static void _light_dm_gateway_show_message_lightdm_greeter_show_message (LightDMGreeter* _sender, const gchar* text, LightDMMessageType type, gpointer self);
static void light_dm_gateway_show_prompt (LightDMGateway* self, const gchar* text, LightDMPromptType type);
static void _light_dm_gateway_show_prompt_lightdm_greeter_show_prompt (LightDMGreeter* _sender, const gchar* text, LightDMPromptType type, gpointer self);
static void light_dm_gateway_authentication (LightDMGateway* self);
static void _light_dm_gateway_authentication_lightdm_greeter_authentication_complete (LightDMGreeter* _sender, gpointer self);
static void light_dm_gateway_real_login_with_mask (LoginGateway* base, LoginMask* login, gboolean guest);
static LoginMask* light_dm_gateway_get_current_login (LightDMGateway* self);
void login_mask_login_aborted (LoginMask* self);
static void light_dm_gateway_set_current_login (LightDMGateway* self, LoginMask* value);
const gchar* login_mask_get_login_name (LoginMask* self);
static void light_dm_gateway_real_respond (LoginGateway* base, const gchar* text);
const gchar* lightdm_message_type_to_string (LightDMMessageType self);
static MessageText light_dm_gateway_string_to_messagetext (LightDMGateway* self, const gchar* text);
static void light_dm_gateway_send_prompt (LightDMGateway* self, PromptType type, PromptText prompttext, const gchar* text);
void login_mask_show_message (LoginMask* self, LightDMMessageType type, MessageText messagetext, const gchar* text);
const gchar* lightdm_prompt_type_to_string (LightDMPromptType self);
static PromptType light_dm_gateway_lightdm_prompttype_to_prompttype (LightDMGateway* self, LightDMPromptType type);
static PromptText light_dm_gateway_string_to_prompttext (LightDMGateway* self, const gchar* text);
void login_mask_show_prompt (LoginMask* self, PromptType type, PromptText prompttext, const gchar* text);
gboolean light_dm_gateway_check_fprintd_string (LightDMGateway* self, const gchar* text, const gchar* action, const gchar* position);
static void light_dm_gateway_real_start_session (LoginGateway* base);
const gchar* login_mask_get_login_session (LoginMask* self);
GType pantheon_greeter_get_type (void) G_GNUC_CONST;
PantheonGreeter* pantheon_greeter_get_instance (void);
void pantheon_greeter_set_greeter_state (PantheonGreeter* self, const gchar* key, const gchar* value);
void login_mask_not_authenticated (LoginMask* self);
static void light_dm_gateway_finalize (GObject* obj);
gboolean login_gateway_get_hide_users (LoginGateway* self);
gboolean login_gateway_get_has_guest_account (LoginGateway* self);
gboolean login_gateway_get_show_manual_login (LoginGateway* self);
gboolean login_gateway_get_lock (LoginGateway* self);
const gchar* login_gateway_get_default_session (LoginGateway* self);
const gchar* login_gateway_get_select_user (LoginGateway* self);
static void _vala_light_dm_gateway_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_light_dm_gateway_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void _light_dm_gateway_show_message_lightdm_greeter_show_message (LightDMGreeter* _sender, const gchar* text, LightDMMessageType type, gpointer self) {
	light_dm_gateway_show_message ((LightDMGateway*) self, text, type);
}


static void _light_dm_gateway_show_prompt_lightdm_greeter_show_prompt (LightDMGreeter* _sender, const gchar* text, LightDMPromptType type, gpointer self) {
	light_dm_gateway_show_prompt ((LightDMGateway*) self, text, type);
}


static void _light_dm_gateway_authentication_lightdm_greeter_authentication_complete (LightDMGreeter* _sender, gpointer self) {
	light_dm_gateway_authentication ((LightDMGateway*) self);
}


LightDMGateway* light_dm_gateway_construct (GType object_type) {
	LightDMGateway * self = NULL;
	LightDMGreeter* _tmp0_ = NULL;
	LightDMGreeter* _tmp7_ = NULL;
	LightDMGreeter* _tmp8_ = NULL;
	LightDMGreeter* _tmp9_ = NULL;
	GError * _inner_error_ = NULL;
	self = (LightDMGateway*) g_object_new (object_type, NULL);
	g_message ("LightDMGateway.vala:84: Connecting to LightDM...");
	_tmp0_ = lightdm_greeter_new ();
	_g_object_unref0 (self->priv->lightdm);
	self->priv->lightdm = _tmp0_;
	{
		LightDMGreeter* _tmp1_ = NULL;
		_tmp1_ = self->priv->lightdm;
		lightdm_greeter_connect_to_daemon_sync (_tmp1_, &_inner_error_);
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			goto __catch12_g_error;
		}
	}
	goto __finally12;
	__catch12_g_error:
	{
		GError* e = NULL;
		GError* _tmp2_ = NULL;
		const gchar* _tmp3_ = NULL;
		const gchar* _tmp4_ = NULL;
		gchar* _tmp5_ = NULL;
		gchar* _tmp6_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp2_ = e;
		_tmp3_ = _tmp2_->message;
		_tmp4_ = string_to_string (_tmp3_);
		_tmp5_ = g_strconcat ("Couldn't connect to lightdm: ", _tmp4_, NULL);
		_tmp6_ = _tmp5_;
		g_warning ("LightDMGateway.vala:90: %s", _tmp6_);
		_g_free0 (_tmp6_);
		exit (EXIT_FAILURE);
		_g_error_free0 (e);
	}
	__finally12:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	g_message ("LightDMGateway.vala:93: Successfully connected to LightDM.");
	_tmp7_ = self->priv->lightdm;
	g_signal_connect_object (_tmp7_, "show-message", (GCallback) _light_dm_gateway_show_message_lightdm_greeter_show_message, self, 0);
	_tmp8_ = self->priv->lightdm;
	g_signal_connect_object (_tmp8_, "show-prompt", (GCallback) _light_dm_gateway_show_prompt_lightdm_greeter_show_prompt, self, 0);
	_tmp9_ = self->priv->lightdm;
	g_signal_connect_object (_tmp9_, "authentication-complete", (GCallback) _light_dm_gateway_authentication_lightdm_greeter_authentication_complete, self, 0);
	return self;
}


LightDMGateway* light_dm_gateway_new (void) {
	return light_dm_gateway_construct (TYPE_LIGHT_DM_GATEWAY);
}


static void light_dm_gateway_real_login_with_mask (LoginGateway* base, LoginMask* login, gboolean guest) {
	LightDMGateway * self;
	gboolean _tmp0_ = FALSE;
	LoginMask* _tmp1_ = NULL;
	LoginMask* _tmp3_ = NULL;
	gboolean _tmp4_ = FALSE;
	self = (LightDMGateway*) base;
	g_return_if_fail (login != NULL);
	_tmp0_ = self->priv->awaiting_start_session;
	if (_tmp0_) {
		g_warning ("LightDMGateway.vala:101: Got login_with_mask while awaiting start_sess" \
"ion!");
		return;
	}
	g_message ("LightDMGateway.vala:105: %s", "Starting authentication...");
	_tmp1_ = self->priv->_current_login;
	if (_tmp1_ != NULL) {
		LoginMask* _tmp2_ = NULL;
		_tmp2_ = self->priv->_current_login;
		login_mask_login_aborted (_tmp2_);
	}
	self->priv->had_prompt = FALSE;
	self->priv->awaiting_confirmation = FALSE;
	_tmp3_ = login;
	light_dm_gateway_set_current_login (self, _tmp3_);
	_tmp4_ = guest;
	if (_tmp4_) {
		LightDMGreeter* _tmp5_ = NULL;
		_tmp5_ = self->priv->lightdm;
		lightdm_greeter_authenticate_as_guest (_tmp5_);
	} else {
		LightDMGreeter* _tmp6_ = NULL;
		LoginMask* _tmp7_ = NULL;
		const gchar* _tmp8_ = NULL;
		const gchar* _tmp9_ = NULL;
		_tmp6_ = self->priv->lightdm;
		_tmp7_ = self->priv->_current_login;
		_tmp8_ = login_mask_get_login_name (_tmp7_);
		_tmp9_ = _tmp8_;
		lightdm_greeter_authenticate (_tmp6_, _tmp9_);
	}
}


static void light_dm_gateway_real_respond (LoginGateway* base, const gchar* text) {
	LightDMGateway * self;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	self = (LightDMGateway*) base;
	g_return_if_fail (text != NULL);
	_tmp0_ = self->priv->awaiting_start_session;
	if (_tmp0_) {
		g_warning ("LightDMGateway.vala:122: Got respond while awaiting start_session!");
		return;
	}
	_tmp1_ = self->priv->awaiting_confirmation;
	if (_tmp1_) {
		g_warning ("LightDMGateway.vala:127: Got user-interaction. Starting session");
		self->priv->awaiting_start_session = TRUE;
		g_signal_emit_by_name ((LoginGateway*) self, "login-successful");
	} else {
		LightDMGreeter* _tmp2_ = NULL;
		const gchar* _tmp3_ = NULL;
		_tmp2_ = self->priv->lightdm;
		_tmp3_ = text;
		lightdm_greeter_respond (_tmp2_, _tmp3_);
	}
}


static void light_dm_gateway_show_message (LightDMGateway* self, const gchar* text, LightDMMessageType type) {
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	LightDMMessageType _tmp2_ = 0;
	GEnumValue* _tmp3_;
	const gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	MessageText messagetext = 0;
	const gchar* _tmp7_ = NULL;
	MessageText _tmp8_ = 0;
	gboolean _tmp9_ = FALSE;
	MessageText _tmp10_ = 0;
	LoginMask* _tmp12_ = NULL;
	LightDMMessageType _tmp13_ = 0;
	MessageText _tmp14_ = 0;
	const gchar* _tmp15_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	_tmp0_ = text;
	_tmp1_ = string_to_string (_tmp0_);
	_tmp2_ = type;
	_tmp3_ = g_enum_get_value (g_type_class_ref (lightdm_message_type_get_type ()), _tmp2_);
	_tmp4_ = string_to_string ((_tmp3_ != NULL) ? _tmp3_->value_name : NULL);
	_tmp5_ = g_strconcat ("LightDM message: '", _tmp1_, "' (", _tmp4_, ")", NULL);
	_tmp6_ = _tmp5_;
	g_message ("LightDMGateway.vala:137: %s", _tmp6_);
	_g_free0 (_tmp6_);
	_tmp7_ = text;
	_tmp8_ = light_dm_gateway_string_to_messagetext (self, _tmp7_);
	messagetext = _tmp8_;
	_tmp10_ = messagetext;
	if (_tmp10_ == MESSAGE_TEXT_FPRINT_SWIPE) {
		_tmp9_ = TRUE;
	} else {
		MessageText _tmp11_ = 0;
		_tmp11_ = messagetext;
		_tmp9_ = _tmp11_ == MESSAGE_TEXT_FPRINT_PLACE;
	}
	if (_tmp9_) {
		light_dm_gateway_send_prompt (self, PROMPT_TYPE_FPRINT, PROMPT_TEXT_OTHER, "");
	}
	_tmp12_ = self->priv->_current_login;
	_tmp13_ = type;
	_tmp14_ = messagetext;
	_tmp15_ = text;
	login_mask_show_message (_tmp12_, _tmp13_, _tmp14_, _tmp15_);
}


static void light_dm_gateway_show_prompt (LightDMGateway* self, const gchar* text, LightDMPromptType type) {
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	LightDMPromptType _tmp2_ = 0;
	GEnumValue* _tmp3_;
	const gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	LightDMPromptType _tmp7_ = 0;
	PromptType _tmp8_ = 0;
	const gchar* _tmp9_ = NULL;
	PromptText _tmp10_ = 0;
	const gchar* _tmp11_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	_tmp0_ = text;
	_tmp1_ = string_to_string (_tmp0_);
	_tmp2_ = type;
	_tmp3_ = g_enum_get_value (g_type_class_ref (lightdm_prompt_type_get_type ()), _tmp2_);
	_tmp4_ = string_to_string ((_tmp3_ != NULL) ? _tmp3_->value_name : NULL);
	_tmp5_ = g_strconcat ("LightDM prompt: '", _tmp1_, "' (", _tmp4_, ")", NULL);
	_tmp6_ = _tmp5_;
	g_message ("LightDMGateway.vala:150: %s", _tmp6_);
	_g_free0 (_tmp6_);
	_tmp7_ = type;
	_tmp8_ = light_dm_gateway_lightdm_prompttype_to_prompttype (self, _tmp7_);
	_tmp9_ = text;
	_tmp10_ = light_dm_gateway_string_to_prompttext (self, _tmp9_);
	_tmp11_ = text;
	light_dm_gateway_send_prompt (self, _tmp8_, _tmp10_, _tmp11_);
}


static void light_dm_gateway_send_prompt (LightDMGateway* self, PromptType type, PromptText prompttext, const gchar* text) {
	LoginMask* _tmp0_ = NULL;
	PromptType _tmp1_ = 0;
	PromptText _tmp2_ = 0;
	const gchar* _tmp3_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	self->priv->had_prompt = TRUE;
	_tmp0_ = self->priv->_current_login;
	_tmp1_ = type;
	_tmp2_ = prompttext;
	_tmp3_ = text;
	login_mask_show_prompt (_tmp0_, _tmp1_, _tmp2_, _tmp3_);
}


static PromptType light_dm_gateway_lightdm_prompttype_to_prompttype (LightDMGateway* self, LightDMPromptType type) {
	PromptType result = 0;
	LightDMPromptType _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = type;
	if (_tmp0_ == LIGHTDM_PROMPT_TYPE_SECRET) {
		result = PROMPT_TYPE_SECRET;
		return result;
	}
	result = PROMPT_TYPE_QUESTION;
	return result;
}


static PromptText light_dm_gateway_string_to_prompttext (LightDMGateway* self, const gchar* text) {
	PromptText result = 0;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (text != NULL, 0);
	_tmp0_ = text;
	if (g_strcmp0 (_tmp0_, "Password: ") == 0) {
		result = PROMPT_TEXT_PASSWORD;
		return result;
	}
	_tmp1_ = text;
	if (g_strcmp0 (_tmp1_, "login: ") == 0) {
		result = PROMPT_TEXT_USERNAME;
		return result;
	}
	result = PROMPT_TEXT_OTHER;
	return result;
}


static MessageText light_dm_gateway_string_to_messagetext (LightDMGateway* self, const gchar* text) {
	MessageText result = 0;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (text != NULL, 0);
	_tmp0_ = text;
	_tmp1_ = g_dgettext ("fprintd", "An unknown error occured");
	if (g_strcmp0 (_tmp0_, _tmp1_) == 0) {
		result = MESSAGE_TEXT_FPRINT_ERROR;
		return result;
	} else {
		const gchar* _tmp2_ = NULL;
		gboolean _tmp3_ = FALSE;
		_tmp2_ = text;
		_tmp3_ = light_dm_gateway_check_fprintd_string (self, _tmp2_, "Swipe", "across");
		if (_tmp3_) {
			result = MESSAGE_TEXT_FPRINT_SWIPE;
			return result;
		} else {
			const gchar* _tmp4_ = NULL;
			const gchar* _tmp5_ = NULL;
			_tmp4_ = text;
			_tmp5_ = g_dgettext ("fprintd", "Swipe your finger again");
			if (g_strcmp0 (_tmp4_, _tmp5_) == 0) {
				result = MESSAGE_TEXT_FPRINT_SWIPE_AGAIN;
				return result;
			} else {
				const gchar* _tmp6_ = NULL;
				const gchar* _tmp7_ = NULL;
				_tmp6_ = text;
				_tmp7_ = g_dgettext ("fprintd", "Swipe was too short, try again");
				if (g_strcmp0 (_tmp6_, _tmp7_) == 0) {
					result = MESSAGE_TEXT_FPRINT_SWIPE_TOO_SHORT;
					return result;
				} else {
					const gchar* _tmp8_ = NULL;
					const gchar* _tmp9_ = NULL;
					_tmp8_ = text;
					_tmp9_ = g_dgettext ("fprintd", "Your finger was not centered, try swiping your finger again");
					if (g_strcmp0 (_tmp8_, _tmp9_) == 0) {
						result = MESSAGE_TEXT_FPRINT_NOT_CENTERED;
						return result;
					} else {
						const gchar* _tmp10_ = NULL;
						const gchar* _tmp11_ = NULL;
						_tmp10_ = text;
						_tmp11_ = g_dgettext ("fprintd", "Remove your finger, and try swiping your finger again");
						if (g_strcmp0 (_tmp10_, _tmp11_) == 0) {
							result = MESSAGE_TEXT_FPRINT_REMOVE;
							return result;
						} else {
							const gchar* _tmp12_ = NULL;
							gboolean _tmp13_ = FALSE;
							_tmp12_ = text;
							_tmp13_ = light_dm_gateway_check_fprintd_string (self, _tmp12_, "Place", "on");
							if (_tmp13_) {
								result = MESSAGE_TEXT_FPRINT_PLACE;
								return result;
							} else {
								const gchar* _tmp14_ = NULL;
								const gchar* _tmp15_ = NULL;
								_tmp14_ = text;
								_tmp15_ = g_dgettext ("fprintd", "Place your finger on the reader again");
								if (g_strcmp0 (_tmp14_, _tmp15_) == 0) {
									result = MESSAGE_TEXT_FPRINT_PLACE_AGAIN;
									return result;
								} else {
									const gchar* _tmp16_ = NULL;
									const gchar* _tmp17_ = NULL;
									_tmp16_ = text;
									_tmp17_ = g_dgettext ("fprintd", "Failed to match fingerprint");
									if (g_strcmp0 (_tmp16_, _tmp17_) == 0) {
										result = MESSAGE_TEXT_FPRINT_NO_MATCH;
										return result;
									} else {
										const gchar* _tmp18_ = NULL;
										const gchar* _tmp19_ = NULL;
										_tmp18_ = text;
										_tmp19_ = g_dgettext ("fprintd", "Verification timed out");
										if (g_strcmp0 (_tmp18_, _tmp19_) == 0) {
											result = MESSAGE_TEXT_FPRINT_TIMEOUT;
											return result;
										} else {
											const gchar* _tmp20_ = NULL;
											_tmp20_ = text;
											if (g_strcmp0 (_tmp20_, "Login failed") == 0) {
												result = MESSAGE_TEXT_FAILED;
												return result;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	result = MESSAGE_TEXT_OTHER;
	return result;
}


gboolean light_dm_gateway_check_fprintd_string (LightDMGateway* self, const gchar* text, const gchar* action, const gchar* position) {
	gboolean result = FALSE;
	gchar** fingers = NULL;
	gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	gchar* _tmp7_ = NULL;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_ = NULL;
	gchar* _tmp10_ = NULL;
	gchar** _tmp11_ = NULL;
	gint fingers_length1 = 0;
	gint _fingers_size_ = 0;
	gchar** _tmp12_ = NULL;
	gint _tmp12__length1 = 0;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (text != NULL, FALSE);
	g_return_val_if_fail (action != NULL, FALSE);
	g_return_val_if_fail (position != NULL, FALSE);
	_tmp0_ = g_strdup ("finger");
	_tmp1_ = g_strdup ("left thumb");
	_tmp2_ = g_strdup ("left index finger");
	_tmp3_ = g_strdup ("left middle finger");
	_tmp4_ = g_strdup ("left ring finger");
	_tmp5_ = g_strdup ("left little finger");
	_tmp6_ = g_strdup ("right thumb");
	_tmp7_ = g_strdup ("right index finger");
	_tmp8_ = g_strdup ("right middle finger");
	_tmp9_ = g_strdup ("right ring finger");
	_tmp10_ = g_strdup ("right little finger");
	_tmp11_ = g_new0 (gchar*, 11 + 1);
	_tmp11_[0] = _tmp0_;
	_tmp11_[1] = _tmp1_;
	_tmp11_[2] = _tmp2_;
	_tmp11_[3] = _tmp3_;
	_tmp11_[4] = _tmp4_;
	_tmp11_[5] = _tmp5_;
	_tmp11_[6] = _tmp6_;
	_tmp11_[7] = _tmp7_;
	_tmp11_[8] = _tmp8_;
	_tmp11_[9] = _tmp9_;
	_tmp11_[10] = _tmp10_;
	fingers = _tmp11_;
	fingers_length1 = 11;
	_fingers_size_ = fingers_length1;
	_tmp12_ = fingers;
	_tmp12__length1 = fingers_length1;
	{
		gchar** finger_collection = NULL;
		gint finger_collection_length1 = 0;
		gint _finger_collection_size_ = 0;
		gint finger_it = 0;
		finger_collection = _tmp12_;
		finger_collection_length1 = _tmp12__length1;
		for (finger_it = 0; finger_it < _tmp12__length1; finger_it = finger_it + 1) {
			gchar* _tmp13_ = NULL;
			gchar* finger = NULL;
			_tmp13_ = g_strdup (finger_collection[finger_it]);
			finger = _tmp13_;
			{
				gchar* english_string = NULL;
				const gchar* _tmp14_ = NULL;
				const gchar* _tmp15_ = NULL;
				const gchar* _tmp16_ = NULL;
				gchar* _tmp17_ = NULL;
				const gchar* _tmp18_ = NULL;
				const gchar* _tmp19_ = NULL;
				const gchar* _tmp20_ = NULL;
				gchar* _tmp21_ = NULL;
				gchar* _tmp22_ = NULL;
				gboolean _tmp23_ = FALSE;
				gboolean _tmp24_ = FALSE;
				_tmp14_ = action;
				_tmp15_ = finger;
				_tmp16_ = position;
				_tmp17_ = g_strconcat (_tmp14_, " your ", _tmp15_, " ", _tmp16_, " %s", NULL);
				english_string = _tmp17_;
				_tmp18_ = text;
				_tmp19_ = english_string;
				_tmp20_ = g_dgettext ("fprintd", _tmp19_);
				_tmp21_ = g_strdup_printf (_tmp20_, "");
				_tmp22_ = _tmp21_;
				_tmp23_ = g_str_has_prefix (_tmp18_, _tmp22_);
				_tmp24_ = _tmp23_;
				_g_free0 (_tmp22_);
				if (_tmp24_) {
					result = TRUE;
					_g_free0 (english_string);
					_g_free0 (finger);
					fingers = (_vala_array_free (fingers, fingers_length1, (GDestroyNotify) g_free), NULL);
					return result;
				}
				_g_free0 (english_string);
				_g_free0 (finger);
			}
		}
	}
	result = FALSE;
	fingers = (_vala_array_free (fingers, fingers_length1, (GDestroyNotify) g_free), NULL);
	return result;
}


static void light_dm_gateway_real_start_session (LoginGateway* base) {
	LightDMGateway * self;
	gboolean _tmp0_ = FALSE;
	LoginMask* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	PantheonGreeter* _tmp7_ = NULL;
	PantheonGreeter* _tmp8_ = NULL;
	LoginMask* _tmp9_ = NULL;
	const gchar* _tmp10_ = NULL;
	const gchar* _tmp11_ = NULL;
	GError * _inner_error_ = NULL;
	self = (LightDMGateway*) base;
	_tmp0_ = self->priv->awaiting_start_session;
	if (!_tmp0_) {
		g_warning ("LightDMGateway.vala:260: Got start_session without awaiting it.");
	}
	_tmp1_ = self->priv->_current_login;
	_tmp2_ = login_mask_get_login_session (_tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = string_to_string (_tmp3_);
	_tmp5_ = g_strconcat ("Starting session ", _tmp4_, NULL);
	_tmp6_ = _tmp5_;
	g_message ("LightDMGateway.vala:262: %s", _tmp6_);
	_g_free0 (_tmp6_);
	_tmp7_ = pantheon_greeter_get_instance ();
	_tmp8_ = _tmp7_;
	_tmp9_ = self->priv->_current_login;
	_tmp10_ = login_mask_get_login_name (_tmp9_);
	_tmp11_ = _tmp10_;
	pantheon_greeter_set_greeter_state (_tmp8_, "last-user", _tmp11_);
	{
		LightDMGreeter* _tmp12_ = NULL;
		LoginMask* _tmp13_ = NULL;
		const gchar* _tmp14_ = NULL;
		const gchar* _tmp15_ = NULL;
		_tmp12_ = self->priv->lightdm;
		_tmp13_ = self->priv->_current_login;
		_tmp14_ = login_mask_get_login_session (_tmp13_);
		_tmp15_ = _tmp14_;
		lightdm_greeter_start_session_sync (_tmp12_, _tmp15_, &_inner_error_);
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			goto __catch13_g_error;
		}
	}
	goto __finally13;
	__catch13_g_error:
	{
		GError* e = NULL;
		const gchar* _tmp16_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp16_ = e->message;
		g_error ("LightDMGateway.vala:268: %s", _tmp16_);
		_g_error_free0 (e);
	}
	__finally13:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void light_dm_gateway_authentication (LightDMGateway* self) {
	LightDMGreeter* _tmp0_ = NULL;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->lightdm;
	_tmp1_ = lightdm_greeter_get_is_authenticated (_tmp0_);
	_tmp2_ = _tmp1_;
	if (_tmp2_) {
		gboolean _tmp3_ = FALSE;
		_tmp3_ = self->priv->had_prompt;
		if (_tmp3_) {
			self->priv->awaiting_start_session = TRUE;
			g_signal_emit_by_name ((LoginGateway*) self, "login-successful");
		} else {
			LoginMask* _tmp4_ = NULL;
			g_message ("LightDMGateway.vala:281: %s", "Auth complete, but we await user-interaction before we" "start a session");
			self->priv->awaiting_confirmation = TRUE;
			_tmp4_ = self->priv->_current_login;
			login_mask_show_prompt (_tmp4_, PROMPT_TYPE_CONFIRM_LOGIN, PROMPT_TEXT_OTHER, "");
		}
	} else {
		LoginMask* _tmp5_ = NULL;
		_tmp5_ = self->priv->_current_login;
		login_mask_not_authenticated (_tmp5_);
	}
}


static LoginMask* light_dm_gateway_get_current_login (LightDMGateway* self) {
	LoginMask* result;
	LoginMask* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_current_login;
	result = _tmp0_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void light_dm_gateway_set_current_login (LightDMGateway* self, LoginMask* value) {
	LoginMask* _tmp0_ = NULL;
	LoginMask* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_current_login);
	self->priv->_current_login = _tmp1_;
}


static gboolean light_dm_gateway_real_get_hide_users (LoginGateway* base) {
	gboolean result;
	LightDMGateway* self;
	LightDMGreeter* _tmp0_ = NULL;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	self = (LightDMGateway*) base;
	_tmp0_ = self->priv->lightdm;
	_tmp1_ = lightdm_greeter_get_hide_users_hint (_tmp0_);
	_tmp2_ = _tmp1_;
	result = _tmp2_;
	return result;
}


static gboolean light_dm_gateway_real_get_has_guest_account (LoginGateway* base) {
	gboolean result;
	LightDMGateway* self;
	LightDMGreeter* _tmp0_ = NULL;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	self = (LightDMGateway*) base;
	_tmp0_ = self->priv->lightdm;
	_tmp1_ = lightdm_greeter_get_has_guest_account_hint (_tmp0_);
	_tmp2_ = _tmp1_;
	result = _tmp2_;
	return result;
}


static gboolean light_dm_gateway_real_get_show_manual_login (LoginGateway* base) {
	gboolean result;
	LightDMGateway* self;
	LightDMGreeter* _tmp0_ = NULL;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	self = (LightDMGateway*) base;
	_tmp0_ = self->priv->lightdm;
	_tmp1_ = lightdm_greeter_get_show_manual_login_hint (_tmp0_);
	_tmp2_ = _tmp1_;
	result = _tmp2_;
	return result;
}


static gboolean light_dm_gateway_real_get_lock (LoginGateway* base) {
	gboolean result;
	LightDMGateway* self;
	LightDMGreeter* _tmp0_ = NULL;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	self = (LightDMGateway*) base;
	_tmp0_ = self->priv->lightdm;
	_tmp1_ = lightdm_greeter_get_lock_hint (_tmp0_);
	_tmp2_ = _tmp1_;
	result = _tmp2_;
	return result;
}


static const gchar* light_dm_gateway_real_get_default_session (LoginGateway* base) {
	const gchar* result;
	LightDMGateway* self;
	LightDMGreeter* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	self = (LightDMGateway*) base;
	_tmp0_ = self->priv->lightdm;
	_tmp1_ = lightdm_greeter_get_default_session_hint (_tmp0_);
	_tmp2_ = _tmp1_;
	result = _tmp2_;
	return result;
}


static const gchar* light_dm_gateway_real_get_select_user (LoginGateway* base) {
	const gchar* result;
	LightDMGateway* self;
	LightDMGreeter* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	self = (LightDMGateway*) base;
	_tmp0_ = self->priv->lightdm;
	_tmp1_ = lightdm_greeter_get_select_user_hint (_tmp0_);
	_tmp2_ = _tmp1_;
	result = _tmp2_;
	return result;
}


static void light_dm_gateway_class_init (LightDMGatewayClass * klass) {
	light_dm_gateway_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (LightDMGatewayPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_light_dm_gateway_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_light_dm_gateway_set_property;
	G_OBJECT_CLASS (klass)->finalize = light_dm_gateway_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), LIGHT_DM_GATEWAY_HIDE_USERS, g_param_spec_boolean ("hide-users", "hide-users", "hide-users", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), LIGHT_DM_GATEWAY_HAS_GUEST_ACCOUNT, g_param_spec_boolean ("has-guest-account", "has-guest-account", "has-guest-account", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), LIGHT_DM_GATEWAY_SHOW_MANUAL_LOGIN, g_param_spec_boolean ("show-manual-login", "show-manual-login", "show-manual-login", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), LIGHT_DM_GATEWAY_LOCK, g_param_spec_boolean ("lock", "lock", "lock", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), LIGHT_DM_GATEWAY_DEFAULT_SESSION, g_param_spec_string ("default-session", "default-session", "default-session", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), LIGHT_DM_GATEWAY_SELECT_USER, g_param_spec_string ("select-user", "select-user", "select-user", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void light_dm_gateway_login_gateway_interface_init (LoginGatewayIface * iface) {
	light_dm_gateway_login_gateway_parent_iface = g_type_interface_peek_parent (iface);
	iface->login_with_mask = (void (*)(LoginGateway*, LoginMask*, gboolean)) light_dm_gateway_real_login_with_mask;
	iface->respond = (void (*)(LoginGateway*, const gchar*)) light_dm_gateway_real_respond;
	iface->start_session = (void (*)(LoginGateway*)) light_dm_gateway_real_start_session;
	iface->get_hide_users = light_dm_gateway_real_get_hide_users;
	iface->get_has_guest_account = light_dm_gateway_real_get_has_guest_account;
	iface->get_show_manual_login = light_dm_gateway_real_get_show_manual_login;
	iface->get_lock = light_dm_gateway_real_get_lock;
	iface->get_default_session = light_dm_gateway_real_get_default_session;
	iface->get_select_user = light_dm_gateway_real_get_select_user;
}


static void light_dm_gateway_instance_init (LightDMGateway * self) {
	self->priv = LIGHT_DM_GATEWAY_GET_PRIVATE (self);
	self->priv->_current_login = NULL;
	self->priv->had_prompt = FALSE;
	self->priv->awaiting_confirmation = FALSE;
	self->priv->awaiting_start_session = FALSE;
}


static void light_dm_gateway_finalize (GObject* obj) {
	LightDMGateway * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_LIGHT_DM_GATEWAY, LightDMGateway);
	_g_object_unref0 (self->priv->_current_login);
	_g_object_unref0 (self->priv->lightdm);
	G_OBJECT_CLASS (light_dm_gateway_parent_class)->finalize (obj);
}


/**
 * Passes communication to LightDM.
 */
GType light_dm_gateway_get_type (void) {
	static volatile gsize light_dm_gateway_type_id__volatile = 0;
	if (g_once_init_enter (&light_dm_gateway_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (LightDMGatewayClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) light_dm_gateway_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (LightDMGateway), 0, (GInstanceInitFunc) light_dm_gateway_instance_init, NULL };
		static const GInterfaceInfo login_gateway_info = { (GInterfaceInitFunc) light_dm_gateway_login_gateway_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType light_dm_gateway_type_id;
		light_dm_gateway_type_id = g_type_register_static (G_TYPE_OBJECT, "LightDMGateway", &g_define_type_info, 0);
		g_type_add_interface_static (light_dm_gateway_type_id, TYPE_LOGIN_GATEWAY, &login_gateway_info);
		g_once_init_leave (&light_dm_gateway_type_id__volatile, light_dm_gateway_type_id);
	}
	return light_dm_gateway_type_id__volatile;
}


static void _vala_light_dm_gateway_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	LightDMGateway * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_LIGHT_DM_GATEWAY, LightDMGateway);
	switch (property_id) {
		case LIGHT_DM_GATEWAY_HIDE_USERS:
		g_value_set_boolean (value, login_gateway_get_hide_users ((LoginGateway*) self));
		break;
		case LIGHT_DM_GATEWAY_HAS_GUEST_ACCOUNT:
		g_value_set_boolean (value, login_gateway_get_has_guest_account ((LoginGateway*) self));
		break;
		case LIGHT_DM_GATEWAY_SHOW_MANUAL_LOGIN:
		g_value_set_boolean (value, login_gateway_get_show_manual_login ((LoginGateway*) self));
		break;
		case LIGHT_DM_GATEWAY_LOCK:
		g_value_set_boolean (value, login_gateway_get_lock ((LoginGateway*) self));
		break;
		case LIGHT_DM_GATEWAY_DEFAULT_SESSION:
		g_value_set_string (value, login_gateway_get_default_session ((LoginGateway*) self));
		break;
		case LIGHT_DM_GATEWAY_SELECT_USER:
		g_value_set_string (value, login_gateway_get_select_user ((LoginGateway*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_light_dm_gateway_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	LightDMGateway * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_LIGHT_DM_GATEWAY, LightDMGateway);
	switch (property_id) {
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



