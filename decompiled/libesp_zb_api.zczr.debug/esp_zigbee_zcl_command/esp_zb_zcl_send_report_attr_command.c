/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_send_report_attr_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_send_report_attr_command(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  
  uVar1 = zb_buf_get_out_func();
  uVar9 = *(uint *)(param_1 + 0x10);
  iVar2 = zb_zcl_construct_general_command_header
                    (uVar9 >> 0x12 & 1,uVar9 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                     uVar9 >> 0x13 & 1,10);
  iVar3 = zb_buf_get_ptr_off_func(uVar1,iVar2);
  iVar4 = zb_buf_len_func(uVar1);
  zb_buf_alloc_right_func(uVar1,iVar3 - iVar4);
  iVar3 = param_2;
_L0:
  do {
    if (iVar3 == 0) {
_L0:
      zb_zcl_finish_and_send_packet
                (uVar1,iVar2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_2 + 1),*(undefined2 *)(param_2 + 0x34),
                 *(undefined2 *)(param_2 + 2));
      return;
    }
    puVar5 = (undefined2 *)
             zb_zcl_get_attr_desc_manuf_a
                       (*(undefined1 *)(iVar3 + 1),*(undefined2 *)(iVar3 + 2),
                        *(undefined1 *)(iVar3 + 4),*(undefined2 *)(iVar3 + 6),
                        *(undefined2 *)(iVar3 + 0x36));
    iVar4 = zb_zcl_can_cluster_be_fragmented
                      (*(undefined2 *)(iVar3 + 0x34),*(undefined2 *)(iVar3 + 2));
    if (iVar4 == 0) {
      uVar9 = zb_buf_get_ptr_off_func(uVar1,iVar2);
      uVar9 = 0x52 - (uVar9 & 0xffff);
    }
    else {
      iVar4 = zb_buf_get_max_size_func(uVar1);
      iVar6 = zb_buf_get_ptr_off_func(uVar1,iVar2);
      uVar9 = (iVar4 - iVar6 & 0xffffU) - 0x2d;
    }
    iVar4 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(puVar5 + 1),*(undefined4 *)(puVar5 + 3));
    if (iVar4 == 0xffff) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar1,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_send_report_attr_command",0x10b);
      return;
    }
    if (((uVar9 & 0xffff) - 0x19 & 0xffff) < iVar4 + 3U) {
      iVar4 = zb_zcl_can_cluster_be_fragmented
                        (*(undefined2 *)(iVar3 + 0x34),*(undefined2 *)(iVar3 + 2));
      if (iVar4 == 0) {
        uVar8 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC5,uVar8,"ESP_ZIGBEE_COMMAND");
        goto _L0;
      }
      iVar2 = zb_buf_get_max_size_func(uVar1);
      uVar8 = zb_buf_get_func(0,iVar2 + 1);
      zb_buf_copy_func(uVar1);
      zb_buf_free_func(uVar1);
      iVar2 = zb_buf_begin_func(uVar8);
      iVar4 = zb_buf_len_func(uVar8);
      iVar2 = iVar2 + iVar4;
      uVar1 = uVar8;
      goto _L0;
    }
    zb_buf_alloc_right_func(uVar1);
    puVar7 = (undefined1 *)zb_put_next_htole16(*puVar5);
    *puVar7 = *(undefined1 *)(puVar5 + 1);
    iVar2 = esp_zb_zcl_put_attribute_value(puVar7 + 1,*(undefined4 *)(puVar5 + 3),iVar4);
    iVar3 = 0;
  } while( true );
}

