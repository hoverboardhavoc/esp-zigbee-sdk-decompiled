/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_report_attr_cmd_req
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
  uint uVar10;
  undefined2 *unaff_s3;
  uint uVar11;
  undefined4 unaff_s6;
  int unaff_s7;
  int unaff_s8;
  
  bVar1 = *(byte *)(param_1 + 0x12);
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 != 0) {
    uVar10 = ((bVar1 & 4) == 0) + 1;
    if ((*(byte *)(param_1 + 0x12) & 3) == 0) {
      *(undefined2 *)(param_1 + 0x14) = 0xffff;
    }
    iVar4 = zb_zcl_get_attr_desc_manuf_a
                      (*(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),uVar10,
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
             (*(byte *)(uVar2 + 4) == uVar10)) &&
            (*(short *)(uVar2 + 6) == *(short *)(param_1 + 0x16))) &&
           (*(short *)(uVar2 + 0x36) == *(short *)(param_1 + 0x14))) break;
        cVar9 = cVar9 + '\x01';
        uVar2 = uVar2 + 0x38;
      }
      uVar10 = zb_buf_get_out_func();
      uVar8 = *(uint *)(param_1 + 0x10);
      unaff_s6 = zb_zcl_construct_general_command_header
                           (uVar8 >> 0x12 & 1,uVar8 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                            uVar8 >> 0x13 & 1,10);
      iVar4 = zb_buf_get_ptr_off_func(uVar10,unaff_s6);
      iVar5 = zb_buf_len_func(uVar10);
      zb_buf_alloc_right_func(uVar10,iVar4 - iVar5);
      unaff_s8 = 0x52;
      unaff_s7 = 0xffff;
_L0:
      unaff_s3 = (undefined2 *)
                 zb_zcl_get_attr_desc_manuf_a
                           (*(undefined1 *)(uVar2 + 1),*(undefined2 *)(uVar2 + 2),
                            *(undefined1 *)(uVar2 + 4),*(undefined2 *)(uVar2 + 6),
                            *(undefined2 *)(uVar2 + 0x36));
      iVar4 = zb_zcl_can_cluster_be_fragmented
                        (*(undefined2 *)(uVar2 + 0x34),*(undefined2 *)(uVar2 + 2));
      if (iVar4 == 0) goto _L0;
      iVar4 = zb_buf_get_max_size_func(uVar10);
      iVar5 = zb_buf_get_ptr_off_func(uVar10,unaff_s6);
      uVar11 = (iVar4 + -0x2d) - iVar5;
      uVar8 = uVar10;
      do {
        iVar4 = esp_zb_zcl_get_attribute_size
                          (*(undefined1 *)(unaff_s3 + 1),*(undefined4 *)(unaff_s3 + 3));
        uVar10 = uVar8;
        if (iVar4 != unaff_s7) {
          if ((uVar11 & 0xffff) < iVar4 + 3U) {
            iVar4 = zb_zcl_can_cluster_be_fragmented
                              (*(undefined2 *)(uVar2 + 0x34),*(undefined2 *)(uVar2 + 2));
            if (iVar4 != 0) goto _L0;
            uVar7 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC1,uVar7,"ESP_ZIGBEE_COMMAND");
          }
          else {
            zb_buf_alloc_right_func(uVar8);
            puVar6 = (undefined1 *)zb_put_next_htole16(*unaff_s3);
            *puVar6 = *(undefined1 *)(unaff_s3 + 1);
            unaff_s6 = esp_zb_zcl_put_attribute_value(*(undefined4 *)(unaff_s3 + 3),iVar4);
          }
          zb_zcl_finish_and_send_packet
                    (uVar8,unaff_s6,param_1,*(undefined1 *)(param_1 + 0xc),
                     *(undefined1 *)(param_1 + 8),*(undefined1 *)(uVar2 + 1),
                     *(undefined2 *)(uVar2 + 0x34),*(undefined2 *)(uVar2 + 2));
        }
_L0:
        if (uVar2 < *(int *)(iVar3 + 0x1b) + (uint)*(byte *)(iVar3 + 0x1a) * 0x38) {
          return 0;
        }
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zcl_command.c"
                  ,0x154);
_L0:
        iVar4 = zb_buf_get_ptr_off_func(uVar10,unaff_s6);
        uVar11 = unaff_s8 - iVar4;
        uVar8 = uVar10;
      } while( true );
    }
  }
  return 0x105;
_L0:
  iVar4 = zb_buf_get_max_size_func(uVar8);
  uVar10 = zb_buf_get_func(0,iVar4 + 1);
  zb_buf_copy_func(uVar8);
  zb_buf_free_func(uVar8);
  goto _L0;
}

