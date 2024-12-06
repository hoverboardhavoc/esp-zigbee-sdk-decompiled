/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_ias_wd_squawk_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_ias_wd_squawk_cmd_req(int param_1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  undefined2 uVar6;
  
  uVar6 = 0x104;
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar4 != 0) {
    uVar6 = *(undefined2 *)(iVar4 + 1);
  }
  iVar4 = zb_buf_get_out_func();
  if (iVar4 == 0) {
    pbVar5 = (byte *)zb_zcl_get_ctx();
    bVar1 = *pbVar5;
    *pbVar5 = bVar1 + 1;
    return bVar1;
  }
  bVar1 = *(byte *)(param_1 + 0x12);
  cVar2 = *(char *)(param_1 + 0x10);
  bVar3 = *(byte *)(param_1 + 0x11);
  pbVar5 = (byte *)zb_zcl_start_command_header(1,0,1,0);
  *pbVar5 = bVar1 & 3 | cVar2 << 4 | (byte)((bVar3 & 1) << 3);
  zb_zcl_finish_and_send_packet
            (iVar4,pbVar5 + 1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),uVar6,0x502);
  pbVar5 = (byte *)zb_buf_begin_func(iVar4);
  if ((*pbVar5 & 4) == 0) {
    iVar4 = 1;
  }
  else {
    iVar4 = 3;
  }
  return pbVar5[iVar4];
}

