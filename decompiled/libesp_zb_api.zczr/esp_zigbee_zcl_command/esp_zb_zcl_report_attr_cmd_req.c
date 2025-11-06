/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_report_attr_cmd_req(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined1 *puVar9;
  uint uVar10;
  char cVar11;
  char cVar12;
  undefined4 uVar13;
  int unaff_s3;
  int unaff_s5;
  
  bVar1 = *(byte *)(param_1 + 0x12);
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 != 0) {
    cVar12 = ((bVar1 & 4) == 0) + '\x01';
    if ((*(byte *)(param_1 + 0x12) & 3) == 0) {
      *(undefined2 *)(param_1 + 0x14) = 0xffff;
    }
    iVar4 = zb_zcl_get_attr_desc_manuf_a
                      (*(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),cVar12,
                       *(undefined2 *)(param_1 + 0x16),*(undefined2 *)(param_1 + 0x14));
    if (iVar4 != 0) {
      if (((*(byte *)(iVar4 + 3) & 4) == 0) || ((byte)(*(char *)(iVar4 + 2) + 0xb8U) < 10)) {
        return 0x106;
      }
      uVar2 = *(uint *)(iVar3 + 0x1b);
      cVar11 = '\0';
      while( true ) {
        if (*(char *)(iVar3 + 0x1a) == cVar11) goto _L0;
        if ((((*(short *)(uVar2 + 2) == *(short *)(param_1 + 0x10)) &&
             (*(char *)(uVar2 + 4) == cVar12)) &&
            (*(short *)(uVar2 + 6) == *(short *)(param_1 + 0x16))) &&
           (*(short *)(uVar2 + 0x36) == *(short *)(param_1 + 0x14))) break;
        cVar11 = cVar11 + '\x01';
        uVar2 = uVar2 + 0x38;
      }
      unaff_s3 = zb_buf_get_out_func();
      uVar13 = 0x101;
      if (unaff_s3 == 0) goto _L0;
      uVar10 = *(uint *)(param_1 + 0x10);
      iVar4 = zb_zcl_construct_general_command_header
                        (uVar10 >> 0x12 & 1,uVar10 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                         uVar10 >> 0x13 & 1,10);
      iVar5 = zb_buf_get_ptr_off_func(unaff_s3,iVar4);
      iVar6 = zb_buf_len_func(unaff_s3);
      zb_buf_alloc_right_func(unaff_s3,iVar5 - iVar6);
      unaff_s5 = 0xffff;
_L0:
      puVar7 = (undefined2 *)
               zb_zcl_get_attr_desc_manuf_a
                         (*(undefined1 *)(uVar2 + 1),*(undefined2 *)(uVar2 + 2),
                          *(undefined1 *)(uVar2 + 4),*(undefined2 *)(uVar2 + 6),
                          *(undefined2 *)(uVar2 + 0x36));
      iVar5 = zb_zcl_can_cluster_be_fragmented
                        (*(undefined2 *)(uVar2 + 0x34),*(undefined2 *)(uVar2 + 2));
      if (iVar5 == 0) {
        iVar4 = zb_buf_get_ptr_off_func(unaff_s3,iVar4);
        iVar5 = 0x52;
      }
      else {
        iVar5 = zb_buf_get_max_size_func(unaff_s3);
        iVar4 = zb_buf_get_ptr_off_func(unaff_s3,iVar4);
        iVar5 = iVar5 + -0x2d;
      }
      iVar8 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(puVar7 + 1),*(undefined4 *)(puVar7 + 3))
      ;
      iVar6 = unaff_s3;
      if (iVar8 == unaff_s5) goto _L0;
      if (((iVar5 - iVar4 & 0xffffU) - 0x19 & 0xffff) < iVar8 + 3U) goto _L0;
      zb_buf_alloc_right_func(unaff_s3);
      puVar9 = (undefined1 *)zb_put_next_htole16(*puVar7);
      *puVar9 = *(undefined1 *)(puVar7 + 1);
      uVar13 = esp_zb_zcl_put_attribute_value(*(undefined4 *)(puVar7 + 3),iVar8);
      zb_zcl_finish_and_send_packet
                (unaff_s3,uVar13,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8)
                 ,*(undefined1 *)(uVar2 + 1),*(undefined2 *)(uVar2 + 0x34),
                 *(undefined2 *)(uVar2 + 2));
_L0:
      uVar13 = 0;
_L0:
      do {
        if (uVar2 < *(int *)(iVar3 + 0x1b) + (uint)*(byte *)(iVar3 + 0x1a) * 0x38) {
          return uVar13;
        }
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zcl_command.c"
                  ,0x107);
        iVar6 = unaff_s3;
_L0:
        iVar4 = zb_zcl_can_cluster_be_fragmented
                          (*(undefined2 *)(uVar2 + 0x34),*(undefined2 *)(uVar2 + 2));
        if (iVar4 == 0) {
_L0:
          uVar13 = 0x104;
          unaff_s3 = iVar6;
        }
        else {
          iVar4 = zb_buf_get_max_size_func(iVar6);
          unaff_s3 = zb_buf_get_func(0,iVar4 + 1);
          if (unaff_s3 != 0) goto _L0;
          uVar13 = 0x101;
          unaff_s3 = iVar6;
        }
        zb_buf_free_func(unaff_s3);
      } while( true );
    }
  }
  return 0x105;
_L0:
  zb_buf_copy_func(iVar6);
  zb_buf_free_func(iVar6);
  iVar4 = zb_buf_begin_func(unaff_s3);
  iVar5 = zb_buf_len_func(unaff_s3);
  iVar4 = iVar4 + iVar5;
  goto _L0;
}

