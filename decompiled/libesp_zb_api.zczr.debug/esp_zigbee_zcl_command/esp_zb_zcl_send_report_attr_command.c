/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
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
  undefined4 uVar6;
  undefined1 *puVar7;
  uint uVar8;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar6 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): No I/O buffer for reporting\n",uVar6,
            "ESP_ZIGBEE_COMMAND","esp_zb_zcl_send_report_attr_command",0xa2);
    uVar6 = 0x101;
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
    while (param_2 != 0) {
      puVar5 = (undefined2 *)
               zb_zcl_get_attr_desc_manuf_a
                         (*(undefined1 *)(param_2 + 1),*(undefined2 *)(param_2 + 2),
                          *(undefined1 *)(param_2 + 4),*(undefined2 *)(param_2 + 6),
                          *(undefined2 *)(param_2 + 0x36));
      iVar3 = zb_zcl_can_cluster_be_fragmented
                        (*(undefined2 *)(param_2 + 0x34),*(undefined2 *)(param_2 + 2));
      if (iVar3 == 0) {
        uVar8 = zb_buf_get_ptr_off_func(iVar1,iVar2);
        uVar8 = 0x52 - (uVar8 & 0xffff);
      }
      else {
        iVar3 = zb_buf_get_max_size_func(iVar1);
        iVar2 = zb_buf_get_ptr_off_func(iVar1,iVar2);
        uVar8 = (iVar3 - iVar2 & 0xffffU) - 0x2d;
      }
      iVar2 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(puVar5 + 1),*(undefined4 *)(puVar5 + 3))
      ;
      if (iVar2 == 0xffff) {
        uVar6 = esp_log_timestamp();
        esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): Failed to get attribute size\n",uVar6,
                "ESP_ZIGBEE_COMMAND","esp_zb_zcl_send_report_attr_command",0xad);
        uVar6 = 0x104;
        goto _L0;
      }
      if (iVar2 + 3U <= ((uVar8 & 0xffff) - 0x19 & 0xffff)) {
        zb_buf_alloc_right_func(iVar1);
        puVar7 = (undefined1 *)zb_put_next_htole16(*puVar5);
        *puVar7 = *(undefined1 *)(puVar5 + 1);
        iVar2 = esp_zb_zcl_put_attribute_value(puVar7 + 1,*(undefined4 *)(puVar5 + 3),iVar2);
        break;
      }
      iVar2 = zb_zcl_can_cluster_be_fragmented
                        (*(undefined2 *)(param_2 + 0x34),*(undefined2 *)(param_2 + 2));
      if (iVar2 == 0) {
        uVar6 = esp_log_timestamp();
        esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): No space in ASDU for reporting\n",uVar6,
                "ESP_ZIGBEE_COMMAND","esp_zb_zcl_send_report_attr_command",0xcc);
        uVar6 = 0x104;
        goto _L0;
      }
      iVar2 = zb_buf_get_max_size_func(iVar1);
      iVar3 = zb_buf_get_func(0,iVar2 + 1);
      if (iVar3 == 0) {
        uVar6 = esp_log_timestamp();
        esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): No enough memory for reporting\n",uVar6,
                "ESP_ZIGBEE_COMMAND","esp_zb_zcl_send_report_attr_command",0xc3);
        uVar6 = 0x101;
        goto _L0;
      }
      zb_buf_copy_func(iVar1);
      zb_buf_free_func(iVar1);
      iVar2 = zb_buf_begin_func(iVar3);
      iVar1 = zb_buf_len_func(iVar3);
      iVar2 = iVar2 + iVar1;
      iVar1 = iVar3;
    }
    zb_zcl_finish_and_send_packet
              (iVar1,iVar2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_2 + 1),*(undefined2 *)(param_2 + 0x34),
               *(undefined2 *)(param_2 + 2));
    uVar6 = 0;
  }
  return uVar6;
}

