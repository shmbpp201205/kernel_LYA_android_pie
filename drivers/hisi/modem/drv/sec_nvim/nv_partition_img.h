/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef _NV_PART_IMG_H_
#define _NV_PART_IMG_H_


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define MAX_DIRENT_LEN  1024

#define NVM_IMG_BIN 0x5a5a5a5a
#define NVM_IMG_BAK 0x7a7a7a7a
#ifdef BSP_CONFIG_PHONE_TYPE
#define NV_MBN_PATH                             "/mbn_nv/carrier.bin"
#else
#define NV_MBN_PATH                             "/mbn_nv/sec_carrier.bin"
#endif
#define NV_MBN_COMM_PATH                        "/mbn_nv/comm.bin"

#define NV_IMG_HEAD_PATH                        "/modem_nv/nv_head.bin"
#define NV_IMG_RESUM_PATH                       "/modem_nv/nv_resum.bin"
#define NV_IMG_RDONLY_PATH                      "/modem_nv/nv_rdonly.bin"
#define NV_IMG_RDWR_PATH                        "/modem_nv/nv_rdwr.bin"
#define NV_IMG_RDWR_PATH1                       "/modem_nv/nv_rdwr.bk"
#define NV_IMG_FLAG_SAVE_PATH                   "/modem_nv/nv_flag.txt"

enum
{
    NV_IMG = 0,      /* 0 */
    NV_MBN,          /* 1 */
    NV_MBN_COMM,     /* 2 */
    NV_IMG_HEAD,     /* 3 */
    NV_IMG_RESUM,    /* 4 */
    NV_IMG_RDONLY,   /* 5 */
    NV_IMG_RDWR,     /* 6 */
    NV_IMG_RDWR1,    /* 7 */
    NV_IMG_FLAG,     /* 8 */
    NV_MAX,
};


typedef struct nv_path_info_stru
{
    s8* root_dir;
    s8  file_path[NV_MAX][DRV_NAME_MAX];
}nv_path_info;

u32 nv_img_write(u8* pdata, u32 len, u32 file_offset);
u32 nv_img_boot_check(const s8 * pdir);
void nv_img_clear_check_result(void);
u32 nv_img_check_all_file(void);
u32 nv_img_recover_from_bak(void);
u32 nv_img_reload(void);
u32 nv_img_mreset_load(void);
u32 nv_img_flush(void);
u32 nv_img_load_carrier(s8 * path);
u32 nv_img_flush_carrier(void);
void nv_img_remove_all_file(void);
bool nv_img_is_need_flush(void);
u32 nv_img_load_file(u32 type, unsigned long offset, u32 length);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif



#endif /*_NV_PART_IMG_H_*/


