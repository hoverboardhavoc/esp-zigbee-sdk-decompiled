/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_poll_control_fast_poll_stop_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_poll_control_fast_poll_stop_cmd_req(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  
  if ((param_1 != 0) && (iVar3 = zb_buf_get_out_func(), iVar3 != 0)) {
    iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
    uVar6 = 0x104;
    if (iVar4 != 0) {
      uVar6 = *(undefined2 *)(iVar4 + 1);
    }
    uVar5 = zb_zcl_start_command_header(iVar3,1,0,1,0);
    zb_zcl_finish_and_send_packet
              (iVar3,uVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar6,0x20);
    pbVar2 = (byte *)zb_buf_begin_func(iVar3);
    if ((*pbVar2 & 4) == 0) {
      iVar3 = 1;
    }
    else {
      iVar3 = 3;
    }
    return pbVar2[iVar3];
  }
  pbVar2 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar2;
  *pbVar2 = bVar1 + 1;
  return bVar1;
}

