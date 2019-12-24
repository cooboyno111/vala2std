#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>
#include <stdarg.h>
#include <ctype.h>
#include <locale.h>

#define gint8 char
#define gushort unsigned short
#define guint unsigned int
#define guint32 unsigned int

#define gdouble double
#define gchar char
#define gunichar wchar_t
#define gint int
#define gint32 int
#define glong long long int
#define gshort short
#define gint64 long long int
#define guint64 unsigned long long int
#define gsize size_t
#define guint8 unsigned char
#define gssize int
#define GType int
#define gboolean bool
#define FALSE	false
#define TRUE	true
#define G_PI	M_PI
#define gpointer void*

#define g_free free
#define g_strdup strdup
#define g_strndup strndup
#define g_ascii_strtod strtod
#define g_return_val_if_fail(expr,val) if((expr)==FALSE) return val;
#define g_return_if_fail(expr) if((expr)==FALSE) return;
#define g_print printf

#define g_strcmp0 strcmp
#define g_memmove memmove
//for32bitMCU/ESP32-STM32
/*
static inline guint hashcode(const gchar * str){
	int i,stlen;
        unsigned int hash;
	stlen=strlen(str);
	hash=0;
	for (i = 0; i < stlen; i++) {
		hash=31*hash+str[i];
	}
	return hash;
}
#define GQuark unsigned int
static inline GQuark g_quark_from_string(const gchar* str){
	return hashcode(str);
}
static inline GQuark g_quark_from_static_string(const gchar* str){
	return hashcode(str);
}*/
static inline gint* g_new0(size_t sizeOfElement,size_t numElements){
return (gint*)calloc(numElements,sizeOfElement);
}
static inline void* g_renew(size_t sizeOfElement,void *ptr,size_t numElements){
return realloc(ptr,numElements*sizeOfElement);
}
static inline void* g_memdup(const void *src, size_t n)
{
    void *dest;

    dest = malloc(n);
    if (dest == NULL)
            return NULL;

    return memcpy(dest, src, n);
}
static inline double g_random_double()
{
int nValue = rand();
double *pfValue = (double *)&nValue;
return *pfValue;
} 
static inline int g_random_int()
{
int nValue = rand();
return nValue;
}
static inline double g_random_double_range(double min,double max)
{    
    return min+g_random_double()/(double)(RAND_MAX/(max-min));
}
static inline int g_random_int_range(int min,int max)
{    
    return min+g_random_int()/(RAND_MAX/(max-min));
}
static inline char *strupr(char *str)
{
    char *orign=str;
    for (; *str!='\0'; str++)
        *str = toupper(*str);
    return orign;
}
static inline char *strlowr(char *str)
{
    char *orign=str;
    for (; *str!='\0'; str++)
        *str = tolower(*str);
    return orign;
}
static inline char * strrev (char * string)
{
        char *start = string;
        char *left = string;
        char ch;

        while (*string++)                 /* find end of string */
                ;
        string -= 2;

        while (left < string)
        {
                ch = *left;
                *left++ = *string;
                *string-- = ch;
        }

        return(start);
}
static inline char * g_utf8_strdown(char * str){
        gchar *string=NULL;
        string=(gchar*)malloc((strlen(str)+1)*sizeof(gchar));
        memset(string, 0, sizeof(gchar) * (strlen(str)+1));
        memcpy(string,str,strlen(str));
	return strlowr(string);
}
static inline char * g_utf8_strup(char * str){
        gchar *string=NULL;
        string=(gchar*)malloc((strlen(str)+1)*sizeof(gchar));
        memset(string, 0, sizeof(gchar) * (strlen(str)+1));
        memcpy(string,str,strlen(str));
	return strupr(string);
}
static inline char * g_utf8_strreverse(char * str,int a)
{
        gchar *string=NULL;
        string=(gchar*)malloc((strlen(str)+1)*sizeof(gchar));
        memset(string, 0, sizeof(gchar) * (strlen(str)+1));
        memcpy(string,str,strlen(str));
        return strrev(string);
}

static gchar * g_strdup_printf(const gchar *format,void* val){
        gchar *dup_str=NULL;
        gchar str[32];
        sprintf(str, format, val);
        //printf("len:%d str: %s\n", strlen(str), str);
        dup_str=(gchar*)malloc((strlen(str)+1)*sizeof(gchar));
        memset(dup_str, 0, sizeof(gchar) * (strlen(str)+1));
        memcpy(dup_str,str,strlen(str));
        //printf("len:%d str: %s\n", strlen(dup_str), dup_str);
	return dup_str;
}
/*
static gchar * g_strconcat (const gchar* prev_param, ...)
{
    va_list pArgs;
    gchar *dup_str=NULL;
    size_t alllen=0;
    char* para;  
    //获得长度
    va_start(pArgs, prev_param); 
    alllen+=strlen(prev_param);
    while (1) 
    {
        para = va_arg(pArgs, char*);
        if(para==NULL){
           break;
        }
    	alllen+=strlen(para);
    }
    alllen+=1;
    //printf("alllen=%d\n",alllen);
    //复制
    dup_str=(gchar*)malloc(alllen*sizeof(gchar));
    memset(dup_str, 0, sizeof(gchar) * alllen);
    strcat(dup_str,prev_param);
    va_start(pArgs, prev_param); 
    while (1) 
    {
        para = va_arg(pArgs, char*);
        if(para==NULL){
           break;
        }
        strcat(dup_str,para);
        //printf("Parameter is: %s\n", para);
    }
//vsnprintf(dup_str,alllen,"",pArgs);        
va_end(pArgs);
    return dup_str;   
}
static inline char *g_strdup_printf(const char *fmt, ...) {
	unsigned int length;
	char *buf = NULL;
	va_list ap;
	va_start (ap, fmt);
	length = (unsigned int)vsnprintf(buf, 0, fmt, ap);
	buf = calloc(length + 1, sizeof(char));
	vsnprintf(buf, length + 1, fmt, ap);
	va_end (ap);
	return buf;
}*/
static inline char *g_strconcat(const char *str, ...) {
	int plen, olen;
	const char *p;
	char *out;
	va_list ap;

	va_start (ap, str);
	out = strdup (str);
	olen = strlen (out);
	for (;;) {
        	p = va_arg (ap, char*);
		if (!p) break;
		plen = strlen (p);
		out = realloc (out, plen + olen+1);
		strcpy (out+olen, p);
		olen += plen;
	}
	va_end (ap);
	return out;
}
static inline char *g_strrstr(const char *dst, const char *src)
{
	const char *pdst = dst;
	const char *psrc = src;
	char *right= NULL;
	while (*dst)
	{
		while (*pdst == *psrc)
		{
			if (*pdst== '\0')
				return right=(char *)dst;
			else
			{
				pdst++;
				psrc++;
			}
		}
		if (*psrc == '\0')
			right = (char *)dst;
		pdst = ++dst;
		psrc = src;
	}
	return right;
}
static inline guint g_str_hash(const gchar * str){
	int i,stlen;
        unsigned int hash;
	stlen=strlen(str);
	hash=0;
	for (i = 0; i < stlen; i++) {
		hash=31*hash+str[i];
	}
	return hash;
}
//StringBuilder
#define GCAPA 15
typedef struct tagGString {
	gint pos;
	gint str_length;
	gchar* str;
}GString;
static inline GString * g_string_new(char * a){
struct tagGString * ts=malloc(sizeof(GString));
ts->pos=0;
ts->str_length=GCAPA;
ts->str=calloc(ts->str_length+1,sizeof(char));
memset(ts->str, 0, sizeof(gchar) * ts->str_length+1);
return ts;
}

static inline void g_string_free(GString* _this,bool a){
//     printf ("call g_string_free\n");
_this->pos=0;
_this->str_length=0;
if(_this->str!=NULL){
free(_this->str);
}
free(_this);
}
static inline void g_string_ensurecapa(GString* _this){
//      printf ("call g_string_ensurecapa size=%d\n",_this->str_length);
      int capalen;
      capalen =_this->str_length*2;
      _this->str=realloc(_this->str,capalen+1);
      for (int i = _this->pos; i < capalen+1; i++)
          _this->str[i]='\0';
      _this->str_length=capalen;
}
static inline void g_string_append(GString* _this,const char * ca){
     int pos,stlen,newlen;
     pos=_this->pos;
     stlen=strlen(ca);
     newlen=pos+stlen;
     if(newlen>_this->str_length){
        g_string_ensurecapa(_this);
     }
     for (int i = 0; i < stlen; i++)
     {
 		_this->str[pos+i]=ca[i];
                _this->pos++;
     }
}
static inline void array_move (gpointer array, gsize element_size, gint src, gint dest, gint length) {
	g_memmove (((char*) array) + (dest * element_size), ((char*) array) + (src * element_size), length * element_size);
	if ((src < dest) && ((src + length) > dest)) {
		memset (((char*) array) + (src * element_size), 0, (dest - src) * element_size);
	} else if ((src > dest) && (src < (dest + length))) {
		memset (((char*) array) + ((dest + length) * element_size), 0, (src - dest) * element_size);
	} else if (src != dest) {
		memset (((char*) array) + (src * element_size), 0, length * element_size);
	}
}

static inline void g_string_insert(GString* _this,gssize offset,const char * ca){
     int pos,stlen,newlen,len;
     pos=_this->pos;
     len=pos-offset;
     stlen=strlen(ca);
     newlen=pos+stlen;
     if(newlen>_this->str_length){
        g_string_ensurecapa(_this);
     }
     array_move (_this->str, sizeof (gchar), offset, offset+stlen, len);
     for (int i = 0; i < stlen; i++){
       _this->str[offset+i]=ca[i];
     }
     _this->pos+=stlen;
}
static inline void g_string_prepend(GString* _this,const char * ca){
     g_string_insert(_this,0,ca);
}
/*
static gint g_utf8_strlen(const gchar* str,int t){
int len=strlen(str);
printf("strlen-%d\n",len);
return len;
}
*/
static gunichar g_utf8_get_char(char * str,int index){
    char *chSrc=str;
    //wprintf(L"towchars:ptr=%d\n",chSrc);
    size_t nDestSize = mbstowcs(NULL, chSrc, 0) + 1;
    //wprintf(L"towchars:size2=%d\n",nDestSize);
    wchar_t wchDest[nDestSize];
    //wmemset(wchDest, 0, nDestSize);
    mbstowcs(wchDest,chSrc,nDestSize);
    //wprintf(L"wc=%ls\n",&wchDest);
    //wprintf(&wchDest);
    //wprintf(L"\n");
    return wchDest[0];
}
static inline const gchar* g_utf8_next_char (const gchar *s) {
        //printf("nextc-%s\n",s);
	unsigned char ch = *s;
	if (ch == '\0') return NULL;
	if (ch < 0x80) return s+1;
	if (ch < 0xE0) return s + 2;
	if (ch < 0xF0) return s + 3;
	if (ch < 0xF5) return s + 4;
	return NULL;
}
static inline int g_unichar_len(gunichar self) {
        int lenChar=0;        
        if(self < 0x80){
         lenChar=1;
        }else if(self>=0x80&&self<0x07FF){
         lenChar=2;
        }else if(self>=0x0800&&self<0xFFFF){
         lenChar=3;
        }else{
         lenChar=4;
        }
        return lenChar;
}
static inline gchar* g_unichar_to_string (gunichar self) {
        //printf("self=%d\n",self);
        wchar_t array[2];
        array[0]=self;
        array[1]='\0';
        int lenChar=g_unichar_len(self);
        //printf("len=%d\n",lenChar);
	gchar* str = g_new0 (sizeof(gchar), lenChar+1); 
	memset(str,0,lenChar+1);
	int dSize=wcstombs(str,(wchar_t*)(&array),lenChar);
        //printf("covlen=%d\n",dSize);
        //printf("g2s-%s\n",str);
        return str;
}
static inline void g_string_append_unichar(GString* _this, gunichar c){
     char * tc=g_unichar_to_string(c);
     g_string_append(_this,tc);
     g_free(tc);
}
////ERROR&GQuark
#define G_UNLIKELY(expr) (expr)
#define g_critical printf
#define GQuark void*
#define g_quark_from_static_string(x) ((GQuark)(size_t)(x))
#define g_quark_from_string(x) ((GQuark)(size_t)(x))
static inline const gchar *g_quark_to_string(GQuark q) {
	return (const gchar *)(size_t)q;
}
#define g_error_new(x,y,z) g_error_new_literal(x, y, z)
#define g_error_free(x) free(x->message),free(x)
#define g_clear_error free
#define g_propagate_error(x,y) *x=y
typedef struct _GError GError;
struct _GError {
	GQuark       domain;
	gint         code;
	gchar       *message;
};
static inline GError *g_error_new_literal(GQuark x, gint y, const gchar *msg) {
	GError *err = g_new0 (sizeof(GError), 1);
	err->domain = x;
	err->code = y;
	err->message = strdup (msg);
	return err;
}
////GLIST
typedef void (*GFunc)(gpointer data, gpointer user_data);
#define gconstpointer const void *
#define gintptr signed long

typedef struct _GList GList;
struct _GList {
	gpointer data;
	GList *next;
	GList *prev;
};

#define _g_list_alloc() calloc(1, sizeof(GList))

static inline void g_list_free(GList *list) {
	GList *current, *tmp;
	current = list;
	while (current) {
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
static inline int g_list_length(GList *list)
{
    int k=0;
    while(list!=NULL)
    {
        k++;
        list = list->next;
    }
    return k;
}

static inline gpointer g_list_nth_data(GList *list,guint index){
    int k=0;
    if(index==0){return list->data;}
    while(list!=NULL)
    {
        k++;
        list = list->next;
        if(k==index){
          break;
        }
    }
    return list->data;
}
static inline int g_list_index(GList *list,gpointer data,bool nostr){
    int len=g_list_length(list);
    for(int i=0;i<len;i++){
       gpointer val=g_list_nth_data(list,i);
       //printf ("val=%d|%d\n", val,data);
       if(nostr){
         if(val==data)
            return i;
       }else{
         if(strcmp(val,data)==0)
            return i;
       }
    }
    return -1;
}
static inline GList* g_list_last (GList *list) {
	if (list)
		while (list->next)
			list = list->next;
	return list;
}

static inline GList* g_list_append (GList *list, gpointer data) {
	GList *new_list = _g_list_alloc ();
	GList *last;
	if (!new_list) return NULL;
	new_list->data = data;
	new_list->next = NULL;
	if (list) {
		last = g_list_last (list);
		last->next = new_list;
		new_list->prev = last;
		return list;
	}
	new_list->prev = NULL;
	return new_list;
}

static inline GList* g_list_prepend (GList *list, gpointer data) {
	GList *new_list = _g_list_alloc ();
	new_list->data = data;
	new_list->next = list;
	if (list) {
		new_list->prev = list->prev;
		if (list->prev)
			list->prev->next = new_list;
		list->prev = new_list;
	} else new_list->prev = NULL;
	return new_list;
}
static inline GList* g_list_insert (GList *list, gpointer data ,guint index) {
    if(list==NULL){
         //printf ("g_list_insert null %d\n", index);
         return g_list_append(list,data);
    }
    if(index>g_list_length(list))return list;
    //printf ("g_list_insert %d\n", index);
    if(index==0){
         return g_list_prepend(list,data);
    }else{
        int j = 0;
        GList *p = list;
        GList *last=NULL;
        while(j<index){
           last=p;
           p = p->next;
           j++;
        }
        //printf ("g_list_insert end %d\n", p);
        if(p==NULL){
           //printf ("g_list_insert p=null %d\n", last);
           GList *nDLNode = _g_list_alloc ();
           nDLNode->data = data;
	   nDLNode->next = NULL;
           nDLNode->prev=last;
           last->next=nDLNode;
        }else{
	   GList *nDLNode = _g_list_alloc ();
	   nDLNode->data = data;
           nDLNode->prev = p->prev;
           p->prev->next = nDLNode;
           p->prev = nDLNode;
           nDLNode->next = p;
        }
        return list;
    }
}
static inline GList* g_list_remove_byindex(GList *list,guint index){
    if(list==NULL)return NULL;
    if(index>=g_list_length(list))return list;
    if(index==0){
        //printf ("g_list_remove zero %d\n", index);
	GList *p=list;
        GList *head=p->next;
        if(head!=NULL){
           head->prev=NULL;
        }
        free(p);
        return head;
    }else{
        //printf ("g_list_remove nozero %d\n", index);
        GList *p = list;
        int j = 0;
        while(j<index){
           p = p->next;
           //printf ("g_list_remove val %d\n", p->prev);
           j++;
        }
        //printf ("g_list_remove end %d\n", p->next);
        p->prev->next = p->next;
        if(p->next!=NULL){p->next->prev = p->prev;}
        free(p);
        return list;
    }
}
static inline GList* g_list_remove(GList *list,gpointer data,bool nostr){
    int index=g_list_index(list,data,nostr);
    if(index!=-1){
      return g_list_remove_byindex(list,index);
    }else{
      return list;
    }
}
static inline void g_list_foreach (GList *list, GFunc func, gpointer user_data) {
	while (list) {
		GList *next = list->next;
		(*func) (list->data, user_data);
		list = next;
	}
}

