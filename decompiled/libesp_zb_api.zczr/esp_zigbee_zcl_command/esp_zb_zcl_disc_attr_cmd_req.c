/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_disc_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_disc_attr_cmd_req(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  uint uVar6;
  
  uVar2 = 0x104;
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 != 0) {
    uVar2 = *(undefined2 *)(iVar3 + 1);
  }
  iVar3 = zb_buf_get_out_func();
  if (iVar3 == 0) {
    pbVar5 = (byte *)zb_zcl_get_ctx();
    bVar1 = *pbVar5;
    *pbVar5 = bVar1 + 1;
    return bVar1;
  }
  uVar6 = *(uint *)(param_1 + 0x10);
  zb_zcl_construct_general_command_header
            (uVar6 >> 0x12 & 1,uVar6 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),uVar6 >> 0x13 & 1,
             0xc);
  puVar4 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(param_1 + 0x16));
  *puVar4 = *(undefined1 *)(param_1 + 0x18);
  zb_zcl_finish_and_send_packet
            (iVar3,puVar4 + 1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),uVar2,*(undefined2 *)(param_1 + 0x10));
  pbVar5 = (byte *)zb_buf_begin_func(iVar3);
  if ((*pbVar5 & 4) == 0) {
    iVar3 = 1;
  }
  else {
    iVar3 = 3;
  }
  return pbVar5[iVar3];
}

