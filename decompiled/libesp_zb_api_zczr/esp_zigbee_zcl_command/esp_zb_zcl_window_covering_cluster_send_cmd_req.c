/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_window_covering_cluster_send_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_window_covering_cluster_send_cmd_req(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  
  uVar3 = 0x104;
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar4 != 0) {
    uVar3 = *(undefined2 *)(iVar4 + 1);
  }
  iVar4 = zb_buf_get_out_func();
  if (iVar4 == 0) {
    pbVar6 = (byte *)zb_zcl_get_ctx();
    bVar2 = *pbVar6;
    *pbVar6 = bVar2 + 1;
    return bVar2;
  }
  puVar5 = (undefined1 *)zb_zcl_start_command_header(1,0,*(undefined1 *)(param_1 + 0x16),0);
  cVar1 = *(char *)(param_1 + 0x16);
  if ((cVar1 == '\x04') || (cVar1 == '\a')) {
    puVar7 = *(undefined1 **)(param_1 + 0x10);
    *puVar5 = *puVar7;
    puVar5[1] = puVar7[1];
  }
  else if ((cVar1 == '\x05') || (cVar1 == '\b')) {
    *puVar5 = **(undefined1 **)(param_1 + 0x10);
  }
  zb_zcl_finish_and_send_packet
            (iVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),uVar3,*(undefined2 *)(param_1 + 0x14));
  pbVar6 = (byte *)zb_buf_begin_func(iVar4);
  if ((*pbVar6 >> 2 & 1) == 0) {
    iVar4 = 1;
  }
  else {
    iVar4 = 3;
  }
  return pbVar6[iVar4];
}

