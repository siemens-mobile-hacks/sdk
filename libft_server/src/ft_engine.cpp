#include "ft_engine.h"
#include <map>
#include <string>

std::map < std::string, ft_engine* > fonts_base;


__attribute__((visibility ("hidden")))
void fte_cleanMap()
{
    std::map< std::string, ft_engine* > ::iterator it;
    for(it = fonts_base.begin(); it != fonts_base.end(); ++it)
    {
        ft_engine * fte = it->second;
        fte_close(fte, 1);
    }
}

__attribute__((visibility ("hidden")))
bool fte_isexist(const char *name)
{
    FILE *f = fopen(name, "r");
    if(!f) return false;
    fclose(f);
    return true;
}

ft_engine * _fte_open(const char *file)
{
    ft_engine *cfte = fonts_base[file];
    if(cfte)
    {
        cfte->clients++;
        return cfte;
    }

    if(!fte_isexist(file)) return 0;

    ft_engine * fte = new ft_engine;
    if(!fte) return 0;

    fte->clients = 1;
    fte->file = file;
    fte->load_flags = FT_LOAD_DEFAULT;
    fte->render_flags = FT_RENDER_MODE_NORMAL;
    fte->error = FT_Init_FreeType(&fte->library);
    if(fte->error)
    {
        goto err;
    }


    fte->error = FT_New_Face(fte->library, file, 0, &fte->face);
    if ( fte->error == FT_Err_Unknown_File_Format )
    {
        printf("Unknown font format!\n");
        goto err;
    }
    else if ( fte->error )
    {
        printf("Can`t open font!\n");
        goto err;
    }


    fonts_base[file] = fte;

    return fte;
err:
    FT_Done_Face(fte->face);
    FT_Done_FreeType(fte->library);
    delete fte;
    return 0;
}


void _fte_close(ft_engine *fte, int clean_now)
{
    if(!fte) return;
    if(fte->clients > 1)
    {
        fte->clients--;
        return;
    }
    if(!clean_now) return;

    fte_clear_cache(fte);

    FT_Done_Face(fte->face);
    FT_Done_FreeType(fte->library);

    fonts_base.erase(fte->file);

    delete fte;
}



int _fte_cache_symbol(fte_info *fti, uint16_t letter)
{
    if (!fti) return -1;
    if (fti)
    {
        if( fti->symbols[letter] )
            if( fti->symbols[letter]->bitmap ) return 1;
    }
    else
        return -2;

    ft_engine *fte = (ft_engine*)fti->fte;
    FT_Set_Pixel_Sizes( fte->face, fti->w, fti->h );
    fte->error = FT_Load_Char( fte->face, letter, fte->load_flags);
    if (fte->error) return -3;

    fte->error = FT_Render_Glyph (fte->face->glyph, fte->render_flags);
    if (fte->error) return -4;

    fti->symbols.set(letter, new fte_symbol);
    fte_symbol *symb = fti->symbols[letter];


    fte->slot = fte->face->glyph;

    symb->width = fte->slot->bitmap.width;
    symb->height = fte->slot->bitmap.rows;
    symb->top = fte->slot->bitmap_top;
    symb->left = fte->slot->bitmap_left;

    symb->xadvance = fte->slot->advance.x >> 6;
    symb->yadvance = fte->slot->advance.y >> 6;
    uint32_t bmlen = symb->width * symb->height;
    symb->bitmap = (uint8_t*)malloc(bmlen);
    memcpy(symb->bitmap, fte->slot->bitmap.buffer, bmlen);
    return 0;
}


fte_symbol *_fte_get_symbol(fte_info *fti, uint16_t letter)
{
    if( !fti ) return 0;
    if(fte_cache_symbol(fti, letter) < 0) return 0;
    return fti->symbols[letter];
}


const char *_fte_get_name(ft_engine *fte)
{
    if( !fte ) return 0;
    return fte->file.c_str();
}

int _fte_clear_cache_by_metrics(fte_info *fti)
{
    if(!fti) return -1;

    fte_info *fi = fti;

    if(fi->clients > 0) return -2;
    int clened = 0;
    int inf_size = fi->symbols.size();
    for(int c = 0; c < inf_size; ++c)
    {
        fte_symbol *symb = fi->symbols[c];
        if(!symb) continue;
        clened += symb->width*symb->height;
        delete symb->bitmap;
        delete symb;
    }

    fi->symbols.clear();
    ft_engine *fte = (ft_engine*)fti->fte;
    fte->font_map[fti->h] = 0;
    delete fi;
    return clened;
}


int _fte_clear_cache(ft_engine *fte)
{
    bool no_clen_map = false;
    int size = fte->font_map.size();
    for(int i = 0; i <size; ++i)
    {
        if(fte_clear_cache_by_metrics(fte->font_map[i]) == -2)
            no_clen_map = true;
    }
    if(no_clen_map)
        fte->font_map.clear();
    return 0;
}


fte_info *_fte_open_cache_by_metrics(ft_engine *fte, uint16_t size)
{
    if( !fte ) return 0;
    if( !fte->font_map[size] )
    {
        fte->font_map.set(size, new fte_info);
        fte->font_map[size]->clients = 0;
        fte->font_map[size]->h = size;
        fte->font_map[size]->w = size;
        fte->font_map[size]->fte = (void*)fte;
    }
    fte->font_map[size]->clients++;
    return fte->font_map[size];
}


int _fte_close_cache_metrics(fte_info *fti)
{
    if( !fti ) return -1;
    fti->clients--;
    return 0;
}


FT_Library _fte_library_handler(ft_engine *fte)
{
    return fte->library;
}


FT_Face _fte_face_handler(ft_engine *fte)
{
    return fte->face;
}


void _fte_set_load_flags(ft_engine *fte, FT_Int32 flag)
{
    fte->load_flags = flag;
}

FT_Int32 _fte_load_flags(ft_engine *fte)
{
    return fte->load_flags;
}

void _fte_set_render_flags(ft_engine *fte, FT_Render_Mode flag)
{
    fte->render_flags = flag;
}

FT_Render_Mode _fte_render_flags(ft_engine *fte)
{
    return fte->render_flags;
}

ft_engine * _fte_open_env(const char *name)
{
    const char *env = getenv("FONTS");
    if(!env) return NULL;
    std::string str = env;
    str += name;

    return fte_open (str.c_str());
}


extern "C" {

    ft_engine * fte_open(const char *file)
    {
        return _fte_open(file);
    }

    ft_engine * fte_open_env(const char *file)
    {
        return _fte_open_env(file);
    }

    void fte_close(ft_engine *fte, int clean_now)
    {
        _fte_close(fte, clean_now);
    }

    int fte_cache_symbol(fte_info *fti, uint16_t letter)
    {
        return _fte_cache_symbol(fti, letter);
    }

    fte_symbol *fte_get_symbol(fte_info *fti, uint16_t letter)
    {
        return _fte_get_symbol(fti, letter);
    }

    const char *fte_get_name(ft_engine *fte)
    {
        return _fte_get_name(fte);
    }

    int fte_clear_cache_by_metrics(fte_info *fti)
    {
        return _fte_clear_cache_by_metrics(fti);
    }

    int fte_clear_cache(ft_engine *fte)
    {
        return _fte_clear_cache(fte);
    }

    fte_info *fte_open_cache_by_metrics(ft_engine *fte, uint16_t size)
    {
        return _fte_open_cache_by_metrics(fte, size);
    }

    int fte_close_cache_metrics(fte_info *fti)
    {
        return _fte_close_cache_metrics(fti);
    }


    FT_Library fte_library_handler(ft_engine *fte)
    {
        return _fte_library_handler(fte);
    }

    FT_Face fte_face_handler(ft_engine *fte)
    {
        return _fte_face_handler(fte);
    }

    void fte_set_load_flags(ft_engine *fte, FT_Int32 flag)
    {
        _fte_set_load_flags(fte, flag);
    }

	void fte_set_flags(ft_engine *fte, FT_Int32 flag) {
		_fte_set_load_flags(fte, flag);
	}

    FT_Int32 fte_load_flags(ft_engine *fte)
    {
        return _fte_load_flags(fte);
    }

    void fte_set_render_flags(ft_engine *fte, FT_Render_Mode flag)
    {
        _fte_set_render_flags(fte, flag);
    }

    FT_Render_Mode fte_render_flags(ft_engine *fte)
    {
        return _fte_render_flags(fte);
    }


}



