/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_config_report_cmd_req(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  char *pcVar6;
  int iVar7;
  byte *pbVar8;
  undefined2 uVar9;
  int iVar10;
  int iVar11;
  
  uVar9 = 0x104;
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar4 != 0) {
    uVar9 = *(undefined2 *)(iVar4 + 1);
  }
  iVar4 = zb_buf_get_out_func();
  if (iVar4 == 0) {
    pbVar8 = (byte *)zb_zcl_get_ctx();
    bVar2 = *pbVar8;
    *pbVar8 = bVar2 + 1;
    return bVar2;
  }
  if (**(int **)(param_1 + 0x14) == 0) {
    puVar5 = (undefined1 *)zb_buf_reuse_func();
    *puVar5 = 0;
  }
  else {
    puVar5 = (undefined1 *)zb_buf_reuse_func();
    *puVar5 = 8;
  }
  pcVar6 = (char *)zb_zcl_get_ctx();
  cVar1 = *pcVar6;
  puVar3 = puVar5 + 3;
  iVar11 = 0;
  *pcVar6 = cVar1 + '\x01';
  puVar5[1] = cVar1;
  puVar5[2] = 6;
  while ((iVar11 < (int)(uint)*(ushort *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
    *puVar3 = 0;
    iVar10 = iVar11 * 0x10;
    puVar5 = (undefined1 *)
             zb_put_next_htole16(puVar3 + 1,*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar10 + 4));
    *puVar5 = *(undefined1 *)(*(int *)(param_1 + 0x14) + iVar10 + 6);
    zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar10 + 8));
    puVar3 = (undefined1 *)
             zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar10 + 10));
    iVar7 = zb_zcl_is_analog_data_type(*(undefined1 *)(*(int *)(param_1 + 0x14) + iVar10 + 6));
    if (iVar7 != 0) {
      iVar10 = *(int *)(param_1 + 0x14) + iVar10;
      puVar3 = (undefined1 *)
               zb_zcl_put_value_to_packet
                         (puVar3,*(undefined1 *)(iVar10 + 6),*(undefined4 *)(iVar10 + 0xc));
    }
    iVar11 = iVar11 + 1;
  }
  zb_zcl_finish_and_send_packet
            (iVar4,puVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),uVar9,*(undefined2 *)(param_1 + 0x10));
  pbVar8 = (byte *)zb_buf_begin_func(iVar4);
  if ((*pbVar8 >> 2 & 1) == 0) {
    iVar4 = 1;
  }
  else {
    iVar4 = 3;
  }
  return pbVar8[iVar4];
}

