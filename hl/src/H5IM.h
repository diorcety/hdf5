
/****************************************************************************
 * NCSA HDF                                                                 *
 * Scientific Data Technologies                                             *
 * National Center for Supercomputing Applications                          *
 * University of Illinois at Urbana-Champaign                               *
 * 605 E. Springfield, Champaign IL 61820                                   *
 *                                                                          *
 * For conditions of distribution and use, see the accompanying             *
 * hdf/COPYING file.                                                        *
 *                                                                          *
 ****************************************************************************/


#ifndef _H5IM_H
#define _H5IM_H

#include "H5LT.h"
#include "../../fortran/src/H5f90i_gen.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IMAGE_CLASS   "IMAGE"
#define PALETTE_CLASS "PALETTE"
#define IMAGE_VERSION "1.2"
#define IMAGE8_RANK    3
#define IMAGE24_RANK   3


herr_t H5IMmake_image_8bit( hid_t loc_id, 
                            const char *dset_name, 
                            hsize_t width,
                            hsize_t height,
                            const unsigned char *buffer );

herr_t H5IMmake_image_24bit( hid_t loc_id, 
                             const char *dset_name, 
                             hsize_t width,
                             hsize_t height,
                             const char *interlace,
                             const unsigned char *buffer );

herr_t H5IMget_image_info( hid_t loc_id, 
                     const char *dset_name, 
                     hsize_t *width,
                     hsize_t *height,
                     hsize_t *planes,
                     char    *interlace,
                     hssize_t *npals );

herr_t H5IMread_image( hid_t loc_id, 
                       const char *dset_name, 
                       unsigned char *buffer );



herr_t H5IMmake_palette( hid_t loc_id, 
                         const char *pal_name,
                         const hsize_t *pal_dims,
                         const unsigned char *pal_data );

herr_t H5IMlink_palette( hid_t loc_id, 
                        const char *image_name, 
                        const char *pal_name );

herr_t H5IMunlink_palette( hid_t loc_id, 
                           const char *image_name, 
                           const char *pal_name );

herr_t H5IMget_npalettes( hid_t loc_id, 
                          const char *image_name,  
                          hssize_t *npals );

herr_t H5IMget_palette_info( hid_t loc_id, 
                        const char *image_name, 
                        int pal_number,
                        hsize_t *pal_dims );


herr_t H5IMget_palette( hid_t loc_id, 
                        const char *image_name,
                        int pal_number,
                        unsigned char *pal_data );

herr_t H5IMis_image( hid_t loc_id, 
                     const char *dset_name );

herr_t H5IMis_palette( hid_t loc_id, 
                     const char *dset_name );

herr_t H5IMmake_image_8bitf( hid_t loc_id, 
                             const char *dset_name, 
                             hsize_t width,
                             hsize_t height,
                             int_f *buf );

herr_t H5IMmake_image_24bitf( hid_t loc_id, 
                              const char *dset_name, 
                              hsize_t width,
                              hsize_t height,
                              const char *interlace,
                              int_f *buf);

herr_t H5IMread_imagef( hid_t loc_id, 
                        const char *dset_name, 
                        int_f *buf );

herr_t H5IMmake_palettef( hid_t loc_id, 
                          const char *pal_name,
                          const hsize_t *pal_dims,
                          int_f *pal_data );

herr_t H5IMget_palettef( hid_t loc_id, 
                         const char *image_name,
                         int pal_number,
                         int_f *pal_data );


#ifdef __cplusplus
}
#endif

#endif
