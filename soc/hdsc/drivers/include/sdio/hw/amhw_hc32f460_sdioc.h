/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief SDIOC Ӳ�������ӿ�
 * \internal
 * \par Modification history
 * - 1.00 17-04-28  cds, first implementation
 * \endinternal
 */

#ifndef __AMHW_HC32F460_SDIO_H
#define __AMHW_HC32F460_SDIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "am_types.h"
#include "am_bitops.h"


/**
 * \addtogroup amhw_hc32f460_sdio
 * \copydoc amhw_hc32f460_sdio.h
 * @{
 */

/**
 * \brief sdio structure of register
 */

typedef struct
{
    __IO uint16_t TBS                       :12;
    uint16_t RESERVED12                     : 4;
} stc_sdioc_blksize_field_t;

typedef struct
{
    uint16_t RESERVED0                      : 1;
    __IO uint16_t BCE                       : 1;
    __IO uint16_t ATCEN                     : 2;
    __IO uint16_t DDIR                      : 1;
    __IO uint16_t MULB                      : 1;
    uint16_t RESERVED6                      :10;
} stc_sdioc_transmode_field_t;

typedef struct
{
    __IO uint16_t RESTYP                    : 2;
    uint16_t RESERVED2                      : 1;
    __IO uint16_t CCE                       : 1;
    __IO uint16_t ICE                       : 1;
    __IO uint16_t DAT                       : 1;
    __IO uint16_t TYP                       : 2;
    __IO uint16_t IDX                       : 6;
    uint16_t RESERVED14                     : 2;
} stc_sdioc_cmd_field_t;

typedef struct
{
    __IO uint32_t CIC                       : 1;
    __IO uint32_t CID                       : 1;
    __IO uint32_t DA                        : 1;
    uint32_t RESERVED3                      : 5;
    __IO uint32_t WTA                       : 1;
    __IO uint32_t RTA                       : 1;
    __IO uint32_t BWE                       : 1;
    __IO uint32_t BRE                       : 1;
    uint32_t RESERVED12                     : 4;
    __IO uint32_t CIN                       : 1;
    __IO uint32_t CSS                       : 1;
    __IO uint32_t CDL                       : 1;
    __IO uint32_t WPL                       : 1;
    __IO uint32_t DATL                      : 4;
    __IO uint32_t CMDL                      : 1;
    uint32_t RESERVED25                     : 7;
} stc_sdioc_pstat_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 1;
    __IO uint8_t DW                         : 1;
    __IO uint8_t HSEN                       : 1;
    uint8_t RESERVED3                       : 2;
    __IO uint8_t EXDW                       : 1;
    __IO uint8_t CDTL                       : 1;
    __IO uint8_t CDSS                       : 1;
} stc_sdioc_hostcon_field_t;

typedef struct
{
    __IO uint8_t PWON                       : 1;
    uint8_t RESERVED1                       : 7;
} stc_sdioc_pwrcon_field_t;

typedef struct
{
    __IO uint8_t SABGR                      : 1;
    __IO uint8_t CR                         : 1;
    __IO uint8_t RWC                        : 1;
    __IO uint8_t IABG                       : 1;
    uint8_t RESERVED4                       : 4;
} stc_sdioc_blkgpcon_field_t;

typedef struct
{
    __IO uint16_t ICE                       : 1;
    uint16_t RESERVED1                      : 1;
    __IO uint16_t CE                        : 1;
    uint16_t RESERVED3                      : 5;
    __IO uint16_t FS                        : 8;
} stc_sdioc_clkcon_field_t;

typedef struct
{
    __IO uint8_t DTO                        : 4;
    uint8_t RESERVED4                       : 4;
} stc_sdioc_toutcon_field_t;

typedef struct
{
    __IO uint8_t RSTA                       : 1;
    __IO uint8_t RSTC                       : 1;
    __IO uint8_t RSTD                       : 1;
    uint8_t RESERVED3                       : 5;
} stc_sdioc_sftrst_field_t;

typedef struct
{
    __IO uint16_t CC                        : 1;
    __IO uint16_t TC                        : 1;
    __IO uint16_t BGE                       : 1;
    uint16_t RESERVED3                      : 1;
    __IO uint16_t BWR                       : 1;
    __IO uint16_t BRR                       : 1;
    __IO uint16_t CIST                      : 1;
    __IO uint16_t CRM                       : 1;
    __IO uint16_t CINT                      : 1;
    uint16_t RESERVED9                      : 6;
    __IO uint16_t EI                        : 1;
} stc_sdioc_norintst_field_t;

typedef struct
{
    __IO uint16_t CTOE                      : 1;
    __IO uint16_t CCE                       : 1;
    __IO uint16_t CEBE                      : 1;
    __IO uint16_t CIE                       : 1;
    __IO uint16_t DTOE                      : 1;
    __IO uint16_t DCE                       : 1;
    __IO uint16_t DEBE                      : 1;
    uint16_t RESERVED7                      : 1;
    __IO uint16_t ACE                       : 1;
    uint16_t RESERVED9                      : 7;
} stc_sdioc_errintst_field_t;

typedef struct
{
    __IO uint16_t CCEN                      : 1;
    __IO uint16_t TCEN                      : 1;
    __IO uint16_t BGEEN                     : 1;
    uint16_t RESERVED3                      : 1;
    __IO uint16_t BWREN                     : 1;
    __IO uint16_t BRREN                     : 1;
    __IO uint16_t CISTEN                    : 1;
    __IO uint16_t CRMEN                     : 1;
    __IO uint16_t CINTEN                    : 1;
    uint16_t RESERVED9                      : 7;
} stc_sdioc_norintsten_field_t;

typedef struct
{
    __IO uint16_t CTOEEN                    : 1;
    __IO uint16_t CCEEN                     : 1;
    __IO uint16_t CEBEEN                    : 1;
    __IO uint16_t CIEEN                     : 1;
    __IO uint16_t DTOEEN                    : 1;
    __IO uint16_t DCEEN                     : 1;
    __IO uint16_t DEBEEN                    : 1;
    uint16_t RESERVED7                      : 1;
    __IO uint16_t ACEEN                     : 1;
    uint16_t RESERVED9                      : 7;
} stc_sdioc_errintsten_field_t;

typedef struct
{
    __IO uint16_t CCSEN                     : 1;
    __IO uint16_t TCSEN                     : 1;
    __IO uint16_t BGESEN                    : 1;
    uint16_t RESERVED3                      : 1;
    __IO uint16_t BWRSEN                    : 1;
    __IO uint16_t BRRSEN                    : 1;
    __IO uint16_t CISTSEN                   : 1;
    __IO uint16_t CRMSEN                    : 1;
    __IO uint16_t CINTSEN                   : 1;
    uint16_t RESERVED9                      : 7;
} stc_sdioc_norintsgen_field_t;

typedef struct
{
    __IO uint16_t CTOESEN                   : 1;
    __IO uint16_t CCESEN                    : 1;
    __IO uint16_t CEBESEN                   : 1;
    __IO uint16_t CIESEN                    : 1;
    __IO uint16_t DTOESEN                   : 1;
    __IO uint16_t DCESEN                    : 1;
    __IO uint16_t DEBESEN                   : 1;
    uint16_t RESERVED7                      : 1;
    __IO uint16_t ACESEN                    : 1;
    uint16_t RESERVED9                      : 7;
} stc_sdioc_errintsgen_field_t;

typedef struct
{
    __IO uint16_t NE                        : 1;
    __IO uint16_t TOE                       : 1;
    __IO uint16_t CE                        : 1;
    __IO uint16_t EBE                       : 1;
    __IO uint16_t IE                        : 1;
    uint16_t RESERVED5                      : 2;
    __IO uint16_t CMDE                      : 1;
    uint16_t RESERVED8                      : 8;
} stc_sdioc_atcerrst_field_t;

typedef struct
{
    __IO uint16_t FNE                       : 1;
    __IO uint16_t FTOE                      : 1;
    __IO uint16_t FCE                       : 1;
    __IO uint16_t FEBE                      : 1;
    __IO uint16_t FIE                       : 1;
    uint16_t RESERVED5                      : 2;
    __IO uint16_t FCMDE                     : 1;
    uint16_t RESERVED8                      : 8;
} stc_sdioc_fea_field_t;

typedef struct
{
    __IO uint16_t FCTOE                     : 1;
    __IO uint16_t FCCE                      : 1;
    __IO uint16_t FCEBE                     : 1;
    __IO uint16_t FCIE                      : 1;
    __IO uint16_t FDTOE                     : 1;
    __IO uint16_t FDCE                      : 1;
    __IO uint16_t FDEBE                     : 1;
    uint16_t RESERVED7                      : 1;
    __IO uint16_t FACE                      : 1;
    uint16_t RESERVED9                      : 7;
} stc_sdioc_fee_field_t;

typedef struct amhw_hc32f460_sdioc {
    uint8_t RESERVED0[4];
    union
    {
        __IO uint16_t BLKSIZE;
        stc_sdioc_blksize_field_t BLKSIZE_f;
    };
    __IO uint16_t BLKCNT;
    __IO uint16_t ARG0;
    __IO uint16_t ARG1;
    union
    {
        __IO uint16_t TRANSMODE;
        stc_sdioc_transmode_field_t TRANSMODE_f;
    };
    union
    {
        __IO uint16_t CMD;
        stc_sdioc_cmd_field_t CMD_f;
    };
    __IO uint16_t RESP0;
    __IO uint16_t RESP1;
    __IO uint16_t RESP2;
    __IO uint16_t RESP3;
    __IO uint16_t RESP4;
    __IO uint16_t RESP5;
    __IO uint16_t RESP6;
    __IO uint16_t RESP7;
    __IO uint16_t BUF0;
    __IO uint16_t BUF1;
    union
    {
        __IO uint32_t PSTAT;
        stc_sdioc_pstat_field_t PSTAT_f;
    };
    union
    {
        __IO uint8_t HOSTCON;
        stc_sdioc_hostcon_field_t HOSTCON_f;
    };
    union
    {
        __IO uint8_t PWRCON;
        stc_sdioc_pwrcon_field_t PWRCON_f;
    };
    union
    {
        __IO uint8_t BLKGPCON;
        stc_sdioc_blkgpcon_field_t BLKGPCON_f;
    };
    uint8_t RESERVED20[1];
    union
    {
        __IO uint16_t CLKCON;
        stc_sdioc_clkcon_field_t CLKCON_f;
    };
    union
    {
        __IO uint8_t TOUTCON;
        stc_sdioc_toutcon_field_t TOUTCON_f;
    };
    union
    {
        __IO uint8_t SFTRST;
        stc_sdioc_sftrst_field_t SFTRST_f;
    };
    union
    {
        __IO uint16_t NORINTST;
        stc_sdioc_norintst_field_t NORINTST_f;
    };
    union
    {
        __IO uint16_t ERRINTST;
        stc_sdioc_errintst_field_t ERRINTST_f;
    };
    union
    {
        __IO uint16_t NORINTSTEN;
        stc_sdioc_norintsten_field_t NORINTSTEN_f;
    };
    union
    {
        __IO uint16_t ERRINTSTEN;
        stc_sdioc_errintsten_field_t ERRINTSTEN_f;
    };
    union
    {
        __IO uint16_t NORINTSGEN;
        stc_sdioc_norintsgen_field_t NORINTSGEN_f;
    };
    union
    {
        __IO uint16_t ERRINTSGEN;
        stc_sdioc_errintsgen_field_t ERRINTSGEN_f;
    };
    union
    {
        __IO uint16_t ATCERRST;
        stc_sdioc_atcerrst_field_t ATCERRST_f;
    };
    uint8_t RESERVED30[18];
    union
    {
        __IO uint16_t FEA;
        stc_sdioc_fea_field_t FEA_f;
    };
    union
    {
        __IO uint16_t FEE;
        stc_sdioc_fee_field_t FEE_f;
    };
} amhw_hc32f460_sdioc_t;

#define AMHW_HC32F460_SDIOC1_INT_VSSEL_BITS_MASK    (0x7)
#define AMHW_HC32F460_SDIOC2_INT_VSSEL_BITS_MASK    (0x7 << 3)

/**
 * \brief ���ݿ鳤�����ú���
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] size      : ���ݿ鳤�ȣ�1~512�ֽڣ�
 */

am_static_inline
void amhw_hc32f460_sdioc_blksize_set (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                      uint16_t               size)
{
    p_hw_sdioc->BLKSIZE_f.TBS = size;
}

/**
 * \brief �趨�������ݿ������
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] count     : Ҫ��������ݿ�����
 */

am_static_inline
void amhw_hc32f460_sdioc_blkcount_set (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                       uint16_t               count)
{
    p_hw_sdioc->BLKCNT = count;
}

/**
 * \brief д�����Ĵ���0
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] arg       : �������
 */

am_static_inline
void amhw_hc32f460_sdioc_arg0_set (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                   uint16_t               arg)
{
    p_hw_sdioc->ARG0 = arg;
}

/**
 * \brief д�����Ĵ���1
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] arg       : �������
 */

am_static_inline
void amhw_hc32f460_sdioc_arg1_set (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                   uint16_t               arg)
{
    p_hw_sdioc->ARG1 = arg;
}

/**
 * \brief ����Ϊ�����ݿ鴫��
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 */

am_static_inline
void amhw_hc32f460_sdioc_transmode_single_blk_set (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->TRANSMODE_f.MULB = 0;
}

/**
 * \brief ����Ϊ�����ݿ鴫��
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 */

am_static_inline
void amhw_hc32f460_sdioc_transmode_multi_blk_set (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->TRANSMODE_f.MULB = 1;
}

typedef enum {
    AMHW_HC32F460_SDIOC_TRANSMODE_DIR_WRITE = 0,
    AMHW_HC32F460_SDIOC_TRANSMODE_DIR_READ  = 1,
} amhw_hc32f460_sdioc_transmode_dir_t;

/**
 * \brief ���ݴ��䷽������
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] dir       : ���䷽��
 */

am_static_inline
void amhw_hc32f460_sdioc_transmode_dir_set (amhw_hc32f460_sdioc_t              *p_hw_sdioc,
                                            amhw_hc32f460_sdioc_transmode_dir_t dir)
{
    p_hw_sdioc->TRANSMODE_f.DDIR = dir;
}

/**
 * \brief �Զ�����ʹ��
 *        ������ݴ���������Զ�����CMD12
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 */

am_static_inline
void amhw_hc32f460_sdioc_transmode_autocmd_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->TRANSMODE_f.ATCEN = 1;
}

/**
 * \brief �Զ��������
 *        �������Զ�����
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 */

am_static_inline
void amhw_hc32f460_sdioc_transmode_autocmd_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->TRANSMODE_f.ATCEN = 0;
}

/**
 * \brief �����ʹ��
 *        �������ݿ����
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 */

am_static_inline
void amhw_hc32f460_sdioc_transmode_blkcnt_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->TRANSMODE_f.BCE = 1;
}

/**
 * \brief ���������
 *        �������ݿ����
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 */

am_static_inline
void amhw_hc32f460_sdioc_transmode_blkcnt_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->TRANSMODE_f.BCE = 0;
}




/**
 * \brief ����������
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] id        : Ҫ���͵�������
 */

am_static_inline
void amhw_hc32f460_sdioc_cmd_id_set (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                     uint8_t               id)
{
    p_hw_sdioc->CMD_f.IDX = id;
}



typedef enum {
    AMHW_HC32F460_SDIOC_CMD_TYPE_NORMAL  = 0,  /** \brief ��ͨ���� */
    AMHW_HC32F460_SDIOC_CMD_TYPE_SUSPEND = 1,  /** \brief �������� */
    AMHW_HC32F460_SDIOC_CMD_TYPE_RESUME  = 2,  /** \brief �ָ����� */
    AMHW_HC32F460_SDIOC_CMD_TYPE_ABORT   = 3,  /** \brief ��ֹ���� */
} amhw_hc32f460_sdioc_cmd_type_t;

/**
 * \brief ������������
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] type      : Ҫ���͵���������
 */

am_static_inline
void amhw_hc32f460_sdioc_cmd_type_set (amhw_hc32f460_sdioc_t          *p_hw_sdioc,
                                       amhw_hc32f460_sdioc_cmd_type_t  type)
{
    p_hw_sdioc->CMD_f.TYP = type;
}

/**
 * \brief ʹ�ܴ���������
 *        ����ǰ������Ҫʹ��������
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 */

am_static_inline
void amhw_hc32f460_sdioc_cmd_dat_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->CMD_f.DAT = 1;
}

/**
 * \brief ���ܴ���������
 *        ����ǰ����ֻʹ��������
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 */

am_static_inline
void amhw_hc32f460_sdioc_cmd_dat_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->CMD_f.DAT = 0;
}

/**
 * \brief ʹ�ܱ�ż��
 *        �����Ӧ���е�������
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 */

am_static_inline
void amhw_hc32f460_sdioc_cmd_ice_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->CMD_f.ICE = 1;
}

/**
 * \brief ���ܱ�ż��
 *        �������Ӧ���е�������
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 */

am_static_inline
void amhw_hc32f460_sdioc_cmd_ice_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->CMD_f.ICE = 0;
}

/**
 * \brief ʹ��CRC���
 *        �����Ӧ���е�CRCУ����
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] flag      : AM_TRUE/AM_FALSE
 */

am_static_inline
void amhw_hc32f460_sdioc_cmd_crc_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                         am_bool_t              flag)
{
    p_hw_sdioc->CMD_f.CCE = flag;
}


typedef enum {
    AMHW_HC32F460_SDIOC_CMD_NO_RESPONSE = 0,
    AMHW_HC32F460_SDIOC_CMD_136BIT_RESPONSE,
    AMHW_HC32F460_SDIOC_CMD_48BIT_RESPONSE,
    AMHW_HC32F460_SDIOC_CMD_48BIT_BUSY_RESPONS,
}amhw_hc32f460_sdioc_cmd_res_type_t;


/**
 * \brief ����Ӧ������
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 */

am_static_inline
void amhw_hc32f460_sdioc_cmd_restype_set (amhw_hc32f460_sdioc_t              *p_hw_sdioc,
                                          amhw_hc32f460_sdioc_cmd_res_type_t  type)
{
    p_hw_sdioc->CMD_f.RESTYP = type;
}



/**
 * \brief SDIOC �������ýṹ��
 */
typedef struct amhw_hc32f460_sdioc_cmd_cfg {
    uint8_t                             cmd_id;     /* ������ */

    uint32_t                            cmd_arg;    /* ������� */

    amhw_hc32f460_sdioc_cmd_type_t      cmd_type;   /* �������� */

    amhw_hc32f460_sdioc_cmd_res_type_t  rsp_type;   /* ��Ӧ���� */

    am_bool_t                           use_data;   /* �Ƿ�ʹ�������� */
} amhw_hc32f460_sdioc_cmd_cfg_t;

/**
 * \brief ��������Ĵ�������������
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] flag      : Ҫ���õ�ֵ
 */

am_static_inline
void amhw_hc32f460_sdioc_cmd_set (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                  uint16_t               flag)
{
    p_hw_sdioc->CMD = flag;
}


/**
 * \brief ��ȡӦ����Ϣ��0~15λ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return Ӧ����Ϣ��0��15λ
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_resp0_15b_read (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->RESP0;
}

/**
 * \brief ��ȡӦ����Ϣ��16~31λ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return Ӧ����Ϣ��16��31λ
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_resp16_31b_read (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->RESP1;
}
/**
 * \brief ��ȡӦ����Ϣ��32~47λ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return Ӧ����Ϣ��32��47λ
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_resp32_47b_read (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->RESP2;
}
/**
 * \brief ��ȡӦ����Ϣ��48~63λ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return Ӧ����Ϣ��48��63λ
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_resp48_63b_read (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->RESP3;
}
/**
 * \brief ��ȡӦ����Ϣ��64~79λ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return Ӧ����Ϣ��64��79λ
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_resp64_79b_read (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->RESP4;
}
/**
 * \brief ��ȡӦ����Ϣ��80~95λ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return Ӧ����Ϣ��80��95λ
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_resp80_95b_read (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->RESP5;
}
/**
 * \brief ��ȡӦ����Ϣ��96~111λ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return Ӧ����Ϣ��96��111λ
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_resp96_111b_read (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->RESP6;
}
/**
 * \brief ��ȡӦ����Ϣ��112~127λ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return Ӧ����Ϣ��112��127λ
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_resp112_127b_read (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->RESP7;
}

/**
 * \brief д���ݵĵ�16λ������Ĵ���
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] data      : Ҫд�������
 */
am_static_inline
void amhw_hc32f460_sdioc_data_low_write (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                             uint16_t               data)
{
    p_hw_sdioc->BUF0 = data;
}

/**
 * \brief д���ݵĸ�16λ������Ĵ���
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] data      : Ҫд�������
 */
am_static_inline
void amhw_hc32f460_sdioc_data_high_write (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                          uint16_t               data)
{
    p_hw_sdioc->BUF1 = data;
}

/**
 * \brief д32λ���ݵ�buffer
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] data      : Ҫд�������
 */
am_static_inline
void amhw_hc32f460_sdioc_data_write (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                     uint32_t               data)
{
    uint32_t *addr_buffer = (uint32_t *)&(p_hw_sdioc->BUF0);
    *addr_buffer = data;
}



/**
 * \brief �ӻ���Ĵ�����ȡ���ݵĵ�16λ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return    ���յ����ݵĵ�16λ
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_data_low_read (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->BUF0;
}

/**
 * \brief �ӻ���Ĵ�����ȡ���ݵĸ�16λ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return    ���յ����ݵĸ�16λ
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_data_high_read (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->BUF1;
}

/**
 * \brief �ӻ���Ĵ�����ȡ32λ����
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return    ����32λ������
 */
am_static_inline
uint32_t amhw_hc32f460_sdioc_data_read (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    uint32_t *addr_buffer = (uint32_t *)(&(p_hw_sdioc->BUF0));
    return (*addr_buffer);
}



/* ����״̬��־ */
#define  AMHW_HC32F460_SDIOC_PSTAT_CMDL (1 << 24)   /* ������״̬ */
#define  AMHW_HC32F460_SDIOC_PSTAT_DATL (0xF << 20) /* ������״̬��D0-D3�� */
#define  AMHW_HC32F460_SDIOC_PSTAT_WPL  (1 << 19)   /* д������״̬ */
#define  AMHW_HC32F460_SDIOC_PSTAT_CDL  (1 << 18)   /* ��ʶ����״̬ */
#define  AMHW_HC32F460_SDIOC_PSTAT_CSS  (1 << 17)   /* �豸�ȶ�״̬ */
#define  AMHW_HC32F460_SDIOC_PSTAT_CIN  (1 << 16)   /* �豸����״̬ */
#define  AMHW_HC32F460_SDIOC_PSTAT_BRE  (1 << 11)   /* ���ݻ����� */
#define  AMHW_HC32F460_SDIOC_PSTAT_BWE  (1 << 10)   /* ���ݻ���� */
#define  AMHW_HC32F460_SDIOC_PSTAT_RTA  (1 << 9)    /* ������״̬ */
#define  AMHW_HC32F460_SDIOC_PSTAT_WTA  (1 << 8)    /* д����״̬ */
#define  AMHW_HC32F460_SDIOC_PSTAT_DA   (1 << 2)    /* �����ߴ���״̬ */
#define  AMHW_HC32F460_SDIOC_PSTAT_CID  (1 << 1)    /* �������������� */
#define  AMHW_HC32F460_SDIOC_PSTAT_CIC  (1 << 0)    /* �������� */

/**
 * \brief ��ȡ����״̬
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return    ����״̬
 */
am_static_inline
uint32_t amhw_hc32f460_sdioc_pstat_all_get (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->PSTAT;
}

/**
 * \brief ��ȡ������Ӧ״̬λ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return    ����״̬
 */
am_static_inline
uint32_t amhw_hc32f460_sdioc_pstat_get (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                        uint32_t               flag)
{
    return (p_hw_sdioc->PSTAT & flag) ? AM_TRUE : AM_FALSE;
}


typedef enum{
    AMHW_HC32F460_SDIOC_HOSTCON_CDSS_TRUE = 0, /* ������ʵSDIOx_CD�߷�ӳ��ʶ��״̬ */
    AMHW_HC32F460_SDIOC_HOSTCON_CDSS_TEST = 1, /* ���ÿ�ʶ������źŷ�ӳ��ʶ��״̬ */
}amhw_hc32f460_sdioc_hostcon_cdss_t;

/**
 * \brief ��ʶ����ѡ��
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] cdss      : ��ʶ����ѡ���־
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_hostcon_cdss_set (amhw_hc32f460_sdioc_t             *p_hw_sdioc,
                                           amhw_hc32f460_sdioc_hostcon_cdss_t cdss)
{
    p_hw_sdioc->HOSTCON_f.CDSS = cdss;
}

/**
 * \brief ��ʶ������źż���Ƿ����豸����
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * return AM_TRUE : ��⵽�豸����
 *        AM_FALSE: ���豸����
 */
am_static_inline
am_bool_t amhw_hc32f460_sdioc_hostcon_cdtl_check (amhw_hc32f460_sdioc_t  *p_hw_sdioc)
{
    return (p_hw_sdioc->HOSTCON_f.CDTL) ? AM_FALSE : AM_TRUE;
}



/**
 * \brief ��չ����λ����������λ��Ϊ8λ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_hostcon_exdw_enable (amhw_hc32f460_sdioc_t  *p_hw_sdioc)
{
    p_hw_sdioc->HOSTCON_f.EXDW = 1;
}

/**
 * \brief ��ֹ��չ����λ����������λ������DWλ�趨
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_hostcon_exdw_disable (amhw_hc32f460_sdioc_t  *p_hw_sdioc)
{
    p_hw_sdioc->HOSTCON_f.EXDW = 0;
}

typedef enum {
    AMHW_HC32F460_HOSTCON_DATA_WIDE_1BIT = 0,
    AMHW_HC32F460_HOSTCON_DATA_WIDE_4BIT = 1,
}amhw_hc32f460_sdioc_hostcon_datawide_t;

/**
 * \brief ����λ��ѡ�񣨷���չ��
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_hostcon_datawide_set (amhw_hc32f460_sdioc_t                  *p_hw_sdioc,
                                               amhw_hc32f460_sdioc_hostcon_datawide_t  flag)
{
    p_hw_sdioc->HOSTCON_f.DW = flag;
}

/**
 * \brief sdio�ٶ�ģʽ����
 */
typedef enum amhw_hc32f460_sdioc_speed_mode {
    AMHW_HC32F460_SDIO_SPEED_MODE_LOW      = 0x0,   /**< \brief ����ģʽ */
    AMHW_HC32F460_SDIO_SPEED_MODE_HIGH     = 0x1,   /**< \brief ����ģʽ */
} amhw_hc32f460_sdioc_speed_mode_t;

/**
 * \brief ���ø���ģʽ
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_hostcon_speedmode_set (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                                amhw_hc32f460_sdioc_speed_mode_t speed_mode)
{
    p_hw_sdioc->HOSTCON_f.HSEN = speed_mode;
}


/**
 * \brief SDIOC������ʹ��
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->PWRCON_f.PWON = 1;
}

/**
 * \brief SDIOC����������
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->PWRCON_f.PWON = 0;
}

/**
 * \brief �������ݿ��϶�ڼ����SDIO�豸�ж�
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_blkgpcon_iabg_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->BLKGPCON_f.IABG = 1;
}

/**
 * \brief ��ֹ���ݿ��϶�ڼ����SDIO�豸�ж�
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_blkgpcon_iabg_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->BLKGPCON_f.IABG = 0;
}

/**
 * \brief ���ö��ȴ�����
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_blkgpcon_read_wait_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->BLKGPCON_f.RWC = 1;
}

/**
 * \brief ���ö��ȴ�����
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_blkgpcon_read_wait_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->BLKGPCON_f.RWC = 0;
}

/**
 * \brief ��������ݿ��϶ֹͣ�Ĵ��䣬��������
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_blkgpcon_continue_trans (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->BLKGPCON_f.CR = 1;
}

/**
 * \brief �����ݿ��϶ʱֹͣ����
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_blkgpcon_stop_trans_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->BLKGPCON_f.SABGR = 1;
}

/**
 * \brief �������ݿ��϶ʱֹͣ����
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_blkgpcon_stop_trans_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->BLKGPCON_f.SABGR = 0;
}

/* SDIOx_CK ʱ�ӷ�Ƶѡ�񣬻�׼ʱ��ΪEXCLK */
typedef enum {
    AMHW_HC32F460_SDIOC_CK_DIV_1   = 0x00, /* EXCLK��1��Ƶ */
    AMHW_HC32F460_SDIOC_CK_DIV_2   = 0x01, /* EXCLK��2��Ƶ */
    AMHW_HC32F460_SDIOC_CK_DIV_4   = 0x02, /* EXCLK��4��Ƶ */
    AMHW_HC32F460_SDIOC_CK_DIV_8   = 0x04, /* EXCLK��8��Ƶ */
    AMHW_HC32F460_SDIOC_CK_DIV_16  = 0x08, /* EXCLK��16��Ƶ */
    AMHW_HC32F460_SDIOC_CK_DIV_32  = 0x10, /* EXCLK��32��Ƶ */
    AMHW_HC32F460_SDIOC_CK_DIV_64  = 0x20, /* EXCLK��64��Ƶ */
    AMHW_HC32F460_SDIOC_CK_DIV_128 = 0x40, /* EXCLK��128��Ƶ */
    AMHW_HC32F460_SDIOC_CK_DIV_256 = 0x80, /* EXCLK��256��Ƶ */
}amhw_hc32f460_sdioc_clkdiv_t;


/**
 * \brief ����SDIO_CKʱ�ӷ�Ƶ,��׼ʱ��ΪEXCLK
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_clkcon_clkdiv_set (amhw_hc32f460_sdioc_t       *p_hw_sdioc,
                                            amhw_hc32f460_sdioc_clkdiv_t clk_div)
{
    p_hw_sdioc->CLKCON_f.FS = clk_div;
}

/**
 * \brief SDIOx_CK���
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_clkcon_ck_output (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->CLKCON_f.CE = 1;
}

/**
 * \brief SDIOx_CKֹͣ���
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_clkcon_ck_stop_output (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->CLKCON_f.CE = 0;
}

/**
 * \brief SDIOx_CKʱ�ӿ���
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_clkcon_ck_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->CLKCON_f.ICE = 1;
}

/**
 * \brief SDIOx_CKʱ�ӹر�
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_clkcon_ck_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    p_hw_sdioc->CLKCON_f.ICE = 0;
}

typedef enum {
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_13 = 0,  /* ��ʱʱ��ΪEXCLK �� 2^13 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_14 = 1,  /* ��ʱʱ��ΪEXCLK �� 2^14 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_15 = 2,  /* ��ʱʱ��ΪEXCLK �� 2^15 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_16 = 3,  /* ��ʱʱ��ΪEXCLK �� 2^16 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_17 = 4,  /* ��ʱʱ��ΪEXCLK �� 2^17 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_18 = 5,  /* ��ʱʱ��ΪEXCLK �� 2^18 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_19 = 6,  /* ��ʱʱ��ΪEXCLK �� 2^19 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_20 = 7,  /* ��ʱʱ��ΪEXCLK �� 2^20 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_21 = 8,  /* ��ʱʱ��ΪEXCLK �� 2^21 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_22 = 9,  /* ��ʱʱ��ΪEXCLK �� 2^22 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_23 = 10, /* ��ʱʱ��ΪEXCLK �� 2^23 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_24 = 11, /* ��ʱʱ��ΪEXCLK �� 2^24 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_25 = 12, /* ��ʱʱ��ΪEXCLK �� 2^25 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_26 = 13, /* ��ʱʱ��ΪEXCLK �� 2^26 */
    AMHW_HC32F460_SDIOC_TIMEOUT_EXCLK_2_27 = 14, /* ��ʱʱ��ΪEXCLK �� 2^27 */
}amhw_hc32f460_sdioc_timeout_time_t;


/**
 * \brief �趨��ʱʱ��
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] time      : Ҫ�趨�ĳ�ʱʱ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_timeout_time_set (amhw_hc32f460_sdioc_t               *p_hw_sdioc,
                                            amhw_hc32f460_sdioc_timeout_time_t  time)
{
    p_hw_sdioc->TOUTCON_f.DTO = time;
}

/**
 * \brief ���ݸ�λ
 *        ��λ����������صļĴ������������¼Ĵ���λ��
 *        BUF0,BUF1
 *        PSTAT.BRE, PSTAT.BWE, PSTAT.RTA, PSTAT.WTA, PSTAT.DLA, PSTAT.CID
 *        BLKGPCOM.CR, BLKGPCON.SABGR
 *        NORINTST.BRR, NORINTST.BWR, NORINTST.BGE, NORINTST.TC
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] flag      : �Ƿ�������ݸ�λ��AM_TRUE:��λ��AM_FALSE:����λ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_data_rst (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                   am_bool_t              flag)
{
    p_hw_sdioc->SFTRST_f.RSTD = flag;
}

/**
 * \brief ���λ
 *        ��λ����������صļĴ������������¼Ĵ���λ��
 *        PSTAT.CIC
 *        NORINTST.CC
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] flag      : �Ƿ�������ݸ�λ��AM_TRUE:��λ��AM_FALSE:����λ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_cmd_rst (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                  am_bool_t              flag)
{
    p_hw_sdioc->SFTRST_f.RSTC = flag;
}

/**
 * \brief ȫ����λ
 *        ��λ����ʶ�������ȫ��SDIOC�Ĵ���
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] flag      : �Ƿ�������ݸ�λ��AM_TRUE:��λ��AM_FALSE:����λ��
 *
 */
am_static_inline
void amhw_hc32f460_sdioc_all_rst (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                  am_bool_t              flag)
{
    p_hw_sdioc->SFTRST_f.RSTA = flag;
}

#define AMHW_HC32F460_SDIOC_NORMAL_INT_EI   (1 << 15) /* �����ж� */
#define AMHW_HC32F460_SDIOC_NORMAL_INT_CINT (1 << 8)  /* ���ж� */
#define AMHW_HC32F460_SDIOC_NORMAL_INT_CRM  (1 << 7)  /* ���Ƴ� */
#define AMHW_HC32F460_SDIOC_NORMAL_INT_CIST (1 << 6)  /* ������ */
#define AMHW_HC32F460_SDIOC_NORMAL_INT_BRR  (1 << 5)  /* �������ɶ� */
#define AMHW_HC32F460_SDIOC_NORMAL_INT_BWR  (1 << 4)  /* ��������д */
#define AMHW_HC32F460_SDIOC_NORMAL_INT_BGE  (1 << 2)  /* ���ݿ��϶ֹͣ���� */
#define AMHW_HC32F460_SDIOC_NORMAL_INT_TC   (1 << 1)  /* ������� */
#define AMHW_HC32F460_SDIOC_NORMAL_INT_CC   (1 << 0)  /* ������� */
#define AMHW_HC32F460_SDIOC_NORMAL_INT_ALL  (AMHW_HC32F460_SDIOC_NORMAL_INT_CRM  | \
                                             AMHW_HC32F460_SDIOC_NORMAL_INT_CIST | \
                                             AMHW_HC32F460_SDIOC_NORMAL_INT_BRR  | \
                                             AMHW_HC32F460_SDIOC_NORMAL_INT_BWR  | \
                                             AMHW_HC32F460_SDIOC_NORMAL_INT_BGE  | \
                                             AMHW_HC32F460_SDIOC_NORMAL_INT_TC   | \
                                             AMHW_HC32F460_SDIOC_NORMAL_INT_CC)/* ������ͨ�жϣ������жϺͿ��жϳ��� */




/**
 * \brief ��ȡ��ͨ�ж�״̬��־
 *
 * \param[in] p_hw_sdioc: ָ��SDIOC�Ĵ����ṹ���ָ��

 * \return  �ж�״̬
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_normal_intstat_all_get (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->NORINTST;
}

/**
 * \brief ��ȡ��ͨ�ж�ĳһ�жϵ�״̬��־
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] intstat_mask: �жϱ�־����

 * \return  �ж�״̬
 */
am_static_inline
am_bool_t amhw_hc32f460_sdioc_normal_intstat_get (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                                  uint16_t               intstat_mask)
{
    return (p_hw_sdioc->NORINTST & intstat_mask) ? AM_TRUE : AM_FALSE;
}

/**
 * \brief �����ͨ�ж�ĳһ�жϵ�״̬��־
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] intstat_mask: �жϱ�־����(�����ж�EI�����ж�CINT���⣬���ж�CINT��SDIO�豸���������λ)
 *
 * \return  �ж�״̬
 */
am_static_inline
void amhw_hc32f460_sdioc_normal_intstat_clr (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                             uint32_t               intstat_mask)
{
    p_hw_sdioc->NORINTST = intstat_mask;
}

/**
 * \brief ��ͨ�ж�״̬ʹ��(�����������ж�)
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] intstat_mask: �жϱ�־����
 * \return  �ж�״̬
 */
am_static_inline
void amhw_hc32f460_sdioc_normal_intstat_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                                uint16_t               intstat_mask)
{
    p_hw_sdioc->NORINTSTEN |= intstat_mask;
}

/**
 * \brief ��ͨ�ж�״̬��ֹ(�����������ж�)
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] intstat_mask: �жϱ�־����
 */
am_static_inline
void amhw_hc32f460_sdioc_normal_intstat_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                                 uint16_t               intstat_mask)
{
    p_hw_sdioc->NORINTSTEN &= (~intstat_mask);
}

/**
 * \brief ��ͨ�ж��ź�ʹ��(�����������ж�)
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] intstat_mask: �жϱ�־����
 */
am_static_inline
void amhw_hc32f460_sdioc_normal_int_signal_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                                   uint16_t               int_mask)
{
    p_hw_sdioc->NORINTSGEN |= int_mask;
}



/**
 * \brief ��ͨ�ж��źŽ�ֹ(�����������ж�)
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] intstat_mask: �жϱ�־����
 */
am_static_inline
void amhw_hc32f460_sdioc_normal_int_signal_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                                    uint16_t               int_mask)
{
	p_hw_sdioc->NORINTSGEN &= (~int_mask);
}


#define AMHW_HC32F460_SDIOC_ERR_INT_ACE  (1 << 8) /* �Զ������������ */
#define AMHW_HC32F460_SDIOC_ERR_INT_DEBE (1 << 6) /* ����ֹͣλ���� */
#define AMHW_HC32F460_SDIOC_ERR_INT_DCE  (1 << 5) /* ����CRCУ����� */
#define AMHW_HC32F460_SDIOC_ERR_INT_DTOE (1 << 4) /* ���ݳ�ʱ���� */
#define AMHW_HC32F460_SDIOC_ERR_INT_CIE  (1 << 3) /* �����Ŵ��� */
#define AMHW_HC32F460_SDIOC_ERR_INT_CEBE (1 << 2) /* ����ֹͣλ���� */
#define AMHW_HC32F460_SDIOC_ERR_INT_CCE  (1 << 1) /* ����CRCУ����� */
#define AMHW_HC32F460_SDIOC_ERR_INT_CTOE (1 << 0) /* ���ʱ���� */
#define AMHW_HC32F460_SDIOC_ERR_INT_ALL  (AMHW_HC32F460_SDIOC_ERR_INT_ACE  | \
                                          AMHW_HC32F460_SDIOC_ERR_INT_DEBE | \
                                          AMHW_HC32F460_SDIOC_ERR_INT_DCE  | \
                                          AMHW_HC32F460_SDIOC_ERR_INT_DTOE | \
                                          AMHW_HC32F460_SDIOC_ERR_INT_CIE  | \
                                          AMHW_HC32F460_SDIOC_ERR_INT_CEBE | \
                                          AMHW_HC32F460_SDIOC_ERR_INT_CCE  | \
                                          AMHW_HC32F460_SDIOC_ERR_INT_CTOE)


/**
 * \brief ��ȡ�����ж�״̬��־
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 *
 * \return  �����ж�״̬
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_err_intstat_all_get (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->ERRINTST;
}

/**
 * \brief ��������жϵ�״̬��־
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] intstat_mask: �жϱ�־����(�����ж�EI�����ж�CINT���⣬���ж�CINT��SDIO�豸���������λ)
 *
 * \return  �ж�״̬
 */
am_static_inline
void amhw_hc32f460_sdioc_err_intstat_clr (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                          uint32_t               int_mask)
{
    p_hw_sdioc->ERRINTST = int_mask;
}


/**
 * \brief �����ж�״̬ʹ��
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] int_mask    : �����ж�����
 */
am_static_inline
void amhw_hc32f460_sdioc_err_intstat_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                             uint16_t               int_mask)
{
    p_hw_sdioc->ERRINTSTEN |= int_mask;
}

/**
 * \brief �����ж�״̬����
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] int_mask    : �����ж�����
 */
am_static_inline
void amhw_hc32f460_sdioc_err_intstat_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                              uint16_t               int_mask)
{
    p_hw_sdioc->ERRINTSTEN &= (~int_mask);
}


/**
 * \brief �����ж��ź�ʹ��
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] int_mask    : �����ж�����
 */
am_static_inline
void amhw_hc32f460_sdioc_err_int_signal_enable (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                                uint16_t               int_mask)
{
    p_hw_sdioc->ERRINTSGEN |= int_mask;
}

/**
 * \brief �����ж��źŽ���
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] int_mask    : �����ж�����
 */
am_static_inline
void amhw_hc32f460_sdioc_err_int_signal_disable (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                                 uint16_t               int_mask)
{
    p_hw_sdioc->ERRINTSGEN &= (~int_mask);
}

#define AMHW_HC32F460_SDIOC_AUTOCMD_ERRSTAT_CMDE (1 << 7) /* δ���ʹ��� */
#define AMHW_HC32F460_SDIOC_AUTOCMD_ERRSTAT_IE   (1 << 4) /* �����Ŵ��� */
#define AMHW_HC32F460_SDIOC_AUTOCMD_ERRSTAT_EBE  (1 << 3) /* ֹͣλ���� */
#define AMHW_HC32F460_SDIOC_AUTOCMD_ERRSTAT_CE   (1 << 2) /* ���ݳ�ʱ���� */
#define AMHW_HC32F460_SDIOC_AUTOCMD_ERRSTAT_TOE  (1 << 1) /* ���ʱ���� */
#define AMHW_HC32F460_SDIOC_AUTOCMD_ERRSTAT_NE   (1 << 0) /* δִ�д��� */

/**
 * \brief ��ȡ�Զ��������״̬
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] int_mask    : �����ж�����
 */
am_static_inline
uint16_t amhw_hc32f460_sdioc_err_int_signal_all_get (amhw_hc32f460_sdioc_t *p_hw_sdioc)
{
    return p_hw_sdioc->ATCERRST;
}

/**
 * \brief ��ȡ�Զ��������״̬
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] int_mask    : �Զ������ж�����
 */
am_static_inline
am_bool_t amhw_hc32f460_sdioc_autocmd_err_stat_get (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                                    uint16_t               int_mask)
{
    return (p_hw_sdioc->ATCERRST & int_mask) ? AM_TRUE : AM_FALSE;
}

/**
 * \brief ǿ�Ʒ���ĳ�Զ��������״̬
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] int_mask    : �Զ������ж�����
 */
am_static_inline
void amhw_hc32f460_sdioc_autocmd_err_stat_set (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                               uint16_t               int_mask)
{
    p_hw_sdioc->FEA |= int_mask;
}

/**
 * \brief ǿ�Ʒ���ĳ����״̬
 *
 * \param[in] p_hw_sdioc  : ָ��SDIOC�Ĵ����ṹ���ָ��
 * \param[in] int_mask    : �����ж�����
 */
am_static_inline
void amhw_hc32f460_sdioc_err_stat_set (amhw_hc32f460_sdioc_t *p_hw_sdioc,
                                       uint16_t               int_mask)
{
    p_hw_sdioc->FEE |= int_mask;
}

/**
 * @} amhw_hc32f460_if_sdioc
 */

#ifdef __cplusplus
}
#endif

#endif /* __AMHW_HC32F460_SDIOC_H */

/* end of file */