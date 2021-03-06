/* cuintstr.c generated by valac 0.30.1, the Vala compiler
 * generated from cuintstr.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define TYPE_INTSTR (intstr_get_type ())
typedef struct _intstr intstr;
#define _g_free0(var) (var = (g_free (var), NULL))

#define TYPE_INTSTRMAP (intstrmap_get_type ())
typedef struct _intstrmap intstrmap;

struct _intstr {
	guint hash;
	gchar* data;
};

struct _intstrmap {
	gint mListPos;
	intstr* mListData;
	gint mListData_length1;
	gint _mListData_size_;
};



#define DEFAULT_CAPACITY 50
GType intstr_get_type (void) G_GNUC_CONST;
intstr* intstr_dup (const intstr* self);
void intstr_free (intstr* self);
void intstr_copy (const intstr* self, intstr* dest);
void intstr_destroy (intstr* self);
GType intstrmap_get_type (void) G_GNUC_CONST;
intstrmap* intstrmap_dup (const intstrmap* self);
void intstrmap_free (intstrmap* self);
void intstrmap_copy (const intstrmap* self, intstrmap* dest);
void intstrmap_destroy (intstrmap* self);
static void _vala_intstr_array_free (intstr* array, gint array_length);
void intstrmap_init (intstrmap *self);
static void intstrmap_ensureCapa (intstrmap *self);
static void intstrmap_add (intstrmap *self, guint ukey, const gchar* val);
static gint intstrmap_index (intstrmap *self, guint ukey);
void intstrmap_setkv (intstrmap *self, guint ukey, const gchar* val);
void intstrmap_print (intstrmap *self);
gchar* intstrmap_getkv (intstrmap *self, guint ukey);
void intstrmap_delkv (intstrmap *self, guint ukey);
static intstr* _vala_array_dup1 (intstr* self, int length);
void _vala_main (void);


void intstr_copy (const intstr* self, intstr* dest) {
	guint _tmp0_ = 0U;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	_tmp0_ = (*self).hash;
	(*dest).hash = _tmp0_;
	_tmp1_ = (*self).data;
	_tmp2_ = g_strdup (_tmp1_);
	_g_free0 ((*dest).data);
	(*dest).data = _tmp2_;
}


void intstr_destroy (intstr* self) {
	_g_free0 ((*self).data);
}


intstr* intstr_dup (const intstr* self) {
	intstr* dup;
	dup = g_new0 (intstr, 1);
	intstr_copy (self, dup);
	return dup;
}


void intstr_free (intstr* self) {
	intstr_destroy (self);
	g_free (self);
}


GType intstr_get_type (void) {
	static volatile gsize intstr_type_id__volatile = 0;
	if (g_once_init_enter (&intstr_type_id__volatile)) {
		GType intstr_type_id;
		intstr_type_id = g_boxed_type_register_static ("intstr", (GBoxedCopyFunc) intstr_dup, (GBoxedFreeFunc) intstr_free);
		g_once_init_leave (&intstr_type_id__volatile, intstr_type_id);
	}
	return intstr_type_id__volatile;
}


static void _vala_intstr_array_free (intstr* array, gint array_length) {
	if (array != NULL) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			intstr_destroy (&array[i]);
		}
	}
	g_free (array);
}


void intstrmap_init (intstrmap *self) {
	intstr* _tmp0_ = NULL;
	memset (self, 0, sizeof (intstrmap));
	(*self).mListPos = 0;
	_tmp0_ = g_new0 (intstr, DEFAULT_CAPACITY);
	(*self).mListData = (_vala_intstr_array_free ((*self).mListData, (*self).mListData_length1), NULL);
	(*self).mListData = _tmp0_;
	(*self).mListData_length1 = DEFAULT_CAPACITY;
	(*self)._mListData_size_ = (*self).mListData_length1;
}


static void intstrmap_ensureCapa (intstrmap *self) {
	gint capalen = 0;
	intstr* _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	gint _tmp1_ = 0;
	_tmp0_ = (*self).mListData;
	_tmp0__length1 = (*self).mListData_length1;
	capalen = _tmp0__length1 * 2;
	_tmp1_ = capalen;
	(*self).mListData = g_renew (intstr, (*self).mListData, capalen);
	(_tmp1_ > (*self).mListData_length1) ? memset ((*self).mListData + (*self).mListData_length1, 0, sizeof (intstr) * (_tmp1_ - (*self).mListData_length1)) : NULL;
	(*self).mListData_length1 = _tmp1_;
	(*self)._mListData_size_ = _tmp1_;
}


static void intstrmap_add (intstrmap *self, guint ukey, const gchar* val) {
	gint _tmp0_ = 0;
	intstr* _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	intstr isns = {0};
	guint _tmp2_ = 0U;
	const gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	gint _tmp5_ = 0;
	intstr _tmp6_ = {0};
	intstr _tmp7_ = {0};
	intstr _tmp8_ = {0};
	gint _tmp9_ = 0;
	g_return_if_fail (val != NULL);
	_tmp0_ = (*self).mListPos;
	_tmp1_ = (*self).mListData;
	_tmp1__length1 = (*self).mListData_length1;
	if ((_tmp0_ + 1) > _tmp1__length1) {
		intstrmap_ensureCapa (&(*self));
	}
	memset (&isns, 0, sizeof (intstr));
	_tmp2_ = ukey;
	isns.hash = _tmp2_;
	_tmp3_ = val;
	_tmp4_ = g_strdup (_tmp3_);
	_g_free0 (isns.data);
	isns.data = _tmp4_;
	_tmp5_ = (*self).mListPos;
	_tmp6_ = isns;
	intstr_copy (&_tmp6_, &_tmp7_);
	intstr_destroy (&(*self).mListData[_tmp5_]);
	(*self).mListData[_tmp5_] = _tmp7_;
	_tmp8_ = (*self).mListData[_tmp5_];
	_tmp9_ = (*self).mListPos;
	(*self).mListPos = _tmp9_ + 1;
	intstr_destroy (&isns);
}


static gint intstrmap_index (intstrmap *self, guint ukey) {
	gint result = 0;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				gint _tmp2_ = 0;
				gint _tmp3_ = 0;
				intstr kh = {0};
				intstr* _tmp4_ = NULL;
				gint _tmp4__length1 = 0;
				gint _tmp5_ = 0;
				intstr _tmp6_ = {0};
				intstr _tmp7_ = {0};
				intstr _tmp8_ = {0};
				guint _tmp9_ = 0U;
				guint _tmp10_ = 0U;
				if (!_tmp0_) {
					gint _tmp1_ = 0;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = (*self).mListPos;
				if (!(_tmp2_ < _tmp3_)) {
					break;
				}
				_tmp4_ = (*self).mListData;
				_tmp4__length1 = (*self).mListData_length1;
				_tmp5_ = i;
				_tmp6_ = _tmp4_[_tmp5_];
				intstr_copy (&_tmp6_, &_tmp7_);
				kh = _tmp7_;
				_tmp8_ = kh;
				_tmp9_ = _tmp8_.hash;
				_tmp10_ = ukey;
				if (_tmp9_ == _tmp10_) {
					result = i;
					intstr_destroy (&kh);
					return result;
				}
				intstr_destroy (&kh);
			}
		}
	}
	result = -1;
	return result;
}


void intstrmap_setkv (intstrmap *self, guint ukey, const gchar* val) {
	gint index = 0;
	guint _tmp0_ = 0U;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	g_return_if_fail (val != NULL);
	_tmp0_ = ukey;
	_tmp1_ = intstrmap_index (&(*self), _tmp0_);
	index = _tmp1_;
	_tmp2_ = index;
	if (_tmp2_ == -1) {
		guint _tmp3_ = 0U;
		const gchar* _tmp4_ = NULL;
		_tmp3_ = ukey;
		_tmp4_ = val;
		intstrmap_add (&(*self), _tmp3_, _tmp4_);
	} else {
		intstr* _tmp5_ = NULL;
		gint _tmp5__length1 = 0;
		gint _tmp6_ = 0;
		const gchar* _tmp7_ = NULL;
		gchar* _tmp8_ = NULL;
		_tmp5_ = (*self).mListData;
		_tmp5__length1 = (*self).mListData_length1;
		_tmp6_ = index;
		_tmp7_ = val;
		_tmp8_ = g_strdup (_tmp7_);
		_g_free0 (_tmp5_[_tmp6_].data);
		_tmp5_[_tmp6_].data = _tmp8_;
	}
}


void intstrmap_print (intstrmap *self) {
	FILE* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	_tmp0_ = stdout;
	_tmp1_ = (*self).mListPos;
	fprintf (_tmp0_, "len=%d\n", _tmp1_);
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp2_ = FALSE;
			_tmp2_ = TRUE;
			while (TRUE) {
				gint _tmp4_ = 0;
				gint _tmp5_ = 0;
				gchar* data = NULL;
				intstr* _tmp6_ = NULL;
				gint _tmp6__length1 = 0;
				gint _tmp7_ = 0;
				intstr _tmp8_ = {0};
				const gchar* _tmp9_ = NULL;
				gchar* _tmp10_ = NULL;
				guint hs = 0U;
				intstr* _tmp11_ = NULL;
				gint _tmp11__length1 = 0;
				gint _tmp12_ = 0;
				intstr _tmp13_ = {0};
				guint _tmp14_ = 0U;
				FILE* _tmp15_ = NULL;
				const gchar* _tmp16_ = NULL;
				guint _tmp17_ = 0U;
				if (!_tmp2_) {
					gint _tmp3_ = 0;
					_tmp3_ = i;
					i = _tmp3_ + 1;
				}
				_tmp2_ = FALSE;
				_tmp4_ = i;
				_tmp5_ = (*self).mListPos;
				if (!(_tmp4_ < _tmp5_)) {
					break;
				}
				_tmp6_ = (*self).mListData;
				_tmp6__length1 = (*self).mListData_length1;
				_tmp7_ = i;
				_tmp8_ = _tmp6_[_tmp7_];
				_tmp9_ = _tmp8_.data;
				_tmp10_ = g_strdup (_tmp9_);
				data = _tmp10_;
				_tmp11_ = (*self).mListData;
				_tmp11__length1 = (*self).mListData_length1;
				_tmp12_ = i;
				_tmp13_ = _tmp11_[_tmp12_];
				_tmp14_ = _tmp13_.hash;
				hs = _tmp14_;
				_tmp15_ = stdout;
				_tmp16_ = data;
				_tmp17_ = hs;
				fprintf (_tmp15_, "iskv:%s|%u\n", _tmp16_, _tmp17_);
				_g_free0 (data);
			}
		}
	}
}


gchar* intstrmap_getkv (intstrmap *self, guint ukey) {
	gchar* result = NULL;
	gint index = 0;
	guint _tmp0_ = 0U;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	_tmp0_ = ukey;
	_tmp1_ = intstrmap_index (&(*self), _tmp0_);
	index = _tmp1_;
	_tmp2_ = index;
	if (_tmp2_ == -1) {
		result = NULL;
		return result;
	} else {
		intstr* _tmp3_ = NULL;
		gint _tmp3__length1 = 0;
		gint _tmp4_ = 0;
		intstr _tmp5_ = {0};
		const gchar* _tmp6_ = NULL;
		gchar* _tmp7_ = NULL;
		_tmp3_ = (*self).mListData;
		_tmp3__length1 = (*self).mListData_length1;
		_tmp4_ = index;
		_tmp5_ = _tmp3_[_tmp4_];
		_tmp6_ = _tmp5_.data;
		_tmp7_ = g_strdup (_tmp6_);
		result = _tmp7_;
		return result;
	}
}


void intstrmap_delkv (intstrmap *self, guint ukey) {
	gint _tmp0_ = 0;
	gint index = 0;
	guint _tmp1_ = 0U;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	_tmp0_ = (*self).mListPos;
	(*self).mListPos = _tmp0_ - 1;
	_tmp1_ = ukey;
	_tmp2_ = intstrmap_index (&(*self), _tmp1_);
	index = _tmp2_;
	_tmp3_ = index;
	if (_tmp3_ != -1) {
		intstr* nlists = NULL;
		gint _tmp4_ = 0;
		intstr* _tmp5_ = NULL;
		gint nlists_length1 = 0;
		gint _nlists_size_ = 0;
		_tmp4_ = (*self).mListPos;
		_tmp5_ = g_new0 (intstr, _tmp4_);
		nlists = _tmp5_;
		nlists_length1 = _tmp4_;
		_nlists_size_ = nlists_length1;
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp6_ = FALSE;
				_tmp6_ = TRUE;
				while (TRUE) {
					gint _tmp8_ = 0;
					gint _tmp9_ = 0;
					gint _tmp10_ = 0;
					gint _tmp11_ = 0;
					if (!_tmp6_) {
						gint _tmp7_ = 0;
						_tmp7_ = i;
						i = _tmp7_ + 1;
					}
					_tmp6_ = FALSE;
					_tmp8_ = i;
					_tmp9_ = (*self).mListPos;
					if (!(_tmp8_ < _tmp9_)) {
						break;
					}
					_tmp10_ = i;
					_tmp11_ = index;
					if (_tmp10_ == _tmp11_) {
						intstr* _tmp12_ = NULL;
						gint _tmp12__length1 = 0;
						gint _tmp13_ = 0;
						intstr* _tmp14_ = NULL;
						gint _tmp14__length1 = 0;
						gint _tmp15_ = 0;
						intstr _tmp16_ = {0};
						intstr _tmp17_ = {0};
						intstr _tmp18_ = {0};
						_tmp12_ = nlists;
						_tmp12__length1 = nlists_length1;
						_tmp13_ = i;
						_tmp14_ = (*self).mListData;
						_tmp14__length1 = (*self).mListData_length1;
						_tmp15_ = i;
						_tmp16_ = _tmp14_[_tmp15_ + 1];
						intstr_copy (&_tmp16_, &_tmp17_);
						intstr_destroy (&_tmp12_[_tmp13_]);
						_tmp12_[_tmp13_] = _tmp17_;
						_tmp18_ = _tmp12_[_tmp13_];
					} else {
						gint _tmp19_ = 0;
						gint _tmp20_ = 0;
						_tmp19_ = i;
						_tmp20_ = index;
						if (_tmp19_ < _tmp20_) {
							intstr* _tmp21_ = NULL;
							gint _tmp21__length1 = 0;
							gint _tmp22_ = 0;
							intstr* _tmp23_ = NULL;
							gint _tmp23__length1 = 0;
							gint _tmp24_ = 0;
							intstr _tmp25_ = {0};
							intstr _tmp26_ = {0};
							intstr _tmp27_ = {0};
							_tmp21_ = nlists;
							_tmp21__length1 = nlists_length1;
							_tmp22_ = i;
							_tmp23_ = (*self).mListData;
							_tmp23__length1 = (*self).mListData_length1;
							_tmp24_ = i;
							_tmp25_ = _tmp23_[_tmp24_];
							intstr_copy (&_tmp25_, &_tmp26_);
							intstr_destroy (&_tmp21_[_tmp22_]);
							_tmp21_[_tmp22_] = _tmp26_;
							_tmp27_ = _tmp21_[_tmp22_];
						} else {
							intstr* _tmp28_ = NULL;
							gint _tmp28__length1 = 0;
							gint _tmp29_ = 0;
							intstr* _tmp30_ = NULL;
							gint _tmp30__length1 = 0;
							gint _tmp31_ = 0;
							intstr _tmp32_ = {0};
							intstr _tmp33_ = {0};
							intstr _tmp34_ = {0};
							_tmp28_ = nlists;
							_tmp28__length1 = nlists_length1;
							_tmp29_ = i;
							_tmp30_ = (*self).mListData;
							_tmp30__length1 = (*self).mListData_length1;
							_tmp31_ = i;
							_tmp32_ = _tmp30_[_tmp31_ + 1];
							intstr_copy (&_tmp32_, &_tmp33_);
							intstr_destroy (&_tmp28_[_tmp29_]);
							_tmp28_[_tmp29_] = _tmp33_;
							_tmp34_ = _tmp28_[_tmp29_];
						}
					}
				}
			}
		}
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp35_ = FALSE;
				_tmp35_ = TRUE;
				while (TRUE) {
					gint _tmp37_ = 0;
					gint _tmp38_ = 0;
					gint _tmp39_ = 0;
					intstr* _tmp40_ = NULL;
					gint _tmp40__length1 = 0;
					gint _tmp41_ = 0;
					intstr _tmp42_ = {0};
					intstr _tmp43_ = {0};
					intstr _tmp44_ = {0};
					if (!_tmp35_) {
						gint _tmp36_ = 0;
						_tmp36_ = i;
						i = _tmp36_ + 1;
					}
					_tmp35_ = FALSE;
					_tmp37_ = i;
					_tmp38_ = (*self).mListPos;
					if (!(_tmp37_ < _tmp38_)) {
						break;
					}
					_tmp39_ = i;
					_tmp40_ = nlists;
					_tmp40__length1 = nlists_length1;
					_tmp41_ = i;
					_tmp42_ = _tmp40_[_tmp41_];
					intstr_copy (&_tmp42_, &_tmp43_);
					intstr_destroy (&(*self).mListData[_tmp39_]);
					(*self).mListData[_tmp39_] = _tmp43_;
					_tmp44_ = (*self).mListData[_tmp39_];
				}
			}
		}
		nlists = (_vala_intstr_array_free (nlists, nlists_length1), NULL);
	}
}


static intstr* _vala_array_dup1 (intstr* self, int length) {
	intstr* result;
	int i;
	result = g_new0 (intstr, length);
	for (i = 0; i < length; i++) {
		intstr _tmp0_ = {0};
		intstr_copy (&self[i], &_tmp0_);
		result[i] = _tmp0_;
	}
	return result;
}


void intstrmap_copy (const intstrmap* self, intstrmap* dest) {
	gint _tmp0_ = 0;
	intstr* _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	intstr* _tmp2_ = NULL;
	gint _tmp2__length1 = 0;
	_tmp0_ = (*self).mListPos;
	(*dest).mListPos = _tmp0_;
	_tmp1_ = (*self).mListData;
	_tmp1__length1 = (*self).mListData_length1;
	_tmp2_ = (_tmp1_ != NULL) ? _vala_array_dup1 (_tmp1_, _tmp1__length1) : ((gpointer) _tmp1_);
	_tmp2__length1 = _tmp1__length1;
	(*dest).mListData = (_vala_intstr_array_free ((*dest).mListData, (*dest).mListData_length1), NULL);
	(*dest).mListData = _tmp2_;
	(*dest).mListData_length1 = _tmp2__length1;
	(*dest)._mListData_size_ = (*dest).mListData_length1;
}


void intstrmap_destroy (intstrmap* self) {
	(*self).mListData = (_vala_intstr_array_free ((*self).mListData, (*self).mListData_length1), NULL);
}


intstrmap* intstrmap_dup (const intstrmap* self) {
	intstrmap* dup;
	dup = g_new0 (intstrmap, 1);
	intstrmap_copy (self, dup);
	return dup;
}


void intstrmap_free (intstrmap* self) {
	intstrmap_destroy (self);
	g_free (self);
}


GType intstrmap_get_type (void) {
	static volatile gsize intstrmap_type_id__volatile = 0;
	if (g_once_init_enter (&intstrmap_type_id__volatile)) {
		GType intstrmap_type_id;
		intstrmap_type_id = g_boxed_type_register_static ("intstrmap", (GBoxedCopyFunc) intstrmap_dup, (GBoxedFreeFunc) intstrmap_free);
		g_once_init_leave (&intstrmap_type_id__volatile, intstrmap_type_id);
	}
	return intstrmap_type_id__volatile;
}


void _vala_main (void) {
	intstrmap mp = {0};
	intstrmap_init (&mp);
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				gint _tmp2_ = 0;
				gchar* sout = NULL;
				gint _tmp3_ = 0;
				gchar* _tmp4_ = NULL;
				gint _tmp5_ = 0;
				const gchar* _tmp6_ = NULL;
				if (!_tmp0_) {
					gint _tmp1_ = 0;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				if (!(_tmp2_ < 100)) {
					break;
				}
				_tmp3_ = i;
				_tmp4_ = g_strdup_printf ("%i", _tmp3_);
				sout = _tmp4_;
				_tmp5_ = i;
				_tmp6_ = sout;
				intstrmap_setkv (&mp, (guint) _tmp5_, _tmp6_);
				_g_free0 (sout);
			}
		}
	}
	intstrmap_print (&mp);
	intstrmap_delkv (&mp, (guint) 5);
	intstrmap_setkv (&mp, (guint) 5, "good");
	intstrmap_print (&mp);
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp7_ = FALSE;
			_tmp7_ = TRUE;
			while (TRUE) {
				gint _tmp9_ = 0;
				gchar* s = NULL;
				gint _tmp10_ = 0;
				gchar* _tmp11_ = NULL;
				FILE* _tmp12_ = NULL;
				const gchar* _tmp13_ = NULL;
				if (!_tmp7_) {
					gint _tmp8_ = 0;
					_tmp8_ = i;
					i = _tmp8_ + 1;
				}
				_tmp7_ = FALSE;
				_tmp9_ = i;
				if (!(_tmp9_ < 100)) {
					break;
				}
				_tmp10_ = i;
				_tmp11_ = intstrmap_getkv (&mp, (guint) _tmp10_);
				s = _tmp11_;
				_tmp12_ = stdout;
				_tmp13_ = s;
				fprintf (_tmp12_, "get:%s\n", _tmp13_);
				_g_free0 (s);
			}
		}
	}
	intstrmap_destroy (&mp);
}


int main (int argc, char ** argv) {
#if !GLIB_CHECK_VERSION (2,35,0)
	g_type_init ();
#endif
	_vala_main ();
	return 0;
}



