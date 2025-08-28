/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_send_report_attr_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_send_report_attr_command(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar7 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC1,uVar7,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_send_report_attr_command",0xa2);
    uVar7 = 0x101;
_L0:
    if (iVar1 != 0) {
      zb_buf_free_func(iVar1);
    }
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x10);
    iVar2 = zb_zcl_construct_general_command_header
                      (uVar8 >> 0x12 & 1,uVar8 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                       uVar8 >> 0x13 & 1,10);
    iVar3 = zb_buf_get_ptr_off_func(iVar1,iVar2);
    iVar4 = zb_buf_len_func(iVar1);
    zb_buf_alloc_right_func(iVar1,iVar3 - iVar4);
    iVar3 = param_2;
    while (iVar3 != 0) {
      puVar5 = (undefined2 *)
               zb_zcl_get_attr_desc_manuf_a
                         (*(undefined1 *)(iVar3 + 1),*(undefined2 *)(iVar3 + 2),
                          *(undefined1 *)(iVar3 + 4),*(undefined2 *)(iVar3 + 6),
                          *(undefined2 *)(iVar3 + 0x36));
      iVar4 = zb_zcl_can_cluster_be_fragmented
                        (*(undefined2 *)(iVar3 + 0x34),*(undefined2 *)(iVar3 + 2));
      if (iVar4 == 0) {
        uVar8 = zb_buf_get_ptr_off_func(iVar1,iVar2);
        uVar8 = 0x52 - (uVar8 & 0xffff);
      }
      else {
        iVar4 = zb_buf_get_max_size_func(iVar1);
        iVar2 = zb_buf_get_ptr_off_func(iVar1,iVar2);
        uVar8 = (iVar4 - iVar2 & 0xffffU) - 0x2d;
      }
      iVar2 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(puVar5 + 1),*(undefined4 *)(puVar5 + 3))
      ;
      if (iVar2 == 0xffff) {
        uVar7 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC2,uVar7,"ESP_ZIGBEE_COMMAND",
                      "esp_zb_zcl_send_report_attr_command",0xad);
        uVar7 = 0x104;
        goto _L0;
      }
      if (((uVar8 & 0xffff) - 0x19 & 0xffff) < iVar2 + 3U) {
        iVar2 = zb_zcl_can_cluster_be_fragmented
                          (*(undefined2 *)(iVar3 + 0x34),*(undefined2 *)(iVar3 + 2));
        if (iVar2 == 0) {
          uVar7 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC4,uVar7,"ESP_ZIGBEE_COMMAND",
                        "esp_zb_zcl_send_report_attr_command",0xcc);
          uVar7 = 0x104;
          goto _L0;
        }
        iVar2 = zb_buf_get_max_size_func(iVar1);
        iVar4 = zb_buf_get_func(0,iVar2 + 1);
        if (iVar4 == 0) {
          uVar7 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC3,uVar7,"ESP_ZIGBEE_COMMAND",
                        "esp_zb_zcl_send_report_attr_command",0xc3);
          uVar7 = 0x101;
          goto _L0;
        }
        zb_buf_copy_func(iVar1);
        zb_buf_free_func(iVar1);
        iVar2 = zb_buf_begin_func(iVar4);
        iVar1 = zb_buf_len_func(iVar4);
        iVar2 = iVar2 + iVar1;
        iVar1 = iVar4;
      }
      else {
        zb_buf_alloc_right_func(iVar1);
        puVar6 = (undefined1 *)zb_put_next_htole16(*puVar5);
        *puVar6 = *(undefined1 *)(puVar5 + 1);
        iVar2 = esp_zb_zcl_put_attribute_value(puVar6 + 1,*(undefined4 *)(puVar5 + 3),iVar2);
        iVar3 = 0;
      }
    }
    zb_zcl_finish_and_send_packet
              (iVar1,iVar2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_2 + 1),*(undefined2 *)(param_2 + 0x34),
               *(undefined2 *)(param_2 + 2));
    uVar7 = 0;
  }
  return uVar7;
}

