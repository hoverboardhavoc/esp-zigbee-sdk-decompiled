/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_send_report_attr_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_send_report_attr_command(int param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  byte *pbVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined2 *puVar10;
  int iVar11;
  undefined1 *puVar12;
  byte *pbVar13;
  undefined4 uVar14;
  uint uVar15;
  
  uVar4 = zb_buf_get_out_func();
  pbVar5 = (byte *)zb_buf_reuse_func();
  bVar1 = *(short *)(param_2 + 0x36) != -1;
  *pbVar5 = bVar1 << 2 | 8;
  if (bVar1) {
    pcVar6 = (char *)zb_put_next_htole16(*(undefined2 *)(param_2 + 0x36));
    pcVar7 = (char *)zb_zcl_get_ctx();
    cVar2 = *pcVar7;
    *pcVar7 = cVar2 + '\x01';
    *pcVar6 = cVar2;
    pcVar6[1] = '\n';
    pbVar5 = (byte *)(pcVar6 + 2);
  }
  else {
    pbVar13 = (byte *)zb_zcl_get_ctx(pbVar5 + 1);
    bVar3 = *pbVar13;
    *pbVar13 = bVar3 + 1;
    pbVar5[1] = bVar3;
    pbVar5[2] = 10;
    pbVar5 = pbVar5 + 3;
  }
  iVar8 = zb_buf_get_ptr_off_func(uVar4,pbVar5);
  iVar9 = zb_buf_len_func(uVar4);
  zb_buf_alloc_right_func(uVar4,iVar8 - iVar9);
  iVar8 = param_2;
_L0:
  do {
    if (iVar8 == 0) {
_L0:
      zb_zcl_finish_and_send_packet
                (uVar4,pbVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_2 + 1),*(undefined2 *)(param_2 + 0x34),
                 *(undefined2 *)(param_2 + 2));
      return;
    }
    puVar10 = (undefined2 *)
              zb_zcl_get_attr_desc_manuf_a
                        (*(undefined1 *)(iVar8 + 1),*(undefined2 *)(iVar8 + 2),
                         *(undefined1 *)(iVar8 + 4),*(undefined2 *)(iVar8 + 6),
                         *(undefined2 *)(iVar8 + 0x36));
    iVar9 = zb_zcl_can_cluster_be_fragmented
                      (*(undefined2 *)(iVar8 + 0x34),*(undefined2 *)(iVar8 + 2));
    if (iVar9 == 0) {
      uVar15 = zb_buf_get_ptr_off_func(uVar4,pbVar5);
      uVar15 = 0x52 - (uVar15 & 0xffff);
    }
    else {
      iVar9 = zb_buf_get_max_size_func(uVar4);
      iVar11 = zb_buf_get_ptr_off_func(uVar4,pbVar5);
      uVar15 = (iVar9 - iVar11 & 0xffffU) - 0x2d;
    }
    iVar9 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(puVar10 + 1),*(undefined4 *)(puVar10 + 3))
    ;
    if (iVar9 == 0xffff) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar4,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_send_report_attr_command",0xfd);
      return;
    }
    if ((uVar15 & 0xffff) < iVar9 + 3U) {
      iVar9 = zb_zcl_can_cluster_be_fragmented
                        (*(undefined2 *)(iVar8 + 0x34),*(undefined2 *)(iVar8 + 2));
      if (iVar9 == 0) {
        uVar14 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC5,uVar14,"ESP_ZIGBEE_COMMAND");
        goto _L0;
      }
      iVar9 = zb_buf_get_max_size_func(uVar4);
      uVar14 = zb_buf_get_func(0,iVar9 + 1);
      zb_buf_copy_func(uVar4);
      zb_buf_free_func(uVar4);
      uVar4 = uVar14;
      goto _L0;
    }
    zb_buf_alloc_right_func(uVar4);
    puVar12 = (undefined1 *)zb_put_next_htole16(*puVar10);
    *puVar12 = *(undefined1 *)(puVar10 + 1);
    pbVar5 = (byte *)esp_zb_zcl_put_attribute_value(puVar12 + 1,*(undefined4 *)(puVar10 + 3),iVar9);
    iVar8 = 0;
  } while( true );
}

