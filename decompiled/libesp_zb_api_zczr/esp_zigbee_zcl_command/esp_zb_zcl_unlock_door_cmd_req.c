/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_unlock_door_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_unlock_door_cmd_req(int param_1)

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
  uVar3 = zb_zcl_start_command_header(1,0,1,0);
  zb_zcl_finish_and_send_packet
            (iVar2,uVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,0x101);
  pbVar4 = (byte *)zb_buf_begin_func(iVar2);
  if ((*pbVar4 & 4) == 0) {
    iVar2 = 1;
  }
  else {
    iVar2 = 3;
  }
  return pbVar4[iVar2];
}

