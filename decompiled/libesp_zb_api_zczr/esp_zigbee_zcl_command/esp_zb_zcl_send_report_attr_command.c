/*
 * Last changed at upstream commit b278a1511ed728943e19c371f88a01e9d130f19f
 * https://github.com/espressif/esp-zigbee-sdk/commit/b278a1511ed728943e19c371f88a01e9d130f19f
 * Upstream date: 2023-02-27 14:43:05 +0800
 * Upstream subject: zcl: add ZCL API for color and report attribute(af3fa1e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_send_report_attr_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_send_report_attr_command(int param_1,undefined4 param_2,undefined1 param_3)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  char *pcVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  undefined2 *puVar10;
  uint uVar11;
  uint uVar12;
  
  iVar4 = zb_zcl_get_attr_desc_manuf_a
                    (*(undefined1 *)(param_1 + 1),*(undefined2 *)(param_1 + 2),
                     *(undefined1 *)(param_1 + 4),*(undefined2 *)(param_1 + 6),
                     *(undefined2 *)(param_1 + 0x2e));
  pbVar5 = (byte *)zb_buf_reuse_func(param_2);
  bVar1 = *(byte *)(iVar4 + 3);
  bVar3 = (bVar1 & 0x20) != 0;
  *pbVar5 = bVar3 << 2 | 8;
  iVar4 = param_1;
  if ((bVar1 & 0x20) == 0) {
    pbVar8 = (byte *)zb_zcl_get_ctx();
    bVar1 = *pbVar8;
    *pbVar8 = bVar1 + 1;
    pbVar5[1] = bVar1;
    pbVar5[2] = 10;
    pbVar5 = pbVar5 + 3;
  }
  else {
    pcVar6 = (char *)zb_put_next_htole16(pbVar5 + 1,*(undefined2 *)(param_1 + 0x2e));
    pcVar7 = (char *)zb_zcl_get_ctx();
    cVar2 = *pcVar7;
    *pcVar7 = cVar2 + '\x01';
    *pcVar6 = cVar2;
    pcVar6[1] = '\n';
    pbVar5 = (byte *)(pcVar6 + 2);
  }
  while (iVar4 != 0) {
    puVar10 = (undefined2 *)
              zb_zcl_get_attr_desc_manuf_a
                        (*(undefined1 *)(iVar4 + 1),*(undefined2 *)(iVar4 + 2),
                         *(undefined1 *)(iVar4 + 4),*(undefined2 *)(iVar4 + 6),
                         *(undefined2 *)(iVar4 + 0x2e));
    uVar11 = zb_buf_get_ptr_off_func(param_2,pbVar5);
    uVar12 = zb_zcl_get_attribute_size(*(undefined1 *)(puVar10 + 1),*(undefined4 *)(puVar10 + 3));
    if ((0x52 - (uVar11 & 0xffff) & 0xffff) < uVar12 + 3) break;
    puVar9 = (undefined1 *)zb_put_next_htole16(pbVar5,*puVar10);
    *puVar9 = *(undefined1 *)(puVar10 + 1);
    pbVar5 = (byte *)esp_zb_zcl_put_attribute_value
                               (puVar9 + 1,puVar10,*(undefined4 *)(puVar10 + 3),uVar12 & 0xffff);
    zb_zcl_save_reported_value(iVar4,puVar10);
    bVar1 = *(byte *)(iVar4 + 8);
    *(byte *)(iVar4 + 8) = bVar1 & 0xfd;
    *(byte *)(iVar4 + 8) = bVar1 & 0xf9;
    *(byte *)(iVar4 + 8) = bVar1 & 0xe9;
    *(byte *)(iVar4 + 8) = bVar1 & 0xe9 | 0x20;
    iVar4 = zb_zcl_get_next_reporting_info(param_1,bVar3);
  }
  zb_zcl_finish_and_send_packet
            (param_2,pbVar5,param_1 + 0x28,param_3,*(undefined1 *)(param_1 + 0x2a),
             *(undefined1 *)(param_1 + 1),*(undefined2 *)(param_1 + 0x2c),
             *(undefined2 *)(param_1 + 2));
  return;
}

