/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_level_move_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_level_move_cmd_req(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  code *pcVar5;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if ((iVar2 != 0) && (iVar4 = zb_buf_get_out_func(), iVar4 != 0)) {
    pcVar5 = zb_zcl_cmd_send_status_cb;
    if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
      pcVar5 = zb_zcl_cmd_send_status_handler;
    }
    zb_zcl_level_control_send_move_cmd
              (param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar2 + 1),0,pcVar5);
    pbVar3 = (byte *)zb_buf_begin_func(iVar4);
    if ((*pbVar3 >> 2 & 1) == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = 3;
    }
    return pbVar3[iVar2];
  }
  pbVar3 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar3;
  *pbVar3 = bVar1 + 1;
  return bVar1;
}

