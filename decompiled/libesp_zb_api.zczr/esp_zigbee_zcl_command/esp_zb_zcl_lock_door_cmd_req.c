/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_lock_door_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_lock_door_cmd_req(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    pbVar4 = (byte *)zb_zcl_get_ctx();
    bVar1 = *pbVar4;
    *pbVar4 = bVar1 + 1;
    return bVar1;
  }
  uVar3 = zb_zcl_start_command_header(1,0,0,0);
  zb_zcl_finish_and_send_packet
            (iVar2,uVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,0x101);
  pbVar4 = (byte *)zb_buf_begin_func(iVar2);
  return pbVar4[(-(uint)((*pbVar4 & 4) == 0) & 0xfffffffe) + 3];
}

