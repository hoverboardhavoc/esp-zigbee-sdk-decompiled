/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
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
  undefined1 *puVar7;
  uint uVar8;
  char cVar9;
  char cVar10;
  undefined4 uVar11;
  int unaff_s3;
  int unaff_s5;
  int unaff_s6;
  undefined2 *unaff_s7;
  int unaff_s8;
  
  bVar1 = *(byte *)(param_1 + 0x12);
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 != 0) {
    cVar10 = ((bVar1 & 4) == 0) + '\x01';
    if ((*(byte *)(param_1 + 0x12) & 3) == 0) {
      *(undefined2 *)(param_1 + 0x14) = 0xffff;
    }
    iVar4 = zb_zcl_get_attr_desc_manuf_a
                      (*(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),cVar10,
                       *(undefined2 *)(param_1 + 0x16),*(undefined2 *)(param_1 + 0x14));
    if (iVar4 != 0) {
      if (((*(byte *)(iVar4 + 3) & 4) == 0) || ((byte)(*(char *)(iVar4 + 2) + 0xb8U) < 10)) {
        return 0x106;
      }
      uVar2 = *(uint *)(iVar3 + 0x1b);
      cVar9 = '\0';
      while( true ) {
        if (*(char *)(iVar3 + 0x1a) == cVar9) goto _L0;
        if ((((*(short *)(uVar2 + 2) == *(short *)(param_1 + 0x10)) &&
             (*(char *)(uVar2 + 4) == cVar10)) &&
            (*(short *)(uVar2 + 6) == *(short *)(param_1 + 0x16))) &&
           (*(short *)(uVar2 + 0x36) == *(short *)(param_1 + 0x14))) break;
        cVar9 = cVar9 + '\x01';
        uVar2 = uVar2 + 0x38;
      }
      iVar4 = zb_buf_get_out_func();
      uVar11 = 0x101;
      unaff_s3 = iVar4;
      if (iVar4 == 0) goto _L0;
      uVar8 = *(uint *)(param_1 + 0x10);
      unaff_s8 = zb_zcl_construct_general_command_header
                           (uVar8 >> 0x12 & 1,uVar8 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                            uVar8 >> 0x13 & 1,10);
      iVar5 = zb_buf_get_ptr_off_func(iVar4,unaff_s8);
      iVar6 = zb_buf_len_func(iVar4);
      zb_buf_alloc_right_func(iVar4,iVar5 - iVar6);
      unaff_s6 = 0x52;
      unaff_s5 = 0xffff;
      do {
        unaff_s7 = (undefined2 *)
                   zb_zcl_get_attr_desc_manuf_a
                             (*(undefined1 *)(uVar2 + 1),*(undefined2 *)(uVar2 + 2),
                              *(undefined1 *)(uVar2 + 4),*(undefined2 *)(uVar2 + 6),
                              *(undefined2 *)(uVar2 + 0x36));
        iVar5 = zb_zcl_can_cluster_be_fragmented
                          (*(undefined2 *)(uVar2 + 0x34),*(undefined2 *)(uVar2 + 2));
        unaff_s3 = iVar4;
        if (iVar5 == 0) goto _L0;
        iVar5 = zb_buf_get_max_size_func(iVar4);
        iVar4 = zb_buf_get_ptr_off_func(iVar4,unaff_s8);
        uVar8 = (iVar5 + -0x2d) - iVar4;
_L0:
        iVar4 = esp_zb_zcl_get_attribute_size
                          (*(undefined1 *)(unaff_s7 + 1),*(undefined4 *)(unaff_s7 + 3));
        if (iVar4 == unaff_s5) {
_L0:
          uVar11 = 0x104;
_L0:
          zb_buf_free_func(unaff_s3);
_L0:
          if (uVar2 < *(int *)(iVar3 + 0x1b) + (uint)*(byte *)(iVar3 + 0x1a) * 0x38) {
            return uVar11;
          }
          zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zcl_command.c"
                    ,0x107);
_L0:
          iVar4 = zb_buf_get_ptr_off_func(unaff_s3,unaff_s8);
          uVar8 = unaff_s6 - iVar4;
          goto _L0;
        }
        if (iVar4 + 3U <= ((uVar8 & 0xffff) - 0x19 & 0xffff)) {
          zb_buf_alloc_right_func(unaff_s3);
          puVar7 = (undefined1 *)zb_put_next_htole16(*unaff_s7);
          *puVar7 = *(undefined1 *)(unaff_s7 + 1);
          uVar11 = esp_zb_zcl_put_attribute_value(*(undefined4 *)(unaff_s7 + 3),iVar4);
          zb_zcl_finish_and_send_packet
                    (unaff_s3,uVar11,param_1,*(undefined1 *)(param_1 + 0xc),
                     *(undefined1 *)(param_1 + 8),*(undefined1 *)(uVar2 + 1),
                     *(undefined2 *)(uVar2 + 0x34),*(undefined2 *)(uVar2 + 2));
_L0:
          uVar11 = 0;
          goto _L0;
        }
        iVar4 = zb_zcl_can_cluster_be_fragmented
                          (*(undefined2 *)(uVar2 + 0x34),*(undefined2 *)(uVar2 + 2));
        if (iVar4 == 0) goto _L0;
        iVar4 = zb_buf_get_max_size_func(unaff_s3);
        iVar4 = zb_buf_get_func(0,iVar4 + 1);
        if (iVar4 == 0) {
          uVar11 = 0x101;
          goto _L0;
        }
        zb_buf_copy_func(unaff_s3);
        zb_buf_free_func(unaff_s3);
        iVar5 = zb_buf_begin_func(iVar4);
        iVar6 = zb_buf_len_func(iVar4);
        unaff_s8 = iVar5 + iVar6;
      } while( true );
    }
  }
  return 0x105;
}

