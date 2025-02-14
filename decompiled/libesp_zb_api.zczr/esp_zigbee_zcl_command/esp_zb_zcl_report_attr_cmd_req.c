/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
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
  undefined1 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  char cVar9;
  char cVar10;
  undefined4 unaff_s3;
  undefined4 uVar11;
  int unaff_s4;
  int unaff_s6;
  int unaff_s7;
  undefined2 *unaff_s8;
  
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
      unaff_s3 = zb_buf_get_out_func();
      uVar8 = *(uint *)(param_1 + 0x10);
      unaff_s4 = zb_zcl_construct_general_command_header
                           (uVar8 >> 0x12 & 1,uVar8 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                            uVar8 >> 0x13 & 1,10);
      iVar4 = zb_buf_get_ptr_off_func(unaff_s3,unaff_s4);
      iVar5 = zb_buf_len_func(unaff_s3);
      zb_buf_alloc_right_func(unaff_s3,iVar4 - iVar5);
      unaff_s7 = 0x52;
      unaff_s6 = 0xffff;
_L0:
      unaff_s8 = (undefined2 *)
                 zb_zcl_get_attr_desc_manuf_a
                           (*(undefined1 *)(uVar2 + 1),*(undefined2 *)(uVar2 + 2),
                            *(undefined1 *)(uVar2 + 4),*(undefined2 *)(uVar2 + 6),
                            *(undefined2 *)(uVar2 + 0x36));
      iVar4 = zb_zcl_can_cluster_be_fragmented
                        (*(undefined2 *)(uVar2 + 0x34),*(undefined2 *)(uVar2 + 2));
      if (iVar4 == 0) goto _L0;
      iVar4 = zb_buf_get_max_size_func(unaff_s3);
      iVar5 = zb_buf_get_ptr_off_func(unaff_s3,unaff_s4);
      uVar8 = (iVar4 + -0x2d) - iVar5;
      uVar11 = unaff_s3;
      do {
        iVar4 = esp_zb_zcl_get_attribute_size
                          (*(undefined1 *)(unaff_s8 + 1),*(undefined4 *)(unaff_s8 + 3));
        unaff_s3 = uVar11;
        if (iVar4 != unaff_s6) {
          if (((uVar8 & 0xffff) - 0x19 & 0xffff) < iVar4 + 3U) {
            iVar4 = zb_zcl_can_cluster_be_fragmented
                              (*(undefined2 *)(uVar2 + 0x34),*(undefined2 *)(uVar2 + 2));
            if (iVar4 != 0) goto _L0;
            uVar7 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC1,uVar7,"ESP_ZIGBEE_COMMAND");
          }
          else {
            zb_buf_alloc_right_func(uVar11);
            puVar6 = (undefined1 *)zb_put_next_htole16(*unaff_s8);
            *puVar6 = *(undefined1 *)(unaff_s8 + 1);
            unaff_s4 = esp_zb_zcl_put_attribute_value(*(undefined4 *)(unaff_s8 + 3),iVar4);
          }
          zb_zcl_finish_and_send_packet
                    (uVar11,unaff_s4,param_1,*(undefined1 *)(param_1 + 0xc),
                     *(undefined1 *)(param_1 + 8),*(undefined1 *)(uVar2 + 1),
                     *(undefined2 *)(uVar2 + 0x34),*(undefined2 *)(uVar2 + 2));
        }
_L0:
        if (uVar2 < *(int *)(iVar3 + 0x1b) + (uint)*(byte *)(iVar3 + 0x1a) * 0x38) {
          return 0;
        }
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zcl_command.c"
                  ,0x15d);
_L0:
        iVar4 = zb_buf_get_ptr_off_func(unaff_s3,unaff_s4);
        uVar8 = unaff_s7 - iVar4;
        uVar11 = unaff_s3;
      } while( true );
    }
  }
  return 0x105;
_L0:
  iVar4 = zb_buf_get_max_size_func(uVar11);
  unaff_s3 = zb_buf_get_func(0,iVar4 + 1);
  zb_buf_copy_func(uVar11);
  zb_buf_free_func(uVar11);
  iVar4 = zb_buf_begin_func(unaff_s3);
  iVar5 = zb_buf_len_func(unaff_s3);
  unaff_s4 = iVar4 + iVar5;
  goto _L0;
}

