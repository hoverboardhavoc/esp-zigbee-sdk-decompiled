/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_ias_zone_enroll_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_ias_zone_enroll_cmd_req(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  byte *pbVar8;
  
  uVar3 = 0x104;
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar4 != 0) {
    uVar3 = *(undefined2 *)(iVar4 + 1);
  }
  iVar4 = zb_buf_get_out_func();
  if (iVar4 == 0) {
    pbVar8 = (byte *)zb_zcl_get_ctx();
    bVar2 = *pbVar8;
    *pbVar8 = bVar2 + 1;
    return bVar2;
  }
  puVar5 = (undefined1 *)zb_buf_reuse_func();
  *puVar5 = 0x19;
  pcVar6 = (char *)zb_zcl_get_ctx();
  cVar1 = *pcVar6;
  *pcVar6 = cVar1 + '\x01';
  puVar5[1] = cVar1;
  puVar5[2] = 1;
  zb_put_next_htole16(puVar5 + 3,*(undefined2 *)(param_1 + 0x10));
  uVar7 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x12));
  zb_zcl_finish_and_send_packet
            (iVar4,uVar7,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),uVar3,0x500);
  pbVar8 = (byte *)zb_buf_begin_func(iVar4);
  if ((*pbVar8 & 4) == 0) {
    iVar4 = 1;
  }
  else {
    iVar4 = 3;
  }
  return pbVar8[iVar4];
}

