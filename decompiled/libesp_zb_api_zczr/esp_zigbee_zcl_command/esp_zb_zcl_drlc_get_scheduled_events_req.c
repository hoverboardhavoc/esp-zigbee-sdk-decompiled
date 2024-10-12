/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
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
  if ((*pbVar3 >> 2 & 1) == 0) {
    iVar2 = 1;
  }
  else {
    iVar2 = 3;
  }
  return pbVar3[iVar2];
}

