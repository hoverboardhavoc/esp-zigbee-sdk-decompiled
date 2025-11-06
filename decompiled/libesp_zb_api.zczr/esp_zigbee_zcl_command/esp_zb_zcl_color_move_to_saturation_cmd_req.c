/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_color_move_to_saturation_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_color_move_to_saturation_cmd_req(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined2 uVar4;
  code *pcVar5;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  uVar4 = 0x104;
  if (iVar2 != 0) {
    uVar4 = *(undefined2 *)(iVar2 + 1);
  }
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    pbVar3 = (byte *)zb_zcl_get_ctx(uVar4);
    bVar1 = *pbVar3;
    *pbVar3 = bVar1 + 1;
    return bVar1;
  }
  pcVar5 = zb_zcl_cmd_send_status_cb;
  if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
    pcVar5 = zb_zcl_cmd_send_status_handler;
  }
  zb_zcl_color_control_send_move_to_saturation_req
            (param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0,pcVar5);
  pbVar3 = (byte *)zb_buf_begin_func(iVar2);
  return pbVar3[(-(uint)((*pbVar3 & 4) == 0) & 0xfffffffe) + 3];
}

