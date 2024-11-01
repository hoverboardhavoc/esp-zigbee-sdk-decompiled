/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_drlc_get_scheduled_events_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_drlc_get_scheduled_events_req(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    pbVar3 = (byte *)zb_zcl_get_ctx();
    bVar1 = *pbVar3;
    *pbVar3 = bVar1 + 1;
    return bVar1;
  }
  zb_zcl_send_cmd(*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),0,
                  *(undefined1 *)(param_1 + 9),param_1 + 0x10,0xc);
  pbVar3 = (byte *)zb_buf_begin_func(iVar2);
  if ((*pbVar3 & 4) == 0) {
    iVar2 = 1;
  }
  else {
    iVar2 = 3;
  }
  return pbVar3[iVar2];
}

