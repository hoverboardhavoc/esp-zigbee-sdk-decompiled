/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
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
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  char *pcVar7;
  char *pcVar8;
  undefined2 *puVar9;
  int iVar10;
  int iVar11;
  undefined1 *puVar12;
  byte *pbVar13;
  undefined4 uVar14;
  uint uVar15;
  
  uVar5 = zb_buf_get_out_func();
  pbVar6 = (byte *)zb_buf_reuse_func();
  bVar1 = *(short *)(param_2 + 0x36) != -1;
  *pbVar6 = bVar1 << 2 | 8;
  iVar4 = param_2;
  if (bVar1) {
    pcVar7 = (char *)zb_put_next_htole16(*(undefined2 *)(param_2 + 0x36));
    pcVar8 = (char *)zb_zcl_get_ctx();
    cVar2 = *pcVar8;
    *pcVar8 = cVar2 + '\x01';
    *pcVar7 = cVar2;
    pcVar7[1] = '\n';
    pbVar6 = (byte *)(pcVar7 + 2);
  }
  else {
    pbVar13 = (byte *)zb_zcl_get_ctx(pbVar6 + 1);
    bVar3 = *pbVar13;
    *pbVar13 = bVar3 + 1;
    pbVar6[1] = bVar3;
    pbVar6[2] = 10;
    pbVar6 = pbVar6 + 3;
  }
_L0:
  do {
    if (iVar4 == 0) {
_L0:
      zb_zcl_finish_and_send_packet
                (uVar5,pbVar6,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_2 + 1),*(undefined2 *)(param_2 + 0x34),
                 *(undefined2 *)(param_2 + 2));
      return;
    }
    puVar9 = (undefined2 *)
             zb_zcl_get_attr_desc_manuf_a
                       (*(undefined1 *)(iVar4 + 1),*(undefined2 *)(iVar4 + 2),
                        *(undefined1 *)(iVar4 + 4),*(undefined2 *)(iVar4 + 6),
                        *(undefined2 *)(iVar4 + 0x36));
    iVar10 = zb_zcl_can_cluster_be_fragmented
                       (*(undefined2 *)(iVar4 + 0x34),*(undefined2 *)(iVar4 + 2));
    if (iVar10 == 0) {
      uVar15 = zb_buf_get_ptr_off_func(uVar5,pbVar6);
      uVar15 = 0x52 - (uVar15 & 0xffff);
    }
    else {
      iVar10 = zb_buf_get_max_size_func(uVar5);
      iVar11 = zb_buf_get_ptr_off_func(uVar5,pbVar6);
      uVar15 = (iVar10 - iVar11 & 0xffffU) - 0x2d;
    }
    iVar10 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(puVar9 + 1),*(undefined4 *)(puVar9 + 3));
    if (iVar10 == 0xffff) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar5,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_send_report_attr_command",0xfa);
      return;
    }
    if ((uVar15 & 0xffff) < iVar10 + 3U) {
      iVar10 = zb_zcl_can_cluster_be_fragmented
                         (*(undefined2 *)(iVar4 + 0x34),*(undefined2 *)(iVar4 + 2));
      if (iVar10 == 0) {
        uVar14 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC5,uVar14,"ESP_ZIGBEE_COMMAND");
        goto _L0;
      }
      iVar10 = zb_buf_get_max_size_func(uVar5);
      uVar14 = zb_buf_get_func(0,iVar10 + 1);
      zb_buf_copy_func(uVar5);
      zb_buf_free_func(uVar5);
      uVar5 = uVar14;
      goto _L0;
    }
    puVar12 = (undefined1 *)zb_put_next_htole16(pbVar6,*puVar9);
    *puVar12 = *(undefined1 *)(puVar9 + 1);
    pbVar6 = (byte *)esp_zb_zcl_put_attribute_value(puVar12 + 1,*(undefined4 *)(puVar9 + 3),iVar10);
    iVar4 = 0;
  } while( true );
}

