/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_on_off_on_with_timed_off_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_on_off_on_with_timed_off_cmd_req(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  byte *pbVar6;
  
  uVar2 = 0x104;
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 != 0) {
    uVar2 = *(undefined2 *)(iVar3 + 1);
  }
  iVar3 = zb_buf_get_out_func();
  if (iVar3 == 0) {
    pbVar6 = (byte *)zb_zcl_get_ctx();
    bVar1 = *pbVar6;
    *pbVar6 = bVar1 + 1;
    return bVar1;
  }
  puVar4 = (undefined1 *)zb_zcl_start_command_header(1,0,0x42,0);
  *puVar4 = *(undefined1 *)(param_1 + 0x10);
  zb_put_next_htole16(*(undefined2 *)(param_1 + 0x12));
  uVar5 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x14));
  zb_zcl_finish_and_send_packet
            (iVar3,uVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),uVar2,6);
  pbVar6 = (byte *)zb_buf_begin_func(iVar3);
  if ((*pbVar6 >> 2 & 1) == 0) {
    iVar3 = 1;
  }
  else {
    iVar3 = 3;
  }
  return pbVar6[iVar3];
}

